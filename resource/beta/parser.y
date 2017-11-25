%{
    extern char* yytext;
    void yyerror(const char *s);
%}

%token PROGRAM_KW STRUCT_KW CONST_KW INTEGER_KW REAL_KW BOOLEAN_KW CHARACTER_KW IF_KW THEN_KW ELSE_KW SWITCH_KW END_KW STATE_KW DEFAULT_KW WHEN_KW RETURN_KW BREAK_KW OR_KW AND_KW NOT_KW XOR_KW ANDTHEN_KW SEMICOLON COLON COMMA OPEN_BRACKET CLOSE_BRACKET OPEN_CURLY_BRACES CLOSE_CURLY_BRACES OPEN_PARENTHESIS CLOSE_PARENTHESIS DOT LT_OP GT_OP EQ_OP PLUS_OP MINUS_OP MULTIPLY_OP DIVIDE_OP QUESTIONMARK_OP PERCENT_OP IDENTIFIER NUMBER CONST_CHAR REAL_NUMBER BOOLEAN_FALSE BOOLEAN_TRUE 

%%

program:
    PROGRAM_KW IDENTIFIER tarifha
    {
        printf("Rule 1 \t\t program -> PROGRAM_KW IDENTIFIER tarifha \n"); 
    }
    ;
tarifha:
    tarifha tarif
    {
        printf("Rule 2 \t\t tarifha -> tarifha tarif \n");
    }
    | tarif
    {
        printf("Rule 3 \t\t tarifha -> tarif \n");
    }
    ;

tarif:
    tarifeSakhtar
    {
        printf("Rule 4 \t\t tarif -> tarifeSakhtar \n");
    }
    | tarifeMoteghayyer
    {
        printf("Rule 5 \t\t tarif -> tarifeMoteghayyer \n");
    }
    | tarifeTabe
    {
        printf("Rule 6 \t\t tarif -> tarifeTaber \n");
    }
    ;
tarifeSakhtar:
    STRUCT_KW IDENTIFIER OPEN_CURLY_BRACES tarifhayeMahalli CLOSE_CURLY_BRACES
    {
        printf("Rule 7 \t\t tarifeSakhtar -> STRUCT_KW IDENTIFIER OPEN_CURLY_BRACES tarifhayeMahalli CLOSE_CURLY_BRACES \n");
    }
    ;
tarifhayeMahalli:
    tarifhayeMahalli tarifeMoteghayyereMahdud
    {
        printf("Rule 8 \t\t tarifhayeMahalli -> tarifhayeMahalli tarifeMoteghayyereMahdud \n");
    }
    | LAMBDA
    {
        printf("Rule 9 \t\t tarifhayeMahalli -> LAMBDA \n");
    }
    ;
tarifeMoteghayyereMahdud:
    jenseMahdud tarifhayeMotheghayyerha SEMICOLON
    {
        printf("Rule 10 \t\t tarifeMoteghayyereMahdud -> jenseMahdud tarifhayeMotheghayyerha SEMICOLON \n");
    }
    ;
jenseMahdud:
    CONST_KW jens
    {
        printf("Rule 11 \t\t jenseMahdud -> CONST_KW jens \n");
    }
    | jens
    {
        printf("Rule 12 \t\t jenseMahdud -> jens \n");
    }
    ;
jens:
    INTEGER_KW
    {
        printf("Rule 13 \t\t jens -> INTEGER_KW \n");
    }
    | REAL_KW
    {
        printf("Rule 14 \t\t jens -> REAL_KW \n");
    }
    | BOOLEAN_KW
    {
        printf("Rule 15 \t\t jens -> BOOLEAN_KW \n");
    }
    | CHARACTER_KW
    {
        printf("Rule 16 \t\t jens -> CHARACTER_KW \n");
    }
    ;

tarifeMoteghayyer:
    jens tarifhayeMotheghayyerha SEMICOLON
    {
        printf("Rule 17 \t\t tarifeMoteghayyer -> jens tarifhayeMotheghayyerha SEMICOLON \n");
    }
    ;
