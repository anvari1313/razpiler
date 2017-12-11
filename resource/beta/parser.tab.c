/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

    extern char* yytext;
    void yyerror(const char *s);

    int label_counter = 0;
    int temp_counter = 0;

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

#line 92 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROGRAM_KW = 258,
    STRUCT_KW = 259,
    CONST_KW = 260,
    INTEGER_KW = 261,
    REAL_KW = 262,
    BOOLEAN_KW = 263,
    CHARACTER_KW = 264,
    IF_KW = 265,
    THEN_KW = 266,
    ELSE_KW = 267,
    SWITCH_KW = 268,
    END_KW = 269,
    STATE_KW = 270,
    DEFAULT_KW = 271,
    WHEN_KW = 272,
    RETURN_KW = 273,
    BREAK_KW = 274,
    OR_KW = 275,
    AND_KW = 276,
    NOT_KW = 277,
    XOR_KW = 278,
    ANDTHEN_KW = 279,
    SEMICOLON = 280,
    COLON = 281,
    COMMA = 282,
    OPEN_BRACKET = 283,
    CLOSE_BRACKET = 284,
    OPEN_CURLY_BRACES = 285,
    CLOSE_CURLY_BRACES = 286,
    OPEN_PARENTHESIS = 287,
    CLOSE_PARENTHESIS = 288,
    DOT = 289,
    LT_OP = 290,
    GT_OP = 291,
    EQ_OP = 292,
    PLUS_PLUS_OP = 293,
    MINUS_MINUS_OP = 294,
    PLUS_OP = 295,
    MINUS_OP = 296,
    MULTIPLY_OP = 297,
    DIVIDE_OP = 298,
    QUESTIONMARK_OP = 299,
    PERCENT_OP = 300,
    IDENTIFIER = 301,
    NUMBER = 302,
    CONST_CHAR = 303,
    REAL_NUMBER = 304,
    BOOLEAN_FALSE = 305,
    BOOLEAN_TRUE = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "parser.y" /* yacc.c:355  */

    struct {
        char *place;
        char *code;
        char *true_list;
        char *false_list;
    } eval;

