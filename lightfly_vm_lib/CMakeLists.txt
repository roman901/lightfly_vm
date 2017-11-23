add_library(lightfly_vm_lib
        src/lib.c src/lf_loader.c)
target_include_directories(lightfly_vm_lib
        PUBLIC
        $<BUILD_INTERFACE:${lightfly_vm_lib_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        src)