tarifhayeMotheghayyerha:
    tarifeMeghdareAvvalie
    {
        printf("Rule 18 \t\t tarifhayeMotheghayyerha -> tarifeMeghdareAvvalie \n");
    }
    | tarifhayeMotheghayyerha COMMA tarifeMeghdareAvvalie
    {
        printf("Rule 19 \t\t tarifhayeMotheghayyerha -> tarifhayeMotheghayyerha COMMA tarifeMeghdareAvvalie \n");
    }
    ;
tarifeMeghdareAvvalie:
    tarifeShenaseyeMoteghayyer
    {
        printf("Rule 20 \t\t tarifeMeghdareAvvalie -> tarifeShenaseyeMoteghayyer \n");
    }
    | tarifeShenaseyeMoteghayyer EQ_OP ebarateSade
    {
        printf("Rule 21 \t\t tarifeMeghdareAvvalie -> tarifeShenaseyeMoteghayyer EQ_OP ebarateSade \n");
    }
    ;
tarifeShenaseyeMoteghayyer:
    IDENTIFIER
    {
        printf("Rule 22 \t\t tarifeShenaseyeMoteghayyer -> IDENTIFIER \n");
    }
    | IDENTIFIER OPEN_BRACKET NUMBER CLOSE_BRACKET
    {
        printf("Rule 23 \t\t tarifeShenaseyeMoteghayyer -> IDENTIFIER OPEN_BRACKET NUMBER CLOSE_BRACKET \n");
    }
    ;
tarifeTabe:
    jens IDENTIFIER OPEN_PARENTHESIS vorudi CLOSE_PARENTHESIS jomle
    {
        printf("Rule 24 \t\t tarifeTabe -> jens IDENTIFIER OPEN_PARENTHESIS vorudi CLOSE_PARENTHESIS jomle \n");
    }
    | IDENTIFIER OPEN_PARENTHESIS vorudi CLOSE_PARENTHESIS jomle
    {
        printf("Rule 25 \t\t tarifeTabe -> IDENTIFIER OPEN_PARENTHESIS vorudi CLOSE_PARENTHESIS jomle \n");
    }
    ;
vorudi:
    vorudiha
    {
        printf("Rule 26 \t\t vorudi -> vorudiha \n");
    }
    | LAMBDA
    {
        printf("Rule 27 \t\t vorudi -> LAMBDA \n");
    }
    ;
vorudiha:
    vorudiha SEMICOLON jensVorudiha
    {
        printf("Rule 28 \t\t vorudiha -> vorudiha SEMICOLON jensVorudiha \n");
    }
    | jensVorudiha
    {
        printf("Rule 29 \t\t vorudiha -> jensVorudiha \n");
    }
    ;
jensVorudiha:
    jens shenaseyeVorudiha
    {
        printf("Rule 30 \t\t jensVorudiha -> shenaseyeVorudiha \n");
    }
    ;
shenaseyeVorudiha:
    shenaseyeVorudiha COMMA shenaseyeVorudi
    {
        printf("Rule 31 \t\t shenaseyeVorudiha -> shenaseyeVorudiha COMMA shenaseyeVorudi \n");
    }
    | shenaseyeVorudi
    {
        printf("Rule 32 \t\t shenaseyeVorudiha -> shenaseyeVorudi \n");
    }
    ;
shenaseyeVorudi:
    IDENTIFIER
    {
        printf("Rule 33 \t\t shenaseyeVorudi -> IDENTIFIER \n");
    }
    | IDENTIFIER OPEN_BRACKET CLOSE_BRACKET
    {
        printf("Rule 34 \t\t shenaseyeVorudi -> IDENTIFIER OPEN_BRACKET CLOSE_BRACKET \n");
    }
    ;
jomle:
    jomleyeMorakkab
    {
        printf("Rule 35 \t\t jomle -> jomleyeMorakkab \n");
    }
    | jomleyeEbarat
    {
        printf("Rule 36 \t\t jomle -> jomleyeEbarat \n");
    }
    | jomleyeEntekhab
    {
        printf("Rule 37 \t\t jomle -> jomleyeEntekhab \n");
    }
    | jomleyeTekrar
    {
        printf("Rule 38 \t\t jomle -> jomleyeTekrar \n");
    }
    | jomleyeBazgasht
    {
        printf("Rule 39 \t\t jomle -> jomleyeBazgasht \n");
    }
    | jomleyeShekast
    {
        printf("Rule 40 \t\t jomle -> jomleyeShekast \n");
    }
    ;
