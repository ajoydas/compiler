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
#line 2 "1405079.y" /* yacc.c:339  */

#include<bits/stdc++.h>
#include "SymbolTable.h"
#define YYSTYPE SymbolInfo*
using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;

FILE *logout;
FILE *error;
FILE *symtable;
FILE *codes;
FILE *optimized;
bool symtabprint=false;
SymbolTable* table = new SymbolTable(7,1);

int errorcount = 0;
extern int line_count;

string type;
string functype;
Function *fn=NULL;
Function *fn2=NULL;
vector<SymbolInfo> params,args;
bool paramerr=false;

void yyerror(string s){
	errorcount++;
fprintf(error,"Error at Line %d: %s \n\n",line_count,s.c_str());
fprintf(logout,"Error at Line %d: %s \n\n",line_count,s.c_str());
}
//Assembly Portion
string asmb = "";
string declaration = "";

int labelCount=0;
int tempCount=0;
string funcName="";
int funcId=0;
char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	strcat(t,b);
	return t;
}

string newAdd(string s,int i)
{
	ostringstream oss;
	oss<<s<<i;
	return oss.str();
}

void optimize(char *s)
{
	//printf ("Splitting string \"%s\" into tokens:\n",s);
	char *end_str;
	char *token =strtok_r(s, "\n", &end_str);
	bool prev=false;
	while (token != NULL)
	{
		char *end_token,*reg1,*reg2,*reg3,*reg4;
		printf("%s\n", token);
		char *saved=(char*)malloc(sizeof(char) * (strlen(token)+1));
		strcpy(saved,token);

		char *token2 = strtok_r(token, " ", &end_token);
		printf("%s\n", token2);
		if(!strcmp(token2,"mov"))
		{
			printf("Mov found = %s\n", token2);
			reg3 = strtok_r(NULL, ",", &end_token);
			reg4 = end_token;
			printf("Reg3 = %s Reg4 = %s\n\n", reg3,reg4);
			if(prev && !strcmp(reg1,reg4) &&!strcmp(reg2,reg3))
			{
				printf("Match found\n");
				fprintf(optimized,"mov %s,%s\n",reg1,reg2);
				prev=false;
			}
			else
			{
				//cout<<"####1"<<endl;
				if(prev){
				fprintf(optimized,"mov %s,%s\n",reg1,reg2);
				}
                //cout<<"####2"<<endl;
				prev=true;
                reg1=reg3;
                reg2=reg4;
			}
		}
        else {
                 if(prev)
                 {
                    fprintf(optimized,"mov %s,%s\n",reg1,reg2);
                 }
                prev=false;
                fprintf(optimized,"%s\n",saved);
            }
		token = strtok_r(NULL, "\n", &end_str);
	}
}


#line 189 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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
    FOR = 259,
    DO = 260,
    INT = 261,
    FLOAT = 262,
    VOID = 263,
    SWITCH = 264,
    DEFAULT = 265,
    ELSE = 266,
    WHILE = 267,
    BREAK = 268,
    RETURN = 269,
    CASE = 270,
    CONTINUE = 271,
    PRINTLN = 272,
    CONST_INT = 273,
    CONST_FLOAT = 274,
    ID = 275,
    ADDOP = 276,
    MULOP = 277,
    INCOP = 278,
    DECOP = 279,
    RELOP = 280,
    ASSINOP = 281,
    LOGICOP = 282,
    NOT = 283,
    LPAREN = 284,
    RPAREN = 285,
    LCURL = 286,
    RCURL = 287,
    LTHIRD = 288,
    RTHIRD = 289,
    COMMA = 290,
    SEMICOLON = 291,
    SINGLECOM = 292,
    MULTICOM = 293,
    only_if = 294
  };
#endif
/* Tokens.  */
#define IF 258
#define FOR 259
#define DO 260
#define INT 261
#define FLOAT 262
#define VOID 263
#define SWITCH 264
#define DEFAULT 265
#define ELSE 266
#define WHILE 267
#define BREAK 268
#define RETURN 269
#define CASE 270
#define CONTINUE 271
#define PRINTLN 272
#define CONST_INT 273
#define CONST_FLOAT 274
#define ID 275
#define ADDOP 276
#define MULOP 277
#define INCOP 278
#define DECOP 279
#define RELOP 280
#define ASSINOP 281
#define LOGICOP 282
#define NOT 283
#define LPAREN 284
#define RPAREN 285
#define LCURL 286
#define RCURL 287
#define LTHIRD 288
#define RTHIRD 289
#define COMMA 290
#define SEMICOLON 291
#define SINGLECOM 292
#define MULTICOM 293
#define only_if 294

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

#line 318 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   148

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   136,   136,   157,   164,   178,   184,   191,   203,   251,
     300,   299,   425,   424,   547,   555,   561,   569,   578,   577,
     607,   606,   628,   635,   636,   637,   643,   690,   757,   801,
     863,   869,   880,   884,   888,   892,   907,   919,   935,   950,
     964,   974,   982,   989,   997,  1021,  1074,  1079,  1153,  1158,
    1220,  1224,  1325,  1329,  1411,  1416,  1526,  1554,  1592,  1598,
    1614,  1675,  1679,  1690,  1701,  1715,  1732,  1736,  1743,  1755
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "FOR", "DO", "INT", "FLOAT",
  "VOID", "SWITCH", "DEFAULT", "ELSE", "WHILE", "BREAK", "RETURN", "CASE",
  "CONTINUE", "PRINTLN", "CONST_INT", "CONST_FLOAT", "ID", "ADDOP",
  "MULOP", "INCOP", "DECOP", "RELOP", "ASSINOP", "LOGICOP", "NOT",
  "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA",
  "SEMICOLON", "SINGLECOM", "MULTICOM", "only_if", "$accept", "start",
  "program", "unit", "func_declaration", "func_definition", "$@1", "$@2",
  "parameter_list", "compound_statement", "$@3", "@4", "var_declaration",
  "type_specifier", "declaration_list", "statements", "statement",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -76

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-76)))

#define YYTABLE_NINF -21

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      49,   -76,   -76,   -76,     3,    49,   -76,   -76,   -76,   -76,
       2,   -76,   -76,   -13,    23,     7,    10,    16,   -76,     5,
     -12,    26,    17,    20,   -76,    31,    32,    49,   -76,   -76,
      53,    43,   -76,   -76,    31,    56,    45,   100,    50,   -76,
     -76,   -76,    41,    52,    59,    64,    71,    67,   -76,   -76,
       1,    71,    71,    71,   -76,   -76,   -76,    85,    66,   -76,
     -76,    24,    73,   -76,    83,    14,    89,   -76,   -76,   -76,
     -76,    71,   104,    71,    77,    95,    71,    71,    37,   -76,
     -76,    86,    93,   -76,   -76,   -76,   -76,    71,   -76,    71,
      71,    71,    71,    97,   104,   105,   -76,   107,   -76,   108,
      99,    96,   -76,   -76,   -76,    89,   118,   -76,   100,    71,
     100,   106,   -76,    71,   -76,   130,   113,   -76,   -76,   -76,
     100,   100,   -76,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    23,    24,    25,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    28,     0,     0,     0,     0,    22,    12,
       0,    17,     0,    26,     9,     0,    10,     0,    16,    29,
       0,    18,    13,     8,     0,    15,     0,     0,     0,    11,
      14,    27,     0,     0,     0,     0,     0,     0,    62,    63,
      44,     0,     0,     0,    42,    34,    32,     0,     0,    30,
      33,    59,     0,    46,    48,    50,    52,    54,    58,    21,
      41,     0,     0,     0,     0,     0,    67,     0,    59,    56,
      57,     0,    28,    19,    31,    64,    65,     0,    43,     0,
       0,     0,     0,     0,     0,     0,    40,     0,    69,     0,
      66,     0,    61,    47,    49,    53,    51,    55,     0,     0,
       0,     0,    60,     0,    45,    36,     0,    38,    39,    68,
       0,     0,    37,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   139,   -76,   -76,   -76,   -76,   -76,    -8,
     -76,   -76,    19,     6,   -76,   -76,   -56,   -62,   -47,   -46,
     -75,    57,    54,    58,   -43,   -76,   -76,   -76
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    34,    25,    20,    55,
      37,    38,    56,    57,    14,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    99,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      74,    98,    84,    11,    78,    78,    10,    81,    79,    80,
      94,    10,   103,     1,     2,     3,    15,    32,    26,     9,
      16,    21,    13,    27,     9,    93,    39,    95,    22,    78,
      76,   101,   109,    35,    77,    90,    23,    19,   119,    91,
      78,    24,    78,    78,    78,    78,    28,    85,    86,   107,
      87,    29,   115,    30,   117,     1,     2,     3,    17,    18,
      85,    86,    31,   116,   122,   123,    78,    42,    33,    43,
      44,    36,     1,     2,     3,   -20,    40,    70,    45,    41,
      46,    71,    69,    47,    48,    49,    50,    51,    72,    48,
      49,    50,    51,    73,    52,    53,    75,    31,    83,    52,
      53,    42,    54,    43,    44,    82,     1,     2,     3,    88,
      89,    92,    45,    96,    46,    97,   102,    47,    48,    49,
      50,    51,    48,    49,    50,    51,    16,   108,    52,    53,
     114,    31,    52,    53,   113,   110,    54,   111,   112,    90,
      54,   120,   118,   121,    12,   106,   104,     0,   105
};

