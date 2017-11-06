%{
    #include "lexer.h"

    FileLine *current_line_pointer = NULL;
%}
COMMENT ((\/\*)[^(\/\*)]+(\*\/))|((\/\/)[^(\n)]*)

PROGRAM_KW (CMdBcf)
STRUCT_KW (PBJEBM)
CONST_KW (FBCE)
INTEGER_KW (RIgI)
REAL_KW (BVQBMg)
BOOLEAN_KW (cdTYg)
CHARACTER_KW (IMX)
IF_KW (BaM)
THEN_KW (Adaf)
ELSE_KW (eaMdf)
SWITCH_KW (ZbgK)
END_KW (EcBc)
STATE_KW (IBbE)
DEFAULT_KW (FgQXMS)
WHEN_KW (eYEg)
RETURN_KW (CMaMKBd)
BREAK_KW (CQZd)

OR_KW (gB)
AND_KW (e)
NOT_KW (JbBX)
XOR_KW (gB eaMdf)
ANDTHEN_KW (e fcHdgd)

SEMICOLON [;]
COLON [:]
COMMA [,]

WHITESPACE [\t' '\n]
CHARACTER [A-Za-f]
DIGIT [0-9]
CHARACTER_DIGIT {CHARACTER}|{DIGIT}
IDENTIFIER {CHARACTER}{CHARACTER_DIGIT}*
NUMBER {DIGIT}+
CONST_CHAR [\'][\\]?{CHARACTER}[\']
%%

%%

int func(char *string, FileLine *fileLine)
{
    current_line_pointer = fileLine;

    yy_scan_buffer(string, sizeof(string));
    yylex();

    return 0;
}

void add_node(char *value, unsigned char type, long long column)
{
    Lexeme *node = (Lexeme *)malloc(sizeof(Lexeme));

    node->value = value;
    node->type = type;
    node->column = column;
    node->file_line = current_line_pointer;

    if (output == NULL) {
        output->next = node;
    } else {
        current_lexeme_pointer->next = node;
        current_lexeme_pointer = node;
    }
}
