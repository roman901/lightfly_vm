#include <stdio.h>
#include <stdlib.h>

#include <lf_loader.h>
#include <lf_executor.h>
#include <string.h>

#define HEADER_LENGHT 3

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Incorrect interpreter usage. Correct: lightfly_vm_runner <filename.lf>");
        return EXIT_FAILURE;
    }

    // Stage 1: try to open file
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error: can't open file %s", argv[1]);
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);

    // Stage 2: check file length
    size_t length = (size_t) ftell(file);
    if (length > 65538) { // 2 for signature, 1 for version, 65535 for code
        printf("Error: program length can't be greater than 65538 bytes (includes header)");
    }

    // Stage 3: load program to memory
    fseek (file, 0, SEEK_SET);
    unsigned char *raw_program = malloc(length);
    if (raw_program) {
        fread(raw_program, 1, length, file);
    }
    fclose(file);

    // Stage 4: check header signature and bytecode version
    if (!lf_loader_check_header(raw_program)) {
        printf("Error: incorrect header (must be 0x55 0x57)");
    }

    if (!lf_loader_check_version(raw_program)) {
        printf("Error: incorrect version of bytecode");
    }

    // Stage 5: init VM
    // Context struct, describes current state of execution
    lf_context *context = malloc(sizeof(lf_context));

    unsigned char const *program = malloc(length - HEADER_LENGHT);
    memcpy(raw_program + HEADER_LENGHT, program, length - HEADER_LENGHT); // Copy program code without header

    // TODO(spark): dynamic calculation of header size

    lf_executor_init(context, length - HEADER_LENGHT, program);

    // Stage 6: start executing program
    int status = LF_STEP_SUCCESS;
    while (status == LF_STEP_SUCCESS) {
        status = lf_executor_do_step(context);
    }

    if (status == LF_STEP_EXCEPTION) {
        printf("Program has ended with exception");
        return EXIT_FAILURE;
    } else if (status == LF_STEP_HALT) {
        printf("Program has halted");
    } else {
        printf("Program has reached end");
    }

    return EXIT_SUCCESS;
}