static const yytype_int8 yycheck[] =
{
      46,    76,    58,     0,    51,    52,     0,    53,    51,    52,
      72,     5,    87,     6,     7,     8,    29,    25,    30,     0,
      33,    15,    20,    35,     5,    71,    34,    73,    18,    76,
      29,    77,    94,    27,    33,    21,    20,    30,   113,    25,
      87,    36,    89,    90,    91,    92,    20,    23,    24,    92,
      26,    34,   108,    33,   110,     6,     7,     8,    35,    36,
      23,    24,    31,   109,   120,   121,   113,     1,    36,     3,
       4,    18,     6,     7,     8,    32,    20,    36,    12,    34,
      14,    29,    32,    17,    18,    19,    20,    21,    29,    18,
      19,    20,    21,    29,    28,    29,    29,    31,    32,    28,
      29,     1,    36,     3,     4,    20,     6,     7,     8,    36,
      27,    22,    12,    36,    14,    20,    30,    17,    18,    19,
      20,    21,    18,    19,    20,    21,    33,    30,    28,    29,
      34,    31,    28,    29,    35,    30,    36,    30,    30,    21,
      36,    11,    36,    30,     5,    91,    89,    -1,    90
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,    41,    42,    43,    44,    45,    52,
      53,     0,    43,    20,    54,    29,    33,    35,    36,    30,
      48,    53,    18,    20,    36,    47,    30,    35,    20,    34,
      33,    31,    49,    36,    46,    53,    18,    50,    51,    49,
      20,    34,     1,     3,     4,    12,    14,    17,    18,    19,
      20,    21,    28,    29,    36,    49,    52,    53,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    32,
      36,    29,    29,    29,    59,    29,    29,    33,    58,    64,
      64,    59,    20,    32,    56,    23,    24,    26,    36,    27,
      21,    25,    22,    59,    57,    59,    36,    20,    60,    66,
      67,    59,    30,    60,    61,    63,    62,    64,    30,    57,
      30,    30,    30,    35,    34,    56,    59,    56,    36,    60,
      11,    30,    56,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    44,    44,
      46,    45,    47,    45,    48,    48,    48,    48,    50,    49,
      51,    49,    52,    53,    53,    53,    54,    54,    54,    54,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    66,    66,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     0,     6,     4,     3,     2,     1,     0,     4,
       0,     3,     3,     1,     1,     1,     3,     6,     1,     4,
       1,     2,     1,     1,     1,     7,     5,     7,     5,     5,
       3,     2,     1,     2,     1,     4,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     2,     2,     1,     1,
       4,     3,     1,     1,     2,     2,     1,     0,     3,     1
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
#line 137 "1405079.y" /* yacc.c:1646  */
    {
		//fprintf(logout,"Line %d: start : program\n\n",line_count);
		fprintf(logout,"Total Lines: %d\n\nTotal Errors: %d\n\n",line_count,errorcount);

		(yyval) = new SymbolInfo();
		asmb += ".model small\n.stack 100h\n.data\n"+ declaration +"\n"+".code\nPRINTLN PROC\n@END_IF1:\nXOR CX,CX\nMOV BX,10D\n@REPEAT1:\nXOR DX,DX\nDIV BX\nPUSH DX\nINC CX\nOR AX,AX\nJNE @REPEAT1\nMOV AH,2\n@PRINT_LOOP:\nPOP DX\nOR DL,30H\nINT 21H\nLOOP @PRINT_LOOP\nMOV DL,0DH\nINT 21H\nMOV DL,0AH\nINT 21H\nRET\nPRINTLN ENDP\n\n";
		(yyval)->code += asmb + (yyvsp[0])->code;
		//cout<<$5->code;

		(yyval)->code += "end main\n";
		if(!errorcount){
			fprintf(codes,"%s\n",(yyval)->code.c_str());
			//optimize( const_cast<char*>($$->code.c_str()));
			//char cha[]="mov ax,@data\nmov ds, ax\nmov es, ax\nmov t1,ax\nmov ax,t1\nadd y1, ax\nmov t2, ax\nadd ax, bx\nmov ax, t2\nmov ah, 4ch\nint 21h\n";
			//char *ch=cha;
			optimize( const_cast<char*>((yyval)->code.c_str()));
		}
	}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 158 "1405079.y" /* yacc.c:1646  */
    {
		fprintf(logout,"Line %d: program : program unit\n\n",line_count);
		(yyval)=(yyvsp[-1]);
		(yyval)->code+=(yyvsp[0])->code;
	}
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 165 "1405079.y" /* yacc.c:1646  */
    {
		fprintf(logout,"Line %d: program : unit\n\n",line_count);
		(yyval)=(yyvsp[0]);

		/*
		| error unit {
			fprintf(logout,"Line %d: unit : error unit\n\n",line_count);
			$$=$2;
		}
		*/
	}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 179 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: unit : var_declaration\n\n",line_count);
			(yyval)=(yyvsp[0]);
		}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 185 "1405079.y" /* yacc.c:1646  */
    {
/**/
			fprintf(logout,"Line %d: unit : func_declaration\n\n",line_count);
			(yyval)=(yyvsp[0]);
     	}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 192 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: unit : func_definition\n\n",line_count);
			(yyval)=(yyvsp[0]);
