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

COMMENT ((\/\*)[^(\/\*)]+(\*\/))|((\/\/)[^(\n)]*)
%%
{PROGRAM_KW} {printf("%s Keyword found\n", yytext);}
{IDENTIFIER} {printf("\'%s\' is IDENTIFIER\n", yytext);}
{NUMBER} {printf("\'%s\' is NUMBER\n", yytext);}
{CONST_CHAR} {printf("%s is CONST CHAR\n", yytext);}
{COMMENT} {printf("%s COMMENT FOUND!\n", yytext);}
%%

typedef struct Lexeme
{
    wchar_t *value;
    unsigned char type;
    long long column;
    FileLine *file_line;
    int symbol_table_id;
    struct Lexeme *next;
}Lexeme;

int func()
{
    yylex();
    return 0;
}