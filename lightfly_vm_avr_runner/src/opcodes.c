#include <stdio.h>
#include <lf_opcodes.h>
#include <lf_executor.h>

int _lf_opcode_prnt(lf_context *context) {
    printf("%c", lf_executor_next_instruction(context));
    return LF_STATE_SUCCESS;
}

void lf_runner_opcodes_init() {
    REGISTER_OPCODE(0xFE, _lf_opcode_prnt);
}