jomleyeMorakkab:
    OPEN_CURLY_BRACES tarifhayeMahalli jomleha CLOSE_CURLY_BRACES
    {
        printf("Rule 41 \t\t jomleyeMorakkab -> OPEN_CURLY_BRACES tarifhayeMahalli jomleha CLOSE_CURLY_BRACES \n");
    }
    ;
jomleha:
    jomleha jomle
    {
        printf("Rule 42 \t\t jomleha -> jomleha jomle \n");
    }
    | LAMBDA
    {
        printf("Rule 43 \t\t jomleha -> LAMBDA \n");
    }
    ;
jomleyeEbarat:
    ebarat SEMICOLON
    {
        printf("Rule 44 \t\t jomleyeEbarat -> ebarat SEMICOLON \n");
    }
    | SEMICOLON
    {
        printf("Rule 45 \t\t jomleyeEbarat -> SEMICOLON \n");
    }
    ;
jomleyeEntekhab:
    IF_KW ebarateSade THEN_KW jomle
    {
        printf("Rule 46 \t\t jomleyeEntekhab -> IF_KW ebarateSade THEN_KW jomle \n");
    }
    | IF_KW ebarateSade THEN_KW jomle ELSE_KW jomle
    {
        printf("Rule 47 \t\t jomleyeEntekhab -> IF_KW ebarateSade THEN_KW jomle ELSE_KW jomle \n");
    }
    | SWITCH_KW OPEN_PARENTHESIS ebarateSade CLOSE_PARENTHESIS onsoreHalat onsorePishfarz END_KW
    {
        printf("Rule 48 \t\t jomleyeEntekhab -> SWITCH_KW OPEN_PARENTHESIS ebarateSade CLOSE_PARENTHESIS onsoreHalat onsorePishfarz END_KW \n");
    }
    ;
onsoreHalat:
    STATE_KW NUMBER COLON jomle SEMICOLON
    {
        printf("Rule 49 \t\t onsoreHalat -> STATE_KW NUMBER COLON jomle SEMICOLON \n");
    }
    | onsoreHalat STATE_KW NUMBER COLON jomle SEMICOLON
    {
        printf("Rule 50 \t\t onsoreHalat -> onsoreHalat STATE_KW NUMBER COLON jomle SEMICOLON \n");
    }
    ;
onsorePishfarz:
    DEFAULT_KW COLON jomle SEMICOLON
    {
        printf("Rule 51 \t\t onsorePishfarz -> DEFAULT_KW COLON jomle SEMICOLON \n");
    }
    | LAMBDA
    {
        printf("Rule 52 \t\t onsorePishfarz -> LAMBDA \n");
    }
    ;
jomleyeTekrar:
    WHEN_KW OPEN_PARENTHESIS ebarateSade CLOSE_PARENTHESIS jomle
    {
        printf("Rule 53 \t\t jomleyeTekrar -> WHEN_KW OPEN_PARENTHESIS ebarateSade CLOSE_PARENTHESIS jomle \n");
    }
    ;
jomleyeBazgasht:
    RETURN_KW SEMICOLON
    {
        printf("Rule 54 \t\t jomleyeBazgasht -> RETURN_KW SEMICOLON \n");
    }
    | RETURN_KW ebarat SEMICOLON
    {
        printf("Rule 55 \t\t jomleyeBazgasht -> RETURN_KW ebarat SEMICOLON \n");
    }
    ;
jomleyeShekast:
    BREAK_KW SEMICOLON
    {
        printf("Rule 56 \t\t jomleyeShekast -> BREAK_KW SEMICOLON \n");
    }
    ;
