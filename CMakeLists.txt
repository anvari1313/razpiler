cmake_minimum_required(VERSION 3.8)
project(razpiler__)

set(CMAKE_CXX_STANDARD 11)


add_executable(razpiler__ src/main.c src/scanner/pp.c src/scanner/pp.h src/scanner/scanner.c src/scanner/scanner.h src/scanner/lex.yy.c src/scanner/type.h src/symtable/symtable.h src/symtable/symtable.c src/symtable/kwtable.h src/symtable/kwtable.c src/util/llstack/llstack.h src/util/llstack/llstack.c src/util/lllist/lllist.h src/util/lllist/lllist.c src/stdout/stdout.h src/stdout/stdout.c src/ircg/exp.h src/ircg/exp.c src/scanner/parser.tab.h src/scanner/parser.tab.c src/ircg/quadruple/quad.h src/ircg/quadruple/quad.c src/ircg/error/error.h src/ircg/error/error.c)