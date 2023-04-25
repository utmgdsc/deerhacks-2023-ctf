#include <stdio.h>
#include <string.h>

#define MAX_LEN 128

int check(char *input) {
	return strcmp(input, "G8e78Q27cnfV4d") == 0;
}

void secret() {
	printf("Congrats! Your flag is: dhctf{PULl1n9_4_f3W_57r1n95_vl194}\n");
}

int main (int argc, char *argv[]) {
	printf("Welcome administrator! Please verify your identity below:\n\n");

	char input[MAX_LEN] = {0};

	while (1) {
		printf("Enter password: ");
		fgets(input, MAX_LEN, stdin) == NULL;

		input[strcspn(input, "\n")] = '\0';

		if (check(input)) {
			secret();
			break;
		}
		printf("Incorrect. Try again.\n");
	}

	printf("Correct! The flag is the password.\n");

	return 0;
}
