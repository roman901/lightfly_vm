project(lightfly_vm_lib)

set(SOURCE_LIB
        src/lib.c
        src/lf_loader.c
        src/lf_executor.c

        include/lf_loader.h
        include/lib.h
        include/lf_executor.h include/lf_opcodes.h src/lf_stack.c include/lf_stack.h)

# TODO(spark): get target platform and include needed HAL file
set(SOURCE_LIB ${SOURCE_LIB} src/arch/linux.c src/lf_opcodes.c) # Add linux HAL by default

add_library(lightfly_vm_lib ${SOURCE_LIB})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
