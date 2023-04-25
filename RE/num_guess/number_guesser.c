#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define PORT 1337
#define BUFF_SIZE 32

char flag[] = "flag{pr3d1c74bl3_prn6_4j4v19}";

extern char *tzname[2]; // std and dst time zone

int main (int argc, char *argv[]) {
	int sock;
	int connfd;

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(PORT);

	sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock == -1) {
		exit(1);
	}

	if (bind(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_in)) == -1) {
		exit(1);
	}

	if (listen(sock, 8) == -1) {
		exit(1);
	}

	while (1) {
		connfd = accept(sock, NULL, NULL);
		if (connfd == -1) {
			continue;
		}

		if (fork() == 0) {
			time_t t;
			srand(time(&t)); // VULN!!11!

			FILE *fp;
			if ((fp = fdopen(connfd, "r+")) != NULL) {
				char buff[BUFF_SIZE];
				// Output log:
				struct tm localt = {0};
				if (localtime_r(&t, &localt) == NULL) {
					exit(1);
				}

				char *date = asctime(&localt);
				// Get rid of newline:
				date[strlen(date) - 1] = '\0'; // Not sure if this is allowed lol (shouldn't affect other children)

				fprintf(fp, "[*] Connection at: %s %s\n", date, localt.tm_isdst ? tzname[1] : tzname[0]);

				int num = (rand() % 100000) + 1;
				fputs("[*] Random number generated!\n\n", fp);
				// Game start:
				fputs("Welcome to the number guessing game!\nWe have selected a number randomly in [1, 100000]; but you only have 3 tries to guess it :)\n-------------------------------------------\n\n", fp);

				int guess;
				int attempts = 0;

				while (attempts < 3) {
					fputs("Enter guess: ", fp);
					if (fgets(buff, BUFF_SIZE, fp) == NULL) {
						fclose(fp);
						close(connfd);
						exit(1);
					}
					guess = atoi(buff);
					if (guess == num) {
						fprintf(fp, "Congrats! %s\n", flag);
						break;
					}
					fputs("Wrong...\n", fp);
					attempts += 1;
				}
				if (attempts == 3) fputs("You used up your guesses :(\nReconnect to try again!\n", fp);
				fclose(fp);
			}
			close(connfd);
			exit(0);
		}
	}
}
