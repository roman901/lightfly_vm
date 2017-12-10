project(lightfly_vm_lib)

set(SOURCE_LIB
        src/lib.c
        src/lf_loader.c

        include/lf_loader.h include/lib.h)

# TODO(spark): get target platform and include needed HAL file
set(SOURCE_LIB ${SOURCE_LIB} src/arch/linux.c) # Add linux HAL by default

add_library(lightfly_vm_lib ${SOURCE_LIB})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
