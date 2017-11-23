project(lightfly_vm_runner)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

include_directories(${lightfly_vm_lib_SOURCE_DIR}/include)
link_directories(${lightfly_vm_lib_SOURCE_DIR}/src)

add_executable(lightfly_vm_runner
        src/main.c)

target_link_libraries(lightfly_vm_runner lightfly_vm_lib)