#line 190 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 207 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    57,    61,    68,    72,    76,    82,    88,
      92,    98,   104,   108,   114,   118,   122,   126,   133,   139,
     143,   149,   153,   159,   163,   169,   173,   179,   183,   189,
     193,   199,   205,   209,   215,   219,   225,   229,   233,   237,
     241,   245,   251,   257,   261,   267,   271,   277,   281,   285,
     291,   295,   301,   305,   311,   317,   321,   327,   333,   337,
     341,   345,   349,   353,   357,   361,   367,   380,   394,   398,
     402,   412,   419,   423,   432,   439,   446,   453,   460,   469,
     475,   481,   485,   489,   493,   497,   503,   507,   515,   519,
     523,   529,   535,   541,   547,   551,   557,   561,   565,   571,
     577,   581,   587,   591,   597,   601,   605,   609,   613,   619
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM_KW", "STRUCT_KW", "CONST_KW",
  "INTEGER_KW", "REAL_KW", "BOOLEAN_KW", "CHARACTER_KW", "IF_KW",
  "THEN_KW", "ELSE_KW", "SWITCH_KW", "END_KW", "STATE_KW", "DEFAULT_KW",
  "WHEN_KW", "RETURN_KW", "BREAK_KW", "OR_KW", "AND_KW", "NOT_KW",
  "XOR_KW", "ANDTHEN_KW", "SEMICOLON", "COLON", "COMMA", "OPEN_BRACKET",
  "CLOSE_BRACKET", "OPEN_CURLY_BRACES", "CLOSE_CURLY_BRACES",
  "OPEN_PARENTHESIS", "CLOSE_PARENTHESIS", "DOT", "LT_OP", "GT_OP",
  "EQ_OP", "PLUS_PLUS_OP", "MINUS_MINUS_OP", "PLUS_OP", "MINUS_OP",
  "MULTIPLY_OP", "DIVIDE_OP", "QUESTIONMARK_OP", "PERCENT_OP",
  "IDENTIFIER", "NUMBER", "CONST_CHAR", "REAL_NUMBER", "BOOLEAN_FALSE",
  "BOOLEAN_TRUE", "$accept", "program", "tarifha", "tarif",
  "tarifeSakhtar", "tarifhayeMahalli", "tarifeMoteghayyereMahdud",
  "jenseMahdud", "jens", "tarifeMoteghayyer", "tarifhayeMotheghayyerha",
  "tarifeMeghdareAvvalie", "tarifeShenaseyeMoteghayyer", "tarifeTabe",
  "vorudi", "vorudiha", "jensVorudiha", "shenaseyeVorudiha",
  "shenaseyeVorudi", "jomle", "jomleyeMorakkab", "jomleha",
  "jomleyeEbarat", "jomleyeEntekhab", "onsoreHalat", "onsorePishfarz",
  "jomleyeTekrar", "jomleyeBazgasht", "jomleyeShekast", "ebarat",
  "ebarateSade", "ebarateRabetei", "amalgareRabetei",
  "ebarateRiaziManteghi", "amalgareRiazi", "ebarateYegani",
  "amalgareYegani", "amel", "taghirpazir", "taghirNApazir", "sedaZadan",
  "bordareVorudi", "bordareVorudiha", "meghdareSabet", "LAMBDA", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF -90

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-90)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,     9,    75,     4,   -90,    41,   -90,   -90,   -90,   -90,
      61,     4,   -90,   -90,    53,   -90,   -90,    72,    15,   -90,
      60,    11,   -90,    80,   -90,    73,    88,    99,   -90,   -90,
      78,    15,   -90,    84,   163,    21,   -90,    98,   104,   -90,
     152,    15,   109,   106,   115,   -90,   163,   163,   -90,   -90,
     -90,   117,   -90,   -90,   -90,   -90,   -90,   124,   -90,   191,
     -90,   174,   -90,   -14,   -90,   -90,   -90,    15,   -90,   -90,
      84,   -90,   121,    73,   163,   123,   131,    -7,   139,   -90,
     -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   141,   124,
      69,   -90,   -90,   152,    30,   134,   163,   163,   163,   163,
     163,   135,   136,   154,   -90,   -90,   -90,   -90,   -90,   174,
     174,   -90,   163,   122,   -90,    22,   -90,   -90,    37,   163,
     163,   -90,   150,   -90,   181,   -90,   163,   -90,   -90,   155,
     160,   171,   180,   -90,   -90,   -90,   143,   192,   -90,    30,
     -17,   124,   124,   -90,   -90,   -90,   138,   138,   200,   -90,
     -90,   152,    56,   113,   -90,   110,   -90,   -90,   163,   163,
     163,   163,   -90,   163,   -90,   218,   220,   152,   -90,   -90,
     -90,   -90,   -90,   -90,   -90,   152,   190,    48,   -90,   -90,
     212,   193,   213,   227,   -90,   152,   216,   152,   -90,   219,
     152,   221,   -90,   222,   -90,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    14,    15,    16,    17,
       0,     2,     4,     5,     0,     6,     7,     0,   109,     3,
      23,     0,    19,    21,   109,     0,     0,    27,    30,    28,
       0,   109,    18,     0,     0,     0,    10,    34,    31,    33,
       0,     0,     0,     0,    23,    20,     0,     0,    88,    89,
      90,    93,   104,   106,   105,   108,   107,    22,    71,    72,
      79,     0,    87,    91,    92,    97,    98,     0,     8,     9,
       0,    13,     0,     0,     0,     0,     0,     0,     0,    46,
     109,    26,    36,    37,    38,    39,    40,    41,     0,    65,
      91,    29,    24,     0,    70,     0,   109,     0,     0,     0,
       0,    74,    78,     0,    81,    82,    83,    84,    85,     0,
       0,    86,     0,     0,    12,     0,    35,    32,     0,     0,
       0,    55,     0,    57,   109,    45,     0,    63,    64,     0,
       0,     0,     0,    25,    96,   103,     0,   100,   101,    66,
      67,    68,    69,    75,    77,    76,    73,    80,     0,    95,
      11,     0,     0,     0,    56,     0,    44,    58,     0,     0,
       0,     0,    99,     0,    94,    47,     0,     0,    42,    43,
      59,    60,    61,    62,   102,     0,     0,   109,    54,    48,
       0,     0,     0,     0,    53,     0,     0,     0,    49,     0,
       0,     0,    50,     0,    52,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,   -90,   232,   -90,   165,   -90,   -90,    -2,   -90,
     178,   217,   -90,   -90,   223,   -90,   208,   -90,   179,   -89,
     -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -45,
     -29,   -90,   -90,   -36,   -90,   194,   -90,   -90,   -15,   -90,
     -90,   -90,   -90,   -90,   -24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    11,    12,    13,    35,    69,    70,    25,    15,
      21,    22,    23,    16,    26,    27,    28,    38,    39,    81,
      82,   155,    83,    84,   177,   183,    85,    86,    87,    88,
      89,    58,   109,    59,   110,    60,    61,    62,    90,    64,
      65,   136,   137,    66,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    14,    95,    97,   133,    57,    99,   100,     5,    14,
       6,     7,     8,     9,   112,    46,     1,    94,   121,    63,
     113,     6,     7,     8,     9,    47,    67,     6,     7,     8,
       9,    63,   122,    71,    48,    49,    32,    50,    33,    51,
      52,    53,    54,    55,    56,   118,    63,   150,   151,    33,
      10,   135,    68,    99,   100,     3,    36,    97,    98,    63,
      99,   100,   165,   181,   182,   114,   169,   148,   139,   140,
     141,   142,   138,   146,   147,     4,    97,    98,   178,    99,
     100,   157,    63,    63,    63,    63,   179,    17,    30,   166,
     152,   153,    31,    18,    63,    63,   189,   112,   191,    20,
     156,   193,    24,   113,    63,    63,   126,   127,   128,   129,
     130,   131,   132,   170,   171,   172,   173,    34,   174,    37,
      74,    40,    71,    75,    41,    42,    72,    76,    77,    78,
      44,    73,    46,    97,    98,    79,    99,   100,    92,    93,
      80,   168,    47,    30,    97,    98,   167,    99,   100,    96,
     116,    48,    49,   184,    50,   119,    51,    52,    53,    54,
      55,    56,    74,   120,   123,    75,   125,   134,   149,    76,
      77,    78,   143,   144,    46,   154,   162,    79,   104,   105,
     106,   107,    80,   108,    47,    46,    67,     6,     7,     8,
       9,   145,   158,    48,    49,    47,    50,   159,    51,    52,
      53,    54,    55,    56,    48,    49,    47,    50,   160,    51,
      52,    53,    54,    55,    56,    48,    49,   161,    50,   163,
      51,    52,    53,    54,    55,    56,   101,   102,   103,   164,
     175,   104,   105,   106,   107,   176,   108,   180,   185,   187,
     186,   188,   190,    19,   192,   124,   194,   195,   115,    91,
      45,     0,   117,     0,    43,   111
};

