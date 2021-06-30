#include <stdio.h>
#include <stdbool.h>
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
		*sp--;
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
	default: break;
	}
}

// print stack array for testing purposes
void printStack(int stack[]) {
	for (int i = 0; i < sizeof(*stack); i++) {
		printf("%d\n", stack[i]);
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
