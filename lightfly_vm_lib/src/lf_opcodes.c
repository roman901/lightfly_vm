#include <lf_opcodes.h>
#include <lf_executor.h>
#include <stdio.h>

int _lf_opcode_nop(lf_context *context) { return LF_STATE_SUCCESS; }; // Nothing interesting
int _lf_opcode_add(lf_context *context) {
    context->reg_acc += lf_executor_next_instruction(context);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_sub(lf_context *context) {
    context->reg_acc -= lf_executor_next_instruction(context);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mul(lf_context *context) {
    context->reg_acc *= lf_executor_next_instruction(context);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_div(lf_context *context) {
    context->reg_acc /= lf_executor_next_instruction(context);
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
int _lf_opcode_mov_sp_acc(lf_context *context) {
    context->reg_sp = context->reg_acc;
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_dp_acc(lf_context *context) {
    context->reg_dp = context->reg_acc;
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_r1_acc(lf_context *context) {
    context->reg_r1 = context->reg_acc;
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_r2_acc(lf_context *context) {
    context->reg_r2 = context->reg_acc;
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_r3_acc(lf_context *context) {
    context->reg_r3 = context->reg_acc;
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_r4_acc(lf_context *context) {
    context->reg_r4 = context->reg_acc;
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_r5_acc(lf_context *context) {
    context->reg_r5 = context->reg_acc;
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_acc_sp(lf_context *context) {
    context->reg_acc = context->reg_sp;
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_acc_dp(lf_context *context) {
    context->reg_acc = context->reg_dp;
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_acc_r1(lf_context *context) {
    context->reg_acc = context->reg_r1;
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_acc_r2(lf_context *context) {
    context->reg_acc = context->reg_r2;
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_acc_r3(lf_context *context) {
    context->reg_acc = context->reg_r3;
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_acc_r4(lf_context *context) {
    context->reg_acc = context->reg_r4;
    return LF_STATE_SUCCESS;
}
int _lf_opcode_mov_acc_r5(lf_context *context) {
    context->reg_acc = context->reg_r5;
    return LF_STATE_SUCCESS;
}
int _lf_read_address(lf_context *context) {
    int high = lf_executor_next_instruction(context);
    int low = lf_executor_next_instruction(context);
    return high * 256 + low;
}
int _lf_opcode_jmp(lf_context *context) {
    context->instruction_pointer = _lf_read_address(context);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_je(lf_context *context) {
    if (context->flag_cf == 1)
        context->instruction_pointer = _lf_read_address(context);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_jne(lf_context *context) {
    if (context->flag_cf == 0)
        context->instruction_pointer = _lf_read_address(context);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_jo(lf_context *context) {
    if (context->flag_of == 1)
        context->instruction_pointer = _lf_read_address(context);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_jno(lf_context *context) {
    if (context->flag_of == 0)
        context->instruction_pointer = _lf_read_address(context);
    return LF_STATE_SUCCESS;
}
void _lf_compare_logic(lf_context *context, int first, int second) {
    if (first == second) {
        context->flag_cf = 1;
        return;
    } else {
        context->flag_cf = 0;
        if (first > second) {
            context->flag_of = 1;
        } else {
            context->flag_of = 0;
        }
    }
}
int _lf_opcode_cmp(lf_context *context) {
    int first = lf_executor_next_instruction(context);
    int second = lf_executor_next_instruction(context);
    _lf_compare_logic(context, first, second);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_cmp_acc(lf_context *context) {
    int first = context->reg_acc;
    int second = lf_executor_next_instruction(context);
    _lf_compare_logic(context, first, second);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_cmp_r1(lf_context *context) {
    int first = context->reg_r1;
    int second = lf_executor_next_instruction(context);
    _lf_compare_logic(context, first, second);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_cmp_r2(lf_context *context) {
    int first = context->reg_r2;
    int second = lf_executor_next_instruction(context);
    _lf_compare_logic(context, first, second);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_cmp_r3(lf_context *context) {
    int first = context->reg_r3;
    int second = lf_executor_next_instruction(context);
    _lf_compare_logic(context, first, second);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_cmp_r4(lf_context *context) {
    int first = context->reg_r4;
    int second = lf_executor_next_instruction(context);
    _lf_compare_logic(context, first, second);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_cmp_r5(lf_context *context) {
    int first = context->reg_r5;
    int second = lf_executor_next_instruction(context);
    _lf_compare_logic(context, first, second);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_cmp_r1_acc(lf_context *context) {
    int first = context->reg_r1;
    int second = context->reg_acc;
    _lf_compare_logic(context, first, second);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_cmp_r2_acc(lf_context *context) {
    int first = context->reg_r2;
    int second = context->reg_acc;
    _lf_compare_logic(context, first, second);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_cmp_r3_acc(lf_context *context) {
    int first = context->reg_r3;
    int second = context->reg_acc;
    _lf_compare_logic(context, first, second);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_cmp_r4_acc(lf_context *context) {
    int first = context->reg_r4;
    int second = context->reg_acc;
    _lf_compare_logic(context, first, second);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_cmp_r5_acc(lf_context *context) {
    int first = context->reg_r5;
    int second = context->reg_acc;
    _lf_compare_logic(context, first, second);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_prnt(lf_context *context) {
    char chr = lf_executor_next_instruction(context);
    printf("%c", chr);
    return LF_STATE_SUCCESS;
}
int _lf_opcode_hlt(lf_context *context) { return LF_STATE_HALT; };

void lf_opcodes_init() {
    REGISTER_OPCODE(0x00, _lf_opcode_nop);

    REGISTER_OPCODE(0x01, _lf_opcode_add);
    REGISTER_OPCODE(0x02, _lf_opcode_sub);
    REGISTER_OPCODE(0x03, _lf_opcode_mul);
    REGISTER_OPCODE(0x04, _lf_opcode_div);

    REGISTER_OPCODE(0x05, _lf_opcode_mov_acc);
    REGISTER_OPCODE(0x06, _lf_opcode_mov_sp);
    REGISTER_OPCODE(0x07, _lf_opcode_mov_dp);
    REGISTER_OPCODE(0x08, _lf_opcode_mov_r1);
    REGISTER_OPCODE(0x09, _lf_opcode_mov_r2);
    REGISTER_OPCODE(0x0A, _lf_opcode_mov_r3);
    REGISTER_OPCODE(0x0B, _lf_opcode_mov_r4);
    REGISTER_OPCODE(0x0C, _lf_opcode_mov_r5);

    REGISTER_OPCODE(0x0D, _lf_opcode_mov_sp_acc);
    REGISTER_OPCODE(0x0E, _lf_opcode_mov_dp_acc);
    REGISTER_OPCODE(0x0F, _lf_opcode_mov_r1_acc);
    REGISTER_OPCODE(0x10, _lf_opcode_mov_r2_acc);
    REGISTER_OPCODE(0x11, _lf_opcode_mov_r3_acc);
    REGISTER_OPCODE(0x12, _lf_opcode_mov_r4_acc);
    REGISTER_OPCODE(0x13, _lf_opcode_mov_r5_acc);

    REGISTER_OPCODE(0x14, _lf_opcode_mov_acc_sp);
    REGISTER_OPCODE(0x15, _lf_opcode_mov_acc_dp);
    REGISTER_OPCODE(0x16, _lf_opcode_mov_acc_r1);
    REGISTER_OPCODE(0x17, _lf_opcode_mov_acc_r2);
    REGISTER_OPCODE(0x18, _lf_opcode_mov_acc_r3);
    REGISTER_OPCODE(0x19, _lf_opcode_mov_acc_r4);
    REGISTER_OPCODE(0x1A, _lf_opcode_mov_acc_r5);

    REGISTER_OPCODE(0x1B, _lf_opcode_jmp);
    REGISTER_OPCODE(0x1C, _lf_opcode_je);
    REGISTER_OPCODE(0x1D, _lf_opcode_jne);
    REGISTER_OPCODE(0x1E, _lf_opcode_jo);
    REGISTER_OPCODE(0x1F, _lf_opcode_jno);

    REGISTER_OPCODE(0x20, _lf_opcode_cmp);
    REGISTER_OPCODE(0x21, _lf_opcode_cmp_acc);
    REGISTER_OPCODE(0x22, _lf_opcode_cmp_r1);
    REGISTER_OPCODE(0x23, _lf_opcode_cmp_r2);
    REGISTER_OPCODE(0x24, _lf_opcode_cmp_r3);
    REGISTER_OPCODE(0x25, _lf_opcode_cmp_r4);
    REGISTER_OPCODE(0x26, _lf_opcode_cmp_r5);
    REGISTER_OPCODE(0x27, _lf_opcode_cmp_r1_acc);
    REGISTER_OPCODE(0x28, _lf_opcode_cmp_r2_acc);
    REGISTER_OPCODE(0x29, _lf_opcode_cmp_r3_acc);
    REGISTER_OPCODE(0x2A, _lf_opcode_cmp_r4_acc);
    REGISTER_OPCODE(0x2B, _lf_opcode_cmp_r5_acc);

    REGISTER_OPCODE(0xFE, _lf_opcode_prnt);
    REGISTER_OPCODE(0xFF, _lf_opcode_hlt);
}