static const yytype_int16 yycheck[] =
{
      24,     3,    47,    20,    93,    34,    23,    24,     4,    11,
       6,     7,     8,     9,    28,    22,     3,    46,    25,    34,
      34,     6,     7,     8,     9,    32,     5,     6,     7,     8,
       9,    46,    77,    35,    41,    42,    25,    44,    27,    46,
      47,    48,    49,    50,    51,    74,    61,    25,    11,    27,
      46,    96,    31,    23,    24,    46,    80,    20,    21,    74,
      23,    24,   151,    15,    16,    67,   155,   112,    97,    98,
      99,   100,    96,   109,   110,     0,    20,    21,   167,    23,
      24,   126,    97,    98,    99,   100,   175,    46,    28,    33,
     119,   120,    32,    32,   109,   110,   185,    28,   187,    46,
     124,   190,    30,    34,   119,   120,    37,    38,    39,    40,
      41,    42,    43,   158,   159,   160,   161,    37,   163,    46,
      10,    33,   124,    13,    25,    47,    28,    17,    18,    19,
      46,    27,    22,    20,    21,    25,    23,    24,    29,    33,
      30,    31,    32,    28,    20,    21,    33,    23,    24,    32,
      29,    41,    42,   177,    44,    32,    46,    47,    48,    49,
      50,    51,    10,    32,    25,    13,    25,    33,    46,    17,
      18,    19,    37,    37,    22,    25,    33,    25,    40,    41,
      42,    43,    30,    45,    32,    22,     5,     6,     7,     8,
       9,    37,    37,    41,    42,    32,    44,    37,    46,    47,
      48,    49,    50,    51,    41,    42,    32,    44,    37,    46,
      47,    48,    49,    50,    51,    41,    42,    37,    44,    27,
      46,    47,    48,    49,    50,    51,    35,    36,    37,    29,
      12,    40,    41,    42,    43,    15,    45,    47,    26,    26,
      47,    14,    26,    11,    25,    80,    25,    25,    70,    41,
      33,    -1,    73,    -1,    31,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    53,    46,     0,     4,     6,     7,     8,     9,
      46,    54,    55,    56,    60,    61,    65,    46,    32,    55,
      46,    62,    63,    64,    30,    60,    66,    67,    68,    96,
      28,    32,    25,    27,    37,    57,    96,    46,    69,    70,
      33,    25,    47,    66,    46,    63,    22,    32,    41,    42,
      44,    46,    47,    48,    49,    50,    51,    82,    83,    85,
      87,    88,    89,    90,    91,    92,    95,     5,    31,    58,
      59,    60,    28,    27,    10,    13,    17,    18,    19,    25,
      30,    71,    72,    74,    75,    78,    79,    80,    81,    82,
      90,    68,    29,    33,    82,    81,    32,    20,    21,    23,
      24,    35,    36,    37,    40,    41,    42,    43,    45,    84,
      86,    87,    28,    34,    60,    62,    29,    70,    82,    32,
      32,    25,    81,    25,    57,    25,    37,    38,    39,    40,
      41,    42,    43,    71,    33,    81,    93,    94,    96,    82,
      82,    82,    82,    37,    37,    37,    85,    85,    81,    46,
      25,    11,    82,    82,    25,    73,    96,    81,    37,    37,
      37,    37,    33,    27,    29,    71,    33,    33,    31,    71,
      81,    81,    81,    81,    81,    12,    15,    76,    71,    71,
      47,    15,    16,    77,    96,    26,    47,    26,    14,    71,
      26,    71,    25,    71,    25,    25
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    55,    56,    57,
      57,    58,    59,    59,    60,    60,    60,    60,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    69,    69,    70,    70,    71,    71,    71,    71,
      71,    71,    72,    73,    73,    74,    74,    75,    75,    75,
      76,    76,    77,    77,    78,    79,    79,    80,    81,    81,
      81,    81,    81,    81,    81,    81,    82,    82,    82,    82,
      82,    82,    83,    83,    84,    84,    84,    84,    84,    85,
      85,    86,    86,    86,    86,    86,    87,    87,    88,    88,
      88,    89,    89,    90,    90,    90,    91,    91,    91,    92,
      93,    93,    94,    94,    95,    95,    95,    95,    95,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     1,     1,     1,     5,     2,
       1,     3,     2,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     4,     6,     5,     1,     1,     3,
       1,     2,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     4,     2,     1,     2,     1,     4,     6,     7,
       5,     6,     4,     1,     5,     2,     3,     2,     3,     4,
       4,     4,     4,     2,     2,     1,     3,     3,     3,     3,
       2,     1,     1,     3,     1,     2,     2,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     3,     1,     1,     4,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 52 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 1 \t\t program -> PROGRAM_KW IDENTIFIER tarifha \n"); 
    }
