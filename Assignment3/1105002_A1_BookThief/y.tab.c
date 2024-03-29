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
#line 1 "yacc.y" /* yacc.c:339  */

#include "symboltable.h"
#define YYSTYPE SymbolInfo*


using namespace std;
int yyparse(void);
int yylex(void);
string wholecode;
string varlist;
extern FILE *yyin;
extern int count;
int tempcount=0;
int levelcount=0;

FILE *fp,*fasmp;

void yyerror(char *s)
{
	fprintf(stdout,"At Line %d, ERROR-> %s\n",count+1,s);
	return;
}

string num_to_str(double num)
{
    ostringstream oss;
    oss<<num;
    return oss.str();
}
void generateTemp(string &temp)
{   temp=temp+num_to_str(tempcount); 
	tempcount++;
	
}

void generateLabel(string &level)
{
	level=level+num_to_str(levelcount); 
	levelcount++;
}

SymbolTable st;


#line 111 "y.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INTEGER = 258,
    REAL = 259,
    FUNCTION = 260,
    PROCEDURE = 261,
    DOTDOT = 262,
    COLON = 263,
    VAR = 264,
    ARRAY = 265,
    IF = 266,
    THEN = 267,
    ELSE = 268,
    DO = 269,
    WHILE = 270,
    WRITE = 271,
    PROGRAM = 272,
    OF = 273,
    ID = 274,
    SEMICOLON = 275,
    COMMA = 276,
    BEGIN1 = 277,
    END = 278,
    NUM = 279,
    ASSIGNOP = 280,
    RELOP = 281,
    ADDOP = 282,
    NOT = 283,
    MULOP = 284,
    PAREN1 = 285,
    PAREN2 = 286,
    BRACKET1 = 287,
    BRACKET2 = 288,
    OR = 289,
    AND = 290,
    CURLEY1 = 291,
    CURLEY2 = 292,
    ADDOP1 = 293,
    ADDOP2 = 294,
    MULOP1 = 295,
    MULOP2 = 296,
    IFX = 297
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define REAL 259
#define FUNCTION 260
#define PROCEDURE 261
#define DOTDOT 262
#define COLON 263
#define VAR 264
#define ARRAY 265
#define IF 266
#define THEN 267
#define ELSE 268
#define DO 269
#define WHILE 270
#define WRITE 271
#define PROGRAM 272
#define OF 273
#define ID 274
#define SEMICOLON 275
#define COMMA 276
#define BEGIN1 277
#define END 278
#define NUM 279
#define ASSIGNOP 280
#define RELOP 281
#define ADDOP 282
#define NOT 283
#define MULOP 284
#define PAREN1 285
#define PAREN2 286
#define BRACKET1 287
#define BRACKET2 288
#define OR 289
#define AND 290
#define CURLEY1 291
#define CURLEY2 292
#define ADDOP1 293
#define ADDOP2 294
#define MULOP1 295
#define MULOP2 296
#define IFX 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 246 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   108

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    59,    59,    69,    75,    85,    89,    96,   101,   106,
     112,   119,   123,   128,   133,   138,   144,   148,   153,   158,
     164,   171,   175,   181,   186,   192,   208,   213,   219,   234,
     253,   271,   276,   281,   286,   291,   296,   301,   307,   312,
     353,   359,   377,   396,   402,   428,   433,   438,   445,   460,
     474
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "REAL", "FUNCTION",
  "PROCEDURE", "DOTDOT", "COLON", "VAR", "ARRAY", "IF", "THEN", "ELSE",
  "DO", "WHILE", "WRITE", "PROGRAM", "OF", "ID", "SEMICOLON", "COMMA",
  "BEGIN1", "END", "NUM", "ASSIGNOP", "RELOP", "ADDOP", "NOT", "MULOP",
  "PAREN1", "PAREN2", "BRACKET1", "BRACKET2", "OR", "AND", "CURLEY1",
  "CURLEY2", "ADDOP1", "ADDOP2", "MULOP1", "MULOP2", "IFX", "$accept",
  "program", "identifier_list", "declarations", "type", "standard_type",
  "subprogram_declarations", "subprogram_declaration", "subprogram_head",
  "arguments", "parameter_list", "compound_statement",
  "optional_statements", "statement_list", "statement", "variable",
  "procedure_statement", "expression_list", "expression",
  "simple_expression", "term", "factor", "sign", YY_NULLPTR
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
     295,   296,   297
};
# endif

