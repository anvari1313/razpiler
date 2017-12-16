%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "parser.tab.h"
#define TYPE_PROGRAM_KW 1
#define TYPE_STRUCT_KW 2
#define TYPE_CONST_KW 3
#define TYPE_INTEGER_KW 4
#define TYPE_REAL_KW 5
#define TYPE_BOOLEAN_KW 6
#define TYPE_CHARACTER_KW 7
#define TYPE_IF_KW 8
#define TYPE_THEN_KW 9
#define TYPE_ELSE_KW 10
#define TYPE_SWITCH_KW 11
#define TYPE_END_KW 12
#define TYPE_STATE_KW 13
#define TYPE_DEFAULT_KW 14
#define TYPE_WHEN_KW 15
#define TYPE_RETURN_KW 16
#define TYPE_BREAK_KW 17

#define TYPE_OR_KW 30
#define TYPE_AND_KW 31
#define TYPE_NOT_KW 32
#define TYPE_XOR_KW 33
#define TYPE_ANDTHEN_KW 34

#define TYPE_SEMICOLON 40
#define TYPE_COLON 41
#define TYPE_COMMA 42
#define TYPE_OPEN_BRACKET 43
#define TYPE_CLOSE_BRACKET 44
#define TYPE_OPEN_CURLY_BRACES 45
#define TYPE_CLOSE_CURLY_BRACES 46

#define TYPE_OPEN_PARENTHESIS 47
#define TYPE_CLOSE_PARENTHESIS 48
#define TYPE_DOT 49


#define TYPE_LT_OP 50
#define TYPE_GT_OP 51
#define TYPE_EQ_OP 52
#define TYPE_PLUS_OP 53
#define TYPE_MINUS_OP 54
#define TYPE_MULTIPLY_OP 55
#define TYPE_DIVIDE_OP 56
#define TYPE_QUESTIONMARK_OP 57
#define TYPE_PERCENT_OP 58
#define TYPE_PLUS_PLUS_OP 59
#define TYPE_MINUS_MINUS_OP 60

#define TYPE_IDENTIFIER 70
#define TYPE_NUMBER 71
#define TYPE_CONST_CHAR 72
#define TYPE_REAL_NUMBER 73

