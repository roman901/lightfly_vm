#include <lf_opcodes.h>

int _lf_opcode_nop(lf_context *context) { return LF_STATE_SUCCESS; }; // Nothing interesting

int _lf_opcode_hlt(lf_context *context) { return LF_STATE_HALT; }; // Nothing interesting

void lf_opcodes_init() {
    lf_opcodes = (lf_opcode*) calloc (256, sizeof(lf_opcode));

    REGISTER_OPCODE(0x00, _lf_opcode_nop);
    REGISTER_OPCODE(0xFF, _lf_opcode_hlt);
}