#define YYPACT_NINF -79

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-79)))

#define YYTABLE_NINF -33

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -5,    -2,    21,     1,   -79,    20,   -79,    29,    45,    46,
     -79,   -79,    59,    20,     3,     2,    56,    57,     0,    52,
     -79,   -79,    53,    47,    47,    17,    17,    48,    37,   -79,
      58,    60,   -79,    54,   -79,   -79,    11,   -79,   -79,    50,
      63,   -79,    20,    76,    65,    61,   -79,   -79,    24,    17,
      74,    32,    64,   -79,    24,    73,    69,    17,    17,   -79,
       0,    17,   -79,    66,   -79,    16,    22,    67,   -79,    17,
     -79,    68,     0,    17,    24,    24,    64,     0,    70,    30,
     -79,    62,   -79,   -79,    82,    53,    20,   -79,    72,    34,
     -79,    81,    71,    64,   -79,   -79,   -79,    17,   -79,   -79,
      78,   -79,    19,   -79,   -79,     0,   -79,    75,    53,   -79,
      79,   -79,    67,   -79
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     3,     0,     0,     0,
       4,     5,    11,     0,     0,     0,     0,     0,    21,     0,
       5,     2,     0,    16,    16,     0,     0,     0,    34,    27,
       0,    22,    23,     0,    26,    12,     0,     9,    10,     0,
       0,     7,     0,     0,     0,    45,    47,    50,     0,     0,
       0,    38,    40,    43,     0,     0,     0,     0,     0,    20,
       0,     0,    13,     0,     6,     0,     0,     0,    15,     0,
      49,     0,     0,     0,     0,     0,    41,     0,     0,     0,
      36,     0,    24,    25,     0,     0,     0,    17,     0,     0,
      48,    28,    39,    42,    44,    30,    31,     0,    35,    33,
       0,    18,     0,    14,    46,     0,    37,     0,     0,    29,
       0,    19,     0,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -79,   -79,   -13,    80,   -78,   -63,   -79,   -79,   -79,    83,
     -79,    -8,   -79,   -79,   -59,   -79,   -79,    27,   -23,    31,
     -40,   -43,   -79
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    12,    40,    41,    14,    19,    20,    43,
      66,    29,    30,    31,    32,    33,    34,    79,    80,    51,
      52,    53,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      15,    82,    50,    55,    88,    70,    21,   101,    16,    17,
      22,    25,     1,    91,    76,    26,    27,     3,    95,    28,
      13,     4,    18,     8,    85,    18,    71,   108,    62,    65,
     111,     5,    94,    18,    93,    81,    45,     8,    83,     6,
       8,    46,    86,    45,    47,    48,   109,    49,    46,   113,
       8,    97,    48,    87,    49,    97,    37,    38,    73,    74,
       9,    98,   -32,    39,    10,   104,    11,    57,    13,    58,
      37,    38,    35,   102,   106,    23,    24,    42,    56,    61,
      60,    59,    63,    64,    67,    68,    72,    77,    78,   100,
      84,    69,   103,    75,   105,    99,    89,   112,    74,    90,
      36,    96,   107,     0,    92,     0,     0,    44,   110
};

