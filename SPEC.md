# LightFly VM Specifications and machine language
## Binary file structure
Binary file must start with **0x55** **0x57** bytes signature (UW in ASCII code). 
Next byte represents version of bytecode, **0x01** current.

**TODO:** platform-specific functions checking

All registers and operands are 8-bit.
Because of memory addressing is 16-bit, max count of instructions in file is 65535.
## Passing arguments
For example, opcode `ADD <number>` consists of two parts: opcode for `ADD` (**0x01**) and ADD's argument.

In bytecode `ADD 5` construction looks like:
**0x01** **0x05**

## Registers list
* IPH, IPL - current instruction pointer. Because memory addressing is 16-bit, this register splitted into two 8-bit.
* ACC - accumulator for arithmetical operations
* SP - source pointer register for some operations
* DP - destination pointer register for some operations
* R1-R5 - general purpose registers

## Opcodes list
Size of each operand is 8-bit (one byte).

| # | opcode | mnemonic | description |
| --- | --- | --- | --- |
| 1 | 0x00 | NOP | No operation (skip step) 
| 2 | 0x01 | ADD | Accepts one argument and sum it to ACC register |
| 3 | 0x02 | SUB | Accepts one argument and substract it from ACC register |
| 4 | 0x03 | MOV ACC | Accepts one argument and store it in ACC register |
| 5 | 0x04 | MOV SP | Accepts on argument and store in in SP register |
| 6 | 0x05 | MOV DP | Accepts on argument and store in in DP register |
| 7 | 0x06 | MOV R1 | Accepts on argument and store in in R1 register |
| 8 | 0x07 | MOV R2 | Accepts on argument and store in in R2 register |
| 9 | 0x08 | MOV R3 | Accepts on argument and store in in R3 register |
| 10 | 0x09 | MOV R4 | Accepts on argument and store in in R4 register |
| 11 | 0x0A | MOV R5 | Accepts on argument and store in in R5 register |
| 12 | 0x0B | JMP | Accepts two arguments - address, splitted into two 8-bit digits and jump on it |
| 256 | 0xFF | HLT | Stops VM |