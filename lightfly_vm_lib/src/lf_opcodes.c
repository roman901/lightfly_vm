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
    context->reg_acc = lf_executor_next_instruction(context);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_sp(lf_context *context) {
    context->reg_sp = lf_executor_next_instruction(context);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_dp(lf_context *context) {
    context->reg_dp = lf_executor_next_instruction(context);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_r1(lf_context *context) {
    context->reg_r1 = lf_executor_next_instruction(context);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_r2(lf_context *context) {
    context->reg_r2 = lf_executor_next_instruction(context);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_r3(lf_context *context) {
    context->reg_r3 = lf_executor_next_instruction(context);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_r4(lf_context *context) {
    context->reg_r4 = lf_executor_next_instruction(context);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_r5(lf_context *context) {
    context->reg_r5 = lf_executor_next_instruction(context);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_hlt(lf_context *context) { return LF_STATE_HALT; };

void lf_opcodes_init() {
    lf_opcodes = (lf_opcode*) calloc (256, sizeof(lf_opcode));

    REGISTER_OPCODE(0x00, _lf_opcode_nop);
    REGISTER_OPCODE(0x01, _lf_opcode_add);
    REGISTER_OPCODE(0x02, _lf_opcode_sub);
    REGISTER_OPCODE(0x03, _lf_opcode_mov_acc);
    REGISTER_OPCODE(0x04, _lf_opcode_mov_sp);
    REGISTER_OPCODE(0x05, _lf_opcode_mov_dp);
    REGISTER_OPCODE(0x06, _lf_opcode_mov_r1);
    REGISTER_OPCODE(0x07, _lf_opcode_mov_r2);
    REGISTER_OPCODE(0x08, _lf_opcode_mov_r3);
    REGISTER_OPCODE(0x09, _lf_opcode_mov_r4);
    REGISTER_OPCODE(0x0A, _lf_opcode_mov_r5);
    REGISTER_OPCODE(0xFF, _lf_opcode_hlt);
}
