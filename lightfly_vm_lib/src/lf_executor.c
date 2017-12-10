#include <stdlib.h>
#include <lf_executor.h>
#include <lf_opcodes.h>

void lf_executor_init(lf_context *context,  size_t length, unsigned char const *program) {
    lf_opcodes_init();

    context->instruction_pointer = 0; // First instruction
    context->cycles = 0;
    context->halted = 0;
    context->program_length = length;
    context->program = program;
}

int lf_executor_do_step(lf_context *context) {
    if (context->instruction_pointer == context->program_length) {
        return LF_STATE_HALT;
    }
    context->cycles++;

    unsigned char instruction = lf_executor_next_instruction(context);
    int status = lf_executor_try_execute(context, instruction);
    if (status != LF_STATE_SUCCESS) {
        return status;
    }

    return LF_STATE_SUCCESS;
}

unsigned char lf_executor_next_instruction(lf_context *context) {
    unsigned char instruction = context->program[context->instruction_pointer];
    context->instruction_pointer++;
    return instruction;
}

int lf_executor_try_execute(lf_context *context, unsigned char instruction) {
    lf_opcode opcode = *(lf_opcodes+instruction);

    if (opcode.init == 0) {
        return LF_STATE_EXCEPTION;
    }

    int state = opcode.run(context);
    return state;
}