/*
| error SEMICOLON {fprintf(logout,"Line %d: unit : error SEMICOLON\n\n",line_count);}
		| error RCURL {fprintf(logout,"Line %d: unit : error RCURL\n\n",line_count);}
*/
     	}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 204 "1405079.y" /* yacc.c:1646  */
    {

		fprintf(logout,"Line %d: func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n",line_count);
fprintf(logout,"%s\n\n",(yyvsp[-4])->getName().c_str());
		//cout<<"func_declaration :$1= "<<$1->getName()<<endl;
		//functype=$1->getName();
if(paramerr==true)
{
yyerror("Parameters can't be declared without name in function"+(yyvsp[-4])->getName());
paramerr=false;
}
else {
		if(table->Lookup((yyvsp[-4])->getName())==NULL)
		{
bool flag=true;
for(int i=0;i<params.size();i++)
{
if(params[i].name==(yyvsp[-4])->getName()){
flag=false;
ostringstream oss;
oss<<"Function name matched with "<<i+1<<"th parameter in "<<(yyvsp[-4])->getName();
yyerror(oss.str());
break;
}
}
if(flag){

			table->Insert((yyvsp[-4])->getName(),"function");
			SymbolInfo *s=table->Lookup((yyvsp[-4])->getName());
			s->fp=new Function();
			s->fp->retype= (yyvsp[-5])->getName();
			s->fp->params=params;
			s->Print();
		}
}
		else
		{
			//fprintf(logout,"Error at Line %d: Multiple declaration Function %s\n\n",line_count,$2->getName().c_str());
			yyerror("Multiple declaration Function "+(yyvsp[-4])->getName());
		}
		fn=NULL;

}
params.clear();
 }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 252 "1405079.y" /* yacc.c:1646  */
    {

		fprintf(logout,"Line %d: func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n",line_count);
fprintf(logout,"%s\n\n",(yyvsp[-3])->getName().c_str());
		//cout<<"func_declaration :$1= "<<$1->getName()<<endl;
		//functype=$1->getName();
if(paramerr==true)
{
yyerror("Parameters can't be declared without name in function"+(yyvsp[-3])->getName());
paramerr=false;
}
else {
		if(table->Lookup((yyvsp[-3])->getName())==NULL)
		{
bool flag=true;
for(int i=0;i<params.size();i++)
{
if(params[i].name==(yyvsp[-3])->getName()){
flag=false;
ostringstream oss;
oss<<"Function name matched with "<<i+1<<"th parameter in "<<(yyvsp[-3])->getName();
yyerror(oss.str());
break;
}
}
if(flag){

			table->Insert((yyvsp[-3])->getName(),"function");
			SymbolInfo *s=table->Lookup((yyvsp[-3])->getName());
			s->fp=new Function();
			s->fp->retype= (yyvsp[-4])->getName();
			s->fp->params=params;
			s->Print();
		}
}
		else
		{
			//fprintf(logout,"Error at Line %d: Multiple declaration Function %s\n\n",line_count,$2->getName().c_str());
			yyerror("Multiple declaration Function "+(yyvsp[-3])->getName());
		}
		fn=NULL;

}
params.clear();
 }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 300 "1405079.y" /* yacc.c:1646  */
    {
if(paramerr==true)
{
yyerror("Parameters can't be declared without name in function "+(yyvsp[-3])->getName());
paramerr=false;
}
else {
//cout<<"func_definition: $1= "<<$1->getName()<<endl;
//functype=$1->getName();
		cout<<"func_definition:\n";
		SymbolInfo *si=table->Lookup((yyvsp[-3])->getName());
		if(si==NULL)
		{
bool flag=true;
for(int i=0;i<params.size();i++)
{
if(params[i].name==(yyvsp[-3])->getName()){
flag=false;
ostringstream oss;
oss<<"Function name matched with "<<i+1<<"th parameter in "<<(yyvsp[-3])->getName();
yyerror(oss.str());
break;
}
}
if(flag){

			table->Insert((yyvsp[-3])->getName(),"function");
			SymbolInfo *s=table->Lookup((yyvsp[-3])->getName());
			s->fp=new Function();
			s->fp->retype= (yyvsp[-4])->getName();
			s->fp->retaddress=(string)newTemp();
			declaration +=s->fp->retaddress+ " dw ?\n";
			s->fp->params=params;
			fn=s->fp;
			fn2=s->fp;
			funcName=(yyvsp[-3])->getName();
			s->Print();
}
		}
		else
		{
			fn=si->fp;
			fn2=si->fp;
			funcName=si->getName();
			//fprintf(error,"Line %d: Multiple declaration Function %s\n\n",line_count,$2->getName().c_str());
			if(si->fp->retype==(yyvsp[-4])->getName())
			{
				if(si->fp->params.size()!=params.size()){
//fprintf(logout,"Error at Line %d: Parameters Size Mismatch of Function %s\n\n",line_count,$2->getName().c_str());
yyerror("Parameters Size Mismatch of Function "+(yyvsp[-3])->getName());
}
				else{
					for(int i=0;i<si->fp->params.size();i++)
					{
						if(si->fp->params[i].getName()!=params[i].getName()||si->fp->params[i].getType()!=params[i].getType())
						{
							//fprintf(logout,"Error at Line %d: %dth parameter Mismatch of Function %s\n\n",line_count,i+1,$2->getName().c_str());
ostringstream oss;
oss<<i+1<<"th parameter Mismatch of Function "<<(yyvsp[-3])->getName();
yyerror(oss.str());
						}
if(params[i].name==(yyvsp[-3])->getName()){
ostringstream oss;
oss<<"Function name matched with "<<i+1<<"th parameter in "<<(yyvsp[-3])->getName();
yyerror(oss.str());
break;
}
					}
				}
			}
			else{
				fprintf(logout,"Line %d: Return-type Mismatch of Function %s\n\n",line_count,(yyvsp[-3])->getName().c_str());
yyerror("Return-type Mismatch of Function "+(yyvsp[-3])->getName());
			}
		}
}
		//cout<<"Rparen end\n";
		params.clear();

}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 379 "1405079.y" /* yacc.c:1646  */
    {
		fprintf(logout,"Line %d: func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n",line_count);
fprintf(logout,"%s\n\n",(yyvsp[-5])->getName().c_str());
cout<<"Line %d: func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n";
	(yyval)=new SymbolInfo();
	(yyval)->code=funcName+" proc\n";
	//cout<<"####1"<<endl;
	if(funcName=="main")
	{
		//cout<<"####2"<<endl;
		(yyval)->code+= "mov ax,@data\nmov ds,ax\nmov es,ax\n";
		(yyval)->code+=(yyvsp[0])->code;
	}
	else
	{
		(yyval)->code+="push BP\nmov BP,SP\npush ax\npush bx\npush cx\npush dx\n";
		string popParam="";
		for(int i=fn2->params.size()-1;i>=0;i--)
		{
			ostringstream oss;
			string st=newAdd(fn2->params[i].getName(),funcId);
			oss<<"push "+st+"\n";
			oss<<"mov ax,[BP+"<<4+(fn2->params.size()-1-i)*2<<"]\n";
			(yyval)->code+=oss.str();

			declaration +=st+ " dw ?\n";
			(yyval)->code+="mov "+st+",ax\n";
		}
		(yyval)->code+=(yyvsp[0])->code;
		for(int i=0;i<fn2->params.size();i++)
		{
			string st=newAdd(fn2->params[i].getName(),funcId);
			(yyval)->code+="pop "+st+"\n";
		}
		(yyval)->code+="pop dx\npop cx\npop bx\npop ax\npop BP\n";
		ostringstream oss;
		oss<<"Ret "<<fn2->params.size()*2<<"\n";
		(yyval)->code+=oss.str();
	}
	if(funcName=="main")(yyval)->code+="mov ah,4ch\nint 21h\n";
	(yyval)->code+=funcName+" endp\n\n";
}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 425 "1405079.y" /* yacc.c:1646  */
    {
if(paramerr==true)
{
yyerror("Parameters can't be declared without name in function "+(yyvsp[-2])->getName());
paramerr=false;
}
else {
//cout<<"func_definition: $1= "<<$1->getName()<<endl;
//functype=$1->getName();
		cout<<"func_definition:\n";
		SymbolInfo *si=table->Lookup((yyvsp[-2])->getName());
		if(si==NULL)
		{
bool flag=true;
for(int i=0;i<params.size();i++)
{
if(params[i].name==(yyvsp[-2])->getName()){
flag=false;
ostringstream oss;
oss<<"Function name matched with "<<i+1<<"th parameter in "<<(yyvsp[-2])->getName();
yyerror(oss.str());
break;
}
}
if(flag){

			table->Insert((yyvsp[-2])->getName(),"function");
			SymbolInfo *s=table->Lookup((yyvsp[-2])->getName());
			s->fp=new Function();
			s->fp->retype= (yyvsp[-3])->getName();
			s->fp->retaddress=(string)newTemp();
			declaration +=s->fp->retaddress+ " dw ?\n";
			s->fp->params=params;
			fn=s->fp;
			fn2=s->fp;
			funcName=(yyvsp[-2])->getName();
			s->Print();
}
		}
		else
		{
			fn=si->fp;
			fn2=si->fp;
			funcName=si->getName();
			//fprintf(error,"Line %d: Multiple declaration Function %s\n\n",line_count,$2->getName().c_str());
			if(si->fp->retype==(yyvsp[-3])->getName())
			{
				if(si->fp->params.size()!=params.size()){
//fprintf(logout,"Error at Line %d: Parameters Size Mismatch of Function %s\n\n",line_count,$2->getName().c_str());
yyerror("Parameters Size Mismatch of Function "+(yyvsp[-2])->getName());
}
				else{
					for(int i=0;i<si->fp->params.size();i++)
					{
						if(si->fp->params[i].getName()!=params[i].getName()||si->fp->params[i].getType()!=params[i].getType())
						{
							//fprintf(logout,"Error at Line %d: %dth parameter Mismatch of Function %s\n\n",line_count,i+1,$2->getName().c_str());
ostringstream oss;
oss<<i+1<<"th parameter Mismatch of Function "<<(yyvsp[-2])->getName();
yyerror(oss.str());
						}
if(params[i].name==(yyvsp[-2])->getName()){
ostringstream oss;
oss<<"Function name matched with "<<i+1<<"th parameter in "<<(yyvsp[-2])->getName();
yyerror(oss.str());
break;
}
					}
				}
			}
			else{
				fprintf(logout,"Line %d: Return-type Mismatch of Function %s\n\n",line_count,(yyvsp[-2])->getName().c_str());
yyerror("Return-type Mismatch of Function "+(yyvsp[-2])->getName());
			}
		}
}
		//cout<<"Rparen end\n";
		params.clear();

}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 504 "1405079.y" /* yacc.c:1646  */
    {
		fprintf(logout,"Line %d: func_definition : type_specifier ID LPAREN RPAREN compound_statement\n",line_count);
		fprintf(logout,"%s\n\n",(yyvsp[-4])->getName().c_str());
		(yyval)=new SymbolInfo();
		(yyval)->code=funcName+" proc\n";
		//cout<<"####1"<<endl;
		if(funcName=="main")
		{
			//cout<<"####2"<<endl;
			(yyval)->code+= "mov ax,@data\nmov ds,ax\nmov es,ax\n";
			(yyval)->code+=(yyvsp[0])->code;
		}
		else
		{
			(yyval)->code+="push BP\nmov BP,SP\npush ax\npush bx\npush cx\npush dx\n";
			string popParam="";
			for(int i=fn2->params.size()-1;i>=0;i--)
			{
				ostringstream oss;
				string st=newAdd(fn2->params[i].getName(),funcId);
				oss<<"push "+st+"\n";
				oss<<"mov ax,[BP+"<<4+(fn2->params.size()-1-i)*2<<"]\n";
				(yyval)->code+=oss.str();

				declaration +=st+ " dw ?\n";
				(yyval)->code+="mov "+st+",ax\n";
			}
			(yyval)->code+=(yyvsp[0])->code;
			for(int i=0;i<fn2->params.size();i++)
			{
				string st=newAdd(fn2->params[i].getName(),funcId);
				(yyval)->code+="pop "+st+"\n";
			}
			(yyval)->code+="pop dx\npop cx\npop bx\npop ax\npop BP\n";
			ostringstream oss;
			oss<<"Ret "<<fn2->params.size()*2<<"\n";
			(yyval)->code+=oss.str();
		}
		if(funcName=="main")(yyval)->code+="mov ah,4ch\nint 21h\n";
		(yyval)->code+=funcName+" endp\n\n";
}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 548 "1405079.y" /* yacc.c:1646  */
    {
	fprintf(logout,"Line %d: parameter_list  : parameter_list COMMA type_specifier ID\n",line_count);
	fprintf(logout,"%s\n\n",(yyvsp[0])->getName().c_str());
	SymbolInfo sym((yyvsp[0])->getName(),type);
	params.push_back(sym);
}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 556 "1405079.y" /* yacc.c:1646  */
    {
	fprintf(logout,"Line %d: parameter_list  : parameter_list COMMA type_specifier\n\n",line_count);
	paramerr=true;
}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 562 "1405079.y" /* yacc.c:1646  */
    {
	fprintf(logout,"Line %d: parameter_list  : type_specifier ID\n",line_count);
	fprintf(logout,"%s\n\n",(yyvsp[0])->getName().c_str());
	SymbolInfo sym((yyvsp[0])->getName(),type);
	params.push_back(sym );
}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 570 "1405079.y" /* yacc.c:1646  */
    {
 	fprintf(logout,"Line %d: parameter_list  : type_specifier\n\n",line_count);
	paramerr=true;
}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 578 "1405079.y" /* yacc.c:1646  */
    {
		table->EnterScope();
		//cout<<"Print it";
		if(fn!=NULL)
		{
			for(int i=0;i<fn->params.size();i++)
			{
				//cout<<fn->params[i].getName()<<endl;
				table->Insert(fn->params[i].getName(),fn->params[i].getType());
			}
			funcId=table->id;
			fn=NULL;
		}
	}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 592 "1405079.y" /* yacc.c:1646  */
    {

		(yyval)=(yyvsp[-1]);
		cout<<"Line %d: compound_statement : LCURL statements RCURL\n\n";
		cout<<"####1"<<(yyval)->code<<endl;

		fprintf(logout,"Line %d: compound_statement : LCURL statements RCURL\n\n",line_count);
		symtabprint=true;
		fprintf(symtable,"Line No %d\n\n",line_count);
		table->PrintAllScopeTable();
		symtabprint=false;
		table->ExitScope();

	}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 607 "1405079.y" /* yacc.c:1646  */
    {
		table->EnterScope();
		//cout<<"Print it";
		if(fn!=NULL)
		{
			for(int i=0;i<fn->params.size();i++)
			{
				//cout<<fn->params[i].getName()<<endl;
				table->Insert(fn->params[i].getName(),fn->params[i].getType());
			}
			fn=NULL;
		}
	}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 620 "1405079.y" /* yacc.c:1646  */
    {
		 fprintf(logout,"Line %d: compound_statement : LCURL RCURL\n\n",line_count);
		 table->PrintAllScopeTable();
		 table->ExitScope();
		 (yyval)=(yyvsp[-1]);
	}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 628 "1405079.y" /* yacc.c:1646  */
    {
	 fprintf(logout,"Line %d: var_declaration	: type_specifier declaration_list SEMICOLON\n\n",line_count);
	 (yyval)=(yyvsp[-1]);
	 cout<<"Line %d: var_declaration	: type_specifier declaration_list SEMICOLON\n\n";
	 cout<<"#####1"<<(yyvsp[-1])->address<<endl;
 }
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 635 "1405079.y" /* yacc.c:1646  */
    { fprintf(logout,"Line %d: type_specifier : INT \n\n",line_count); type="int"; (yyval)=new SymbolInfo("int",type); }
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 636 "1405079.y" /* yacc.c:1646  */
    { fprintf(logout,"Line %d: type_specifier : FLOAT\n\n",line_count); type="float";(yyval)=new SymbolInfo("float",type); }
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 637 "1405079.y" /* yacc.c:1646  */
    { fprintf(logout,"Line %d: type_specifier : VOID\n\n",line_count); type="void";(yyval)=new SymbolInfo("void",type); }
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 643 "1405079.y" /* yacc.c:1646  */
    {
				fprintf(logout,"Line %d: declaration_list : declaration_list COMMA ID\n",line_count);
				fprintf(logout,"%s\n\n",(yyvsp[0])->getName().c_str());
SymbolInfo* temp = new SymbolInfo();

if((yyvsp[-2])->Token!="error"){
				if(type == "int"){

					SymbolInfo* s = new SymbolInfo((yyvsp[0])->getName(), "int");
					s-> Token = "ID";
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
					else
					{
						temp->address=newAdd((yyvsp[0])->name,table->id);
						declaration += temp->address+ " dw ?\n";
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo((yyvsp[0])->getName(), "float");
					s-> Token = "ID";
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
					else
					{
						temp->address=newAdd((yyvsp[0])->name,table->id);
						declaration += temp->address+ " dw ?\n";
					}
				}
				if(type == "void"){
					yyerror("A variable cannot be declared as void!");
temp->Token="error";
				}
}
else {temp->Token="error";}

(yyval)=temp;


			}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 690 "1405079.y" /* yacc.c:1646  */
    {
				fprintf(logout,"Line %d: declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",line_count);
				fprintf(logout,"%s\n%d\n\n",(yyvsp[-3])->getName().c_str(),(yyvsp[-1])->ivalue);
SymbolInfo* temp = new SymbolInfo();

if((yyvsp[-5])->Token!="error"){

				if(type == "int"){
					SymbolInfo* s = new SymbolInfo((yyvsp[-3])->getName(), "int");
					s-> Token = "ID";
					s->arraysize = (yyvsp[-1])->ivalue;
cout<<"Array size = "<<s->arraysize<<endl;
					s->array=new SymbolInfo*[s->arraysize];
for(int i=0;i<s->arraysize;i++)
{
cout<<"Creating pos = "<<i<<endl;
s->array[i]=new SymbolInfo("","int");
}
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
					else
					{
						temp->address=newAdd((yyvsp[-3])->name,table->id);
						declaration += temp->address+ " dw ?";
						for(int i =0; i<(yyvsp[-1])->ivalue; i++){
							declaration += ", ?";
						}
						declaration +="\n";
					}

				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo((yyvsp[-3])->getName(), "float");
					s-> Token = "ID";
					s->arraysize = (yyvsp[-1])->ivalue;
					s->array=new SymbolInfo*[s->arraysize];
for(int i=0;i<s->arraysize;i++)
{
s->array[i]=new SymbolInfo("","float");
}
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
					else
					{
						temp->address=newAdd((yyvsp[-3])->name,table->id);
						declaration += temp->address+ " dw ?";
						for(int i =0; i<(yyvsp[-1])->ivalue; i++){
							declaration += ", ?";
						}
						declaration +="\n";
					}
				}
				if(type == "void"){
					yyerror("A variable cannot be declared as void!");
temp->Token="error";
				}
}
else {temp->Token="error";}

(yyval)=temp;
			}
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 757 "1405079.y" /* yacc.c:1646  */
    {
				fprintf(logout,"Line %d: declaration_list : ID\n",line_count);
				fprintf(logout,"%s\n\n",(yyvsp[0])->getName().c_str());
				cout<<"Line %d: declaration_list : ID\n";

SymbolInfo* temp = new SymbolInfo();

				if(type == "int"){
					SymbolInfo* s = new SymbolInfo((yyvsp[0])->getName(), "int");
					s-> Token = "ID";
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
					else
					{
						cout<<"###1"<<endl;
						temp->address=newAdd((yyvsp[0])->name,table->id);
						cout<<"###2"<<endl;
						declaration += temp->address+ " dw ?\n";
						cout<<"###3"<<temp->address<<endl;
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo((yyvsp[0])->getName(), "float");
					s-> Token = "ID";
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
					else
					{
						temp->address=newAdd((yyvsp[0])->name,table->id);
						declaration += temp->address+ " dw ?\n";
					}
				}
				if(type == "void"){
					yyerror("A variable cannot be declared as void!");
temp->Token="error";
				}

(yyval)=temp;
cout<<"Code: "<<temp->code<<endl;
			}
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 801 "1405079.y" /* yacc.c:1646  */
    {
				fprintf(logout,"Line %d: declaration_list : ID LTHIRD CONST_INT RTHIRD\n",line_count);
				fprintf(logout,"%s\n%d\n\n",(yyvsp[-3])->getName().c_str(),(yyvsp[-1])->ivalue);
SymbolInfo* temp = new SymbolInfo();

				if(type == "int"){
					SymbolInfo* s = new SymbolInfo((yyvsp[-3])->getName(), "int");
					s-> Token = "ID";
					s->arraysize = (yyvsp[-1])->ivalue;
cout<<"Array size = "<<s->arraysize<<endl;
s->array=new SymbolInfo*[s->arraysize];
for(int i=0;i<s->arraysize;i++)
{
cout<<"Creating pos = "<<i<<endl;
s->array[i]=new SymbolInfo(s->name,"int");
}
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
					else
					{
						temp->address=newAdd((yyvsp[-3])->name,table->id);
						declaration += temp->address+ " dw ?";
						for(int i =0; i<(yyvsp[-1])->ivalue; i++){
							declaration += ", ?";
						}
						declaration +="\n";
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo((yyvsp[-3])->name, "float");
					s-> Token = "ID";
					s->arraysize = (yyvsp[-1])->ivalue;
s->array=new SymbolInfo*[s->arraysize];
for(int i=0;i<s->arraysize;i++)
{
s->array[i]=new SymbolInfo("","float");
}
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
					else
					{
						temp->address=newAdd((yyvsp[-3])->name,table->id);
						declaration += temp->address+ " dw ?";
						for(int i =0; i<(yyvsp[-1])->ivalue; i++){
							declaration += ", ?";
						}
						declaration +="\n";
					}
				}
				if(type == "void"){
					yyerror("A variable cannot be declared as void!");
temp->Token="error";
				}

(yyval)=temp;
			}
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 863 "1405079.y" /* yacc.c:1646  */
    {
	fprintf(logout,"Line %d: statements : statement\n\n",line_count);
	cout<<"Line %d: statements : statement\n\n";
	(yyval)=(yyvsp[0]);
	cout<<"####1"<<(yyvsp[0])->address<<endl;
 }
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 869 "1405079.y" /* yacc.c:1646  */
    {
		   fprintf(logout,"Line %d: statements : statements statement\n\n",line_count);
		   cout<<"Line %d: statements : statements statement\n\n";
		   (yyval)=(yyvsp[-1]);
		   cout<<"####1\n\n";
		   (yyval)->code += (yyvsp[0])->code;
		   cout<<"####2\n\n"<<(yyval)->code;
	   }
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 880 "1405079.y" /* yacc.c:1646  */
    {
fprintf(logout,"Line %d: statement  : var_declaration\n\n",line_count);
(yyval)=(yyvsp[0]);
}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 884 "1405079.y" /* yacc.c:1646  */
    {
		   fprintf(logout,"Line %d: statement : expression_statement\n\n",line_count);
		   (yyval)=(yyvsp[0]);
	   }
#line 2335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 888 "1405079.y" /* yacc.c:1646  */
    {
		   fprintf(logout,"Line %d: statement : compound_statement\n\n",line_count);
		   (yyval)=(yyvsp[0]);
	   }
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 892 "1405079.y" /* yacc.c:1646  */
    {
		    fprintf(logout,"Line %d: statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n",line_count);
			(yyval)=(yyvsp[-4]);
			char*  label1=newLabel();
		  	char*  label2=newLabel();

			(yyval)->code += string(label1)+":\n";
			(yyval)->code += (yyvsp[-3])->code;
			(yyval)->code += "cmp "+ (yyvsp[-3])->address+", 1\n";
			(yyval)->code += "jne "+string(label2)+"\n";
			(yyval)->code += (yyvsp[0])->code;
			(yyval)->code += (yyvsp[-2])->code;
			(yyval)->code +="jmp "+string(label1)+"\n";
			(yyval)->code += string(label2)+":\n\n";
		}
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 907 "1405079.y" /* yacc.c:1646  */
    {
		    fprintf(logout,"Line %d: statement :  IF LPAREN expression RPAREN statement\n\n",line_count);
			(yyval)=(yyvsp[-2]);

 			char*  label=newLabel();

			(yyval)->code+="mov ax,"+  (yyvsp[-2])->address +"\n";
			(yyval)->code+="cmp ax,0\n";
			(yyval)->code+="je "+string(label)+"\n";
			(yyval)->code+=(yyvsp[0])->code;
			(yyval)->code+=string(label)+":\n\n";
		 }
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 919 "1405079.y" /* yacc.c:1646  */
    {
		   fprintf(logout,"Line %d: statement : IF LPAREN expression RPAREN statement ELSE statement\n\n",line_count);
		   (yyval)=(yyvsp[-4]);

		   char*  label1=newLabel();
		   char*  label2=newLabel();

		   (yyval)->code+="mov ax,"+ (yyvsp[-4])->address +"\n";
		   (yyval)->code+="cmp ax,0\n";
		   (yyval)->code+="je "+string(label1)+"\n";
		   (yyval)->code+=(yyvsp[-2])->code;
		   (yyval)->code+="jmp " + string(label2)+"\n";
		   (yyval)->code+=string(label1)+":\n";
		   (yyval)->code+=(yyvsp[0])->code;
		   (yyval)->code+=string(label2)+":\n\n";
	    }
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 935 "1405079.y" /* yacc.c:1646  */
    {
		    fprintf(logout,"Line %d: statement : WHILE LPAREN expression RPAREN statement\n\n",line_count);
			(yyval)=new SymbolInfo();
			char* label1 = newLabel();
			char* label2 = newLabel();

			//$$->code += $3->code;
			(yyval)->code += string(label1)+":\n";
			(yyval)->code += (yyvsp[-2])->code;
			(yyval)->code += "cmp "+ (yyvsp[-2])->address +",1\n";
			(yyval)->code += "jne "+string(label2)+"\n";
			(yyval)->code += (yyvsp[0])->code;
			(yyval)->code += "jmp "+string(label1)+"\n";
			(yyval)->code += string(label2)+":\n\n";
		 }
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 950 "1405079.y" /* yacc.c:1646  */
    {
		   fprintf(logout,"Line %d: statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n",line_count);
		   (yyval)=new SymbolInfo();
		   (yyval)->code += (yyvsp[-2])->code;
		   SymbolInfo* temp = table->Lookup((yyvsp[-2])->getName());
		   if (temp == NULL){
			   yyerror("Undeclared variable "+(yyvsp[-2])->getName());
		   }
		   else {
			   (yyval)->address=newAdd(temp->name,temp->id);
			   (yyval)->code += "mov ax,"+(yyval)->address+"\n";
			   (yyval)->code += "call PRINTLN\n";
	   	  }
	   }
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 964 "1405079.y" /* yacc.c:1646  */
    {
		   fprintf(logout,"Line %d: statement : RETURN expression SEMICOLON \n\n",line_count);
		   // write code for return.
		   (yyval)=(yyvsp[-1]);
		   (yyval)->code+="mov ax,"+(yyvsp[-1])->address+"\n";
		   (yyval)->code+="mov "+fn2->retaddress+",ax\n";
		   (yyval)->address=fn2->retaddress;
		   cout<<"return ret: "<<(yyval)->address<<endl;
	   }
#line 2455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 974 "1405079.y" /* yacc.c:1646  */
    {
		   (yyval)=new SymbolInfo();
	   	(yyval)->name = ";";
	   	(yyval)->Token = "error";
	   	(yyval)->code="";
	   }
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 982 "1405079.y" /* yacc.c:1646  */
    {
	fprintf(logout,"Line %d: expression_statement	: SEMICOLON\n\n",line_count);
	(yyval)=new SymbolInfo();
	(yyval)->name = ";";
	(yyval)->Token = "SEMICOLON";
	(yyval)->code="";
}
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 989 "1405079.y" /* yacc.c:1646  */
    {
				fprintf(logout,"Line %d: expression_statement	: expression SEMICOLON\n\n",line_count);
				cout<<"Line %d: expression_statement: expression SEMICOLON\n\n";
 			 	(yyval)=(yyvsp[-1]);
				cout<<(yyval)->code;
			 }
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 997 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: variable : ID\n",line_count);
			fprintf(logout,"%s\n\n",(yyvsp[0])->getName().c_str());
			SymbolInfo* temp = table->Lookup((yyvsp[0])->getName());
			if (temp == NULL){
				yyerror("Undeclared variable "+(yyvsp[0])->getName());
temp=new SymbolInfo();
temp->Token="error";
			}
else if(temp->arraysize!=-1)
{
yyerror("Array can't be used without index in "+(yyvsp[0])->getName());
temp = new SymbolInfo();
temp->Token="error";
}
else
{
	temp=new SymbolInfo(temp);
}

			temp->address=newAdd(temp->name,temp->id);
			(yyval) = temp;
			cout<<"return Id : "<<(yyval)->address<<endl;
		}
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1021 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: variable : ID LTHIRD expression RTHIRD\n",line_count);
			fprintf(logout,"%s\n\n",(yyvsp[-3])->getName().c_str());
SymbolInfo* temp = new SymbolInfo();

if((yyvsp[-1])->Token!="error"){
			cout<<(yyvsp[-3])->getName()<<endl;
			temp = table->Lookup((yyvsp[-3])->getName());
			if (temp == NULL){
				yyerror("Undeclared variable "+(yyvsp[-3])->getName());
temp = new SymbolInfo();
temp->Token="error";
			}
			else if((yyvsp[-1])->type!="int"){
yyerror("Array index must be integer"+(yyvsp[-3])->getName());
temp = new SymbolInfo();
temp->Token="error";
}
else if(temp->arraysize==-1)
{
yyerror("Non-Array variable can't be used with index "+(yyvsp[-3])->getName());
temp = new SymbolInfo();
temp->Token="error";
cout<<"Temp Token ="<<temp->Token<<endl;
}
else{
				cout<<"Array index: "<<(yyvsp[-1])->ivalue<<endl;
cout<<"Temp Array Size = "<<temp->arraysize<<endl;
				if((yyvsp[-1])->ivalue >= temp->arraysize){
					yyerror("Array size overbound\n");
temp = new SymbolInfo();
temp->Token="error";
				}
				else {
					int size=temp->arraysize;
					temp = temp->array[(yyvsp[-1])->ivalue];
					temp=new SymbolInfo(temp);
					temp->code=(yyvsp[-1])->code+"mov bx," +(yyvsp[-1])->address +"\nadd bx,bx\n";
					temp->address=newAdd(temp->name,temp->id);
					temp->arraysize=size;
					//fprintf(logout,"Array index insert: %d\n\n",$$->ivalue);
				}

			}
		}
else {temp->Token="error";}
cout<<"Temp Token 2="<<temp->Token<<endl;
(yyval)=temp;

}
#line 2573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1074 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: expression : logic_expression\n\n",line_count);
			(yyval) = (yyvsp[0]);
			cout<<"return le: "<<(yyval)->address<<endl;
		}
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1079 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: expression : variable ASSINOP logic_expression\n\n",line_count);
SymbolInfo* temp = new SymbolInfo();

