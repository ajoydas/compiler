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
#line 2 "offline3.y" /* yacc.c:339  */

#include<bits/stdc++.h>
//#include "SymbolInfo.h"
#include "SymbolTable.h"
using namespace std;

#define YYSTYPE SymbolInfo*      /* yyparse() stack type */

ofstream fout("outputfile.txt");

extern SymbolTable* table = new SymbolTable(13);
int errorcount = 0;
extern int linecount;


string type;
string asmb = "", declaration = "";

void yyerror(string s){
	errorcount++;
	fout<<"Error Number "<<errorcount<<" "<<s<<" at line: "<<linecount;
	;
}

int labelCount=0;
int tempCount=0;

string newLabel()
{
	string lb="L";
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	lb+=b; //changed
	return lb;
}

string newTemp()
{
	string t = "t";
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	t+=b; //changed
	return t;
}


int yylex(void);


#line 118 "y.tab.c" /* yacc.c:339  */

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
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    INT = 262,
    FLOAT = 263,
    DOUBLE = 264,
    CHAR = 265,
    RETURN = 266,
    VOID = 267,
    MAIN = 268,
    PRINTLN = 269,
    ADDOP = 270,
    MULOP = 271,
    ASSIGNOP = 272,
    RELOP = 273,
    LOGICOP = 274,
    SEMICOLON = 275,
    COMMA = 276,
    LPAREN = 277,
    RPAREN = 278,
    LCURL = 279,
    RCURL = 280,
    LTHIRD = 281,
    RTHIRD = 282,
    INCOP = 283,
    DECOP = 284,
    CONST_INT = 285,
    CONST_FLOAT = 286,
    CONST_CHAR = 287,
    ID = 288,
    NOT = 289
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define INT 262
#define FLOAT 263
#define DOUBLE 264
#define CHAR 265
#define RETURN 266
#define VOID 267
#define MAIN 268
#define PRINTLN 269
#define ADDOP 270
#define MULOP 271
#define ASSIGNOP 272
#define RELOP 273
#define LOGICOP 274
#define SEMICOLON 275
#define COMMA 276
#define LPAREN 277
#define RPAREN 278
#define LCURL 279
#define RCURL 280
#define LTHIRD 281
#define RTHIRD 282
#define INCOP 283
#define DECOP 284
#define CONST_INT 285
#define CONST_FLOAT 286
#define CONST_CHAR 287
#define ID 288
#define NOT 289

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

#line 237 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   213

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    58,    58,    76,    81,    85,    92,    97,   103,   104,
     105,   108,   136,   172,   199,   238,   242,   250,   254,   258,
     272,   285,   301,   314,   321,   327,   334,   337,   346,   370,
     374,   442,   446,   499,   503,   595,   599,   722,   726,   903,
     920,   954,   960,   978,   982,   987,   992,   997,  1005
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "INT",
  "FLOAT", "DOUBLE", "CHAR", "RETURN", "VOID", "MAIN", "PRINTLN", "ADDOP",
  "MULOP", "ASSIGNOP", "RELOP", "LOGICOP", "SEMICOLON", "COMMA", "LPAREN",
  "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "INCOP", "DECOP",
  "CONST_INT", "CONST_FLOAT", "CONST_CHAR", "ID", "NOT", "$accept",
  "Program", "compound_statement", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor", YY_NULLPTR
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
     285,   286,   287,   288,   289
};
# endif

#define YYPACT_NINF -39

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-39)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,     0,    20,     1,   -39,     2,    11,    51,   -39,    14,
      15,    16,   -39,   -39,   -39,   174,    17,   174,   -39,   174,
     -39,   -39,   -39,   -39,    -2,   174,   -39,    83,     7,   115,
     -39,   -39,    25,    27,   -39,    30,    -9,    34,   -39,   -21,
     174,    -1,   174,    31,    19,   -39,   -39,    37,   174,   -39,
       7,   147,    38,    -5,    39,   -39,   174,   -39,   174,   174,
     174,   174,   -39,   -39,    47,    -1,    49,   -39,    54,   -39,
      52,    -3,   -39,    44,   -39,    45,   -39,   -39,   -39,    34,
      65,   -39,   179,   174,   179,    67,   -39,   -39,    68,    66,
      92,    76,   -39,   -39,   -39,    70,   179,   179,    74,   -39,
     -39,   -39
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     2,     0,
       0,     0,     8,     9,    10,     0,     0,     0,    25,     0,
       5,    44,    45,    46,    27,     0,    18,     0,     0,     0,
      15,    17,    42,     0,    29,    31,    33,    35,    37,    41,
       0,     0,     0,     0,     0,    42,    39,     0,     0,    40,
       0,     0,    13,     0,     0,    16,     0,    26,     0,     0,
       0,     0,    47,    48,     0,     0,     0,    24,     0,    43,
       0,     0,     3,     0,     6,     0,     4,    30,    32,    36,
      34,    38,     0,     0,     0,     0,    28,     7,     0,    11,
      20,     0,    22,    23,    14,     0,     0,     0,     0,    21,
      19,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,    96,   -39,    77,    56,    81,   -29,   -38,   -15,
     -14,    53,    61,    50,    63,   -13,   -39
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    26,    27,    28,    53,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      55,    43,    45,    65,    46,    47,    59,    62,    63,    60,
      45,     1,    49,     3,    17,    74,    75,    87,    75,    18,
       4,    19,    55,     5,    48,     6,    64,    83,    66,    21,
      22,    23,    24,    25,    70,     7,    40,    41,    42,    44,
      52,    45,    56,    45,    45,    45,    45,    57,    81,    58,
      61,    67,    68,    90,     9,    92,    10,    11,    12,    13,
      69,    14,    15,    76,    73,    16,    17,    99,   100,    91,
      82,    18,    84,    19,    88,     7,    20,    85,    89,    86,
      59,    21,    22,    23,    24,    25,     9,    93,    10,    11,
      12,    13,    95,    14,    15,    94,    96,    16,    17,    97,
      98,   101,     8,    18,    50,    19,    71,     7,    51,    77,
      80,     0,     0,    21,    22,    23,    24,    25,     9,    78,
      10,    11,    79,     0,     0,     0,    15,     0,     0,    16,
      17,     0,     0,     0,     0,    18,     0,    19,     0,     7,
      54,     0,     0,     0,     0,    21,    22,    23,    24,    25,
       9,     0,    10,    11,     0,     0,     0,     0,    15,     0,
       0,    16,    17,     0,     0,     0,     0,    18,     0,    19,
       0,     7,    72,     0,     0,     0,     0,    21,    22,    23,
      24,    25,     9,     0,    10,    11,     0,     0,     0,    17,
      15,     0,     0,    16,    17,     0,    19,     0,     0,    18,
       0,    19,     0,     7,    21,    22,    23,    24,    25,    21,
      22,    23,    24,    25
};

