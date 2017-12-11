cmake_minimum_required(VERSION 3.8)
project(lightfly_vm)

set(CMAKE_C_STANDARD 11)

add_subdirectory(lightfly_vm_lib)
add_subdirectory(lightfly_vm_compiler)
add_subdirectory(lightfly_vm_runner)
add_subdirectory(lightfly_vm_avr_runner)