cout<<"Variable Token= "<<(yyvsp[-2])->Token<<endl;
if((yyvsp[-2])->Token!="error" && (yyvsp[0])->Token!="error"){
			//Print the symboltable here
			cout<<"Variable : "<<(yyvsp[-2])->name<<" "<<(yyvsp[-2])->ivalue<<" "<<(yyvsp[-2])->type<<endl;
			cout<<"Variable : "<<(yyvsp[0])->name<<" "<<(yyvsp[0])->ivalue<<" "<<(yyvsp[0])->type<<endl;
			if((yyvsp[-2])->type == "int"){
				if((yyvsp[0])->type == "int"){
					(yyvsp[-2])->ivalue = (yyvsp[0])->ivalue;
				}
				else if((yyvsp[0])->type=="void"){
yyerror("Calling void function in an expression is not allowed");
temp->Token="error";
}
				else{
					yyerror("Type Mismatch");
temp->Token="error";
				}
			}
			else if((yyvsp[-2])->type == "float"){
				if((yyvsp[0])->type == "int"){
					(yyvsp[-2])->fvalue = (yyvsp[0])->ivalue;
				}
				else if((yyvsp[0])->type == "float"){
					(yyvsp[-2])->fvalue = (yyvsp[0])->fvalue;
				}
			else if((yyvsp[0])->type=="void"){
yyerror("Calling void function in an expression is not allowed");
temp->Token="error";
}
				else {
					yyerror("Type Mismatch");
temp->Token="error";
				}
			}
			else {
					yyerror("Type Mismatch");
temp->Token="error";
				}
			/*else if($1->type == "char"){
				if($3->type == "int"){
					$1->c = $3->ivalue;
				}
				if($3->type == "float"){
					$1->c = $3->fvalue;
				}
				if($3->type == "char"){
					$1->c = $3->c;
				}
			}*/
			cout<<"After assign: "<<(yyvsp[-2])->ivalue<<endl;
			//$$ = $1;
			table->PrintAllScopeTable();
		}
