project(lightfly_vm_lib)

add_library(lightfly_vm_lib
        src/lib.c
        src/arch/linux.c

        src/lf_loader.c

        include/lf_loader.h include/lib.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
