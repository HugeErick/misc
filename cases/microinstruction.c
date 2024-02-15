#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#define INSTRUCTIONSIZE 23
#define longestToken 6

void printArr (char arr[]) {
	printf("\n");
	for (int i = 0; arr[i] != '\0'; i++) {
		printf("%c", arr[i]);
	}
	printf("\n");
}

void printNumArr (int arr[]) {
	printf("\n");
	for (int i = 0; arr[i] != '\0'; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void checkingFormat(char input[]) {
	const char* pattern = "^[0-9]{2} [0-9]{2} [0-9]{2} [0-9]{4} [0-9]{2} [0-9]{5}$";

	regex_t regex;
	int returnInt;

	returnInt = regcomp(&regex, pattern, REG_EXTENDED);

	if (returnInt) {
		fprintf(stderr, "\ncould not compiled\n");
		exit(1);
	}

	returnInt = regexec(&regex, input, 0, NULL, 0);

	if (returnInt == 0) {
		printf("\nok\n");
	} else {
		printf("\nno ok\n");
		exit(1);
	}

	regfree(&regex);
}

char* handleInput(char input[]) {
	int flagWrong = 0;
	char* finalInstruction = (char*)malloc(INSTRUCTIONSIZE * sizeof(char));
	for (int i = 0; i < INSTRUCTIONSIZE && input[i] != '\0'; i++) {
		if (input[i] == ' ') {
				finalInstruction[i] = ' ';
				continue;
		}  
		if (flagWrong > 0) {
			printf("invalid input %c", input[i]);	
			exit(1);
		}
		switch (input[i]) {
			case 48:
				finalInstruction[i] = 48;
				break;
			case 49:
				finalInstruction[i] = 49;
				break;
			case 88:
				finalInstruction[i] = 48;
				break;
			case 120:
				finalInstruction[i] = 48;
				break;
			default: 
				printf("\nfound this %c\n", input[i]);
				flagWrong += 1;
				break;
		} 
	}
	return finalInstruction;
}

int binaryToDecimal(int binaryNum) {
	int deciNum = 0, base = 1, remainder;

	while (binaryNum > 0) {
		remainder = binaryNum % 10;	
		deciNum += remainder * base;
		binaryNum /= 10;
		base *= 2;
	}

	return deciNum;
}

void tokenization(char arr[], int vals[]) {
	int index = 0, litVal = 0;
	char tempToken[longestToken] = {0}; 
	for(int i = 0; arr[i] != '\0'; i++) {
		if (arr[i] == ' ') {
			litVal = atoi(tempToken);
			printf("\nvalue:%d i:%d\n", litVal, index);
			vals[index] = binaryToDecimal(litVal);
			tempToken[0] = '\0';
			index++;	
		}
		tempToken[i % longestToken] = arr[i];
	}
	litVal = atoi(tempToken);
	printf("\nvalue:%d i:%d\n", litVal, index);
	vals[index] = binaryToDecimal(litVal);
}

int main() {
	char instruction[INSTRUCTIONSIZE] = {0};
	int values[6] = {9};

	printf("enter line\n");
	fgets(instruction, INSTRUCTIONSIZE, stdin);

	char* Handleinstruction = handleInput(instruction);

	checkingFormat(Handleinstruction);

	tokenization(Handleinstruction, values);

	printNumArr(values);

	return 0;
}