#line 1449 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 58 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 2 \t\t tarifha -> tarifha tarif \n");
    }
#line 1457 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 62 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 3 \t\t tarifha -> tarif \n");
    }
#line 1465 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 69 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 4 \t\t tarif -> tarifeSakhtar \n");
    }
#line 1473 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 73 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 5 \t\t tarif -> tarifeMoteghayyer \n");
    }
#line 1481 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 77 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 6 \t\t tarif -> tarifeTaber \n");
    }
#line 1489 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 83 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 7 \t\t tarifeSakhtar -> STRUCT_KW IDENTIFIER OPEN_CURLY_BRACES tarifhayeMahalli CLOSE_CURLY_BRACES \n");
    }
#line 1497 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 89 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 8 \t\t tarifhayeMahalli -> tarifhayeMahalli tarifeMoteghayyereMahdud \n");
    }
#line 1505 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 93 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 9 \t\t tarifhayeMahalli -> LAMBDA \n");
    }
#line 1513 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 99 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 10 \t\t tarifeMoteghayyereMahdud -> jenseMahdud tarifhayeMotheghayyerha SEMICOLON \n");
    }
#line 1521 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 105 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 11 \t\t jenseMahdud -> CONST_KW jens \n");
    }
#line 1529 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 109 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 12 \t\t jenseMahdud -> jens \n");
    }
