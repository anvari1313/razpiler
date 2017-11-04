%%
[\t]+
is  |
am  |
are |
was |
were {printf("%s : is a verb.\n", yytext);}
[a-zA-Z]+ {printf("%s : is not a verb.\n", yytext);}
.|\n
%%

int func()
{
    yylex();
    return 0;
}