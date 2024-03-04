#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#define INSTRUCTIONSIZE 23 
#define longestToken 6
#define FOURREGISTERS 4

//microinstruction functions
int* interpretation();

void printArr(char arr[]);
void checkingFormat(char input[]);
int* tokenization(char arr[]);

//decimalNumsInterpretor functions 
void tellingRegs(int arr[]);
void tellingMemory(int arr[]);
void checkEverything(int* mMemory, int* theFourRegs); 
int doOperation(char ariOrLogOp, int operandUno, int operandDos); 
void decimalNumsInterpretor(int* registers, int* ourMemory);

void savingOpAnsInRegs(int zContent, int cAddress, int* regs);
void savingOpAnsInMem(int zContent, int memIndex, int* mMemory);

//main functions
void flushConsoleBuffer();

