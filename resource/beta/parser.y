%{
    extern char* yytext;
    void yyerror(const char *s);
%}

%token PROGRAM_KW STRUCT_KW CONST_KW INTEGER_KW REAL_KW BOOLEAN_KW CHARACTER_KW IF_KW THEN_KW ELSE_KW SWITCH_KW END_KW STATE_KW DEFAULT_KW WHEN_KW RETURN_KW BREAK_KW OR_KW AND_KW NOT_KW XOR_KW ANDTHEN_KW SEMICOLON COLON COMMA OPEN_BRACKET CLOSE_BRACKET OPEN_CURLY_BRACES CLOSE_CURLY_BRACES OPEN_PARENTHESIS CLOSE_PARENTHESIS DOT LT_OP GT_OP EQ_OP PLUS_OP MINUS_OP MULTIPLY_OP DIVIDE_OP QUESTIONMARK_OP IDENTIFIER NUMBER CONST_CHAR REAL_NUMBER BOOLEAN_FALSE BOOLEAN_TRUE 

%%

program:
    PROGRAM_KW { printf("Rule 1 \t\t program -> PROGRAM_KW"); }
    ;

%%

int main()
{
    yyparse();
}

void yyerror(const char *s) {
	printf("**Error: Line near token '%s' --> Message: %s **\n", yytext, s);
}