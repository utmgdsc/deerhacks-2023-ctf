#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FLAG_SIZE 30

uint8_t flag[FLAG_SIZE] = {0x6b, 0x6f, 0x6a, 0x7b, 0x6d, 0x82, 0x3a, 0x55, 0x6a, 0x79, 0x80, 0x77, 0x3e, 0x3a, 0x6b, 0x66, 0x55, 0x37, 0x66, 0x74, 0x37, 0x59, 0x3a, 0x66, 0x58, 0x6f, 0x3f, 0x4d, 0x7d, 0x84};

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: %s [file path]\n", argv[0]);
		exit(0);
	}
	
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("fopen");
		exit(1);
	}
	
	printf("Processing %s...\n\n", argv[1]);
	
	int c = 0;
	int i = 0;
	while ((c = fgetc(fp)) != EOF) {
		uint8_t b = flag[i % FLAG_SIZE];
		b -= 7;
		printf("%02hhX ", b ^ (uint8_t) c);
		i++;
	}
	fclose(fp);
	
	return 0;
}