#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#define INSTRUCTIONSIZE 23 
#define longestToken 6
#define FOURREGISTERS 4

int* interpretation();

void printArr(char arr[]);
void checkingFormat(char input[]);
int* tokenization(char arr[]);


void tellingRegs(int arr[]);
