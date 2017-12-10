#ifndef LIGHTFLY_VM_LF_OPCODES_H
#define LIGHTFLY_VM_LF_OPCODES_H

#include <stdlib.h>
#define REGISTER_OPCODE(opcode) \
    (lf_opcodes+(opcode))->init = 1;

typedef struct {
    int init;
} lf_opcode;

lf_opcode *lf_opcodes;

void lf_opcodes_init();

#endif //LIGHTFLY_VM_LF_OPCODES_H