#line 1537 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 115 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 13 \t\t jens -> INTEGER_KW \n");
    }
#line 1545 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 119 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 14 \t\t jens -> REAL_KW \n");
    }
#line 1553 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 123 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 15 \t\t jens -> BOOLEAN_KW \n");
    }
#line 1561 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 127 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 16 \t\t jens -> CHARACTER_KW \n");
    }
#line 1569 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 134 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 17 \t\t tarifeMoteghayyer -> jens tarifhayeMotheghayyerha SEMICOLON \n");
    }
#line 1577 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 140 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 18 \t\t tarifhayeMotheghayyerha -> tarifeMeghdareAvvalie \n");
    }
#line 1585 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 144 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 19 \t\t tarifhayeMotheghayyerha -> tarifhayeMotheghayyerha COMMA tarifeMeghdareAvvalie \n");
    }
#line 1593 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 150 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 20 \t\t tarifeMeghdareAvvalie -> tarifeShenaseyeMoteghayyer \n");
    }
#line 1601 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 154 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 21 \t\t tarifeMeghdareAvvalie -> tarifeShenaseyeMoteghayyer EQ_OP ebarateSade \n");
    }
#line 1609 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 160 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 22 \t\t tarifeShenaseyeMoteghayyer -> IDENTIFIER \n");
    }
#line 1617 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 164 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 23 \t\t tarifeShenaseyeMoteghayyer -> IDENTIFIER OPEN_BRACKET NUMBER CLOSE_BRACKET \n");
    }
#line 1625 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 170 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 24 \t\t tarifeTabe -> jens IDENTIFIER OPEN_PARENTHESIS vorudi CLOSE_PARENTHESIS jomle \n");
    }
#line 1633 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 174 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 25 \t\t tarifeTabe -> IDENTIFIER OPEN_PARENTHESIS vorudi CLOSE_PARENTHESIS jomle \n");
    }
#line 1641 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 180 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 26 \t\t vorudi -> vorudiha \n");
    }
#line 1649 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 184 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 27 \t\t vorudi -> LAMBDA \n");
    }
#line 1657 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 190 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 28 \t\t vorudiha -> vorudiha SEMICOLON jensVorudiha \n");
    }
#line 1665 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 194 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 29 \t\t vorudiha -> jensVorudiha \n");
    }
#line 1673 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 200 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 30 \t\t jensVorudiha -> shenaseyeVorudiha \n");
    }
#line 1681 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 206 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 31 \t\t shenaseyeVorudiha -> shenaseyeVorudiha COMMA shenaseyeVorudi \n");
    }
#line 1689 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 210 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 32 \t\t shenaseyeVorudiha -> shenaseyeVorudi \n");
    }
#line 1697 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 216 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 33 \t\t shenaseyeVorudi -> IDENTIFIER \n");
    }
#line 1705 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 220 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 34 \t\t shenaseyeVorudi -> IDENTIFIER OPEN_BRACKET CLOSE_BRACKET \n");
    }
