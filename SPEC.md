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

## Flags list
You cannot get flags values directly in code. But there is opcodes like CMP, which can modify or read flag values
* CF - compare flag, get 1 if CMP operands are equals, otherwise 0
* OF - overflow flag, get 1 if ADD or SUM result (or in CMP first operand greater than second) 
get overflow, otherwise 0

## Opcodes list
Size of each operand is 8-bit (one byte).

| # | opcode | mnemonic | description |
| --- | --- | --- | --- |
| 1 | 0x00 | NOP | No operation (skip step) 
| 2 | 0x01 | ADD X | Accepts one argument and sum it to ACC register |
| 3 | 0x02 | SUB X | Accepts one argument and subtract it from ACC register |
| 4 | 0x03 | MUL X | Accepts one argument and multiple it to ACC register |
| 5 | 0x04 | DIV X | Accepts one argument and divides ACC register by it |
| 6 | 0x05 | MOV ACC, X | Accepts one argument and store it in ACC register |
| 7 | 0x06 | MOV SP, X | Accepts on argument and store in in SP register |
| 8 | 0x07 | MOV DP, X | Accepts on argument and store in in DP register |
| 9 | 0x08 | MOV R1, X | Accepts on argument and store in in R1 register |
| 10 | 0x09 | MOV R2, X | Accepts on argument and store in in R2 register |
| 11 | 0x0A | MOV R3, X | Accepts on argument and store in in R3 register |
| 12 | 0x0B | MOV R4, X | Accepts on argument and store in in R4 register |
| 13 | 0x0C | MOV R5, X | Accepts on argument and store in in R5 register |
| 14 | 0x0D | MOV SP, ACC | Moves ACC content to SP register |
| 15 | 0x0E | MOV DP, ACC | Moves ACC content to DP register |
| 16 | 0x0F | MOV R1, ACC | Moves ACC content to R1 register |
| 17 | 0x10 | MOV R2, ACC | Moves ACC content to R2 register |
| 18 | 0x11 | MOV R3, ACC | Moves ACC content to R3 register |
| 19 | 0x12 | MOV R4, ACC | Moves ACC content to R4 register |
| 20 | 0x13 | MOV R5, ACC | Moves ACC content to R5 register |
| 21 | 0x14 | MOV ACC, SP | Moves SP content to ACC register |
| 22 | 0x15 | MOV ACC, DP | Moves DP content to ACC register |
| 23 | 0x16 | MOV ACC, R1 | Moves R1 content to ACC register |
| 24 | 0x17 | MOV ACC, R2 | Moves R2 content to ACC register |
| 25 | 0x18 | MOV ACC, R3 | Moves R3 content to ACC register |
| 26 | 0x19 | MOV ACC, R4 | Moves R4 content to ACC register |
| 27 | 0x1A | MOV ACC, R5 | Moves R5 content to ACC register |
| 28 | 0x1B | JMP X Y| Accepts two arguments - address, splitted into two 8-bit digits and jump on it |
| 29 | 0x1C | JE X Y | Acts like JMP, but does jump only when CF is 1 |
| 30 | 0x1D | JNE X Y | Acts like JMP, but does jump only when CF is not 1 |
| 31 | 0x1E | JO X Y | Acts like JMP, but does jump only when OF is 1 |
| 32 | 0x1F | JNO X Y | Acts like JMP, but does jump only when OF is not 1 |
| 33 | 0x20 | CMP X Y | Accepts two operands and compare it. If they an equal CMP sets CF flag to 1. If first operand greater than second, CMP set OF flag to 1 |
| 34 | 0x21 | CMP ACC Y | Acts like CMP X Y, but with ACC register |
| 35 | 0x22 | CMP R1 Y | Acts like CMP X Y, but with R1 register |
| 36 | 0x23 | CMP R2 Y | Acts like CMP X Y, but with R2 register |
| 37 | 0x24 | CMP R3 Y | Acts like CMP X Y, but with R3 register |
| 38 | 0x25 | CMP R4 Y | Acts like CMP X Y, but with R4 register |
| 39 | 0x26 | CMP R5 Y | Acts like CMP X Y, but with R5 register |
| 40 | 0x27 | CMP R1 ACC | Acts like CMP X Y, but with R1 and ACC register |
| 41 | 0x28 | CMP R2 ACC | Acts like CMP X Y, but with R2 and ACC register |
| 42 | 0x29 | CMP R3 ACC | Acts like CMP X Y, but with R3 and ACC register |
| 43 | 0x2A | CMP R4 ACC | Acts like CMP X Y, but with R4 and ACC register |
| 44 | 0x2B | CMP R5 ACC | Acts like CMP X Y, but with R5 and ACC register |
| 255 | 0xFE | PRNT X | Print one ASCII char (linux-only, for testing purposes) |
| 256 | 0xFF | HLT | Stops VM |