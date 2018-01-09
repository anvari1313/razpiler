%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "../util/lllist/lllist.h"
    #include "../symtable/symtable.h"
    #include "../ircg/quadruple/quad.h"
    #include "../ircg/error/error.h"

    // #ifndef max
	    #define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
    // #endif

    // #ifnef min
	    #define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
    // #endif

    #define ALLOC_STR(str_size) (char *)malloc((str_size + 1) * sizeof(char) )
    extern char* yytext;
    void yyerror(const char *s);

    #define PLUS_OP_CONST 0
    #define MINUS_OP_CONST 1
    #define MULTIPLY_OP_CONST 2
    #define DIVIDE_OP_CONST 3
    #define PERCENT_OP_CONST 4

    #define GT_OP_CONST 5
    #define GT_EQ_OP_CONST 6
    #define EQ_EQ_OP_CONST 7
    #define LT_OP_CONST 8
    #define LT_EQ_OP_CONST 9


    int label_counter = 0;
    int temp_counter = 0;
    
    LLList identifiers_list;
    
    char* new_label()
    {
        char *temp = malloc(sizeof(char) * 10);
        sprintf(temp, "L%d", label_counter);
        label_counter++;

        return temp;
    }

    char* new_temp()
    {
        char *temp = malloc(sizeof(char) * 10);
        sprintf(temp, "t%d", temp_counter);
        temp_counter++;

        return temp;
    }
%}

%union {
    struct {
        unsigned char type;
        char *text;
        char *place;
        char *code;
        void *true_list;
        void *false_list;
    } eval;
    unsigned char id_type;
    char *label;
    float floatval;
    int intval;
    unsigned char operator;
    struct {
        char *const_symtable_segment_link;
        char *const_symtable_segment_return_link;
        char *function_name;
    }const_segment_labels;
    int next_quad;
}

%token PROGRAM_KW STRUCT_KW CONST_KW INTEGER_KW REAL_KW BOOLEAN_KW CHARACTER_KW IF_KW THEN_KW ELSE_KW SWITCH_KW END_KW STATE_KW DEFAULT_KW WHEN_KW RETURN_KW BREAK_KW OR_KW AND_KW NOT_KW XOR_KW ANDTHEN_KW SEMICOLON COLON COMMA OPEN_BRACKET CLOSE_BRACKET OPEN_CURLY_BRACES CLOSE_CURLY_BRACES OPEN_PARENTHESIS CLOSE_PARENTHESIS DOT LT_OP GT_OP EQ_OP PLUS_PLUS_OP MINUS_MINUS_OP PLUS_OP MINUS_OP MULTIPLY_OP DIVIDE_OP QUESTIONMARK_OP PERCENT_OP IDENTIFIER NUMBER CONST_CHAR REAL_NUMBER BOOLEAN_FALSE BOOLEAN_TRUE

%type <eval> ebarateSade ebarat ebarateRabetei ebarateRiaziManteghi taghirpazir amel ebarateYegani IDENTIFIER taghirNApazir meghdareSabet
%type <id_type> jens jenseMahdud
%type <label> startOFWhile
%type <intval> NUMBER
%type <floatval> REAL_NUMBER
%type <operator> amalgareRiazi amalgareRabetei
%type <const_segment_labels> functionHeader
%type <next_quad> mForBP

%left AND_KW
%left OR_KW
%right NOT_KW
%left PLUS_OP MINUS_OP
%left MULTIPLY_OP DIVIDE_OP
%left THEN_KW
%left ELSE_KW

%%

program:
    startProgram PROGRAM_KW IDENTIFIER tarifha endProgram
    {
        printf("Rule 1 \t\t program -> PROGRAM_KW IDENTIFIER(%s) tarifha\n", $3.text);
    }
    ;

startProgram:
    LAMBDA
    {
        lllist_init(&identifiers_list);
        quad_add_no_line("// This is strt of file\n");
    };