#line 1713 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 226 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 35 \t\t jomle -> jomleyeMorakkab \n");
    }
#line 1721 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 230 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 36 \t\t jomle -> jomleyeEbarat \n");
    }
#line 1729 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 234 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 37 \t\t jomle -> jomleyeEntekhab \n");
    }
#line 1737 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 238 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 38 \t\t jomle -> jomleyeTekrar \n");
    }
#line 1745 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 242 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 39 \t\t jomle -> jomleyeBazgasht \n");
    }
#line 1753 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 246 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 40 \t\t jomle -> jomleyeShekast \n");
    }
#line 1761 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 252 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 41 \t\t jomleyeMorakkab -> OPEN_CURLY_BRACES tarifhayeMahalli jomleha CLOSE_CURLY_BRACES \n");
    }
#line 1769 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 258 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 42 \t\t jomleha -> jomleha jomle \n");
    }
#line 1777 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 262 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 43 \t\t jomleha -> LAMBDA \n");
    }
#line 1785 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 268 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 44 \t\t jomleyeEbarat -> ebarat SEMICOLON \n");
    }
#line 1793 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 272 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 45 \t\t jomleyeEbarat -> SEMICOLON \n");
    }
#line 1801 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 278 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 46 \t\t jomleyeEntekhab -> IF_KW ebarateSade THEN_KW jomle \n");
    }
#line 1809 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 282 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 47 \t\t jomleyeEntekhab -> IF_KW ebarateSade THEN_KW jomle ELSE_KW jomle \n");
    }
#line 1817 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 286 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 48 \t\t jomleyeEntekhab -> SWITCH_KW OPEN_PARENTHESIS ebarateSade CLOSE_PARENTHESIS onsoreHalat onsorePishfarz END_KW \n");
    }
#line 1825 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 292 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 49 \t\t onsoreHalat -> STATE_KW NUMBER COLON jomle SEMICOLON \n");
    }
#line 1833 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 296 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 50 \t\t onsoreHalat -> onsoreHalat STATE_KW NUMBER COLON jomle SEMICOLON \n");
    }
#line 1841 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 302 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 51 \t\t onsorePishfarz -> DEFAULT_KW COLON jomle SEMICOLON \n");
    }
#line 1849 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 306 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 52 \t\t onsorePishfarz -> LAMBDA \n");
    }
#line 1857 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 312 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 53 \t\t jomleyeTekrar -> WHEN_KW OPEN_PARENTHESIS ebarateSade CLOSE_PARENTHESIS jomle \n");
    }
#line 1865 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 318 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 54 \t\t jomleyeBazgasht -> RETURN_KW SEMICOLON \n");
    }
#line 1873 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 322 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 55 \t\t jomleyeBazgasht -> RETURN_KW ebarat SEMICOLON \n");
    }
#line 1881 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 328 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 56 \t\t jomleyeShekast -> BREAK_KW SEMICOLON \n");
    }
#line 1889 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 334 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 57 \t\t ebarat -> taghirpazir EQ_OP ebarat \n");
    }
#line 1897 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 338 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 58 \t\t ebarat -> taghirpazir PLUS_OP EQ_OP ebarat \n");
    }
#line 1905 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 342 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 59 \t\t ebarat -> taghirpazir MINUS_OP EQ_OP ebarat \n");
    }
#line 1913 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 346 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 60 \t\t ebarat -> taghirpazir MULTIPLY_OP EQ_OP ebarat \n");
    }
#line 1921 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 350 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 61 \t\t ebarat -> taghirpazir DIVIDE_OP EQ_OP ebarat \n");
    }
#line 1929 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 354 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 62 \t\t ebarat -> taghirpazir PLUS_OP PLUS_OP \n");
    }
#line 1937 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 358 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 63 \t\t ebarat -> taghirpazir MINUS_OP MINUS_OP \n");
    }
#line 1945 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 362 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 64 \t\t ebarat -> ebarateSade \n");
    }
