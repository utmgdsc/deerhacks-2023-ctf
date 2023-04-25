#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define PORT 1338
#define MAX_LEN 128

char flag[] = "dhctf{d0_N07_u53_C4lcUlU5_Dh397}";

int check_pass(FILE *fp, char *user_pass, char *pass) {
	fprintf(fp, user_pass);
	if (strcmp(user_pass, pass) == 0) {
		fprintf(fp, "\nCorrect! Here's your flag: %s\n", flag);
		return 1;
	}
	fprintf(fp, "\nIncorrect. Try again.\n");
	return 0;
}

int main (int argc, char *argv[]) {
	char pass[] = "5UP3R53Cr37P422$#@!";
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
			FILE *fp;
			if ((fp = fdopen(connfd, "r+")) != NULL) {
				fputs("Welcome administrator! Please verify your identity below:\n\n", fp);

				char user_pass[MAX_LEN] = {0};
				while (1) {
					fputs("Enter password: ", fp);

					fgets(user_pass, MAX_LEN, fp) == NULL;

					user_pass[strcspn(user_pass, "\n")] = '\0';
					if (check_pass(fp, user_pass, pass)) break;
				}
			}
			fclose(fp);
			close(connfd);
			exit(0);
		}
	}
}