static const yytype_int8 yycheck[] =
{
      13,    60,    25,    26,    67,    48,    14,    85,     5,     6,
       8,    11,    17,    72,    54,    15,    16,    19,    77,    19,
       9,     0,    22,    21,     8,    22,    49,     8,    36,    42,
     108,    30,    75,    22,    74,    58,    19,    21,    61,    19,
      21,    24,    20,    19,    27,    28,   105,    30,    24,   112,
      21,    21,    28,    31,    30,    21,     3,     4,    26,    27,
      31,    31,    25,    10,    19,    31,    20,    30,     9,    32,
       3,     4,    20,    86,    97,    19,    19,    30,    30,    25,
      20,    23,    32,    20,     8,    20,    12,    14,    19,     7,
      24,    30,    20,    29,    13,    33,    69,    18,    27,    31,
      20,    31,    24,    -1,    73,    -1,    -1,    24,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    44,    19,     0,    30,    19,    45,    21,    31,
      19,    20,    46,     9,    49,    45,     5,     6,    22,    50,
      51,    54,     8,    19,    19,    11,    15,    16,    19,    54,
      55,    56,    57,    58,    59,    20,    46,     3,     4,    10,
      47,    48,    30,    52,    52,    19,    24,    27,    28,    30,
      61,    62,    63,    64,    65,    61,    30,    30,    32,    23,
      20,    25,    54,    32,    20,    45,    53,     8,    20,    30,
      64,    61,    12,    26,    27,    29,    63,    14,    19,    60,
      61,    61,    57,    61,    24,     8,    20,    31,    48,    60,
      31,    57,    62,    63,    64,    57,    31,    21,    31,    33,
       7,    47,    45,    20,    31,    13,    61,    24,     8,    57,
      33,    47,    18,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    49,    49,    50,    51,    51,    52,    52,    53,    53,
      54,    55,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    58,    58,    59,    59,    60,    60,    61,    61,
      62,    62,    62,    63,    63,    64,    64,    64,    64,    64,
      65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     1,     3,     0,     6,     1,     8,     1,
       1,     0,     3,     3,     6,     4,     0,     3,     3,     5,
       3,     0,     1,     1,     3,     3,     1,     1,     4,     6,
       4,     4,     1,     4,     1,     4,     1,     3,     1,     3,
       1,     2,     3,     1,     3,     1,     4,     1,     3,     2,
       1
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
#line 60 "yacc.y" /* yacc.c:1646  */
    {
            printf("program:    PROGRAM ID PAREN1 identifier_list PAREN2 SEMICOLON declarations subprogram_declarations compound_statement\n");
//            string asmcode=$2->code+$4->code+$5->code+$6->code+$7->code+$8->code+$9->code;
            string s=((yyvsp[-5])->symbol+" dw 0\n");
            int x=varlist.find(s);
            varlist.erase(x,s.length());
            wholecode=".model small\n.stack 100H\n.data\n"+varlist+"\n.code\n\nmain proc\n\nMOV AX,@data ;\nMOV ds,AX ;\nMOV es,AX ;\n"+(yyvsp[0])->code+"\n\nmain endp"+"\nend main";
            }
#line 1408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 70 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);
             varlist+=(yyvsp[0])->symbol+" dw 0\n";
             printf("identifier_list--> ID\n");
            }
#line 1417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 76 "yacc.y" /* yacc.c:1646  */
    {
            
            varlist+=(yyvsp[0])->symbol+" dw 0\n";
              
            printf("identifier_list-->COMMA  ID\n");
            
            }
#line 1429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 85 "yacc.y" /* yacc.c:1646  */
    {
            printf("declarations-->    \n");
            }
