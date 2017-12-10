#ifndef LIGHTFLY_VM_LF_EXECUTOR_H
#define LIGHTFLY_VM_LF_EXECUTOR_H

#define LF_STEP_SUCCESS 0
#define LF_STEP_EXCEPTION 1
#define LF_STEP_HALT 2

typedef struct {
    int instruction_pointer;
    long cycles;
    size_t program_length;
    unsigned char const *program;
} lf_context;

void lf_executor_init(lf_context *context, size_t length, unsigned char const *program);
int lf_executor_do_step(lf_context *context);

#endif //LIGHTFLY_VM_LF_EXECUTOR_H
