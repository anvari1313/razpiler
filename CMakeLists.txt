cmake_minimum_required(VERSION 3.4)
project(razpiler)

set(CMAKE_C_STANDARD 99)

##############################################################################################
## Create target for the parser
#ADD_CUSTOM_TARGET(razpiler echo "Creating parser.c")
#
## Create custom command for flex/lex (note the outputs)
#ADD_CUSTOM_COMMAND(
#        SOURCE ${razpiler_SOURCE_DIR}/resource/lexer.l
#        COMMAND ${FLEX_EXECUTABLE}
#        ARGS -o src/lexer.c
#        ${razpiler_SOURCE_DIR}/resource/lexer.l
#        TARGET razpiler
#        OUTPUTS src/lexer.c)
#
## Create custom command for bison/yacc (note the DEPENDS)
#ADD_CUSTOM_COMMAND(
#        SOURCE ${razpiler_SOURCE_DIR}/resource/parser.y
#        COMMAND ${BISON_EXECUTABLE}
#        ARGS -y ${razpiler_SOURCE_DIR}/resource/parser.y
#        -o ${razpiler_BINARY_DIR}/src/parser.c
#        TARGET razpiler
#        DEPENDS ${razpiler_BINARY_DIR}/src/lexer.c
#        OUTPUTS ${razpiler_BINARY_DIR}/src/parser.c)
#
## Add parser.c to the list of sources
#SET(razpiler_SRCS ${razpiler_SRCS} ${razpiler_BINARY_DIR}/src/parser.c)
#
## Since parser.c does not exists yet when cmake is run, mark
## it as generated
#SET_SOURCE_FILES_PROPERTIES(${razpiler_BINARY_DIR}/src/parser.c GENERATED)
#
## Include binary directory to include lexer.c in parser.c
#INCLUDE_DIRECTORIES(${razpiler_BINARY_DIR}/src)
##############################################################################################

find_package(FLEX REQUIRED)
FLEX_TARGET(razpiler resource/lexer.l src/scanner/lex2.yy.c)
set(SOURCE_FILES src/main.c src/scanner/lexer.h src/scanner/pp.c src/scanner/pp.h src/scanner/scanner.c src/scanner/scanner.h src/scanner/lex.yy.c src/scanner/type.h src/symtable/symtable.h src/symtable/symtable.c src/symtable/kwtable.h src/symtable/kwtable.c src/util/llstack/llstack.h src/util/llstack/llstack.c)

add_executable(razpiler ${SOURCE_FILES})