static const yytype_int8 yycheck[] =
{
      29,    15,    17,    41,    17,    19,    15,    28,    29,    18,
      25,     7,    25,    13,    15,    20,    21,    20,    21,    20,
       0,    22,    51,    22,    26,    23,    40,    65,    42,    30,
      31,    32,    33,    34,    48,    24,    22,    22,    22,    22,
      33,    56,    17,    58,    59,    60,    61,    20,    61,    19,
      16,    20,    33,    82,     3,    84,     5,     6,     7,     8,
      23,    10,    11,    24,    26,    14,    15,    96,    97,    83,
      23,    20,    23,    22,    30,    24,    25,    23,    33,    27,
      15,    30,    31,    32,    33,    34,     3,    20,     5,     6,
       7,     8,    26,    10,    11,    27,     4,    14,    15,    23,
      30,    27,     6,    20,    27,    22,    50,    24,    27,    56,
      60,    -1,    -1,    30,    31,    32,    33,    34,     3,    58,
       5,     6,    59,    -1,    -1,    -1,    11,    -1,    -1,    14,
      15,    -1,    -1,    -1,    -1,    20,    -1,    22,    -1,    24,
      25,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
       3,    -1,     5,     6,    -1,    -1,    -1,    -1,    11,    -1,
      -1,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,    22,
      -1,    24,    25,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,     3,    -1,     5,     6,    -1,    -1,    -1,    15,
      11,    -1,    -1,    14,    15,    -1,    22,    -1,    -1,    20,
      -1,    22,    -1,    24,    30,    31,    32,    33,    34,    30,
      31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    36,    13,     0,    22,    23,    24,    37,     3,
       5,     6,     7,     8,    10,    11,    14,    15,    20,    22,
      25,    30,    31,    32,    33,    34,    37,    38,    39,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      22,    22,    22,    45,    22,    44,    50,    45,    26,    50,
      39,    41,    33,    40,    25,    42,    17,    20,    19,    15,
      18,    16,    28,    29,    45,    43,    45,    20,    33,    23,
      45,    40,    25,    26,    20,    21,    24,    46,    47,    49,
      48,    50,    23,    43,    23,    23,    27,    20,    30,    33,
      42,    45,    42,    20,    27,    26,     4,    23,    30,    42,
      42,    27
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    37,    38,    38,    39,    39,
      39,    40,    40,    40,    40,    41,    41,    42,    42,    42,
      42,    42,    42,    42,    42,    43,    43,    44,    44,    45,
      45,    46,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    50,    51,    51,    51,    51,    51,    51,    51
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     2,     3,     4,     1,     1,
       1,     3,     6,     1,     4,     1,     2,     1,     1,     7,
       5,     7,     5,     5,     3,     1,     2,     1,     4,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     2,
       2,     1,     1,     3,     1,     1,     1,     2,     2
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
#line 58 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"Program : INT MAIN LPAREN RPAREN compound_statement"<<endl;
			//$$=$5;
			(yyval) = new SymbolInfo();
			asmb += ".model small\n.stack 100h\n.data\n"+declaration+"\n"+".code\n";
			asmb += "PRINTLN PROC\n@END_IF1:\nXOR CX,CX\nMOV BX,10D\n@REPEAT1:\nXOR DX,DX\nDIV BX\nPUSH DX\nINC CX\nOR AX,AX\nJNE @REPEAT1\nMOV AH,2\n@PRINT_LOOP:\nPOP DX\nOR DL,30H\nINT 21H\nLOOP @PRINT_LOOP\nRET\nPRINTLN ENDP\n";
			
			asmb += "\nmain proc\n";
			(yyval)->code += (yyvsp[0])->code;
			
			(yyval)->code += asmb;
			(yyval)->code += "\nmain endp\nend main\n";
			ofstream aout("code.asm");
			aout << (yyval)->code;
		}
#line 1415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 76 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"compound_statement : LCURL var_declaration statements RCURL"<<endl;
			(yyval)=(yyvsp[-1]);
			(yyval)->code=(yyvsp[-2])->code+(yyvsp[-1])->code;
		}