ebarat:
    taghirpazir EQ_OP ebarat
    {
        printf("Rule 57 \t\t ebarat -> taghirpazir EQ_OP ebarat \n");
    }
    | taghirpazir PLUS_OP EQ_OP ebarat
    {
        printf("Rule 58 \t\t ebarat -> taghirpazir PLUS_OP EQ_OP ebarat \n");
    }
    | taghirpazir MINUS_OP EQ_OP ebarat
    {
        printf("Rule 59 \t\t ebarat -> taghirpazir MINUS_OP EQ_OP ebarat \n");
    }
    | taghirpazir MULTIPLY_OP EQ_OP ebarat
    {
        printf("Rule 60 \t\t ebarat -> taghirpazir MULTIPLY_OP EQ_OP ebarat \n");
    }
    | taghirpazir DIVIDE_OP EQ_OP ebarat
    {
        printf("Rule 61 \t\t ebarat -> taghirpazir DIVIDE_OP EQ_OP ebarat \n");
    }
    | taghirpazir PLUS_OP PLUS_OP
    {
        printf("Rule 62 \t\t ebarat -> taghirpazir PLUS_OP PLUS_OP \n");
    }
    | taghirpazir MINUS_OP MINUS_OP
    {
        printf("Rule 63 \t\t ebarat -> taghirpazir MINUS_OP MINUS_OP \n");
    }
    | ebarateSade
    {
        printf("Rule 64 \t\t ebarat -> ebarateSade \n");
    }
    ;
ebarateSade:
    ebarateSade OR_KW ebarateSade
    {
        printf("Rule 65 \t\t ebarateSade -> ebarateSade OR_KW ebarateSade \n");
    }
    | ebarateSade AND_KW ebarateSade
    {
        printf("Rule 66 \t\t ebarateSade -> ebarateSade AND_KW ebarateSade \n");
    }
    | ebarateSade XOR_KW ebarateSade
    {
        printf("Rule 67 \t\t ebarateSade -> ebarateSade XOR_KW ebarateSade \n");
    }
    | ebarateSade ANDTHEN_KW ebarateSade
    {
        printf("Rule 68 \t\t ebarateSade -> ebarateSade ANDTHEN_KW ebarateSade \n");
    }
    | NOT_KW ebarateSade
    {
        printf("Rule 69 \t\t ebarateSade -> ebarateSade NOT_KW ebarateSade \n");
    }
    | ebarateRabetei
    {
        printf("Rule 70 \t\t ebarateSade -> ebarateRabetei \n");
    }
    ;
ebarateRabetei:
    ebarateRiaziManteghi
    {
        printf("Rule 71 \t\t ebarateRabetei -> ebarateRiaziManteghi \n");
    }
    | ebarateRiaziManteghi amalgareRabetei ebarateRiaziManteghi
    {
        printf("Rule 72 \t\t ebarateRabetei -> ebarateRiaziManteghi amalgareRabetei ebarateRiaziManteghi \n");
    }
    ;
amalgareRabetei:
    LT_OP
    {
        printf("Rule 73 \t\t amalgareRabetei -> LT_OP \n");
    }
    | LT_OP EQ_OP
    {
        printf("Rule 74 \t\t amalgareRabetei -> LT_OP EQ_OP \n");
    }
    | EQ_OP EQ_OP
    {
        printf("Rule 75 \t\t amalgareRabetei -> EQ_OP EQ_OP \n");
    }
    | GT_OP EQ_OP
    {
        printf("Rule 76 \t\t amalgareRabetei -> GT_OP EQ_OP \n");
    }
    | GT_OP
    {
        printf("Rule 77 \t\t amalgareRabetei -> GT_OP \n");
    }
    ;
ebarateRiaziManteghi:
    ebarateYegani
    {
        printf("Rule 78 \t\t ebarateRiaziManteghi -> ebarateYegani \n");
    }
    | ebarateRiaziManteghi amalgareRiazi ebarateRiaziManteghi
    {
        printf("Rule 79 \t\t ebarateRiaziManteghi -> ebarateRiaziManteghi amalgareRiazi ebarateRiaziManteghi \n");
    }
    ;
amalgareRiazi:
    PLUS_OP
    {
        printf("Rule 80 \t\t amalgareRiazi -> PLUS_OP \n");
    }
    | MINUS_OP
    {
        printf("Rule 81 \t\t amalgareRiazi -> MINUS_OP \n");
    }
    | MULTIPLY_OP
    {
        printf("Rule 82 \t\t amalgareRiazi -> MULTIPLY_OP \n");
    }
    | DIVIDE_OP
    {
        printf("Rule 83 \t\t amalgareRiazi -> DIVIDE \n");
    }
    | PERCENT_OP
    {
        printf("Rule 84 \t\t amalgareRiazi -> PERCENT_OP \n");
    }
    ;
