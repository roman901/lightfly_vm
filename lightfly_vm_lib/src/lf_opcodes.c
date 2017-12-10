#include <lf_opcodes.h>
#include <lf_executor.h>

int _lf_opcode_nop(lf_context *context) { return LF_STATE_SUCCESS; }; // Nothing interesting
int _lf_opcode_add(lf_context *context) {
    unsigned char instruction = lf_executor_next_instruction(context);
    context->reg_acc += instruction;
    return LF_STATE_SUCCESS;
}
int _lf_opcode_sub(lf_context *context) {
    unsigned char instruction = lf_executor_next_instruction(context);
    context->reg_acc -= instruction;
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_acc(lf_context *context) {
    unsigned char instruction = lf_executor_next_instruction(context);
    context->reg_acc = instruction;
    return LF_STATE_SUCCESS;
}
int _lf_opcode_hlt(lf_context *context) { return LF_STATE_HALT; };

void lf_opcodes_init() {
    lf_opcodes = (lf_opcode*) calloc (256, sizeof(lf_opcode));

    REGISTER_OPCODE(0x00, _lf_opcode_nop);
    REGISTER_OPCODE(0x01, _lf_opcode_add);
    REGISTER_OPCODE(0x02, _lf_opcode_sub);
    REGISTER_OPCODE(0x03, _lf_opcode_mov_acc);
    REGISTER_OPCODE(0xFF, _lf_opcode_hlt);
}
