project(lightfly_vm_avr_runner)

include_directories(include)

include_directories(${lightfly_vm_lib_SOURCE_DIR}/include)
link_directories(${lightfly_vm_lib_SOURCE_DIR}/src)

add_executable(lightfly_vm_avr_runner
        src/main.c src/opcodes.c include/opcodes.h)

target_link_libraries(lightfly_vm_avr_runner lightfly_vm_lib)
