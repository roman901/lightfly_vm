#ifndef LIGHTFLY_VM_LF_OPCODES_H
#define LIGHTFLY_VM_LF_OPCODES_H

#include <stdlib.h>
#include <lf_executor.h>

#define REGISTER_OPCODE(opcode, function) \
    (lf_opcodes+(opcode))->init = 1; \
    (lf_opcodes+(opcode))->run = (function);

typedef struct {
    int init;
    int (*run)(lf_context *);
} lf_opcode;

lf_opcode *lf_opcodes;

void lf_opcodes_init();

#endif //LIGHTFLY_VM_LF_OPCODES_H
