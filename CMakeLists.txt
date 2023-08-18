cmake_minimum_required(VERSION 3.26)
project(bfcmp C)

set(CMAKE_C_STANDARD 11)

option(BUILD_DEMO "Build the demo program" ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "lib")

# The compiler itself
add_executable(cmp cmp/main.c cmp/clipp.c
        cmp/trans.h
        cmp/fio.h
        cmp/fio.c
        cmp/trans.c
        cmp/util.c
)

add_custom_command(TARGET cmp POST_BUILD DEPENDS ${CMAKE_SOURCE_DIR}/demo/logo.bf COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cmp ARGS --source ${CMAKE_SOURCE_DIR}/demo/logo.bf --output ${CMAKE_SOURCE_DIR}/demo/logo.c)

# Brainfuck core library
add_library(core STATIC
        core/core.h
        core/core.c)

# A demo program compiled with the compiler and linked with `libcore`
if (BUILD_DEMO)
    add_executable(demo demo/logo.c)
    target_link_libraries(demo core)
    set_target_properties(demo PROPERTIES RUNTIME_OUTPUT_DIRECTORY "bin-demo")
endif (BUILD_DEMO)