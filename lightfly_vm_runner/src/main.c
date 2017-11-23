#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    FILE *file;

    if (argc != 2) {
        printf("Incorrect interpreter usage. Correct: lightfly_vm_runner <filename.lf>");
        return EXIT_FAILURE;
    }

    // Stage 1: try to load file
    file = fopen(argv[1], "r");

    if (!file) {
        printf("Cannot open file %s", argv[1]);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}