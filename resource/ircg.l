%{
      #include <stdio.h>
%}

%token DIGIT NEWLINE
%left '+' '-'
%%

start : expr NEWLINE  { 
                        printf("\nComplete\n");
                        exit(1);
                      }
  ;

expr:  expr '+' expr        { printf("+ ");}
  | expr '-' expr     {printf("- ");}
  | '(' expr ')'
  | DIGIT             {printf("%d ",$1);}
  ;

%%

int yylex()
{
    static int index = 0;
    int lex []={DIGIT, '+', DIGIT, NEWLINE };
    printf("New token is given\n");
    return lex[index++];
}

void yyerror(char const *s)
{ 
    printf("yyerror  %s\n",s); 
    return ;
} 
int main()
{
  yyparse();
  return 0;
}