else {temp->Token="error";}

(yyval)=temp;

	(yyval)->code=(yyvsp[0])->code+(yyvsp[-2])->code;
	(yyval)->code+="mov ax,"+(yyvsp[0])->address+"\n";
	if((yyvsp[-2])->arraysize==-1){
		(yyval)->code+= "mov "+(yyvsp[-2])->address+",ax\n";
	}

	else{
		(yyval)->code+= "mov "+(yyvsp[-2])->address+"[bx],ax\n";
	}
}
#line 2659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1153 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: logic_expression : rel_expression\n\n",line_count);
			(yyval) = (yyvsp[0]);
			cout<<"return re: "<<(yyval)->address<<endl;
		}
#line 2669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1158 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: logic_expression : rel_expression\n\n",line_count);
			SymbolInfo* s = new SymbolInfo();
if((yyvsp[-2])->Token!="error" && (yyvsp[0])->Token!="error"){

			s->type = "int";

			float f1, f2;
			if((yyvsp[-2])->type == "int"){
				f1 = (yyvsp[-2])->ivalue;
			}
			else if((yyvsp[-2])->type == "float"){
				f1 = (yyvsp[-2])->fvalue;
			}

			if((yyvsp[0])->type == "int"){
				f2 = (yyvsp[0])->ivalue;
			}
			else if((yyvsp[0])->type == "float"){
				f2 = (yyvsp[0])->fvalue;
			}

			if((yyvsp[-1])->name == "&&"){
				s->ivalue = f1&&f2;
			}
			else if ((yyvsp[-1])->name == "||"){
				s->ivalue = f1||f2;
			}
			//$$ = s;
}
else {s->Token="error";}

