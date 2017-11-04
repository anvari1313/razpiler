cmake_minimum_required(VERSION 3.8)
project(razpiler)

set(CMAKE_C_STANDARD 99)

find_package(FLEX REQUIRED)
set(SOURCE_FILES src/main.c src/lexer/lexer.c src/lexer/lexer.h src/lexer/pp.c src/lexer/pp.h src/lexer/scanner.c src/lexer/scanner.h)

add_executable(razpiler ${SOURCE_FILES})