endProgram:
    LAMBDA
    {
        quad_add_no_line("// This is end of file\n");
    };

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
        printf("Rule 7 \t\t tarifeSakhtar -> STRUCT_KW IDENTIFIER(%s) OPEN_CURLY_BRACES tarifhayeMahalli CLOSE_CURLY_BRACES \n", $2.text);
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
        if (!lllist_is_empty(identifiers_list))
        {
            lllist_go_first(identifiers_list);
            do{
                char *identifier_name = lllist_get_current(identifiers_list);
                printf("Identifier %s is defined with type %d\n", identifier_name, $1);
                add_symbol(identifier_name, $1);
            }while (lllist_step_forward(identifiers_list));
        }
        printf("Rule 10 \t\t tarifeMoteghayyereMahdud -> jenseMahdud(%d) tarifhayeMotheghayyerha SEMICOLON \n", $1);
        lllist_init(&identifiers_list);
    }
    ;
jenseMahdud:
    CONST_KW jens
    {
        // lllist_init(&identifiers_list);
        printf("Rule 11 \t\t jenseMahdud -> CONST_KW jens \n");
        $$ = $2;
    }
    | jens
    {
        // lllist_init(&identifiers_list);
        printf("Rule 12 \t\t jenseMahdud -> jens \n");
        $$ = $1;
    }
    ;
jens:
    INTEGER_KW
    {
        $$ = SYMBOL_TYPE_INT;
        printf("Rule 13 \t\t jens -> INTEGER_KW \n");
    }
    | REAL_KW
    {
        $$ = SYMBOL_TYPE_REAL;
        printf("Rule 14 \t\t jens -> REAL_KW \n");
    }
    | BOOLEAN_KW
    {
        $$ = SYMBOL_TYPE_BOOL;
        printf("Rule 15 \t\t jens -> BOOLEAN_KW \n");
    }
    | CHARACTER_KW
    {
        $$ = SYMBOL_TYPE_CHAR;
        printf("Rule 16 \t\t jens -> CHARACTER_KW \n");
    }
    ;

tarifeMoteghayyer:
    jens tarifhayeMotheghayyerha SEMICOLON
    {
        // printf("-->>-->>%d\n", $1);
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
        char *id_name = (char *)malloc((strlen($1.text) + 2) * sizeof(char));
        strcpy(id_name, $1.text);
        lllist_push_front(identifiers_list, id_name);
        printf("Rule 22 \t\t tarifeShenaseyeMoteghayyer -> IDENTIFIER(%s) \n", $1.text);
    }
    | IDENTIFIER OPEN_BRACKET NUMBER CLOSE_BRACKET
    {
        printf("Rule 23 \t\t tarifeShenaseyeMoteghayyer -> IDENTIFIER(%s) OPEN_BRACKET NUMBER CLOSE_BRACKET \n", $1.text);
    }
    ;
tarifeTabe:
    functionHeader mForStartFunction jomle mForEndFunction
    {
        printf("Function(%s) is reduces (%s, %s)\n", $1.function_name ,$1.const_symtable_segment_link, $1.const_symtable_segment_return_link);
        char *label_const_seg_str = malloc(500 * sizeof (char));
        sprintf(label_const_seg_str, "%s:", $1.const_symtable_segment_link);
        char *return_const_seg_str = malloc(500 * sizeof (char));
        quad_add_no_line(label_const_seg_str);
        qaud_add_const_symbols(function_enviroment($1.function_name));
        sprintf(return_const_seg_str, "goto %s;", $1.const_symtable_segment_return_link);
        quad_add_no_line(return_const_seg_str);
    }
    ;