#line 1953 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 368 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 65 \t\t ebarateSade -> ebarateSade OR_KW ebarateSade \n");

        (yyvsp[-2].eval).true_list = (yyval.eval).true_list;
        (yyvsp[-2].eval).false_list = new_label();
        (yyvsp[0].eval).true_list = (yyval.eval).true_list;
        (yyvsp[0].eval).false_list = (yyval.eval).false_list;
        (yyval.eval).code = malloc(sizeof(char) * 100);
        sprintf((yyval.eval).code, "%s %s:%s", (yyvsp[-2].eval).code, (yyvsp[-2].eval).false_list, (yyvsp[0].eval).code);

        printf("\n\n%s\n\n", (yyval.eval).code);
    }
#line 1970 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 381 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 66 \t\t ebarateSade -> ebarateSade AND_KW ebarateSade \n");

        (yyvsp[-2].eval).true_list = new_label();
        (yyvsp[-2].eval).false_list = (yyval.eval).false_list;
        (yyvsp[0].eval).true_list = (yyval.eval).true_list;
        (yyvsp[0].eval).false_list = (yyval.eval).false_list;
        (yyval.eval).code = malloc(sizeof(char) * 100);
        sprintf((yyval.eval).code, "%s %s: %s", (yyvsp[-2].eval).code, (yyvsp[-2].eval).true_list, (yyvsp[0].eval).code);

        printf("\n\n%s\n\n", (yyval.eval).code);

    }
#line 1988 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 395 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 67 \t\t ebarateSade -> ebarateSade XOR_KW ebarateSade \n");
    }
#line 1996 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 399 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 68 \t\t ebarateSade -> ebarateSade ANDTHEN_KW ebarateSade \n");
    }
#line 2004 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 403 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 69 \t\t ebarateSade -> ebarateSade NOT_KW ebarateSade \n");

        (yyvsp[0].eval).true_list = (yyval.eval).false_list;
        (yyvsp[0].eval).false_list = (yyval.eval).true_list;
        (yyval.eval).code = (yyvsp[0].eval).code;

        printf("\n\n%s\n\n", (yyval.eval).code);
    }
#line 2018 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 413 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 70 \t\t ebarateSade -> ebarateRabetei \n");
        (yyval.eval) = (yyvsp[0].eval);
    }
#line 2027 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 420 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 71 \t\t ebarateRabetei -> ebarateRiaziManteghi \n");
    }
#line 2035 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 424 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 72 \t\t ebarateRabetei -> ebarateRiaziManteghi amalgareRabetei ebarateRiaziManteghi \n");

        (yyval.eval).code = malloc(sizeof(char) * 100);
        sprintf((yyval.eval).code, "if %s %s %s goto %s \ngoto %s", (yyvsp[-2].eval).place, (yyvsp[-1].eval).place, (yyvsp[0].eval).place, (yyval.eval).true_list, (yyval.eval).false_list);
    }
#line 2046 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 433 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 73 \t\t amalgareRabetei -> LT_OP \n");

        (yyval.eval).place = malloc(sizeof(char) * 5);
        (yyval.eval).place = "<";
    }
#line 2057 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 440 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 74 \t\t amalgareRabetei -> LT_OP EQ_OP \n");

        (yyval.eval).place = malloc(sizeof(char) * 5);
        (yyval.eval).place = "<=";
    }
#line 2068 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 447 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 75 \t\t amalgareRabetei -> EQ_OP EQ_OP \n");

        (yyval.eval).place = malloc(sizeof(char) * 5);
        (yyval.eval).place = "==";
    }
#line 2079 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 454 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 76 \t\t amalgareRabetei -> GT_OP EQ_OP \n");

        (yyval.eval).place = malloc(sizeof(char) * 5);
        (yyval.eval).place = ">=";
    }
#line 2090 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 461 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 77 \t\t amalgareRabetei -> GT_OP \n");

        (yyval.eval).place = malloc(sizeof(char) * 5);
        (yyval.eval).place = ">";
    }
#line 2101 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 470 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 78 \t\t ebarateRiaziManteghi -> ebarateYegani \n");

        (yyval.eval) = (yyvsp[0].eval);
    }
