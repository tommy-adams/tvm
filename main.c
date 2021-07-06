#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "headers/program.h"
#include "headers/tests.h"

// fetch instruction from program
int fetch(int ip) {
	return program[ip]; 
}

// evaluate instruction from program. If HLT, program will stop running
void eval(bool *run, int *sp, int *ip, int stack[], int instr) {
	switch (instr) {
	case HLT:
		*run = false;
		break;
	case PSH:
		stack[++*sp] = fetch(++*ip);
		break;
	case POP: 
		--*sp;
		break;
	case ADD: {
		int a = stack[*sp];
		int b = stack[--*sp];
		int sum = a + b;
		stack[*sp] = sum;
	}
		break;
	case SUB: {
		int a = stack[*sp];
		int b = stack[--*sp];
		int sub = a - b;
		stack[*sp] = sub;
	}
		break;
	case SUBR: {
		int a = stack[*sp];
		int b = stack[--*sp];
		int sub = b - a;
		stack[*sp] = sub;
	}
		break;
	case MULT: {
		int a = stack[*sp];
		int b = stack[--*sp];
		int mult = a * b;
		stack[*sp] = mult;
	}
		break;
	case DIV: {
		int a = stack[*sp];
		int b = stack[--*sp];
		int div = a / b;
		stack[*sp] = div;
	}
		break;
	case DIVR: {
		int a = stack[*sp];
		int b = stack[--*sp];
		int divr = b / a;
		stack[*sp] = divr;
	}
		break;
	case OUT:
		printf("%d\n", stack[*sp]);
		break;
	case IN: {
		char instruction[5];
		printf("Enter a command: ");
		scanf("%s", instruction);

		bool instrExists = false;
		for (int i = 0; i < sizeof(conversions) / sizeof(conversions[0]); i++) {
			if (strcmp(instruction, conversions[i].str) == 0) {
				program[*ip] = conversions[i].instr;
				instrExists = true;
				break;
			}
		}

		if (program[*ip] == 0) {
			char value[11];
			printf("Enter an integer: ");
			scanf("%s", value);
			program[*ip + 1] = atoi(value);
		}

		if (!instrExists) {
			printf("Error: %s is not a command.\n", instruction);
			program[*ip] = conversions[10].instr;
		}

		--*ip;
	}
		break;
	default: break;
	}
}

// print stack array for testing purposes
void printStack(int stack[]) {
	for (int i = 0; i < sizeof(*stack); i++) {
		printf("%d\n", stack[i]);
	}
}

// print program instructions for testing purposes
void printInstructions() {
	for (int i = 0; i < sizeof(program) / sizeof(program[0]); i++) {
		printf("%d\n", program[i]);
	}
}

int main() {
	int ip = 0; // instruction pointer
	bool running = true;
	int sp = -1; // stack pointer
	int stack[256];

	while (running) {
		int instr = fetch(ip);
		eval(&running, &sp, &ip, stack, instr);
		ip++;
	}

	return 0;
}
