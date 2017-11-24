#include <lf_loader.h>
#include <lib.h>

int lf_loader_check_header(unsigned char* program_data) {
    if (program_data[0] != 0x55) return 0;
    if (program_data[1] != 0x57) return 0;
    return 1;
}

int lf_loader_check_version(unsigned char* program_data) {
    if (program_data[2] != LF_VERSION) return 0;
    return 1;
}