#line 1425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 81 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"compound_statement : LCURL statements RCURL LCURL "<<endl;
			(yyval)=(yyvsp[-2]);
		}
#line 1434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 85 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"compound_statement : LCURL RCURL "<<endl; 
			
		}
#line 1443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 92 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"var_declaration	: type_specifier declaration_list SEMICOLON "<<endl; 
			(yyval)=(yyvsp[-2]);
			(yyval)->code+=(yyvsp[0])->code;
		}
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 97 "offline3.y" /* yacc.c:1646  */
    {
			fout<<"var_declaration	: var_declaration type_specifier declaration_list SEMICOLON"<<endl; 
			(yyval)=(yyvsp[-2]);
		}
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 103 "offline3.y" /* yacc.c:1646  */
    { fout<<"type_specifier	: INT  "<<endl; type = "int"; }
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 104 "offline3.y" /* yacc.c:1646  */
    { fout<<"type_specifier	: FLOAT"<<endl; type = "float"; }
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 105 "offline3.y" /* yacc.c:1646  */
    { fout<<"type_specifier	: CHAR"<<endl; type = "char"; }
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 108 "offline3.y" /* yacc.c:1646  */
    { 
				fout<<"declaration_list : declaration_list COMMA ID"<<endl;
				fout<<(yyvsp[0])->Name<<endl;
				if(type == "int"){
					SymbolInfo* s = new SymbolInfo((yyvsp[0])->Name, "int");
					s->Token = "ID";
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "char"){
					SymbolInfo* s = new SymbolInfo((yyvsp[0])->Name, "int");
					s->Token = "ID";
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo((yyvsp[0])->Name, "int");
					s->Token = "ID";
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				
				
				declaration += "dw "+ (yyvsp[0])->Name+" ?\n";
			}
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 136 "offline3.y" /* yacc.c:1646  */
    { 
				fout<<"declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD"<<endl;
				fout<<(yyvsp[-3])->Name<<endl;
				if(type == "int"){
					SymbolInfo* s = new SymbolInfo((yyvsp[-3])->Name, "int");
					s->Token = "ID";
					s->arraysize = (yyvsp[-1])->ivalue;
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
					
				}
				if(type == "char"){
					SymbolInfo* s = new SymbolInfo((yyvsp[-3])->Name, "int");
					s->arraysize = (yyvsp[-1])->ivalue;
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
					
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo((yyvsp[-3])->Name, "int");
					s->Token = "ID";
					s->arraysize = (yyvsp[-1])->ivalue;
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				
				int l = (yyvsp[-3])->ivalue;
				declaration += "dw "+ (yyvsp[-5])->Name + "? ";
				for(int i =0; i<l; i++){
					declaration += ", ?";
				}
				declaration += "\n";
			}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 172 "offline3.y" /* yacc.c:1646  */
    {
				fout<<"declaration_list : ID"<<endl; 
				fout<<(yyvsp[0])->Name<<endl;
				if(type == "int"){
					SymbolInfo* s = new SymbolInfo((yyvsp[0])->Name, "int");
					s->Token = "ID";
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "char"){
					SymbolInfo* s = new SymbolInfo((yyvsp[0])->Name, "char");
					s->Token = "ID";
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo((yyvsp[0])->Name, "float");
					s->Token = "ID";
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				
				declaration += "dw "+ (yyvsp[0])->Name+" ?\n";
			}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 199 "offline3.y" /* yacc.c:1646  */
    { 
				fout<<"declaration_list : ID LTHIRD CONST_INT RTHIRD"<<endl;
				fout<<(yyvsp[-3])->Name<<endl;
				
				
				if(type == "int"){
					SymbolInfo* s = new SymbolInfo((yyvsp[-3])->Name, "int");
					s->Token = "ID";
					s->arraysize = (yyvsp[-1])->ivalue;
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "char"){
					SymbolInfo* s = new SymbolInfo((yyvsp[-3])->Name, "int");
					s->Token = "ID";
					s->arraysize = (yyvsp[-1])->ivalue;
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo((yyvsp[-3])->Name, "int");
					s->Token = "ID";
					s->arraysize = (yyvsp[-1])->ivalue;
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				
				int l = (yyvsp[-1])->ivalue;
				declaration += "dw "+ (yyvsp[-3])->Name + "? ";
				for(int i =0; i<l; i++){
					declaration += ", ?";
				}
				declaration += "\n";
			}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 238 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"statements : statement"<<endl; 
			(yyval)=(yyvsp[0]);
		}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 242 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"statements : statements statement"<<endl; 
			(yyval)=(yyvsp[-1]);
			(yyval)->code += (yyvsp[0])->code;
		}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 250 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"statement  : expression_statement"<<endl; 
			(yyval)=(yyvsp[0]);
		}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 254 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"statement  : compound_statement"<<endl; 
			(yyval)=(yyvsp[0]);
		}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 258 "offline3.y" /* yacc.c:1646  */
    {
			fout<<"statement  : FOR LPAREN expression_statement expression_statement expression RPAREN statement"<<endl;
			(yyval)=(yyvsp[-4]);
			string lebel1 = newLabel();
			string lebel2 = newLabel();
			
			(yyval)->code += lebel1;
			(yyval)->code += (yyvsp[-3])->code;
			(yyval)->code += "cmp "+(yyvsp[-3])->Name+", 1\n";
			(yyval)->code += "jne "+lebel2+"\n";
			(yyval)->code += (yyvsp[0])->code;
			(yyval)->code += (yyvsp[-2])->code;
			(yyval)->code += lebel2+":\n";
		}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 272 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"statement  : IF LPAREN expression RPAREN statement"<<endl; 
			(yyval)=(yyvsp[-2]);
					
			string label=newLabel();
			(yyval)->code+="mov ax, "+(yyvsp[-2])->Name+"\n";
			(yyval)->code+="cmp ax, 0\n";
			(yyval)->code+="je "+label+"\n";
			(yyval)->code+=(yyvsp[0])->code;
			(yyval)->code+=label+":\n";
			
			(yyval)->Name = "if";//not necessary
		}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 285 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"statement  : IF LPAREN expression RPAREN statement ELSE statement"<<endl; 
			(yyval)=(yyvsp[-4]);
					
			string label1=newLabel();
			string label2=newLabel();
			(yyval)->code+="mov ax, "+(yyvsp[-4])->Name+"\n";
			(yyval)->code+="cmp ax, 0\n";
			(yyval)->code+="je "+label1+"\n";
			(yyval)->code+=(yyvsp[-2])->code;
			(yyval)->code+="jmp " + label2+"\n";
			(yyval)->code+=label1+":\n";
			(yyval)->code+=(yyvsp[0])->code;
			(yyval)->code+=label2+":\n";
			
		}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 301 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"statement  : WHILE LPAREN expression RPAREN statement "<<endl; 
			string lebel1 = newLabel();
			string lebel2 = newLabel();
			
			(yyval)->code += (yyvsp[-2])->code;
			(yyval)->code += lebel1;
			(yyval)->code += "cmp "+(yyvsp[-2])->Name+", 1\n";
			(yyval)->code += "jne "+lebel2+"\n";
			(yyval)->code += (yyvsp[0])->code;
			(yyval)->code += "jmp "+lebel1+"\n";
			(yyval)->code += lebel2+":\n";
		}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 314 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"statement  : PRINTLN LPAREN ID RPAREN SEMICOLON "<<endl; 
			(yyval)=new SymbolInfo();
			(yyval)->code += (yyvsp[-2])->code;
			(yyval)->code += "mov ax, "+(yyvsp[-2])->Name+"\n";
			(yyval)->code += "call PRINTLN\n";
		}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 321 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"statement  : RETURN expression SEMICOLON "<<endl; 
			(yyval)=(yyvsp[-2]);
		}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 327 "offline3.y" /* yacc.c:1646  */
    {
				fout<<"expression_statement	: SEMICOLON"<<endl;
				(yyval)=new SymbolInfo();
				(yyval)->Name = ";";
				(yyval)->Token = "SEMICOLON";
				(yyval)->code="";
			}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 334 "offline3.y" /* yacc.c:1646  */
    { fout<<"expression_statement	: expression SEMICOLON"<<endl; (yyval)=(yyvsp[-1]);}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 337 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"variable : ID"<<endl;
			SymbolInfo* temp = table->searchTable((yyvsp[0])->Name);
			//cout<<"Found Variable Name: "<<temp->Name<<" Token: "<<temp->Token<<" iValue: "<<temp->ivalue<<" Datatype: "<<temp->datatype<<endl;
			if (temp == 0){
				yyerror("Undeclared variable! ");
			}
			else (yyval) = temp;
		}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 346 "offline3.y" /* yacc.c:1646  */
    {
			fout<<"variable : ID LTHIRD expression RTHIRD "<<endl;
			fout<<(yyvsp[-3])->Name<<endl;
			SymbolInfo* temp = table->searchTable((yyvsp[-3])->Name);
			if (temp == 0){
				yyerror("Undeclared variable! ");
			}
			else{
				fout<<"Array index: "<<(yyvsp[-1])->ivalue<<endl;
				if(temp != 0){
					if((yyvsp[-1])->ivalue >= temp->arraysize){
						yyerror("Array size overbound\n");
					}
					else {
						(yyval) = temp->array[(yyvsp[-1])->ivalue];
						(yyval)->arrIndexHolder=(yyvsp[-1])->Name;
						(yyval)->code=(yyvsp[-1])->code;
						fout<<"Array index insert: "<<(yyval)->ivalue<<endl;
					}
				}
			}
		}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 370 "offline3.y" /* yacc.c:1646  */
    {
			fout<<"expression : logic_expression"<<endl; 
			(yyval) = (yyvsp[0]);
		}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 374 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"expression : variable ASSIGNOP logic_expression"<<endl;
			//Print the symboltable here
			
			//cout<<"Value of logic expression: "<<$3->ivalue<<" type: "<<$3->datatype<<endl;
			SymbolInfo *s = new SymbolInfo();
			if((yyvsp[-2])->datatype == "int"){
				if((yyvsp[0])->datatype == "int"){
					(yyvsp[-2])->ivalue = (yyvsp[0])->ivalue;
				}
				if((yyvsp[0])->datatype == "float"){
					(yyvsp[-2])->ivalue = (yyvsp[0])->fvalue;
				}
				if((yyvsp[0])->datatype == "char"){
					(yyvsp[-2])->ivalue = (yyvsp[0])->c;
				}
				s->ivalue = (yyvsp[-2])->ivalue;
			}
			else if((yyvsp[-2])->datatype == "float"){
				if((yyvsp[0])->datatype == "int"){
					(yyvsp[-2])->fvalue = (yyvsp[0])->ivalue;
				}
				if((yyvsp[0])->datatype == "float"){
					(yyvsp[-2])->fvalue = (yyvsp[0])->fvalue;
				}
				if((yyvsp[0])->datatype == "char"){
					(yyvsp[-2])->fvalue = (yyvsp[0])->c;
				}
				s->fvalue = (yyvsp[-2])->fvalue;
			}
			else if((yyvsp[-2])->datatype == "char"){
				if((yyvsp[0])->datatype == "int"){
					(yyvsp[-2])->c = (yyvsp[0])->ivalue;
				}
				if((yyvsp[0])->datatype == "float"){
					(yyvsp[-2])->c = (yyvsp[0])->fvalue;
				}
				if((yyvsp[0])->datatype == "char"){
					(yyvsp[-2])->c = (yyvsp[0])->c;
				}
				s->c = (yyvsp[-2])->c;
			}
			
			s->code = (yyvsp[-2])->code;
			s->Name = (yyvsp[-2])->Name;
			s->Token = (yyvsp[-2])->Token; //Problem!!
			
			(yyval) = (yyvsp[-2]);
			(yyval)->code +=(yyvsp[0])->code+(yyvsp[-2])->code;
			(yyval)->code+="mov ax, "+(yyvsp[0])->Name+"\n";
			if((yyval)->arrIndexHolder==""){ //actualy it is more appropriate to use arrayLength to make decision
				(yyval)->code+= "mov "+(yyvsp[-2])->Name+", ax\n";
			}
			
			else{
				(yyval)->code+="lea di, " + (yyvsp[-2])->Name+"\n";
				for(int i=0;i<2;i++){
					(yyval)->code += "add di, " + (yyvsp[-2])->arrIndexHolder +"\n";
				}
				(yyval)->code+= "mov [di], ax\n";
				(yyval)->arrIndexHolder="";
			}
				
			/*cout<<"While assigning: "<<$1->Name<<" Token: "<<$1->Token<<" iValue: "<<$1->ivalue<<" Datatype: "<<$1->datatype<<endl;*/
			table->printTable(fout);
		}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 442 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"logic_expression : rel_expression"<<endl;
			(yyval) = (yyvsp[0]);
		}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 446 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"logic_expression : rel_expression LOGICOP rel_expression "<<endl;
			SymbolInfo* s = new SymbolInfo();
			string temp = newTemp();
			string label1 = newLabel();
			string label2 = newLabel();
			string label3 = newLabel();
			s->datatype = "int";
			
			s->code += (yyvsp[-2])->code;
			s->code += (yyvsp[0])->code;
			
			float f1, f2;
			if((yyvsp[-2])->datatype == "int"){
				f1 = (yyvsp[-2])->ivalue;
			}
			else if((yyvsp[-2])->datatype == "float"){
				f1 = (yyvsp[-2])->fvalue;
			}
			else if((yyvsp[-2])->datatype == "char"){
				f1 = (yyvsp[-2])->c;
			}
			
			if((yyvsp[0])->datatype == "int"){
				f2 = (yyvsp[0])->ivalue;
			}
			else if((yyvsp[0])->datatype == "float"){
				f2 = (yyvsp[0])->fvalue;
			}
			else if((yyvsp[0])->datatype == "char"){
				f2 = (yyvsp[0])->c;
			}
			(yyval) = s;
			(yyval)->code +="mov ax, " + (yyvsp[-2])->Name +"\n";
			(yyval)->code +="mov bx, " + (yyvsp[0])->Name +"\n";
			
			if((yyvsp[-1])->Name == "&&"){
				(yyval)->ivalue = f1&&f2;
				//
				(yyval)->code += "cmp ax, 0\nje "+label1+"cmp bx, 0\nje "+label1;
				(yyval)->code += label2+":\nmov "+ temp+", 1\njmp "+label3;
				(yyval)->code += label1+":\nmov "+ temp+", 0\n";
			}
			else if ((yyvsp[-1])->Name == "||"){
				(yyval)->ivalue = f1||f2;
				(yyval)->code += "cmp ax, 0\njne "+label1+"cmp bx, 0\njne "+label1;
				(yyval)->code += label2+":\nmov "+ temp+", 0\njmp "+label3;
				(yyval)->code += label1+":\nmov "+ temp+", 1\n";
			}
			(yyval)->Name = temp;
		}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 499 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"rel_expression	: simple_expression"<<endl;
			(yyval) = (yyvsp[0]);
		}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 503 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"rel_expression	: simple_expression RELOP simple_expression	"<<endl; 
			SymbolInfo* s = new SymbolInfo();
			string temp = newTemp();
			
			s->datatype = "int";
			if((yyvsp[-1])->Name == "=="){
				if((yyvsp[-2]) == (yyvsp[-1])){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if((yyvsp[-1])->Name == "!="){
				if((yyvsp[-2]) != (yyvsp[-1])){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if((yyvsp[-1])->Name == ">"){
				if((yyvsp[-2]) > (yyvsp[-1])){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if((yyvsp[-1])->Name == "<"){
				if((yyvsp[-2]) < (yyvsp[-1])){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if((yyvsp[-1])->Name == ">="){
				if((yyvsp[-2]) >= (yyvsp[-1])){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if((yyvsp[-1])->Name == "<="){
				if((yyvsp[-2]) <= (yyvsp[-1])){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else fout<<"Relational operator error"<<endl;
			(yyval) = s;
			
			(yyval)->code +=(yyvsp[-2])->code;
			(yyval)->code+=(yyvsp[0])->code;
			(yyval)->code+="mov ax, " + (yyvsp[-2])->Name+"\n";
			(yyval)->code+="cmp ax, " + (yyvsp[0])->Name+"\n";
			
			string label1=newLabel();
			string label2=newLabel();
			
			if((yyvsp[-1])->Name == "<"){
				(yyval)->code+="jl " + label1+"\n";
			}
			else if((yyvsp[-1])->Name == "<="){
				(yyval)->code+="jle " + label1+"\n";
			}
			else if((yyvsp[-1])->Name == ">"){
				(yyval)->code+="jg " + label1+"\n";
			}
			else if((yyvsp[-1])->Name == ">="){
				(yyval)->code+="jge " + label1+"\n";
			}
			else if((yyvsp[-1])->Name == "=="){
				(yyval)->code+="je " + label1+"\n";
			}
			else{
				(yyval)->code+="jne " + label1+"\n";
			}
			
			(yyval)->code+="mov "+temp +", 0\n";
			(yyval)->code+="jmp "+label2 +"\n";
			(yyval)->code+=label1+":\nmov "+string(temp)+", 1\n";
			(yyval)->code+=label2+":\n";
			(yyval)->Name =temp;
		}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 595 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"simple_expression : term"<<endl;
			(yyval) = (yyvsp[0]);
		}
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 599 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"simple_expression : simple_expression ADDOP term  "<<endl;
			SymbolInfo* s = new SymbolInfo();
			string temp = newTemp();
			
			if((yyvsp[-1])->Name == "+"){
				if((yyvsp[-2])->datatype == "int" && (yyvsp[0])->datatype == "int"){
					s->ivalue = (yyvsp[-2])->ivalue + (yyvsp[0])->ivalue;
					s->datatype = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "int" && (yyvsp[0])->datatype == "float"){
					s->fvalue = (yyvsp[-2])->ivalue + (yyvsp[0])->fvalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "float" && (yyvsp[0])->datatype == "int"){
					s->fvalue = (yyvsp[-2])->fvalue + (yyvsp[0])->ivalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "float" && (yyvsp[0])->datatype == "float"){
					s->fvalue = (yyvsp[-2])->fvalue + (yyvsp[0])->fvalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "char" && (yyvsp[0])->datatype == "char"){
					s->ivalue = (yyvsp[-2])->c + (yyvsp[0])->c;
					s->datatype = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "char" && (yyvsp[0])->datatype == "int"){
					s->ivalue = (yyvsp[-2])->c + (yyvsp[0])->ivalue;
					s->datatype = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "int" && (yyvsp[0])->datatype == "char"){
					s->ivalue = (yyvsp[-2])->ivalue + (yyvsp[0])->c;
					s->datatype = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "char" && (yyvsp[0])->datatype == "float"){
					s->fvalue = (yyvsp[-2])->c + (yyvsp[0])->fvalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "float" && (yyvsp[0])->datatype == "char"){
					s->fvalue = (yyvsp[-2])->fvalue + (yyvsp[0])->c;
					s->datatype = "float";
					(yyval) = s;
				}
				else {
					fout<<"Incompatible addition"<<endl;
				}
				
			}
			else if((yyvsp[-1])->Name == "-"){
				if((yyvsp[-2])->datatype == "int" && (yyvsp[0])->datatype == "int"){
					s->ivalue = (yyvsp[-2])->ivalue - (yyvsp[0])->ivalue;
					s->datatype = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "int" && (yyvsp[0])->datatype == "float"){
					s->fvalue = (yyvsp[-2])->ivalue - (yyvsp[0])->fvalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "float" && (yyvsp[0])->datatype == "int"){
					s->fvalue = (yyvsp[-2])->fvalue - (yyvsp[0])->ivalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "float" && (yyvsp[0])->datatype == "float"){
					s->fvalue = (yyvsp[-2])->fvalue - (yyvsp[0])->fvalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "char" && (yyvsp[0])->datatype == "char"){
					s->ivalue = (yyvsp[-2])->c - (yyvsp[0])->c;
					s->datatype = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "char" && (yyvsp[0])->datatype == "int"){
					s->ivalue = (yyvsp[-2])->c - (yyvsp[0])->ivalue;
					s->datatype = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "int" && (yyvsp[0])->datatype == "char"){
					s->ivalue = (yyvsp[-2])->ivalue - (yyvsp[0])->c;
					s->datatype = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "char" && (yyvsp[0])->datatype == "float"){
					s->fvalue = (yyvsp[-2])->c - (yyvsp[0])->fvalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "float" && (yyvsp[0])->datatype == "char"){
					s->fvalue = (yyvsp[-2])->fvalue - (yyvsp[0])->c;
					s->datatype = "float";
					(yyval) = s;
				}
				else {
					fout<<"Incompatible addition"<<endl;
				}
			}
			
			(yyval)->code += (yyvsp[-2])->code;
			(yyval)->code+=(yyvsp[0])->code;
			
			if((yyvsp[-1])->Name == "+"){
				(yyval)->code += "MOV AX, " + (yyvsp[-2])->Name + "\n";
				(yyval)->code += "ADD AX, " + (yyvsp[0])->Name + "\n";
				(yyval)->code += "MOV "+ (yyvsp[-2])->Name + ", AX\n";
			}
			else {
				(yyval)->code += "MOV AX, " + (yyvsp[-2])->Name + "\n";
				(yyval)->code += "SUB AX, " + (yyvsp[0])->Name + "\n";
				(yyval)->code += "MOV "+ (yyvsp[-2])->Name + ", AX\n";
			}
		}
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 722 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"term : unary_expression"<<endl; 
			(yyval) = (yyvsp[0]);
		}
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 726 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"term :	term MULOP unary_expression "<<endl;
			SymbolInfo* s = new SymbolInfo();
			string temp = newTemp();
			
			if((yyvsp[-1])->Name == "*"){
				if((yyvsp[-2])->datatype == "int" && (yyvsp[0])->datatype == "int"){
					s->ivalue = (yyvsp[-2])->ivalue * (yyvsp[0])->ivalue;
					s->datatype = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "int" && (yyvsp[0])->datatype == "float"){
					s->fvalue = (yyvsp[-2])->ivalue * (yyvsp[0])->fvalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "float" && (yyvsp[0])->datatype == "int"){
					s->fvalue = (yyvsp[-2])->fvalue * (yyvsp[0])->ivalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "float" && (yyvsp[0])->datatype == "float"){
					s->fvalue = (yyvsp[-2])->fvalue * (yyvsp[0])->fvalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "char" && (yyvsp[0])->datatype == "char"){
					s->ivalue = (yyvsp[-2])->c * (yyvsp[0])->c;
					s->datatype = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "char" && (yyvsp[0])->datatype == "int"){
					s->ivalue = (yyvsp[-2])->c * (yyvsp[0])->ivalue;
					s->datatype = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "int" && (yyvsp[0])->datatype == "char"){
					s->ivalue = (yyvsp[-2])->ivalue * (yyvsp[0])->c;
					s->datatype = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "char" && (yyvsp[0])->datatype == "float"){
					s->fvalue = (yyvsp[-2])->c * (yyvsp[0])->fvalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "float" && (yyvsp[0])->datatype == "char"){
					s->fvalue = (yyvsp[-2])->fvalue * (yyvsp[0])->c;
					s->datatype = "float";
					(yyval) = s;
				}
				else {
					fout<<"Incompatible Multiplication"<<endl;
				}
				
			}
			else if((yyvsp[-1])->Name == "/"){
				if((yyvsp[-2])->datatype == "int" && (yyvsp[0])->datatype == "int"){
					s->ivalue = (yyvsp[-2])->ivalue / (yyvsp[0])->ivalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "int" && (yyvsp[0])->datatype == "float"){
					s->fvalue = (yyvsp[-2])->ivalue / (yyvsp[0])->fvalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "float" && (yyvsp[0])->datatype == "int"){
					s->fvalue = (yyvsp[-2])->fvalue / (yyvsp[0])->ivalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "float" && (yyvsp[0])->datatype == "float"){
					s->fvalue = (yyvsp[-2])->fvalue / (yyvsp[0])->fvalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "char" && (yyvsp[0])->datatype == "char"){
					s->ivalue = (yyvsp[-2])->c / (yyvsp[0])->c;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "char" && (yyvsp[0])->datatype == "int"){
					s->ivalue = (yyvsp[-2])->c / (yyvsp[0])->ivalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "int" && (yyvsp[0])->datatype == "char"){
					s->ivalue = (yyvsp[-2])->ivalue / (yyvsp[0])->c;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "char" && (yyvsp[0])->datatype == "float"){
					s->fvalue = (yyvsp[-2])->c / (yyvsp[0])->fvalue;
					s->datatype = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "float" && (yyvsp[0])->datatype == "char"){
					s->fvalue = (yyvsp[-2])->fvalue / (yyvsp[0])->c;
					s->datatype = "float";
					(yyval) = s;
				}
				else {
					fout<<"Incompatible Division"<<endl;
				}
				
			}
			//mod
			else if((yyvsp[-1])->Name == "%"){
				if((yyvsp[-2])->datatype == "int" && (yyvsp[0])->datatype == "int"){
					s->ivalue = (yyvsp[-2])->ivalue % (yyvsp[0])->ivalue;
					s->datatype = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "int" && (yyvsp[0])->datatype == "float"){
					fout<<"Warning! Cannot take mod of float or with a float"<<endl;
				}
				else if((yyvsp[-2])->datatype == "float" && (yyvsp[0])->datatype == "int"){
					fout<<"Warning! Cannot take mod of float or with a float"<<endl;
				}
				else if((yyvsp[-2])->datatype == "float" && (yyvsp[0])->datatype == "float"){
					fout<<"Warning! Cannot take mod of float or with a float"<<endl;
				}
				else if((yyvsp[-2])->datatype == "char" && (yyvsp[0])->datatype == "char"){
					s->ivalue = (yyvsp[-2])->c % (yyvsp[0])->c;
					s->datatype = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "char" && (yyvsp[0])->datatype == "int"){
					s->ivalue = (yyvsp[-2])->c % (yyvsp[0])->ivalue;
					s->datatype = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "int" && (yyvsp[0])->datatype == "char"){
					s->ivalue = (yyvsp[-2])->ivalue % (yyvsp[0])->c;
					s->datatype = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->datatype == "char" && (yyvsp[0])->datatype == "float"){
					fout<<"Warning! Cannot take mod of float or with a float"<<endl;
				}
				else if((yyvsp[-2])->datatype == "float" && (yyvsp[0])->datatype == "char"){
					fout<<"Warning! Cannot take mod of float or with a float"<<endl;
				}
				else {
					fout<<"Incompatible Modulation"<<endl;
				}
				
			}
			
			(yyval)->code += (yyvsp[-2])->code;
			(yyval)->code += (yyvsp[0])->code;
			
			(yyval)->code += "mov ax, "+ (yyvsp[-2])->Name+"\n";
			(yyval)->code += "mov bx, "+ (yyvsp[0])->Name +"\n";
			
			if((yyvsp[-1])->Name == "*"){
				(yyval)->code += "mul bx\n";
				(yyval)->code += "mov "+ temp + ", ax\n";
			}
			else if((yyvsp[-1])->Name == "/"){
				// clear dx, perform 'div bx' and mov ax to temp
				(yyval)->code += "MOV DX, 0\n";
				(yyval)->code += "DIV BX\n";
				(yyval)->code += "MOV "+temp+", ax\n";
			}
			else if((yyvsp[-1])->Name == "%"){
				// clear dx, perform 'div bx' and mov dx to temp
				(yyval)->code += "MOV DX, 0\n";
				(yyval)->code += "DIV BX\n";
				(yyval)->code += "MOV "+temp+", dx\n";
			}
			(yyval)->Name = temp;
			
		}
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 903 "offline3.y" /* yacc.c:1646  */
    { 
				fout<<"unary_expression :  ADDOP unary_expression"<<endl; 
				if((yyvsp[0])->Name == "+"){
					(yyval) = (yyvsp[0]);
				}
				else if((yyvsp[0])->Name == "-"){
					if(type == "int"){
						(yyval)->ivalue = (yyvsp[0])->ivalue * -1;
					}
					else if(type == "char"){
						(yyval)->c = (yyvsp[0])->c * -1; //some cases are unhandled
					}
					else if(type == "float"){
						(yyval)->fvalue = (yyvsp[0])->fvalue * -1;
					}
				}
			}
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 920 "offline3.y" /* yacc.c:1646  */
    { 
				fout<<"unary_expression : NOT unary_expression"<<endl; 
				SymbolInfo* temp = new SymbolInfo();
				if(type == "int"){
					if((yyvsp[0])->ivalue) {
						temp->ivalue = 0;
					}
					else{
						temp->ivalue = 1;
					}
				}
				else if(type == "char"){
					if((yyvsp[0])->c) {
						temp->ivalue = 0;
					}
					else{
						temp->ivalue = 1;
					}
				}
				else if(type == "float"){
					if((yyvsp[0])->fvalue) {
						temp->ivalue = 0;
					}
					else{
						temp->ivalue = 1;
					}
				}
				(yyval) = temp;
				string t=newTemp();
				(yyval)->code="mov AX, " + (yyvsp[0])->Name + "\n";
				(yyval)->code+="NOT AX\n";
				(yyval)->code+="MOV "+ t +", AX\n";
				(yyval)->Name = t;
			}
#line 2455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 954 "offline3.y" /* yacc.c:1646  */
    { 
				fout<<"unary_expression : factor"<<endl; 
				(yyval) = (yyvsp[0]);
			}
#line 2464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 960 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"factor	: variable"<<endl; 
			(yyval)=(yyvsp[0]);
			
			if((yyval)->arrIndexHolder!=""){//actualy it is better use arrayLength to make decision
				(yyval)->code+="lea di, " + string((yyvsp[0])->Name)+"\n";
				
				(yyval)->code += "add di, " + (yyvsp[0])->arrIndexHolder +"\n";
				(yyval)->code += "add di, " + (yyvsp[0])->arrIndexHolder +"\n";
				
				string temp = newTemp();
				(yyval)->code+= "MOV AX, [di]\n";
				(yyval)->code+= "MOV " + temp + ", AX\n";
				(yyval)->Name = temp;
				(yyval)->arrIndexHolder="";
			}
			cout << endl;
		}
#line 2487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 978 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"factor	: LPAREN expression RPAREN"<<endl;
			(yyval) = (yyvsp[-1]);
		}
#line 2496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 982 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"factor	: CONST_INT"<<endl; 
			fout<<(yyvsp[0])->ivalue<<endl;
			(yyval) = (yyvsp[0]);
		}
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 987 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"factor	: CONST_FLOAT"<<endl;
			fout<<(yyvsp[0])->fvalue<<endl;
			(yyval) = (yyvsp[0]);
		}
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 992 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"factor	: CONST_CHAR "<<endl;
			fout<<(yyvsp[0])->c<<endl;
			(yyval) = (yyvsp[0]);
		}
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 997 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"factor	: factor INCOP"<<endl;
			if(type == "int"){
				(yyvsp[-1])->ivalue++;
			}
			(yyval) = (yyvsp[-1]);
			(yyval)->code += "INC " + string((yyvsp[-1])->Name) + "\n";
		}
#line 2539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1005 "offline3.y" /* yacc.c:1646  */
    { 
			fout<<"factor	: factor DECOP"<<endl; 
			if(type == "int"){
				(yyvsp[-1])->ivalue--;
			}
			(yyval) = (yyvsp[-1]);
			(yyval)->code += "DEC " + string((yyvsp[-1])->Name) + "\n";
		}
#line 2552 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2556 "y.tab.c" /* yacc.c:1646  */
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
#line 1014 "offline3.y" /* yacc.c:1906  */


main()
{
	freopen("input1.txt", "r", stdin);
    yyparse();
    exit(0);
}
