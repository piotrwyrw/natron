cmake_minimum_required(VERSION 3.26)
project(bfcmp C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

add_executable(bfcmp cmp/main.c cmp/clipp.c
        cmp/trans.h
        cmp/fio.h
        cmp/fio.c
        cmp/trans.c
        cmp/util.c
)
