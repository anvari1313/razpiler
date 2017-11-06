%{
    #include "lexer.h"

    FileLine *current_line_pointer = NULL;
    long long column = 0;

    void add_node(char *value, unsigned char type)
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

LT_OP (\<)
GT_OP (\>)
EQ_OP (\=)
PLUS_OP (\+)
MINUS_OP (\-)
MULTIPLY_OP (\*)
DIVIDE_OP (\/)
QUESTIONMARK_OP (\?)


WHITESPACE [\t' '\n]
CHARACTER [A-Za-f]
DIGIT [0-9]
CHARACTER_DIGIT {CHARACTER}|{DIGIT}
IDENTIFIER {CHARACTER}{CHARACTER_DIGIT}*
NUMBER {DIGIT}+
CONST_CHAR [\'][\\]?{CHARACTER}[\']
%%
[^\n] { column++; }
[\n] {column = 0;}

{PROGRAM_KW} {add_node(yytext, TYPE_PROGRAM_KW);}
{STRUCT_KW} {add_node(yytext, TYPE_STRUCT_KW);}
{CONST_KW} {add_node(yytext, TYPE_CONST_KW);}
{INTEGER_KW} {add_node(yytext, TYPE_INTEGER_KW);}
{REAL_KW} {add_node(yytext, TYPE_REAL_KW);}
{BOOLEAN_KW} {add_node(yytext, TYPE_BOOLEAN_KW);}
{CHARACTER_KW} {add_node(yytext, TYPE_CHARACTER_KW);}
{IF_KW} {add_node(yytext, TYPE_IF_KW);}
{THEN_KW} {add_node(yytext, TYPE_THEN_KW);}
{ELSE_KW} {add_node(yytext, TYPE_ELSE_KW);}
{SWITCH_KW} {add_node(yytext, TYPE_SWITCH_KW);}
{END_KW} {add_node(yytext, TYPE_END_KW);}
{STATE_KW} {add_node(yytext, TYPE_STATE_KW);}
{DEFAULT_KW} {add_node(yytext, TYPE_DEFAULT_KW);}
{WHEN_KW} {add_node(yytext, TYPE_WHEN_KW);}
{RETURN_KW} {add_node(yytext, TYPE_RETURN_KW);}
{BREAK_KW} {add_node(yytext, TYPE_BREAK_KW);}

{IDENTIFIER} {add_node(yytext, TYPE_IDENTIFIER);}
{NUMBER} {add_node(yytext, TYPE_NUMBER);}
{CONST_CHAR} {add_node(yytext, TYPE_CONST_CHAR);}
%%

int func(char *string, FileLine *fileLine)
{
    current_line_pointer = fileLine;

    yy_scan_buffer(string, sizeof(string));
    yylex();

    return 0;
}