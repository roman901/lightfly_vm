#include <lf_opcodes.h>

void lf_opcodes_init() {
    lf_opcodes = (lf_opcode*) calloc (256, sizeof(lf_opcode));

    REGISTER_OPCODE(0);
}