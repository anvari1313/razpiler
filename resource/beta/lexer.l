%{
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

#define TYPE_IDENTIFIER 70
#define TYPE_NUMBER 71
#define TYPE_CONST_CHAR 72
#define TYPE_REAL_NUMBER 73

#define TYPE_BOOLEAN_FALSE 80
#define TYPE_BOOLEAN_TRUE 81


    long long column = 0;

    void post_process(char *input)
    {
        int i = 0;
        char *output = malloc(sizeof(char) * 20);
        while(input[i])
        {
            switch(input[i])
            {
                case 'A':
                    output[i] = '';
                    break;
            }
            i++;

        }
    }
    void add_node(char *value, unsigned char type)
    {
        wprintf(L"%s\t%d\n", value, type);
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
OPEN_BRACKET (\])
CLOSE_BRACKET (\[)
OPEN_CURLY_BRACES (\})
CLOSE_CURLY_BRACES (\{)
OPEN_PARENTHESIS (\))
CLOSE_PARENTHESIS (\()
DOT (\.)

LT_OP (\<)
GT_OP (\>)
EQ_OP (\=)
PLUS_OP (\+)
MULTIPLY_OP (\*)
DIVIDE_OP (\/)
MINUS_OP (\-)
QUESTIONMARK_OP (\?)

BOOLEAN_FALSE (WbT)
BOOLEAN_TRUE (KMPE)


WHITESPACE [\t' '\n]
CHARACTER [A-Za-f]
DIGIT [0-9]
CHARACTER_DIGIT {CHARACTER}|{DIGIT}
IDENTIFIER {CHARACTER}{CHARACTER_DIGIT}*
NUMBER {DIGIT}+
REAL_NUMBER {DIGIT}+(.){DIGIT}+
CONST_CHAR [\'][\\]?{CHARACTER}[\']
%%

{OR_KW} {add_node(yytext, TYPE_OR_KW); return TYPE_OR_KW;}
{AND_KW} {add_node(yytext, TYPE_AND_KW); return TYPE_AND_KW;}
{NOT_KW} {add_node(yytext, TYPE_NOT_KW); return TYPE_NOT_KW;}
{XOR_KW} {add_node(yytext, TYPE_XOR_KW); return TYPE_XOR_KW;}
{ANDTHEN_KW} {add_node(yytext, TYPE_ANDTHEN_KW); return TYPE_ANDTHEN_KW;}

{SEMICOLON} {add_node(yytext, TYPE_SEMICOLON); return TYPE_SEMICOLON;}
{COLON} {add_node(yytext, TYPE_COLON); return TYPE_COLON;}
{COMMA} {add_node(yytext, TYPE_COMMA); return TYPE_COMMA;}
{OPEN_BRACKET} {add_node(yytext, TYPE_OPEN_BRACKET); return TYPE_OPEN_BRACKET;}
{CLOSE_BRACKET} {add_node(yytext, TYPE_CLOSE_BRACKET); return TYPE_CLOSE_BRACKET;}
{OPEN_CURLY_BRACES} {add_node(yytext, TYPE_OPEN_CURLY_BRACES); return TYPE_OPEN_CURLY_BRACES;}
{CLOSE_CURLY_BRACES} {add_node(yytext, TYPE_CLOSE_CURLY_BRACES); return TYPE_CLOSE_CURLY_BRACES;}
{OPEN_PARENTHESIS} {add_node(yytext, TYPE_OPEN_PARENTHESIS); return TYPE_OPEN_PARENTHESIS;}
{CLOSE_PARENTHESIS} {add_node(yytext, TYPE_CLOSE_PARENTHESIS); return TYPE_CLOSE_PARENTHESIS;}
{DOT} {add_node(yytext, TYPE_DOT); return TYPE_DOT;}

{LT_OP} {add_node(yytext, TYPE_LT_OP); return TYPE_LT_OP;}
{GT_OP} {add_node(yytext, TYPE_GT_OP); return TYPE_GT_OP;}
{EQ_OP} {add_node(yytext, TYPE_EQ_OP); return TYPE_EQ_OP;}
{PLUS_OP} {add_node(yytext, TYPE_PLUS_OP); return TYPE_PLUS_OP;}
{MINUS_OP}  {add_node(yytext, TYPE_MINUS_OP); return TYPE_MINUS_OP;}
{MULTIPLY_OP} {add_node(yytext, TYPE_MULTIPLY_OP); return TYPE_MULTIPLY_OP;}
{DIVIDE_OP} {add_node(yytext, TYPE_DIVIDE_OP); return TYPE_DIVIDE_OP;}
{QUESTIONMARK_OP} {add_node(yytext, TYPE_QUESTIONMARK_OP); return TYPE_QUESTIONMARK_OP;}

{BOOLEAN_FALSE} {add_node(yytext, TYPE_BOOLEAN_FALSE); return TYPE_BOOLEAN_FALSE;}
{BOOLEAN_TRUE} {add_node(yytext, TYPE_BOOLEAN_TRUE); return TYPE_BOOLEAN_TRUE;}

{PROGRAM_KW} {add_node(yytext, TYPE_PROGRAM_KW); return TYPE_PROGRAM_KW;}
{STRUCT_KW} {add_node(yytext, TYPE_STRUCT_KW); return TYPE_STRUCT_KW;}
{CONST_KW} {add_node(yytext, TYPE_CONST_KW); return TYPE_CONST_KW;}
{INTEGER_KW} {add_node(yytext, TYPE_INTEGER_KW); return TYPE_INTEGER_KW;}
{REAL_KW} {add_node(yytext, TYPE_REAL_KW); return TYPE_REAL_KW;}
{BOOLEAN_KW} {add_node(yytext, TYPE_BOOLEAN_KW); return TYPE_BOOLEAN_KW;}
{CHARACTER_KW} {add_node(yytext, TYPE_CHARACTER_KW); return TYPE_CHARACTER_KW;}
{IF_KW} {add_node(yytext, TYPE_IF_KW); return TYPE_IF_KW;}
{THEN_KW} {add_node(yytext, TYPE_THEN_KW); return TYPE_THEN_KW;}
{ELSE_KW} {add_node(yytext, TYPE_ELSE_KW); return TYPE_ELSE_KW;}
{SWITCH_KW} {add_node(yytext, TYPE_SWITCH_KW); return TYPE_SWITCH_KW;}
{END_KW} {add_node(yytext, TYPE_END_KW); return TYPE_END_KW;}
{STATE_KW} {add_node(yytext, TYPE_STATE_KW); return TYPE_STATE_KW;}
{DEFAULT_KW} {add_node(yytext, TYPE_DEFAULT_KW); return TYPE_DEFAULT_KW;}
{WHEN_KW} {add_node(yytext, TYPE_WHEN_KW); return TYPE_WHEN_KW;}
{RETURN_KW} {add_node(yytext, TYPE_RETURN_KW); return TYPE_RETURN_KW;}
{BREAK_KW} {add_node(yytext, TYPE_BREAK_KW); return TYPE_BREAK_KW;}


{WHITESPACE} { column += yyleng; }
{IDENTIFIER} {add_node(yytext, TYPE_IDENTIFIER); return TYPE_IDENTIFIER;}
{NUMBER} {add_node(yytext, TYPE_NUMBER); return TYPE_NUMBER;}
{REAL_NUMBER} {add_node(yytext, TYPE_REAL_NUMBER); return TYPE_REAL_NUMBER;}
{CONST_CHAR} {add_node(yytext, TYPE_CONST_CHAR); return TYPE_CONST_CHAR; }
%%

int start_lex()
{
    printf("hey");
    yylex();

    return 0;
}