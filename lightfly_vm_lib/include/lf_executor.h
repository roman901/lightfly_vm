#ifndef LIGHTFLY_VM_LF_EXECUTOR_H
#define LIGHTFLY_VM_LF_EXECUTOR_H

#include <stdlib.h>
#include "lf_stack.h"

#define LF_STATE_SUCCESS 0
#define LF_STATE_EXCEPTION 1
#define LF_STATE_HALT 255

typedef struct {
    int instruction_pointer;
    long cycles;
    size_t program_length;
    unsigned char const *program;

    // Registers
    unsigned char reg_acc;
    unsigned char reg_sp;
    unsigned char reg_dp;
    unsigned char reg_r1;
    unsigned char reg_r2;
    unsigned char reg_r3;
    unsigned char reg_r4;
    unsigned char reg_r5;

    unsigned char flag_cf;
    unsigned char flag_of;

    lf_stack *stack;

} lf_context;

void lf_executor_init(lf_context *context, size_t length, unsigned char const *program);
int lf_executor_do_step(lf_context *context);
unsigned char lf_executor_next_instruction(lf_context *context);
int lf_executor_try_execute(lf_context *context, unsigned char instruction);
#endif //LIGHTFLY_VM_LF_EXECUTOR_H
