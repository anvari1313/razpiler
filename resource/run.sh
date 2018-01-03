#!/usr/bin/env bash

echo "This is compiling"
cd ../src/scanner/
rm parser.tab.h parser.tab.c lex.yy.c
flex --noyywrap ../../resource/lexer.l
bison -d ../../resource/parser.y
# gcc parser.tab.h parser.tab.c lex.yy.c -lfl
javac ../../resource/Converter.java
mv ../../resource/Converter.class ../../cmake-build-debug/