(yyval)=s;

	(yyval)->code=(yyvsp[-2])->code;
	(yyval)->code+=(yyvsp[0])->code;
	char *t=newTemp();

	declaration += string(t) + " dw ?\n";
	char *label1=newLabel();
	char *label2=newLabel();
	char *label3=newLabel();

	(yyval)->code +="mov ax," + (yyvsp[-2])->address +"\n";
	(yyval)->code +="mov bx," + (yyvsp[0])->address +"\n";

	if((yyvsp[-1])->name == "&&"){
		(yyval)->code += "cmp ax,0\nje "+string(label1)+"\ncmp bx,0\nje "+string(label1)+"\n";
		(yyval)->code += string(label2)+":\nmov "+ string(t)+",1\njmp "+string(label3)+"\n";
		(yyval)->code += string(label1)+":\nmov "+ string(t)+",0\n";
	}
	else if ((yyvsp[-1])->name == "||"){
		(yyval)->code += "cmp ax,0\njne "+string(label1)+"\ncmp bx,0\njne "+string(label1)+"\n";
		(yyval)->code += string(label2)+":\nmov "+ string(t)+",0\njmp "+string(label3)+"\n";
		(yyval)->code += string(label1)+":\nmov "+ string(t)+",1\n";
	}
	(yyval)->code += string(label3)+":\n";
	(yyval)->address = string(t);

		}
#line 2734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1220 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: rel_expression : simple_expression\n\n",line_count);
			(yyval) = (yyvsp[0]);
		}
#line 2743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1224 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: rel_expression : simple_expression RELOP simple_expression\n\n",line_count);
			SymbolInfo* s = new SymbolInfo();
