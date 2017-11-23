include_directories(${lightfly_vm_compiler_SOURCE_DIR}/inc)

include_directories(${lightfly_vm_lib_SOURCE_DIR}/inc)
link_directories(${lightfly_vm_lib_SOURCE_DIR}/src)

add_executable(lightfly_vm_compiler src/main.c)
target_link_libraries(lightfly_vm_compiler lightfly_vm_lib)