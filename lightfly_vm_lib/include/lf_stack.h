#ifndef LIGHTFLY_VM_LF_STACK_H
#define LIGHTFLY_VM_LF_STACK_H

#define LF_STACK_MAX_LENGHT 16

typedef struct {
    int position;
    unsigned char stack[LF_STACK_MAX_LENGHT];
} lf_stack;

#endif //LIGHTFLY_VM_LF_STACK_H
