// instruction set
typedef enum {
	PSH,
	POP,
	ADD,
	SUB,
	SUBR,
	MULT,
	DIV,
	DIVR,
	SET,
	MOV,
	OUT,
	IN,
	HLT
} Instructions;

// structs for string conversion
const static struct {
	Instructions instr;
	const char *str;
} conversions[] = {
	{PSH, "PSH"},
	{POP, "POP"},
	{ADD, "ADD"},
	{SUB, "SUB"},
	{SUBR, "SUBR"},
	{MULT, "MULT"},
	{DIV, "DIVR"},
	{SET, "SET"},
	{MOV, "MOV"},
	{OUT, "OUT"},
	{HLT, "HLT"}
};

// function declarations
int fetch(int ip);

void eval(bool *run, int *sp, int *ip, int stack[], int instr);

void printStack(int stack[]);

void printInstructions();