#line 1437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 90 "yacc.y" /* yacc.c:1646  */
    {
            (yyval)=(yyvsp[-3]);
            printf("declarations-->   declarations VAR identifier_list COLON type SEMICOLON \n");
            
            }
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 97 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);
            printf("type--->standard_type\n");
            }
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 102 "yacc.y" /* yacc.c:1646  */
    {
            printf("type-->ARRAY BRACKET1 NUM DOTDOT NUM BRACKET2 OF standard_type\n");
            }
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 107 "yacc.y" /* yacc.c:1646  */
    {
            (yyval)=(yyvsp[0]);
            printf("standard_type-->  INTEGER\n");
            }
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "yacc.y" /* yacc.c:1646  */
    {
            (yyval)=(yyvsp[0]);
            printf("standard_type-->  REAL\n");
            }
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "yacc.y" /* yacc.c:1646  */
    {
            printf("subprogram_declarations--> \n");
            }
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 124 "yacc.y" /* yacc.c:1646  */
    {
            printf("subprogram_declarations-->subprogram_declarations subprogram_declaration SEMICOLON\n");
            }
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 129 "yacc.y" /* yacc.c:1646  */
    {
            printf("subprogram_declaration-->subprogram_head declarations compound_statement\n");
            }
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 134 "yacc.y" /* yacc.c:1646  */
    {
            printf("subprogram_head-->FUNCTION ID arguments COLON standard_type SEMICOLON\n");
            }
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 139 "yacc.y" /* yacc.c:1646  */
    {
            printf("subprogram_head-->PROCEDURE ID arguments SEMICOLON\n");
            }
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 144 "yacc.y" /* yacc.c:1646  */
    {
            printf("arguments--> \n");
            }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 149 "yacc.y" /* yacc.c:1646  */
    {
            printf("arguments --> PAREN1 parameter_list PAREN2\n");
            }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 154 "yacc.y" /* yacc.c:1646  */
    {
            printf("parameter_list--->identifier_list COLON type\n");
            }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 159 "yacc.y" /* yacc.c:1646  */
    {
            printf("parameter_list ---> parameter_list SEMICOLON identifier_list COLON type\n");
            }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 165 "yacc.y" /* yacc.c:1646  */
    {
            (yyval)=(yyvsp[-1]);
            printf("compound_statement-->	BEGIN optional_statements END\n");
            }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 171 "yacc.y" /* yacc.c:1646  */
    {
            printf("optional_statements-->	      \n");
            }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 176 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);
            printf("optional_statements--> statement_list\n");
            
            }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 182 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);
            printf("statement_list--> statement\n");
            }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 187 "yacc.y" /* yacc.c:1646  */
    {
            (yyval)->code=(yyvsp[-2])->code+"\n"+(yyvsp[0])->code+"\n";
            printf("statement_list--> statement_list SEMICOLON statement\n");
            }
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 193 "yacc.y" /* yacc.c:1646  */
    {
            string temp="temp";
            generateTemp(temp);
            st.insert(temp,"temp");
            SymbolInfo* n=st.uplook(temp);
            (yyvsp[-2])->value=(yyvsp[0])->value;
            n->code=(yyvsp[0])->code+"\n";
            n->code+="MOV AX, "+(yyvsp[0])->symbol+"\n";
            n->code+="MOV "+(yyvsp[-2])->symbol+" , AX;\n";
            
            (yyval)=n;
            varlist+=(yyval)->symbol+" dw 0\n";
            printf("statement--> variable ASSIGNOP expression\n");
            }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 209 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);
            printf("statement--> procedure_statement\n");
            }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 214 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);
            printf("statement--> compound_statement\n");
            
            }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 220 "yacc.y" /* yacc.c:1646  */
    {
            string temp="temp";
           generateTemp(temp);
        st.insert(temp,"temp");
        SymbolInfo *n=st.uplook(temp);
        SymbolInfo *b=(yyvsp[-2]);
        n->code = b->code + b->TrueLabel + ":\n" + (yyvsp[0])->code + "\n" + b->FalseLabel +":\n";
        (yyval) = n;
            varlist+=(yyval)->symbol+" dw 0\n";
        
        
            printf("statement-->IF expression THEN statement\n");
            }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 235 "yacc.y" /* yacc.c:1646  */
    {
            string temp="temp";
            generateTemp(temp);
            st.insert(temp,"temp");
            SymbolInfo *n=st.uplook(temp);
            SymbolInfo *b=(yyvsp[-4]);
            
            string tempLabel="label";
            generateLabel(tempLabel);
            
            n->code = b->code + b->TrueLabel + ":\n" + (yyvsp[-2])->code + "\ngoto " + tempLabel + ";\n" + b->FalseLabel +":\n" + (yyvsp[0])->code + "\n" + tempLabel +":\n";
        (yyval) = n;
        varlist+=(yyval)->symbol+" dw 0\n";
        
            printf("statement-->IF expression THEN statement ELSE statement\n");
            
            }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 254 "yacc.y" /* yacc.c:1646  */
    {
            string beginLabel="label";
            generateLabel(beginLabel);
            string temp="temp";
            generateTemp(temp);
            st.insert(temp,"temp");
            SymbolInfo *n=st.uplook(temp);
            SymbolInfo *b=(yyvsp[-2]);
            
            n->code=beginLabel+":\n"+(yyvsp[-2])->code+(yyvsp[-2])->TrueLabel+":\n"+(yyvsp[0])->code+"goto " + beginLabel +";\n"+(yyvsp[-2])->FalseLabel;
                       (yyval) = n;
        varlist+=(yyval)->symbol+" dw 0\n";
            
            printf("statement--> WHILE expression DO statement\n");
            
            }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 272 "yacc.y" /* yacc.c:1646  */
    {
            printf("statement-->WRITE PAREN1 ID PAREN2");
            }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 277 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);
            printf("variable-->   ID\n");
            }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 282 "yacc.y" /* yacc.c:1646  */
    {
            printf("variable--> ID BRACKET1 expression BRACKET2\n");
            }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 287 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);
            printf("procedure_statement --> ID \n");
            }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 292 "yacc.y" /* yacc.c:1646  */
    {
            printf("procedure_statement --> ID PAREN1 expression_list PAREN2\n");
            }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 297 "yacc.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]);
            printf("expression_list:	expression\n");
            }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 302 "yacc.y" /* yacc.c:1646  */
    {
            printf("expression_list: expression_list COMMA expression\n");
            
            }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 308 "yacc.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]);
            printf("expression: simple_expression\n");
            }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 313 "yacc.y" /* yacc.c:1646  */
    {
            string temp="temp";
            generateTemp(temp);
            st.insert(temp,"temp");
            SymbolInfo* n=st.uplook(temp);
            
            n->code=(yyvsp[-2])->code+"\n"+(yyvsp[0])->code+"\n";
            string whatsign=(yyvsp[-1])->symbol;
            string compsignm;
            if(whatsign==">")compsignm="jg";
            else if(whatsign==">=")compsignm="jge";
            else if(whatsign=="<" || whatsign=="<>" )compsignm="jl";
            else if(whatsign=="<=")compsignm="jle";
            else if(whatsign=="==")compsignm="je";
            else if(whatsign=="!=")compsignm="jne";
            
            n->code+="push ax;\n push bx;\n";
            n->code+=("mov ax, " + (yyvsp[-2])->symbol+";\n");
            n->code+=("mov bx, " + (yyvsp[0])->symbol+";\n");
            n->code+=("cmp AX,BX;\n");
            
            
            string l1="label";
            generateLabel(l1);
            n->TrueLabel=l1;
            
            string l2="label";
            generateLabel(l2);
            n->FalseLabel=l2;
            
            n->code+=(compsignm + l1+";\n");
            n->code+=("jmp "+l2+";\n");
            n->code+="pop bx;\n pop ax;\n";
            
            (yyval)=n;
            varlist+=(yyval)->symbol+" dw 0\n";
            
            printf("expression: simple_expression RELOP simple_expression\n");
            }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 354 "yacc.y" /* yacc.c:1646  */
    {
            (yyval)=(yyvsp[0]);  
            printf("simple_expression -->term\n");
            }
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 360 "yacc.y" /* yacc.c:1646  */
    {
            string temp="temp";
            generateTemp(temp);
            st.insert(temp,"temp");
            SymbolInfo* n=st.uplook(temp);
            
            n->value=(yyvsp[0])->value;
            if((yyvsp[-1])->symbol=="-")
              {
              n->value*=-1;
              n->code="NEG "+(yyvsp[0])->symbol+"\n";
              }
            (yyval)=n;
            varlist+=(yyval)->symbol+" dw 0\n";
            printf("simple_expression --> sign term\n");
            }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 378 "yacc.y" /* yacc.c:1646  */
    {
            string temp="temp";
            generateTemp(temp);
            st.insert(temp,"temp");
            SymbolInfo* n=st.uplook(temp);
            n->code="\n"+(yyvsp[-2])->code+"\n"+(yyvsp[0])->code+"\n"+"MOV AX,"+(yyvsp[-2])->symbol+";\n"+"MOV BX,"+(yyvsp[0])->symbol+";\n";
            if((yyvsp[-1])->symbol=="+"){
            n->value=(yyvsp[-2])->value+(yyvsp[0])->value;
            n->code+="ADD AX,BX;\n";
            }
            else if  ((yyvsp[-1])->symbol=="-"){n->value=(yyvsp[-2])->value+(yyvsp[0])->value;
            n->code+="SUB AX,BX;\n";
            }
            (yyval)=n;
            varlist+=(yyval)->symbol+" dw 0\n";
            printf("simple_expression --> simple_expression ADDOP term \n");
            }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 397 "yacc.y" /* yacc.c:1646  */
    {
            (yyval)=(yyvsp[0]);
            printf("term-->factor\n");
            }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 403 "yacc.y" /* yacc.c:1646  */
    {
            string temp="temp";
            generateTemp(temp);
            st.insert(temp,"temp");
            SymbolInfo* n=st.uplook(temp);
            
            n->code="MOV AX, "+(yyvsp[-2])->symbol+";\n"; 
            if((yyvsp[-1])->symbol=="*"){n->value=(yyvsp[-2])->value*(yyvsp[0])->value;
            n->code+="MUL "+(yyvsp[0])->symbol+";\n";
            }
            else if((yyvsp[-1])->symbol=="/"){n->value=(yyvsp[-2])->value/(yyvsp[0])->value;
            n->code+="DIV "+(yyvsp[0])->symbol+";\n";
            
            }
            else if((yyvsp[-1])->symbol=="mod"){
            int x=((int)(yyvsp[-2])->value) %((int) (yyvsp[0])->value);
            n->value=x;
            n->code+="DIV "+(yyvsp[0])->symbol+";\n";
            
            }
            n->code+="MOV "+n->symbol+", AX;\n";
            (yyval)=n;
            varlist+=(yyval)->symbol+" dw 0\n";
            }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 429 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);
            printf("factor-->ID \n");
            }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 434 "yacc.y" /* yacc.c:1646  */
    {
            printf("factor--> ID PAREN1 expression_list PAREN2");
            }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 439 "yacc.y" /* yacc.c:1646  */
    {
            (yyval)=(yyvsp[0]);
            cout<<(yyvsp[0])->value<<endl;
            printf("factor-->NUM\n");
            }
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 446 "yacc.y" /* yacc.c:1646  */
    {
            string temp="temp";
            generateTemp(temp);
            st.insert(temp,"temp");
            
            SymbolInfo* n=st.uplook(temp);
            
            n=(yyvsp[-1]);
            (yyval)=n;
            varlist+=(yyval)->symbol+" dw 0\n";

            printf("factor --> PAREN1 expression PAREN2\n");
            }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 461 "yacc.y" /* yacc.c:1646  */
    {string temp="temp";
            generateTemp(temp);
            st.insert(temp,"temp");
            
            SymbolInfo* n=st.uplook(temp);
            
            n->value=~((int)(yyvsp[0])->value);
            (yyval)=n;
            varlist+=(yyval)->symbol+" dw 0\n";

            printf("factor-->NOT factor\n");
            }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 475 "yacc.y" /* yacc.c:1646  */
    {
            (yyval)=(yyvsp[0]);
            printf("sign--> ADDOP\n");
            }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1966 "y.tab.c" /* yacc.c:1646  */
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
#line 481 "yacc.y" /* yacc.c:1906  */

int main(int argc,char *argv[])
{
	if(argc!=4)
	{
		printf("Usage: ./<programname> <input_file>\n");
		printf("Try Again\n");
		exit(1);
	}

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}
	
	yyin=fp;
	freopen(argv[2], "w", stdout);
    ofstream fout( argv[3]);     
        
	yyparse();
	st.dump();
	fout<<wholecode<<endl;
     fout.close(); 
	return 0;
}

