cmake_minimum_required(VERSION 3.26)
project(bfcmp C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "lib")

option(BUILD_DEMO_PROGRAM "Compile the demo program" OFF)

# The compiler itself
add_executable(cmp cmp/main.c cmp/clipp.c
        cmp/trans.h
        cmp/fio.h
        cmp/fio.c
        cmp/trans.c
        cmp/util.c
)

# Use the compiler to compile a sample brainfuck program
add_custom_target(compile-sample DEPENDS cmp DEPENDS ${CMAKE_SOURCE_DIR}/demo/logo.bf COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cmp --source ${CMAKE_SOURCE_DIR}/demo/logo.bf --output ${CMAKE_SOURCE_DIR}/demo/logo.c VERBATIM)

# Brainfuck core library
add_library(core STATIC
        core/core.h
        core/core.c)

# A demo program compiled with the compiler and linked with `libcore`
if (BUILD_DEMO_PROGRAM)
    add_executable(demo demo/logo.c)
    add_dependencies(demo compile-sample)
    target_link_libraries(demo core)
    set_target_properties(demo PROPERTIES RUNTIME_OUTPUT_DIRECTORY "demo")
endif (BUILD_DEMO_PROGRAM)