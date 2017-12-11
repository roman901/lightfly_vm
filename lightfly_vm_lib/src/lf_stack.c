#include "lf_stack.h"
#include "lf_executor.h"

int lf_stack_push(lf_context *context, unsigned char value) {
    if ((context->stack->position) == LF_STACK_MAX_LENGHT)
        return LF_STATE_EXCEPTION;

    context->stack->stack[context->stack->position] = value;
    context->stack->position++;
    return LF_STATE_SUCCESS;
}

int lf_stack_pop(lf_context *context, unsigned char *reg) {
    if ((context->stack->position) == 0)
        return LF_STATE_EXCEPTION;

    *reg = context->stack->stack[context->stack->position];
    context->stack->position--;
    return LF_STATE_SUCCESS;
}