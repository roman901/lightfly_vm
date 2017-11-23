cmake_minimum_required(VERSION 3.8)
project(lightfly_vm)

set(CMAKE_C_STANDARD 11)

subdirs(lightfly_vm_lib lightfly_vm_runner lightfly_vm_compiler)