if((yyvsp[-2])->Token!="error" && (yyvsp[0])->Token!="error"){

			s->type = "int";
			if((yyvsp[-1])->name == "=="){
				if((yyvsp[-2]) == (yyvsp[-1])){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if((yyvsp[-1])->name == "!="){
				if((yyvsp[-2]) != (yyvsp[-1])){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if((yyvsp[-1])->name == ">"){
				if((yyvsp[-2]) > (yyvsp[-1])){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if((yyvsp[-1])->name == "<"){
				if((yyvsp[-2]) < (yyvsp[-1])){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if((yyvsp[-1])->name == ">="){
				if((yyvsp[-2]) >= (yyvsp[-1])){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if((yyvsp[-1])->name == "<="){
				if((yyvsp[-2]) <= (yyvsp[-1])){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else {
yyerror("Relational operator error");
s->Token="error";
}
			//$$ = s;
		}
else {s->Token="error";}

(yyval)=s;
	(yyval)->code=(yyvsp[-2])->code;
	(yyval)->code+=(yyvsp[0])->code;
	(yyval)->code+="mov ax," + (yyvsp[-2])->address+"\n";
	(yyval)->code+="cmp ax," + (yyvsp[0])->address+"\n";
	char *t=newTemp();
	declaration += string(t) + " dw ?\n";
	char *label1=newLabel();
	char *label2=newLabel();
	if((yyvsp[-1])->name=="<"){
		(yyval)->code+="jl " + string(label1)+"\n";
	}
	else if((yyvsp[-1])->name=="<="){
		(yyval)->code+="jle " + string(label1)+"\n";
	}
	else if((yyvsp[-1])->name==">"){
		(yyval)->code+="jg " + string(label1)+"\n";
	}
	else if((yyvsp[-1])->name==">="){
		(yyval)->code+="jge " + string(label1)+"\n";
	}
	else if((yyvsp[-1])->name=="=="){
		(yyval)->code+="je " + string(label1)+"\n";
	}
	else{
		(yyval)->code+="jne " + string(label1)+"\n";
	}

	(yyval)->code+="mov "+string(t) +",0\n";
	(yyval)->code+="jmp "+string(label2) +"\n";
	(yyval)->code+=string(label1)+":\nmov "+string(t)+",1\n";
	(yyval)->code+=string(label2)+":\n";
	(yyval)->address=string(t);

}
#line 2845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1325 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: simple_expression : term\n\n",line_count);
			(yyval) = (yyvsp[0]);
		}
#line 2854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1329 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: simple_expression : simple_expression ADDOP term\n\n",line_count);
			SymbolInfo* s = new SymbolInfo();

if((yyvsp[-2])->Token!="error" && (yyvsp[0])->Token!="error"){
			if((yyvsp[-1])->name == "+"){
				if((yyvsp[-2])->type == "int" && (yyvsp[0])->type == "int"){
					s->ivalue = (yyvsp[-2])->ivalue + (yyvsp[0])->ivalue;
					s->type = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->type == "int" && (yyvsp[0])->type == "float"){
					s->fvalue = (yyvsp[-2])->ivalue + (yyvsp[0])->fvalue;
					s->type = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->type == "float" && (yyvsp[0])->type == "int"){
					s->fvalue = (yyvsp[-2])->fvalue + (yyvsp[0])->ivalue;
					s->type = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->type == "float" && (yyvsp[0])->type == "float"){
					s->fvalue = (yyvsp[-2])->fvalue + (yyvsp[0])->fvalue;
					s->type = "float";
					(yyval) = s;
				}
				else {
					yyerror("Incompatible addition");
s->Token="error";
				}

			}
			else if((yyvsp[-1])->name == "-"){
				if((yyvsp[-2])->type == "int" && (yyvsp[0])->type == "int"){
					s->ivalue = (yyvsp[-2])->ivalue - (yyvsp[0])->ivalue;
					s->type = "int";
					(yyval) = s;
				}
				else if((yyvsp[-2])->type == "int" && (yyvsp[0])->type == "float"){
					s->fvalue = (yyvsp[-2])->ivalue - (yyvsp[0])->fvalue;
					s->type = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->type == "float" && (yyvsp[0])->type == "int"){
					s->fvalue = (yyvsp[-2])->fvalue - (yyvsp[0])->ivalue;
					s->type = "float";
					(yyval) = s;
				}
				else if((yyvsp[-2])->type == "float" && (yyvsp[0])->type == "float"){
					s->fvalue = (yyvsp[-2])->fvalue - (yyvsp[0])->fvalue;
					s->type = "float";
					(yyval) = s;
				}
				else {
					yyerror("Incompatible addition");
s->Token="error";
				}
			}
}
else {s->Token="error";}

(yyval)=s;

(yyval)->code = (yyvsp[-2])->code;
(yyval)->code += (yyvsp[0])->code;
char *t=newTemp();
declaration += string(t) + " dw ?\n";
if((yyvsp[-1])->name=="+"){
	(yyval)->code += "mov ax," + (yyvsp[-2])->address + "\n";
	(yyval)->code += "add ax," + (yyvsp[0])->address + "\n";
	(yyval)->code += "mov "+ string(t) + ",ax\n";
}
else {
	(yyval)->code += "mov ax," + (yyvsp[-2])->address + "\n";
	(yyval)->code += "sub ax," + (yyvsp[0])->address + "\n";
	(yyval)->code += "mov "+ string(t) + ",ax\n";
}
(yyval)->address=string(t);

		}
#line 2939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1411 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: term : unary_expression\n\n",line_count);
			(yyval) = (yyvsp[0]);
			cout<<"return ue: "<<(yyvsp[0])->address<<endl;
		}
#line 2949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1416 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: term : term MULOP unary_expression\n\n",line_count);
						SymbolInfo* s = new SymbolInfo();
if((yyvsp[-2])->Token!="error" && (yyvsp[0])->Token!="error"){

fprintf(logout,"%s\n\n",(yyvsp[-1])->name.c_str());
			if((yyvsp[-1])->name == "*"){
				if((yyvsp[-2])->type == "int" && (yyvsp[0])->type == "int"){
					s->ivalue = (yyvsp[-2])->ivalue * (yyvsp[0])->ivalue;
					s->type = "int";
					//$$ = s;
				}
				else if((yyvsp[-2])->type == "int" && (yyvsp[0])->type == "float"){
					s->fvalue = (yyvsp[-2])->ivalue * (yyvsp[0])->fvalue;
					s->type = "float";
					//$$ = s;
				}
				else if((yyvsp[-2])->type == "float" && (yyvsp[0])->type == "int"){
					s->fvalue = (yyvsp[-2])->fvalue * (yyvsp[0])->ivalue;
					s->type = "float";
					//$$ = s;
				}
				else if((yyvsp[-2])->type == "float" && (yyvsp[0])->type == "float"){
					s->fvalue = (yyvsp[-2])->fvalue * (yyvsp[0])->fvalue;
					s->type = "float";
					//$$ = s;
				}
				else {
					yyerror("Incompatible Multiplication");
s->Token="error";
				}

			}
						else if((yyvsp[-1])->name == "/"){
				if((yyvsp[-2])->type == "int" && (yyvsp[0])->type == "int"){
					s->ivalue = (yyvsp[-2])->ivalue / (yyvsp[0])->ivalue;
					s->type = "int";
					//$$ = s;
				}
				else if((yyvsp[-2])->type == "int" && (yyvsp[0])->type == "float"){
					s->fvalue = (yyvsp[-2])->ivalue / (yyvsp[0])->fvalue;
					s->type = "float";
					//$$ = s;
				}
				else if((yyvsp[-2])->type == "float" && (yyvsp[0])->type == "int"){
					s->fvalue = (yyvsp[-2])->fvalue / (yyvsp[0])->ivalue;
					s->type = "float";
					//$$ = s;
				}
				else if((yyvsp[-2])->type == "float" && (yyvsp[0])->type == "float"){
					s->fvalue = (yyvsp[-2])->fvalue / (yyvsp[0])->fvalue;
					s->type = "float";
					//$$ = s;
				}
				else {
					yyerror("Incompatible Division");
s->Token="error";
				}

			}
			//mod
			else if((yyvsp[-1])->name == "%"){
				cout<<"Mod Variable : "<<(yyvsp[-2])->name<<" "<<(yyvsp[-2])->ivalue<<" "<<(yyvsp[-2])->type<<endl;
				cout<<"Mod Variable : "<<(yyvsp[0])->name<<" "<<(yyvsp[0])->ivalue<<" "<<(yyvsp[0])->type<<endl;
				if((yyvsp[-2])->type == "int" && (yyvsp[0])->type == "int"){
					s->ivalue = (yyvsp[-2])->ivalue % (yyvsp[0])->ivalue;
					cout<<s->ivalue<<endl;
					s->type = "int";
					//$$ = s;
				}
				else {
					yyerror("Non-Integer operand on modulus operator");
s->Token="error";
				}

			}
//code generation

			//cout << endl << $$->code << endl;
			//delete $3;
}
else {s->Token="error";}

(yyval)=s;
(yyval)->code = (yyvsp[-2])->code;
(yyval)->code += (yyvsp[0])->code;
(yyval)->code += "mov ax,"+ (yyvsp[-2])->address+"\n";
(yyval)->code += "mov bx,"+ (yyvsp[0])->address +"\n";
char *t=newTemp();
declaration += string(t) + " dw ?\n";
if((yyvsp[-1])->name=="*"){
	(yyval)->code += "mul bx\n";
	(yyval)->code += "mov "+ string(t) + ",ax\n";
}
else if((yyvsp[-1])->name=="/"){
	// clear dx, perform 'div bx' and mov ax to temp
	(yyval)->code += "mov dx,0\n";
	(yyval)->code += "div bx\n";
	(yyval)->code += "mov "+string(t)+",ax\n";
}
else{
	// clear dx, perform 'div bx' and mov dx to temp
	(yyval)->code += "mov dx,0\n";
	(yyval)->code += "div bx\n";
	(yyval)->code += "mov "+string(t)+",dx\n";
}
(yyval)->address=string(t);
		}
#line 3062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1526 "1405079.y" /* yacc.c:1646  */
    {
				fprintf(logout,"Line %d: unary_expression : ADDOP unary_expression\n\n",line_count);
SymbolInfo* temp = new SymbolInfo();
if((yyvsp[0])->Token!="error"){
				if((yyvsp[0])->name == "+"){
					(yyval) = (yyvsp[0]);
				}
				else if((yyvsp[0])->name == "-"){
					if(type == "int"){
						(yyval)->ivalue = (yyvsp[0])->ivalue * -1;
					}
					else if(type == "float"){
						(yyval)->fvalue = (yyvsp[0])->fvalue * -1;
					}
					temp->code=(yyvsp[0])->code;
					char *t=newTemp();
					declaration += string(t) + " dw ?\n";
					temp->code+="mov ax," + (yyvsp[0])->address + "\n";
					temp->code+="neg ax\n";
					temp->code+="mov "+string(t)+",ax";
					temp->address=string(t);

				}

}
else {temp->Token="error";}
(yyval)=temp;
}
#line 3095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1554 "1405079.y" /* yacc.c:1646  */
    {
fprintf(logout,"Line %d: unary_expression : NOT unary_expression\n\n",line_count);
SymbolInfo* temp = new SymbolInfo();

				if((yyvsp[0])->Token!="error"){

				if(type == "int"){
					if((yyvsp[0])->ivalue) {
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
				temp->code=(yyvsp[0])->code;
				char *t=newTemp();
				char *label1=newLabel();
				char *label2=newLabel();
				declaration += string(t) + " dw ?\n";
				temp->code+="mov ax," + (yyvsp[0])->address + "\n";
				temp->code+="cmp ax,0\n";
				temp->code+="je " + string(label1) + "\nmov " + string(t) +",0\njmp " + string(label2)+"\n";
				temp->code+=string(label1)+":\nmov "+string(t) + ",1\n" + string(label2) + ":\n";
				temp->address=string(t);

}
else {temp->Token="error";}

				(yyval) = temp;
			}
#line 3138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1592 "1405079.y" /* yacc.c:1646  */
    {
				fprintf(logout,"Line %d: unary_expression : factor\n\n",line_count);
				(yyval) = (yyvsp[0]);
			}
#line 3147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1598 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: factor : variable\n\n",line_count);
			(yyval)=(yyvsp[0]);

			if((yyval)->arraysize==-1){

			}
			else{
				char *t= newTemp();
				declaration += string(t) + " dw ?\n";
				(yyval)->code+="mov ax," + (yyvsp[0])->address + "[bx]\n";
				(yyval)->code+= "mov " + string(t) + ",ax\n";
				(yyval)->address=string(t);
			}
			cout<<"return var: "<<(yyval)->address<<endl;
		}
#line 3168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1614 "1405079.y" /* yacc.c:1646  */
    {

fprintf(logout,"Line %d: factor : ID LPAREN argument_list RPAREN\n\n",line_count);

SymbolInfo* si = new SymbolInfo();
SymbolInfo * s=table->Lookup((yyvsp[-3])->name);
if(s!=NULL)
{
if(s->fp==NULL)
{
yyerror((yyvsp[-3])->name+" is not a Function");
si = new SymbolInfo();
si->Token="error";
}
else
{

if(s->fp->params.size()!=args.size())
{
//fprintf(logout,"Error at Line %d: Total Number of Arguments mismatch in funtion %s\n\n",line_count,$1->getName().c_str());
yyerror("Total Number of Arguments mismatch in funtion "+(yyvsp[-3])->getName());
si = new SymbolInfo();
si->Token="error";
}
else{
	si->code=(yyvsp[-1])->code;
	for(int i=0;i<s->fp->params.size();i++)
	{
		if(s->fp->params[i].getType()!=args[i].getType())
		{
			//fprintf(logout,"Error at Line %d: %dth argument mismatch in function %s\n\n",line_count,i+1,$1->getName().c_str());
ostringstream oss;
oss<<i+1<<"th argument mismatch in function "<<(yyvsp[-2])->getName();
yyerror(oss.str());
si = new SymbolInfo();
si->Token="error";
		}
		si->code+="push "+args[i].address+"\n";

	}
si->code+="call "+(yyvsp[-3])->name+"\n";
if(s->fp->retaddress!="")si->address=s->fp->retaddress;

si->name=(yyvsp[-3])->name;
si->type=s->fp->retype;
}
}
}
else
{
yyerror("Undeclared Function "+(yyvsp[-3])->name);
si = new SymbolInfo();
si->Token="error";
}

si->ivalue=0;
si->fvalue=0;
(yyval)=si;
args.clear();
	}
#line 3233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1675 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: factor :  LPAREN expression RPAREN\n\n",line_count);
			(yyval) = (yyvsp[-1]);
		}
#line 3242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1679 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: factor : CONST_INT\n",line_count);
			fprintf(logout,"%d\n\n",(yyvsp[0])->ivalue);
			(yyval) = (yyvsp[0]);
			char *t= newTemp();
			declaration += string(t) + " dw ?\n";
			ostringstream oss;
			oss<<"mov " + string(t) + ","<<(yyvsp[0])->ivalue<<endl;
			(yyval)->code+=oss.str();
			(yyval)->address=string(t);
		}
#line 3258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1690 "1405079.y" /* yacc.c:1646  */
    {
			fprintf(logout,"Line %d: factor : CONST_FLOAT\n",line_count);
			fprintf(logout,"%lf\n\n",(yyvsp[0])->fvalue);
			(yyval) = (yyvsp[0]);
			char *t= newTemp();
			declaration += string(t) + " dw ?\n";
			ostringstream oss;
			oss<<"mov " + string(t) + ","<<(int)(yyvsp[0])->fvalue<<endl;
			(yyval)->code+=oss.str();
			(yyval)->address=string(t);
		}
#line 3274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1701 "1405079.y" /* yacc.c:1646  */
    {
if((yyvsp[-1])->Token!="error")
{
			fprintf(logout,"Line %d: factor : variable INCOP\n\n",line_count);
			if(type == "int"){
				(yyvsp[-1])->ivalue++;
			}
			else if(type == "float"){
				(yyvsp[-1])->fvalue++;
			}
			(yyvsp[-1])->code += "INC " + (yyvsp[-1])->address + "\n";
}
(yyval)=(yyvsp[-1]);
}
#line 3293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1715 "1405079.y" /* yacc.c:1646  */
    {
if((yyvsp[-1])->Token!="error")
{
			fprintf(logout,"Line %d: factor : variable DECOP\n\n",line_count);
			if(type == "int"){
				(yyvsp[-1])->ivalue--;
			}
			else if(type == "float"){
				(yyvsp[-1])->fvalue--;
			}
			(yyvsp[-1])->code += "DEC " + (yyvsp[-1])->address + "\n";

}
(yyval)=(yyvsp[-1]);
}
#line 3313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1732 "1405079.y" /* yacc.c:1646  */
    {
fprintf(logout,"Line %d: argument_list : argumets\n\n",line_count);
(yyval)=(yyvsp[0]);
}
#line 3322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1736 "1405079.y" /* yacc.c:1646  */
    {
fprintf(logout,"Line %d: argument_list : empty\n\n",line_count);
(yyval)= new SymbolInfo();
}
#line 3331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1744 "1405079.y" /* yacc.c:1646  */
    {
fprintf(logout,"Line %d: argument_list : argument_list COMMA logic_expression\n\n",line_count);
if((yyvsp[-2])->Token!="error" && (yyvsp[0])->Token!="error"){
args.push_back(*((yyvsp[0])));
(yyval)= new SymbolInfo();
}
else if((yyvsp[-2])->Token=="error")(yyval)=(yyvsp[-2]);
else (yyval)=(yyvsp[0]);

(yyval)->code=(yyvsp[-2])->code+(yyvsp[0])->code;
}
#line 3347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1756 "1405079.y" /* yacc.c:1646  */
    {
	fprintf(logout,"Line %d: argument_list : logic_expression\n\n",line_count);

	if((yyvsp[0])->Token!="error"){
	args.push_back(*((yyvsp[0])));
	}
	(yyval)=(yyvsp[0]);
}
#line 3360 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3364 "y.tab.c" /* yacc.c:1646  */
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
#line 1768 "1405079.y" /* yacc.c:1906  */


int main(int argc,char *argv[]){

	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}

	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}

	logout= fopen("log.txt","w");
	codes= fopen("code.asm","w");
	optimized= fopen("optimized.asm","w");
	error= fopen("error.txt","w");
	symtable= fopen("symtable.txt","w");

	yyin= fin;
	yyparse();
	fclose(yyin);
	fclose(logout);
	fclose(error);
	fclose(symtable);
	return 0;
}
