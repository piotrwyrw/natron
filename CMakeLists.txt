cmake_minimum_required(VERSION 3.26)
project(bf-natron C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "lib")

option(BUILD_DEMO_PROGRAM "Compile the demo program" OFF)

# The compiler itself
add_executable(natron cmp/main.c cmp/clipp.c
        cmp/trans.h
        cmp/fio.h
        cmp/fio.c
        cmp/trans.c
        cmp/util.c
        cmp/fmt/fmt.h
        cmp/fmt/fmt.c
        cmp/color.h
        cmp/parse.h
        cmp/parse.c
        cmp/help.h
        cmp/help.c
        cmp/defs.h
)

# Reformat the brainfuck source code using the compiler's built-in functionality
add_custom_target(reformat-sample
        DEPENDS natron
        DEPENDS ${CMAKE_SOURCE_DIR}/demo/logo.bf
        DEPENDS ${CMAKE_SOURCE_DIR}/demo/logo_bootstrap.bf
        COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/natron --source ${CMAKE_SOURCE_DIR}/demo/logo_bootstrap.bf --output ${CMAKE_SOURCE_DIR}/demo/logo_bootstrap.ref.bf --reformat --acknowledge-reformatting-damage VERBATIM
        COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/natron --source ${CMAKE_SOURCE_DIR}/demo/logo.bf --output ${CMAKE_SOURCE_DIR}/demo/logo.ref.bf --reformat --acknowledge-reformatting-damage VERBATIM)

# Use the compiler to compile a sample brainfuck program
add_custom_target(compile-sample
        DEPENDS reformat-sample
        COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/natron --source ${CMAKE_SOURCE_DIR}/demo/logo_bootstrap.ref.bf --output ${CMAKE_SOURCE_DIR}/demo/logo_bootstrap.c VERBATIM
        COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/natron --source ${CMAKE_SOURCE_DIR}/demo/logo.ref.bf --output ${CMAKE_SOURCE_DIR}/demo/logo.c VERBATIM)

# Brainfuck core library
add_library(core STATIC
        core/core.h
        core/core.c)

# A demo program compiled with the compiler and linked with `libcore`
if (BUILD_DEMO_PROGRAM)
    add_executable(demo demo/logo.c demo/logo_bootstrap.c)
    add_dependencies(demo compile-sample)
    target_link_libraries(demo core)
    set_target_properties(demo PROPERTIES RUNTIME_OUTPUT_DIRECTORY "demo")
endif (BUILD_DEMO_PROGRAM)