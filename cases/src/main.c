#include "../hdr/microinstruction.h"
#include <stdio.h>

void tellingRegs(int arr[]) {
	for (int i = 0; i < FOURREGISTERS; i++) {
		printf("R%d = %d\n", i, arr[i]);
	}
}

int main() {
	int* decimalVals = interpretation();
	int operand1 = 0, operand2 = 0;
	char operation;
	char* switchesInterpretration;
	int memIndex = decimalVals[5], cAdress = decimalVals[4];


	//registers
	int fourRegisters[FOURREGISTERS] = {0};
	printf("\nassign values for registers\n");
	printf("r0 r1 r2 r2\n");
	
	for (int i = 0; i < FOURREGISTERS; i++ ) {
		scanf("%d", &fourRegisters[i]);
	}

	tellingRegs(fourRegisters);

	//cases
	// case operand1	
	switch (decimalVals[0]) {
		case 1:	
			operand1 = fourRegisters[1];
			break;
		case 2:	
			operand1 = fourRegisters[2];
			break;
		case 3:	
			operand1 = fourRegisters[3];
			break;
		default:
			operand1 = fourRegisters[0];
			break;
	}

	// case operand2	
	switch (decimalVals[1]) {
		case 1:	
			operand2 = fourRegisters[1];
			break;
		case 2:	
			operand2 = fourRegisters[2];
			break;
		case 3:	
			operand2 = fourRegisters[3];
			break;
		default:
			operand2 = fourRegisters[0];
			break;
	}

	// case alu operation	
	switch (decimalVals[2]) {
		case 1:	
			operation = '|';
			break;
		case 2:	
			operation = '&';
			break;
		case 3:	
			operation = '-';
			break;
		default:
			operation = '+';
			break;
	}

	// case switch pos	
	switch (decimalVals[3]) {
		case 5:	
			switchesInterpretration = "operation to mem";
			break;
		case 10:	
			switchesInterpretration = "from mem to reg";
			break;
		case 9:	
			switchesInterpretration = "operation to reg";
			break;
		default:
			switchesInterpretration = "red flag";
			break;
	}

	printf("\n%d %c %d %s (to %d)/ mem:%d\n", operand1, operation, operand2,
			switchesInterpretration, cAdress, memIndex);

	return 0;
}