ebarateYegani:
    amalgareYegani ebarateYegani
    {
        printf("Rule 85 \t\t ebarateYegani -> amalgareYegani ebarateYegani \n");
    }
    | amel
    {
        printf("Rule 86 \t\t ebarateYegani -> amel \n");
    }
    ;
amalgareYegani:
    MINUS_OP
    {
        printf("Rule 87 \t\t amalgareYegani -> MINUS_OP \n");
    }
    | MULTIPLY_OP
    {
        printf("Rule 88 \t\t amalgareYegani -> MULTIPLY_OP \n");
    }
    | QUESTIONMARK_OP
    {
        printf("Rule 89 \t\t amalgareYegani -> QUESTIONMARK_OP \n");
    }
    ;
amel:
    taghirpazir
    {
        printf("Rule 90 \t\t amel -> taghirpazir \n");
    }
    | taghirNApazir
    {
        printf("Rule 91 \t\t amel -> taghirNApazir \n");
    }
    ;
taghirpazir:
    IDENTIFIER
    {
        printf("Rule 92 \t\t taghirpazir -> IDENTIFIER \n");
    }
    | taghirpazir OPEN_BRACKET ebarat CLOSE_BRACKET
    {
        printf("Rule 93 \t\t taghirpazir -> taghirpazir OPEN_BRACKET ebarat CLOSE_BRACKET \n");
    }
    | taghirpazir DOT IDENTIFIER
    {
        printf("Rule 94 \t\t taghirpazir -> taghirpazir DOT IDENTIFIER \n");
    }
    ;
taghirNApazir:
    OPEN_PARENTHESIS ebarat CLOSE_PARENTHESIS
    {
        printf("Rule 95 \t\t taghirNApazir -> OPEN_PARENTHESIS ebarat CLOSE_PARENTHESIS \n");
    }
    | sedaZadan
    {
        printf("Rule 96 \t\t taghirNApazir -> sedaZadan \n");
    }
    | meghdareSabet
    {
        printf("Rule 97 \t\t taghirNApazir -> meghdareSabet \n");
    }
    ;
sedaZadan:
    IDENTIFIER OPEN_PARENTHESIS bordareVorudi CLOSE_PARENTHESIS
    {
        printf("Rule 98 \t\t sedaZadan -> IDENTIFIER OPEN_PARENTHESIS bordareVorudi CLOSE_PARENTHESIS \n");
    }
    ;
bordareVorudi:
    bordareVorudiha
    {
        printf("Rule 99 \t\t bordareVorudi -> bordareVorudiha \n");
    }
    | LAMBDA
    {
        printf("Rule 100 \t\t bordareVorudi -> LAMBDA \n");
    }
    ;
bordareVorudiha:
    bordareVorudiha COMMA ebarat
    {
        printf("Rule 101 \t\t bordareVorudiha -> bordareVorudiha COMMA ebarat \n");
    }
    | ebarat
    {
        printf("Rule 102 \t\t bordareVorudiha -> ebarat \n");
    }
    ;
meghdareSabet:
    NUMBER
    {
        printf("Rule 103 \t\t meghdareSabet -> NUMBER \n");
    }
    | REAL_NUMBER
    {
        printf("Rule 104 \t\t meghdareSabet -> REAL_NUMBER \n");
    }
    | CONST_CHAR
    {
        printf("Rule 105 \t\t meghdareSabet -> CONST_CHAR \n");
    }
    | BOOLEAN_TRUE
    {
        printf("Rule 106 \t\t meghdareSabet -> BOOLEAN_TRUE \n");
    }
    | BOOLEAN_FALSE
    {
        printf("Rule 107 \t\t meghdareSabet -> BOOLEAN_FALSE \n");
    }
    ;
LAMBDA:
    %empty
    {
        printf("Rule 000 \t\t LAMBDA \n");
    }
    ;
%%

int main()
{
    yyparse();
}

void yyerror(const char *s) {
	printf("**Error: Line near token '%s' --> Message: %s **\n", yytext, s);
}