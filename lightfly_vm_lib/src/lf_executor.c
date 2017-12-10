#include <stdlib.h>
#include <lf_executor.h>

void lf_executor_init(lf_context *context,  size_t length, unsigned char const *program) {
    context->instruction_pointer = 0; // First instruction
    context->cycles = 0;
    context->program_length = length;
    context->program = program;
}

int lf_executor_do_step(lf_context *context) {
    if (context->instruction_pointer == context->program_length) {
        return LF_STEP_HALT;
    }
    context->instruction_pointer++;
    context->cycles++;
    return LF_STEP_SUCCESS;
}