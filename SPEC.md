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

## Stack
For temporary data storage Lightfly VM has a stack for 16 8-bit values. There is a `PUSH <reg>` and `POP <reg>` opcodes exists.
If there is no storage for new values when you do `PUSH` (or stack is empty when `POP`) program will be stopped with `LF_STATE_EXCEPTION`.
## Platform-specific opcodes
Runner software can register custom opcodes for their purposes.
By example, Linux runner register 0xFE opcode `PRNT X`, which displays one ASCII char.
In future you will able to check if some opcode exists in interpreter.

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
| 45 | 0x2C | INC ACC | Increments ACC value |
| 46 | 0x2D | INC SP | Increments SP value |
| 47 | 0x2E | INC DP | Increments DP value |
| 48 | 0x2F | INC R1 | Increments R1 value |
| 49 | 0x30 | INC R2 | Increments R2 value |
| 50 | 0x31 | INC R3 | Increments R3 value |
| 51 | 0x32 | INC R4 | Increments R4 value |
| 52 | 0x33 | INC R5 | Increments R5 value |
| 53 | 0x34 | DEC ACC | Decrements ACC value |
| 54 | 0x35 | DEC SP | Decrements SP value |
| 55 | 0x36 | DEC DP | Decrements DP value |
| 56 | 0x37 | DEC R1 | Decrements R1 value |
| 57 | 0x38 | DEC R2 | Decrements R2 value |
| 58 | 0x39 | DEC R3 | Decrements R3 value |
| 59 | 0x3A | DEC R4 | Decrements R4 value |
| 60 | 0x3B | DEC R5 | Decrements R5 value |
| 61 | 0x3C | OPEX X | Check if given opcode exists and set CF to 1 if yes, otherwise 0 |
| 62 | 0x3D | OPREG X | Registers new `virtual` opcode. See [Virtual opcodes specification](VIRTUAL.md) |
| 63 | 0x3E | PUSH ACC | Push ACC register to stack |
| 64 | 0x3F | PUSH SP | Push SP register to stack |
| 65 | 0x40 | PUSH DP | Push DP register to stack |
| 66 | 0x41 | PUSH R1 | Push R1 register to stack |
| 67 | 0x42 | PUSH R2 | Push R2 register to stack |
| 68 | 0x43 | PUSH R3 | Push R3 register to stack |
| 69 | 0x44 | PUSH R4 | Push R4 register to stack |
| 70 | 0x45 | PUSH R5 | Push R5 register to stack |
| 71 | 0x46 | POP ACC | Pop ACC register from stack |
| 72 | 0x47 | POP SP | Pop SP register from stack |
| 73 | 0x48 | POP DP | Pop DP register from stack |
| 74 | 0x49 | POP R1 | Pop R1 register from stack |
| 75 | 0x4A | POP R2 | Pop R2 register from stack |
| 76 | 0x4B | POP R3 | Pop R3 register from stack |
| 77 | 0x4C | POP R4 | Pop R4 register from stack |
| 78 | 0x4D | POP R5 | Pop R5 register from stack |
| 256 | 0xFF | HLT | Stops VM |