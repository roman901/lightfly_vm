#ifndef LIGHTFLY_VM_LF_OPCODES_H
#define LIGHTFLY_VM_LF_OPCODES_H

#include <stdlib.h>
#include "lf_executor.h"

int (*lf_opcodes[256])(lf_context *context);

// TODO(spark): Rewrite to switch-case
#define REGISTER_OPCODE(opcode, function) \
    lf_opcodes[opcode] = &(function);

void lf_opcodes_init();

#endif //LIGHTFLY_VM_LF_OPCODES_H
