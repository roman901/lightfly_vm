#ifndef LIGHTFLY_VM_LF_LOADER_H
#define LIGHTFLY_VM_LF_LOADER_H

int lf_loader_check_header(const unsigned char* program_data);

int lf_loader_check_version(const unsigned char* program_data);

#endif //LIGHTFLY_VM_LF_LOADER_H