#line 2111 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 476 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 79 \t\t ebarateRiaziManteghi -> ebarateRiaziManteghi amalgareRiazi ebarateRiaziManteghi \n");
    }
#line 2119 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 482 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 80 \t\t amalgareRiazi -> PLUS_OP \n");
    }
#line 2127 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 486 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 81 \t\t amalgareRiazi -> MINUS_OP \n");
    }
#line 2135 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 490 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 82 \t\t amalgareRiazi -> MULTIPLY_OP \n");
    }
#line 2143 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 494 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 83 \t\t amalgareRiazi -> DIVIDE \n");
    }
#line 2151 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 498 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 84 \t\t amalgareRiazi -> PERCENT_OP \n");
    }
#line 2159 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 504 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 85 \t\t ebarateYegani -> amalgareYegani ebarateYegani \n");
    }
#line 2167 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 508 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 86 \t\t ebarateYegani -> amel \n");

        (yyval.eval) = (yyvsp[0].eval);
    }
#line 2177 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 516 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 87 \t\t amalgareYegani -> MINUS_OP \n");
    }
#line 2185 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 520 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 88 \t\t amalgareYegani -> MULTIPLY_OP \n");
    }
#line 2193 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 524 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 89 \t\t amalgareYegani -> QUESTIONMARK_OP \n");
    }
#line 2201 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 530 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 90 \t\t amel -> taghirpazir \n");

        (yyval.eval) = (yyvsp[0].eval);
    }
#line 2211 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 536 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 91 \t\t amel -> taghirNApazir \n");
    }
#line 2219 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 542 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 92 \t\t taghirpazir -> IDENTIFIER \n");

        (yyval.eval).place = yytext;
    }
#line 2229 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 548 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 93 \t\t taghirpazir -> taghirpazir OPEN_BRACKET ebarat CLOSE_BRACKET \n");
    }
#line 2237 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 552 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 94 \t\t taghirpazir -> taghirpazir DOT IDENTIFIER \n");
    }
#line 2245 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 558 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 95 \t\t taghirNApazir -> OPEN_PARENTHESIS ebarat CLOSE_PARENTHESIS \n");
    }
#line 2253 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 562 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 96 \t\t taghirNApazir -> sedaZadan \n");
    }
#line 2261 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 566 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 97 \t\t taghirNApazir -> meghdareSabet \n");
    }
#line 2269 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 572 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 98 \t\t sedaZadan -> IDENTIFIER OPEN_PARENTHESIS bordareVorudi CLOSE_PARENTHESIS \n");
    }
#line 2277 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 578 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 99 \t\t bordareVorudi -> bordareVorudiha \n");
    }
#line 2285 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 582 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 100 \t\t bordareVorudi -> LAMBDA \n");
    }
#line 2293 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 588 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 101 \t\t bordareVorudiha -> bordareVorudiha COMMA ebarat \n");
    }
#line 2301 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 592 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 102 \t\t bordareVorudiha -> ebarat \n");
    }
#line 2309 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 598 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 103 \t\t meghdareSabet -> NUMBER \n");
    }
#line 2317 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 602 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 104 \t\t meghdareSabet -> REAL_NUMBER \n");
    }
#line 2325 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 606 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 105 \t\t meghdareSabet -> CONST_CHAR \n");
    }
#line 2333 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 610 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 106 \t\t meghdareSabet -> BOOLEAN_TRUE \n");
    }
#line 2341 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 614 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 107 \t\t meghdareSabet -> BOOLEAN_FALSE \n");
    }
#line 2349 "parser.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 620 "parser.y" /* yacc.c:1661  */
    {
        printf("Rule 000 \t\t LAMBDA \n");
    }
#line 2357 "parser.tab.c" /* yacc.c:1661  */
    break;


#line 2361 "parser.tab.c" /* yacc.c:1661  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 624 "parser.y" /* yacc.c:1906  */


int main()
{
    yyparse();
}

void yyerror(const char *s) {
	printf("**Error: Line near token '%s' --> Message: %s **\n", yytext, s);
}
