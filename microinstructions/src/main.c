#include "../hdr/microinstruction.h"

int* askRegs() {
	int* fourRegisters = (int*)malloc(FOURREGISTERS * sizeof(int));
	printf("assign values for registers\n");
	printf("r0 r1 r2 r3\n");
	for (int i = 0; i < FOURREGISTERS; i++ ) {
		scanf("%d", &fourRegisters[i]);
	}
	flushConsoleBuffer();
	return fourRegisters;
}

void flushConsoleBuffer() {
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

int startProcess(char input) {
	int flag = 1;
	if (input == 121 || input == 89) {
		;
	} else 
		flag = 0;
	return flag;
}

int ask(int task) {
	char answ;
	printf("\nask microinstruction?(y)(n)\n");	
	scanf("%c", &answ);
	task = startProcess(answ);
	return task;
}

int main() {
	int theMemory[6] = {-1, -2, -3, -4, -10}; 
	int task = 1;
	task = ask(task);
	int* setUpRegs = askRegs();
	while (task) {
		decimalNumsInterpretor(setUpRegs, theMemory);
		flushConsoleBuffer();
		task = ask(task);
		flushConsoleBuffer();
	}
	printf("\nexiting...\n");
	return 0;
}