functionHeader:
    jens IDENTIFIER OPEN_PARENTHESIS mForStartFunctionPrams vorudi mForEndFunctionPrams CLOSE_PARENTHESIS
    {
        FunctionBlock fb = new_function($2.text , $1);
        $$.const_symtable_segment_link = fb->const_symtable_segment_link;
        $$.const_symtable_segment_return_link = fb->const_symtable_segment_return_link;
        $$.function_name = $2.text;
        char *goto_const_seg_str = malloc(500 * sizeof (char));
        sprintf(goto_const_seg_str, "goto %s;", fb->const_symtable_segment_link);
        char *return_const_seg_str = malloc(500 * sizeof (char));
        quad_add_no_line(goto_const_seg_str);
        sprintf(return_const_seg_str, "%s:", fb->const_symtable_segment_return_link);
        quad_add_no_line(return_const_seg_str);
        printf("Rule 24 \t\t tarifeTabe -> jens IDENTIFIER(%s) OPEN_PARENTHESIS vorudi CLOSE_PARENTHESIS jomle \n", $2.text);
    }
    |
    IDENTIFIER OPEN_PARENTHESIS mForStartFunctionPrams vorudi mForEndFunctionPrams CLOSE_PARENTHESIS
    {
        // FunctionBlock fb = new_function($1.text , $1);
        // quad_add_function_definition(fb);
        printf("Rule 25 \t\t tarifeTabe -> IDENTIFIER(%s) OPEN_PARENTHESIS vorudi CLOSE_PARENTHESIS jomle \n", $1.text);
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
        printf("Rule 33 \t\t shenaseyeVorudi -> IDENTIFIER(%s) \n", $1.text);
    }
    | IDENTIFIER OPEN_BRACKET CLOSE_BRACKET
    {
        printf("Rule 34 \t\t shenaseyeVorudi -> IDENTIFIER(%s) OPEN_BRACKET CLOSE_BRACKET \n", $1.text);
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
    OPEN_CURLY_BRACES mForScope tarifhayeMahalli jomleha CLOSE_CURLY_BRACES
    {
        printf("Scope is Closed.\n");
        printf("Rule 41 \t\t jomleyeMorakkab -> OPEN_CURLY_BRACES tarifhayeMahalli jomleha CLOSE_CURLY_BRACES \n");
    }
    ;

mForStartFunction:
    LAMBDA 
    {
        start_scope();
        printf("Function is started.\n");
    }
    ;

mForEndFunction:
    LAMBDA 
    {
        end_scope();
        printf("Function is ended.\n");
    }
    ;
mForStartFunctionPrams:
    LAMBDA
    {
        start_function_list();
        printf("Function params is started.\n");
    }
    ;
mForEndFunctionPrams:
    LAMBDA
    {
        printf("Function params is ended.\n");
    }
    ;

mForScope:
    LAMBDA 
    {
        printf("Scope is created.\n");
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
        quad_add($1.code);
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
    WHEN_KW startOFWhile OPEN_PARENTHESIS ebarateSade CLOSE_PARENTHESIS jomle
    {
        char *ifcode = ALLOC_STR(100);
        sprintf(ifcode, "if (%s) goto %s;", $4.place, $2);
        printf("Rule 53 \t\t jomleyeTekrar -> WHEN_KW OPEN_PARENTHESIS ebarateSade CLOSE_PARENTHESIS jomle \n");
    }
    ;

startOFWhile:
    LAMBDA
    {
        $$ = new_label();
        char *code = ALLOC_STR(100);
        sprintf(code, "%s:", $$);
        // quad_add(code);
    };

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
        char gen_code[500];
        sprintf(gen_code, "%s\n%s = %s;", $3.code, $1.place, $3.place);
        $$.code = gen_code;
        $$.place = $1.place;
        $$.type = max($1.type, $3.type);
        printf("Rule 57 \t\t ebarat -> taghirpazir EQ_OP ebarat \n");
        // SymbolNode node = install_temp_id($1.type);
        // $$.place = ALLOC_STR(strlen(node->symbol_id) + 2);
        // $$.code = ALLOC_STR(100);

        // strcpy($$.place, node->symbol_id);
        // $$.type = node->symbol_type;
        // sprintf($$.code, "$s = $s = $s", $$.place, $1.place, $3.place);
        // quad_add($$.code);
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
    | taghirpazir PLUS_PLUS_OP
    {
        printf("Rule 62 \t\t ebarat -> taghirpazir PLUS_OP PLUS_OP \n");
    }
    | taghirpazir MINUS_MINUS_OP
    {
        printf("Rule 63 \t\t ebarat -> taghirpazir MINUS_OP MINUS_OP \n");
    }
    | ebarateSade
    {
        printf("Rule 64 \t\t ebarat -> ebarateSade \n");
        $$ = $1;
    }
    ;
ebarateSade:
    ebarateSade OR_KW mForBP ebarateSade
    {
        printf("Rule 65 \t\t ebarateSade -> ebarateSade OR_KW ebarateSade \n");
        bp_backpatch($1.false_list, $3);
        $$.true_list = bp_merge($1.true_list, $4.true_list);
        $$.false_list = $4.false_list;
        // $1.true_list = $$.true_list;
        // $1.false_list = new_label();
        // $3.true_list = $$.true_list;
        // $3.false_list = $$.false_list;
        // $$.code = malloc(sizeof(char) * 100);
        // sprintf($$.code, "%s %s:%s", $1.code, $1.false_list, $3.code);

        // printf("\n\n%s\n\n", $$.code);
        // SymbolNode node = install_temp_id($1.type);
        
        // $$.type = $1.type;
        // $$.place = ALLOC_STR(strlen(node->symbol_id));
        // $$.code = malloc(sizeof(char) * 100);
        // sprintf($$.code, "%s = %s && %s", $$.place, $1.place, $3.place);
        // quad_add($$.code);
    }
    | ebarateSade AND_KW mForBP ebarateSade
    {
        printf("Rule 66 \t\t ebarateSade -> ebarateSade AND_KW ebarateSade \n");
        bp_backpatch($1.true_list, $3);
        $$.false_list = bp_merge($1.false_list, $4.false_list);
        $$.true_list = $4.true_list;
        // $1.true_list = new_label();
        // $1.false_list = $$.false_list;
        // $3.true_list = $$.true_list;
        // $3.false_list = $$.false_list;
        // $$.code = malloc(sizeof(char) * 100);
        // sprintf($$.code, "%s %s: %s", $1.code, $1.true_list, $3.code);

        // printf("\n\n%s\n\n", $$.code);

        // SymbolNode node = install_temp_id($1.type);
        // $$.type = $1.type;
        // $$.place = ALLOC_STR(strlen(node->symbol_id));
        // $$.code = malloc(sizeof(char) * 100);
        // sprintf($$.code, "%s = %s && %s", $$.place, $1.place, $3.place);
        // quad_add($$.code);
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

        $2.true_list = $$.false_list;
        $2.false_list = $$.true_list;
        $$.code = $2.code;

        printf("\n\n%s\n\n", $$.code);
    }
    | ebarateRabetei
    {
        printf("Rule 70 \t\t ebarateSade -> ebarateRabetei \n");
        $$ = $1;
    }
    ;

    mForBP:
    LAMBDA
    {
        $$ = next_quad();
    }
    ;

ebarateRabetei:
    ebarateRiaziManteghi
    {
        printf("Rule 71 \t\t ebarateRabetei -> ebarateRiaziManteghi \n");
        $$ = $1;
    }
    | ebarateRiaziManteghi amalgareRabetei ebarateRiaziManteghi
    {
        
        printf("Rule 72 \t\t ebarateRabetei -> ebarateRiaziManteghi amalgareRabetei(%d) ebarateRiaziManteghi \n", $2);
        char op[3];

        switch($2)
        {
            case GT_OP_CONST:
                strcpy(op, ">");
                break;

            case GT_EQ_OP_CONST:
                strcpy(op, ">=");
                break;

            case EQ_EQ_OP_CONST:
                strcpy(op, "==");
                break;
            
            case LT_OP_CONST:
                strcpy(op, "<");
                break;

            case LT_EQ_OP_CONST:
                strcpy(op, "<=");
                break;
            default:
                printf("ERROR IN OPERATOR IN RULE 72\n");
                exit(-1);
        }
        
        $$.true_list = bp_make_list(next_quad());
        $$.false_list = bp_make_list(next_quad() + 1);
        // quad_add($1.code);
        // quad_add($3.code);
        
        char if_condition[strlen($1.place) + strlen($3.place) + 100];
        sprintf(if_condition, "(%s %s %s)", $1.place, op, $3.place);
        quad_add4("if", if_condition, "goto", "_");
        quad_add4("", "", "goto", "_");
        // sprintf($$.code, "if %s %s %s goto %s \ngoto %s", $1.place, $2.place, $3.place, $$.true_list, $$.false_list);
    }
    ;
amalgareRabetei:
    LT_OP
    {
        printf("Rule 73 \t\t amalgareRabetei -> LT_OP \n");
        $$ = LT_OP_CONST;
    }
    | LT_OP EQ_OP
    {
        printf("Rule 74 \t\t amalgareRabetei -> LT_OP EQ_OP \n");
        $$ = LT_EQ_OP_CONST;
    }
    | EQ_OP EQ_OP
    {
        printf("Rule 75 \t\t amalgareRabetei -> EQ_OP EQ_OP \n");
        $$ = EQ_EQ_OP_CONST;
    }
    | GT_OP EQ_OP
    {
        printf("Rule 76 \t\t amalgareRabetei -> GT_OP EQ_OP \n");
        $$ = GT_EQ_OP_CONST;
    }
    | GT_OP
    {
        printf("Rule 77 \t\t amalgareRabetei -> GT_OP \n");
        $$ = GT_OP_CONST;
    }
    ;
ebarateRiaziManteghi:
    ebarateYegani
    {
        printf("Rule 78 \t\t ebarateRiaziManteghi -> ebarateYegani \n");
        $$ = $1;
    }
    | ebarateRiaziManteghi amalgareRiazi ebarateRiaziManteghi
    {
        char gen_code[500];

        char op;
        switch($2)
        {
            case PLUS_OP_CONST:
                op = '+';
                break;

            case MINUS_OP_CONST:
                op = '-';
                break;

            case MULTIPLY_OP_CONST:
                op = '*';
                break;
            
            case DIVIDE_OP_CONST:
                op = '/';
                break;

            case PERCENT_OP_CONST:
                op = '%';
                break;
            default:
                printf("ERROR IN OPERATOR IN RULE 79\n");
                exit(-1);
        }
        int res_type = max($1.type, $3.type);
        Symbol s = add_temp_symbol(res_type);
        char *res_place = enviroment(s->name);
        $$.type = res_type;
        $$.place = res_place;
        sprintf(gen_code, "%s\n%s\n%s = %s %c %s;", $1.code, $3.code, res_place, $1.place, op, $3.place);
        printf("$1.place  = %s\n", $1.place);
        printf("$3.place  = %s\n", $3.place);
        $$.code = gen_code;
        printf("Rule 79 \t\t ebarateRiaziManteghi -> ebarateRiaziManteghi(%s) amalgareRiazi(%d) ebarateRiaziManteghi(%s) \n",$1.code, $2, $3.place);
    }
    ;
amalgareRiazi:
    PLUS_OP
    {
        $$ = PLUS_OP_CONST;
        printf("Rule 80 \t\t amalgareRiazi -> PLUS_OP \n");
    }
    | MINUS_OP
    {
        $$ = MINUS_OP_CONST;
        printf("Rule 81 \t\t amalgareRiazi -> MINUS_OP \n");
    }
    | MULTIPLY_OP
    {
        $$ = MULTIPLY_OP_CONST;
        printf("Rule 82 \t\t amalgareRiazi -> MULTIPLY_OP \n");
    }
    | DIVIDE_OP
    {
        $$ = DIVIDE_OP_CONST;
        printf("Rule 83 \t\t amalgareRiazi -> DIVIDE \n");
    }
    | PERCENT_OP
    {
        $$ = PERCENT_OP_CONST;
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
        $$ = $1;
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
        printf("Rule 90 \t\t amel -> taghirpazir(%s) \n", $1.place);

        $$ = $1;
    }
    | taghirNApazir
    {
        printf("Rule 91 \t\t amel -> taghirNApazir \n");
        $$ = $1;
    }
    ;
taghirpazir:
    IDENTIFIER
    {
        printf("Rule 92 \t\t taghirpazir -> IDENTIFIER(%s) \n", $1.text);
        
        $$.place = enviroment($1.text);
    }
    | taghirpazir OPEN_BRACKET ebarat CLOSE_BRACKET
    {
        printf("Rule 93 \t\t taghirpazir -> taghirpazir OPEN_BRACKET ebarat CLOSE_BRACKET \n");
    }
    | taghirpazir DOT IDENTIFIER
    {
        printf("Rule 94 \t\t taghirpazir -> taghirpazir DOT IDENTIFIER(%s) \n", $3.text);
    }
    ;
taghirNApazir:
    OPEN_PARENTHESIS ebarat CLOSE_PARENTHESIS
    {
        printf("Rule 95 \t\t taghirNApazir -> OPEN_PARENTHESIS ebarat CLOSE_PARENTHESIS \n");
        $$ = $2;
    }
    | sedaZadan
    {
        printf("Rule 96 \t\t taghirNApazir -> sedaZadan \n");
    }
    | meghdareSabet
    {
        $$ = $1;
        printf("Rule 97 \t\t taghirNApazir -> meghdareSabet \n");
    }
    ;
sedaZadan:
    IDENTIFIER OPEN_PARENTHESIS bordareVorudi CLOSE_PARENTHESIS
    {
        printf("Rule 98 \t\t sedaZadan -> IDENTIFIER(%s) OPEN_PARENTHESIS bordareVorudi CLOSE_PARENTHESIS \n", $1.text);
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
        union Value v;
        v.intval = $1;
        $$.place = add_const_symbol(v, SYMBOL_TYPE_INT);
        $$.code = "";
        printf("Rule 103 \t\t meghdareSabet -> NUMBER(%d) \n", $1);
    }
    | REAL_NUMBER
    {
        union Value v;
        v.floatval = $1;
        $$.place = add_const_symbol(v, SYMBOL_TYPE_REAL);
        $$.code = "";
        printf("Rule 104 \t\t meghdareSabet -> REAL_NUMBER \n");
    }
    | CONST_CHAR
    {
        $$.type = SYMBOL_TYPE_CHAR;
        union Value v;
        v.charval = 'c';
        $$.code = "";
        printf("Rule 105 \t\t meghdareSabet -> CONST_CHAR \n");
    }
    | BOOLEAN_TRUE
    {
        union Value v;
        v.boolval = false;
        $$.place = add_const_symbol(v, SYMBOL_TYPE_BOOL);
        $$.type = SYMBOL_TYPE_BOOL;
        $$.code = "";
        printf("Rule 106 \t\t meghdareSabet -> BOOLEAN_TRUE \n");
    }
    | BOOLEAN_FALSE
    {
        union Value v;
        v.boolval = false;
        $$.place = add_const_symbol(v, SYMBOL_TYPE_BOOL);
        $$.type = SYMBOL_TYPE_BOOL;
        $$.code = "";
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

extern yyin;

void parse_string(char *content)
{
    yy_scan_string(content);
    yyparse();
}

void parse_file(char *path)
{
    FILE *f = fopen(path, "r");
    char * buffer = 0;
    long length;

    if (f)
    {
        fseek (f, 0, SEEK_END);
        length = ftell (f);
        fseek (f, 0, SEEK_SET);
        buffer = malloc (length);
        if (buffer)
        {
            fread (buffer, 1, length, f);
            parse_string(buffer);
        }
        fclose (f);
    }

}

void yyerror(const char *s) {
	printf("**Error: Line near token '%s' --> Message: %s **\n", yytext, s);
}