# TVM

This virtual machine is currently a *work in progress*.

TVM is a virtual machine emulating basic computer hardware. It functions like a stack with commands including:

- **PSH**: push integer onto the stack
- **POP**: pop item off of the stack
- **ADD**: add the two integers at the top of the stack and push the result onto it
- **SUB**: subtract the two integers at the top of the stack and push the result onto it
- **SUBR**: subtract the top integer from the second integer and push the result onto the stack
- **MULT**: multiply the two integers at the top of the stack and push the result onto it
- **DIV**: divide the two integers at the top of the stack and push the result onto it
- **DIVR**: divide the second integer by the top integer and push the result onto it
- **OUT**: print the top of the stack
- **IN**: ask the user to enter a command (or integer if previous command was PSH)
- **SET**: set a register to a value
- **MOV**: move a value from one register to another
- **HLT**: stop the instructions

This list is not exhaustive as the instruction set will grow as I work on this over time.

**Note**: Registers have not yet been implemented.