#define TYPE_BOOLEAN_FALSE 80
#define TYPE_BOOLEAN_TRUE 81

    char *type_to_string(int type)
    {
        char *result = malloc(sizeof(char) * 20);
        switch(type)
        {
            case 1:
                result = "PROGRAM_KW";
                break;
            case 2:
                result = "STRUCT_KW";
                break;
            case 3:
                result = "CONST_KW";
                break;
            case 4:
                result = "INTEGER_KW";
                break;
            case 5:
                result = "REAL_KW";
                break;
            case 6:
                result = "BOOLEAN_KW";
                break;
            case 7:
                result = "CHARACTER_KW";
                break;
            case 8:
                result = "IF_KW";
                break;
            case 9:
                result = "THEN_KW";
                break;
            case 10:
                result = "ELSE_KW";
                break;
            case 11:
                result = "SWITCH_KW";
                break;
            case 12:
                result = "END_KW";
                break;
            case 13:
                result = "STATE_KW";
                break;
            case 14:
                result = "DEFAULT_KW";
                break;
            case 15:
                result = "WHEN_KW";
                break;
            case 16:
                result = "RETURN_KW";
                break;
            case 17:
                result = "BREAK_KW";
                break;
            case 30:
                result = "OR_KW";
                break;
            case 31:
                result = "AND_KW";
                break;
            case 32:
                result = "NOT_KW";
                break;
            case 33:
                result = "XOR_KW";
                break;
            case 34:
                result = "ANDTHEN_KW";
                break;
            case 40:
                result = "SEMICOLON";
                break;
            case 41:
                result = "COLON";
                break;
            case 42:
                result = "COMMA";
                break;
            case 43:
                result = "OPEN_BRACKET";
                break;
            case 44:
                result = "CLOSE_BRACKET";
                break;
            case 45:
                result = "OPEN_CURLY_BRACES";
                break;
            case 46:
                result = "CLOSE_CURLY_BRACES";
                break;
            case 47:
                result = "OPEN_PARENTHESIS";
                break;
            case 48:
                result = "CLOSE_PARENTHESIS";
                break;
            case 49:
                result = "DOT";
                break;
            case 50:
                result = "LT_OP";
                break;
            case 51:
                result = "GT_OP";
                break;
            case 52:
                result = "EQ_OP";
                break;
            case 53:
                result = "PLUS_OP";
                break;
            case 54:
                result = "MINUS_OP";
                break;
            case 55:
                result = "MULTIPLY_OP";
                break;
            case 56:
                result = "DIVIDE_OP";
                break;
            case 57:
                result = "QUESTIONMARK_OP";
                break;
            case 58:
                result = "PERCENT_OP";
                break;
            case 59:
                result = "PLUS_PLUS_OP";
                break;
            case 60:
                result = "MINUS_MINUS_OP";
                break;

            case 70:
                result = "IDENTIFIER";
                break;
            case 71:
                result = "NUMBER";
                break;
            case 72:
                result = "CONST_CHAR";
                break;
            case 73:
                result = "REAL_NUMBER";
                break;
            case 80:
                result = "BOOLEAN_FALSE";
                break;
            case 81:
                result = "BOOLEAN_TRUE";
                break;
            default:
                result = "**UNKNOWN**";

        }

        return result;
    }

    long long column = 0;

    void add_node(char *value, unsigned char type)
    {
        // wprintf(L"%s\t%s\n", value, type_to_string(type));
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
XOR_KW (gBeaMdf)
ANDTHEN_KW (efcHdgd)

SEMICOLON [;]
COLON [:]
COMMA [,]
OPEN_BRACKET (\[)
CLOSE_BRACKET (\])
OPEN_CURLY_BRACES (\{)
CLOSE_CURLY_BRACES (\})
OPEN_PARENTHESIS (\()
CLOSE_PARENTHESIS (\))
DOT (\.)

LT_OP (\<)
GT_OP (\>)
EQ_OP (\=)
PLUS_OP (\+)
MULTIPLY_OP (\*)
DIVIDE_OP (\/)
MINUS_OP (\-)
QUESTIONMARK_OP (\?)
PERCENT_OP (\%)
PLUS_PLUS_OP "++"
MINUS_MINUS_OP "--"

BOOLEAN_FALSE (WbT)
BOOLEAN_TRUE (KMPE)


WHITESPACE [\t' '\n]
CHARACTER [A-Za-g]
DIGIT [0-9]
CHARACTER_DIGIT {CHARACTER}|{DIGIT}
IDENTIFIER {CHARACTER}{CHARACTER_DIGIT}*
NUMBER {DIGIT}+
REAL_NUMBER {DIGIT}+(.){DIGIT}+
CONST_CHAR [\'][\\]?{CHARACTER}[\']
%%

{OR_KW} {add_node(yytext, TYPE_OR_KW); return OR_KW;}
{AND_KW} {add_node(yytext, TYPE_AND_KW); return AND_KW;}
{NOT_KW} {add_node(yytext, TYPE_NOT_KW); return NOT_KW;}
{XOR_KW} {add_node(yytext, TYPE_XOR_KW); return XOR_KW;}
{ANDTHEN_KW} {add_node(yytext, TYPE_ANDTHEN_KW); return ANDTHEN_KW;}

{SEMICOLON} {add_node(yytext, TYPE_SEMICOLON); return SEMICOLON;}
{COLON} {add_node(yytext, TYPE_COLON); return COLON;}
{COMMA} {add_node(yytext, TYPE_COMMA); return COMMA;}
{OPEN_BRACKET} {add_node(yytext, TYPE_OPEN_BRACKET); return OPEN_BRACKET;}
{CLOSE_BRACKET} {add_node(yytext, TYPE_CLOSE_BRACKET); return CLOSE_BRACKET;}
{OPEN_CURLY_BRACES} {add_node(yytext, TYPE_OPEN_CURLY_BRACES); return OPEN_CURLY_BRACES;}
{CLOSE_CURLY_BRACES} {add_node(yytext, TYPE_CLOSE_CURLY_BRACES); return CLOSE_CURLY_BRACES;}
{OPEN_PARENTHESIS} {add_node(yytext, TYPE_OPEN_PARENTHESIS); return OPEN_PARENTHESIS;}
{CLOSE_PARENTHESIS} {add_node(yytext, TYPE_CLOSE_PARENTHESIS); return CLOSE_PARENTHESIS;}
{DOT} {add_node(yytext, TYPE_DOT); return DOT;}

{LT_OP} {add_node(yytext, TYPE_LT_OP); return LT_OP;}
{GT_OP} {add_node(yytext, TYPE_GT_OP); return GT_OP;}
{EQ_OP} {add_node(yytext, TYPE_EQ_OP); return EQ_OP;}
{PLUS_PLUS_OP} {add_node(yytext, TYPE_PLUS_PLUS_OP); return PLUS_PLUS_OP;}
{MINUS_MINUS_OP} {add_node(yytext, TYPE_MINUS_MINUS_OP); return MINUS_MINUS_OP;}
{PLUS_OP} {add_node(yytext, TYPE_PLUS_OP); return PLUS_OP;}
{MINUS_OP}  {add_node(yytext, TYPE_MINUS_OP); return MINUS_OP;}
{MULTIPLY_OP} {add_node(yytext, TYPE_MULTIPLY_OP); return MULTIPLY_OP;}
{DIVIDE_OP} {add_node(yytext, TYPE_DIVIDE_OP); return DIVIDE_OP;}
{QUESTIONMARK_OP} {add_node(yytext, TYPE_QUESTIONMARK_OP); return QUESTIONMARK_OP;}
{PERCENT_OP} {add_node(yytext, TYPE_PERCENT_OP); return PERCENT_OP;}

{BOOLEAN_FALSE} {add_node(yytext, TYPE_BOOLEAN_FALSE); return BOOLEAN_FALSE;}
{BOOLEAN_TRUE} {add_node(yytext, TYPE_BOOLEAN_TRUE); return BOOLEAN_TRUE;}

{PROGRAM_KW} {add_node(yytext, TYPE_PROGRAM_KW); return PROGRAM_KW;}
{STRUCT_KW} {add_node(yytext, TYPE_STRUCT_KW); return STRUCT_KW;}
{CONST_KW} {add_node(yytext, TYPE_CONST_KW); return CONST_KW;}
{INTEGER_KW} {add_node(yytext, TYPE_INTEGER_KW); return INTEGER_KW;}
{REAL_KW} {add_node(yytext, TYPE_REAL_KW); return REAL_KW;}
{BOOLEAN_KW} {add_node(yytext, TYPE_BOOLEAN_KW); return BOOLEAN_KW;}
{CHARACTER_KW} {add_node(yytext, TYPE_CHARACTER_KW); return CHARACTER_KW;}
{IF_KW} {add_node(yytext, TYPE_IF_KW); return IF_KW;}
{THEN_KW} {add_node(yytext, TYPE_THEN_KW); return THEN_KW;}
{ELSE_KW} {add_node(yytext, TYPE_ELSE_KW); return ELSE_KW;}
{SWITCH_KW} {add_node(yytext, TYPE_SWITCH_KW); return SWITCH_KW;}
{END_KW} {add_node(yytext, TYPE_END_KW); return END_KW;}
{STATE_KW} {add_node(yytext, TYPE_STATE_KW); return STATE_KW;}
{DEFAULT_KW} {add_node(yytext, TYPE_DEFAULT_KW); return DEFAULT_KW;}
{WHEN_KW} {add_node(yytext, TYPE_WHEN_KW); return WHEN_KW;}
{RETURN_KW} {add_node(yytext, TYPE_RETURN_KW); return RETURN_KW;}
{BREAK_KW} {add_node(yytext, TYPE_BREAK_KW); return BREAK_KW;}


{WHITESPACE} { column += yyleng; }
{IDENTIFIER} {
    yylval.eval.text = (char *)malloc((strlen(yytext) + 2) * sizeof(char));
    strcpy(yylval.eval.text, yytext);
    return IDENTIFIER;
    }
{NUMBER} {add_node(yytext, TYPE_NUMBER); return NUMBER;}
{REAL_NUMBER} {add_node(yytext, TYPE_REAL_NUMBER); return REAL_NUMBER;}
{CONST_CHAR} {add_node(yytext, TYPE_CONST_CHAR); return CONST_CHAR; }
%%

int start_lex()
{
    // printf("hey");
    yylex();

    return 0;
}