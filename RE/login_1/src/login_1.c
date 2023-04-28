#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 128
#define FLAG_SIZE 33
#define PASS_SIZE 20

int check_pass(char *user_pass, char *pass) {
	printf(user_pass);
	if (strcmp(user_pass, pass) != 0) {
		printf(" incorrect. Try again.\n");
		return 0;
	}

	FILE *fp;
	if ((fp = fopen("flag.txt", "r")) == NULL) {
		perror("fopen");
		exit(1);
	}

	char flag[FLAG_SIZE] = {0};
	fgets(flag, FLAG_SIZE, fp);
	fclose(fp);

	printf(" correct! Here's your flag: %s\n", flag);
	return 1;
}

int main (int argc, char *argv[]) {
	FILE *passfp;
	if ((passfp = fopen("pass.txt", "r")) == NULL) {
		perror("fopen");
		exit(1);
	}
	char pass[PASS_SIZE];
	fgets(pass, PASS_SIZE, passfp);
	fclose(passfp);

	printf("Welcome administrator! Please verify your identity below:\n\n");

	char user_pass[MAX_LEN] = {0};
	while (1) {
		printf("Enter password: ");

		fgets(user_pass, MAX_LEN, stdin);

		user_pass[strcspn(user_pass, "\n")] = '\0';
		if (check_pass(user_pass, pass)) break;
	}
}
