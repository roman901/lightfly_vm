#include <lf_loader.h>

int lf_loader_check_header(unsigned char* program_data) {
    if (program_data[0] != 0x55) return 0;
    if (program_data[1] != 0x57) return 0;
    return 1;
}