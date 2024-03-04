#include "../hdr/microinstruction.h"

void tellingRegs(int arr[]) {
	for (int i = 0; i < FOURREGISTERS; i++) {
		printf("R%d = %d\t", i, arr[i]);
	}
	printf("\n");
}

void tellingMemory(int arr[]) {
	printf("\nCurrent memory\n");
	for (int i = 0; i < 8; i++) {
		printf("m%d = %d\n", i, arr[i]);
	}
}

void checkEverything(int* mMemory, int* theFourRegs) {
	printf("\n");
	tellingRegs(theFourRegs);
	tellingMemory(mMemory);
}

int doOperation(char ariOrLogOp, int operandUno, int operandDos) {
	int zReg = 0;
	switch (ariOrLogOp) {
		case 43:
			zReg = operandUno + operandDos; 
			break;
		case 124:
			zReg = operandUno | operandDos; 
			break;
		case 38:
			zReg = operandUno & operandDos; 
			break;
		case 45:
			zReg = operandUno - operandDos; 
			break;
		default:
			printf("\nSomething on the operando went wrong\n");
			break;

	}
	printf("z ans:%d\n", zReg);
	return zReg;
}

void savingOpAnsInRegs(int zContent, int cAddress, int* regs) {
	regs[cAddress] = zContent;
}
void savingOpAnsInMem(int zContent, int memIndex, int* mMemory) {
	mMemory[memIndex] =zContent;
}

void decimalNumsInterpretor(int* registers, int* ourMemory) {
	//asking and getting microinstruction
	int* decimalVals = interpretation();
	int operand1 = 0, operand2 = 0, z = 0;
	char operation;
	char* switchesInterpretration;
	int memIndex = decimalVals[5], cAddress = decimalVals[4];
	int* fourRegisters = registers;
	int *mMemory = ourMemory;
	
	printf("before operation\n");
	checkEverything(mMemory,fourRegisters);

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
			printf("\n%d %c %d %s %d\n", operand1, operation, operand2,
					switchesInterpretration, memIndex);
			break;
		case 10:	
			switchesInterpretration = "from mem to reg";
			printf("\nfrom mem %d to reg %d\n", memIndex, cAddress);
			break;
		case 9:	
			switchesInterpretration = "qoperation to reg";
			printf("\n%d %c %d operation to reg %d\n", operand1, operation, operand2
					, cAddress);
			break;
		default:
			switchesInterpretration = "red flag";
			printf("\ninvalid switches config\n");
			exit(1);
			break;
	}

	switch (switchesInterpretration[0]) {
		case 113:
			//case operation to reg
			z = doOperation(operation,operand1,operand2);
			savingOpAnsInRegs(z, cAddress, fourRegisters);

			break;
		case 111:
			// case operation to mem
			z = doOperation(operation,operand1,operand2);
			savingOpAnsInMem(z,memIndex,mMemory);
			break;
		case 102:
			// case from mem to reg
			fourRegisters[cAddress] = mMemory[memIndex];
			break;
		default:
			printf("\nsomething went wrong\n");
			break;
	}	

	printf("after operation\n");
	checkEverything(mMemory,fourRegisters);
}


