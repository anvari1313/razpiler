cmake_minimum_required(VERSION 3.8)
project(razpiler)

set(CMAKE_C_STANDARD 99)

find_package(FLEX REQUIRED)
set(SOURCE_FILES src/main.c src/scanner/lexer.h src/scanner/pp.c src/scanner/pp.h src/scanner/scanner.c src/scanner/scanner.h src/scanner/lex.yy.c src/scanner/type.h)

add_executable(razpiler ${SOURCE_FILES})