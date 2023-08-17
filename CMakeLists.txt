cmake_minimum_required(VERSION 3.26)
project(bfcmp C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

add_executable(bfcmp src/main.c src/clipp.c
        src/trans.h
        src/fio.h
        src/fio.c
        src/trans.c
        src/util.c)
