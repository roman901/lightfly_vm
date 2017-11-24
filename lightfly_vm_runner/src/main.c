#include <stdio.h>
#include <stdlib.h>
#include <lf_loader.h>

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

    fseek (file, 0, SEEK_END);

    // Stage 2: check file length
    size_t length = (size_t) ftell (file);
    if (length > 65538) { // 2 for signature, 1 for version, 65535 for code
        printf("Error: program length can't be greater than 65538 bytes (includes header)");
    }

    // Stage 3: load program to memory
    fseek (file, 0, SEEK_SET);
    unsigned char *program = malloc (length);
    if (program) {
        fread (program, 1, length, file);
    }
    fclose(file);

    // Stage 4: check header signature and bytecode version
    if (!lf_loader_check_header(program)) {
        printf("Error: incorrect header (must be 0x55 0x57)");
    }

    if (!lf_loader_check_version(program)) {
        printf("Error: incorrect version of bytecode");
    }

    return EXIT_SUCCESS;
}