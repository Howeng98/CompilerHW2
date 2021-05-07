/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "compiler_hw2.y"

    #include "common.h" //Extern variables that communicate with lex
    #include "string.h"
    #include "stdbool.h"
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    extern char* yytext;
    
    int current_scope_level = 0;
    int address = 0;
    char arithmetic[5];
    int index_in_each_scope[5] = {0};

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Define a struct to store variables information */
    struct symbol_table{
        int index;
        int address;
        int lineno;
        int scope_level;
        int printed; // printed means the variable is dumped(printed)
        char name[10];
        char type[10];        
        char element_type[10];
        struct symbol_table* next;
    };

    struct symbol_table* head = NULL;
    struct symbol_table* node;
    struct symbol_table* current = NULL;
    struct symbol_table symbol_table[50];
    /* Symbol table function - you can add new function if needed. */
    static void create_symbol(void);
    static void insert_symbol(char* var_name, char* var_type, int lineno, char* element);
    static int lookup_symbol(char* var_name);
    static void dump_symbol(void);
    void printList(struct symbol_table* head);
    char* getType(char* var_name);

#line 118 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    ADD = 258,
    SUB = 259,
    MUL = 260,
    QUO = 261,
    REM = 262,
    INT = 263,
    FLOAT = 264,
    BOOL = 265,
    STRING = 266,
    INC = 267,
    DEC = 268,
    GEQ = 269,
    LEQ = 270,
    EQL = 271,
    NEQ = 272,
    LST = 273,
    GTR = 274,
    ASSIGN = 275,
    ADD_ASSIGN = 276,
    SUB_ASSIGN = 277,
    MUL_ASSIGN = 278,
    QUO_ASSIGN = 279,
    REM_ASSIGN = 280,
    LAND = 281,
    LOR = 282,
    NOT = 283,
    SEMICOLON = 284,
    IF = 285,
    ELSE = 286,
    WHILE = 287,
    FOR = 288,
    PRINT = 289,
    TRUE = 290,
    FALSE = 291,
    INT_LIT = 292,
    FLOAT_LIT = 293,
    STRING_LIT = 294,
    IDENT = 295
  };
#endif
/* Tokens.  */
#define ADD 258
#define SUB 259
#define MUL 260
#define QUO 261
#define REM 262
#define INT 263
#define FLOAT 264
#define BOOL 265
#define STRING 266
#define INC 267
#define DEC 268
#define GEQ 269
#define LEQ 270
#define EQL 271
#define NEQ 272
#define LST 273
#define GTR 274
#define ASSIGN 275
#define ADD_ASSIGN 276
#define SUB_ASSIGN 277
#define MUL_ASSIGN 278
#define QUO_ASSIGN 279
#define REM_ASSIGN 280
#define LAND 281
#define LOR 282
#define NOT 283
#define SEMICOLON 284
#define IF 285
#define ELSE 286
#define WHILE 287
#define FOR 288
#define PRINT 289
#define TRUE 290
#define FALSE 291
#define INT_LIT 292
#define FLOAT_LIT 293
#define STRING_LIT 294
#define IDENT 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 57 "compiler_hw2.y"

    int i_val;
    float f_val;
    char *s_val;
    char *id;
    char *boool;
    char *type;    

#line 259 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   457

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      35,    36,    43,    44,    45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   113,   113,   117,   120,   123,   129,   130,   133,   134,
     137,   143,   153,   156,   160,   163,   170,   173,   180,   183,
     186,   195,   198,   201,   204,   210,   211,   212,   213,   214,
     218,   221,   224,   227,   230,   233,   236,   242,   245,   248,
     251,   254,   260,   263,   269,   272,   278,   281,   287,   290,
     293,   296,   299,   302,   308,   312,   319,   320,   323,   327,
     328,   329,   332,   335,   338,   341,   344,   350,   354,   361,
     368,   371,   375
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "QUO", "REM", "INT",
  "FLOAT", "BOOL", "STRING", "INC", "DEC", "GEQ", "LEQ", "EQL", "NEQ",
  "LST", "GTR", "ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "QUO_ASSIGN", "REM_ASSIGN", "LAND", "LOR", "NOT", "SEMICOLON", "IF",
  "ELSE", "WHILE", "FOR", "PRINT", "TRUE", "FALSE", "'['", "']'", "'{'",
  "'}'", "'('", "')'", "INT_LIT", "FLOAT_LIT", "STRING_LIT", "IDENT",
  "';'", "$accept", "Program", "StatementList", "Statement", "PrintStmt",
  "IfStmt", "LoopStmt", "LoopCondition", "DeclarationStmt", "Type",
  "Expression", "AssignmentExpr", "ArithmeticExpr", "ConversionExpr",
  "BoolExpr", "LogicalExpr", "CompareExpr", "Bool", "TermExpr", "Num",
  "ID", "Bracket", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    91,    93,   123,
     125,    40,    41,   292,   293,   294,   295,    59
};
# endif

#define YYPACT_NINF (-23)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-61)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     143,   -22,   -22,   -23,   -23,   -23,   -23,   157,   157,   -23,
     157,   157,   -21,   -23,   -23,   -23,   -23,     4,   -23,   -23,
     -23,   -23,    11,   143,   -15,   -23,   -23,   -23,   -23,   -19,
     379,   -23,   -23,   -23,   -23,   -23,   -23,   -23,    12,   -23,
     -14,   -23,   -23,   -23,   -23,   379,   250,   -23,    79,   157,
     -23,    -5,    -1,   221,   -23,     2,   -23,   -11,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   -23,   -23,   157,   157,
     143,   157,   157,   177,   177,   -23,   -23,   157,   157,   432,
     432,     5,     5,     5,   427,   427,   427,   427,   427,   427,
      10,    10,   -23,   -23,   -23,   379,   379,   427,   304,   143,
     118,   379,   -23,     9,   -23,   379,   329,    53,   402,   157,
     157,   -23,   157,   278,   354,   427,   -23,   -23
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    21,    22,    24,    23,     0,     0,    13,
       0,     0,     0,    54,    55,    71,    72,     0,    67,    68,
      58,    69,     0,     2,     0,     6,     8,    10,     7,     0,
       9,    25,    26,    27,    29,    44,    45,    61,    28,    59,
      56,    60,    64,    65,    66,    12,     0,    14,     0,     0,
      11,     0,     0,     0,     1,     5,     4,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,    63,     0,     0,
       0,     0,     0,     0,     0,    70,     3,     0,     0,    37,
      38,    39,    40,    41,    50,    51,    52,    53,    49,    48,
      32,    33,    34,    35,    36,    47,    46,    30,     0,     0,
       0,    16,    42,    56,    43,    20,     0,    57,    15,     0,
       0,    19,     0,     0,     0,    31,    17,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -23,   -23,    -4,   -18,   -23,   -23,   -23,   -23,   -23,   -23,
      -7,   -23,   -23,   -23,   -23,   -23,   -23,   -23,    -6,    68,
       6,   -10
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    22,    23,    24,    25,    26,    27,    47,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      44,    45,    50,    46,    48,    55,    78,     1,     2,    87,
      53,    54,    51,    52,    56,    60,    61,    62,    15,    16,
      49,    18,    19,    79,    76,    77,    88,    57,    71,    72,
      73,    86,     7,    71,    72,    73,    80,    83,    82,    13,
      14,    84,    53,    15,    16,    17,   120,    18,    19,    20,
      21,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    42,
      43,   107,   108,   122,   110,   111,   109,   112,   114,     0,
     115,   116,    58,    59,    60,    61,    62,     0,     0,   113,
     113,    55,     0,    63,    64,    65,    66,    67,    68,   118,
      69,    70,    71,    72,    73,    74,    75,     0,     0,     0,
       0,     0,   123,   124,     0,   125,     0,     0,    15,    16,
      49,    58,    59,    60,    61,    62,    81,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,     1,     2,     0,     0,
       0,     3,     4,     5,     6,     0,     0,     0,     0,     0,
       1,     2,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     7,     0,     8,     9,    10,    11,    12,    13,    14,
       1,     2,    15,    16,    17,     7,    18,    19,    20,    21,
       0,     0,    13,    14,     0,     0,    15,    16,    17,     0,
      18,    19,    20,    21,     0,     7,     0,     0,     0,     0,
       0,     0,    13,    14,     0,     0,    15,    16,    49,     0,
      18,    19,    20,    21,    58,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,     0,
       0,     0,     0,    58,    59,    60,    61,    62,     0,     0,
       0,     0,     0,    85,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,     0,     0,
       0,    58,    59,    60,    61,    62,     0,     0,     0,    15,
      16,    49,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,     0,    58,    59,    60,
      61,    62,     0,     0,     0,     0,     0,   126,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    58,    59,    60,    61,    62,     0,     0,     0,
       0,     0,   117,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    58,    59,    60,
      61,    62,     0,     0,     0,     0,     0,   121,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    58,    59,    60,    61,    62,     0,     0,     0,
       0,     0,   127,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,   -60,   -60,   -60,
       0,     0,     0,     0,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,     0,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
      58,    59,    60,    61,    62,     0,     0,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,    69,    70,    71,    72,    73
};

static const yytype_int8 yycheck[] =
{
       7,     8,    12,    10,    11,    23,    20,     3,     4,    20,
      17,     0,     8,     9,    29,     5,     6,     7,    39,    40,
      41,    43,    44,    37,    12,    13,    37,    46,    23,    24,
      25,    29,    28,    23,    24,    25,    46,    42,    48,    35,
      36,    42,    49,    39,    40,    41,    37,    43,    44,    45,
      46,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     1,
       2,    78,    79,    20,    81,    82,    80,    83,    84,    -1,
      87,    88,     3,     4,     5,     6,     7,    -1,    -1,    83,
      84,   109,    -1,    14,    15,    16,    17,    18,    19,   109,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,   119,   120,    -1,   122,    -1,    -1,    39,    40,
      41,     3,     4,     5,     6,     7,    47,    -1,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    -1,    21,
      22,    23,    24,    25,    26,    27,     3,     4,    -1,    -1,
      -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
       3,     4,    39,    40,    41,    28,    43,    44,    45,    46,
      -1,    -1,    35,    36,    -1,    -1,    39,    40,    41,    -1,
      43,    44,    45,    46,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    39,    40,    41,    -1,
      43,    44,    45,    46,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    42,    14,    15,    16,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    39,
      40,    41,    14,    15,    16,    17,    18,    19,    -1,    21,
      22,    23,    24,    25,    26,    27,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    39,    14,    15,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    38,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    38,    14,    15,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    38,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,     5,     6,     7,
      -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
       3,     4,     5,     6,     7,    -1,    -1,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    21,    22,    23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     8,     9,    10,    11,    28,    30,    31,
      32,    33,    34,    35,    36,    39,    40,    41,    43,    44,
      45,    46,    49,    50,    51,    52,    53,    54,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    67,    67,    58,    58,    58,    55,    58,    41,
      69,     8,     9,    58,     0,    51,    29,    46,     3,     4,
       5,     6,     7,    14,    15,    16,    17,    18,    19,    21,
      22,    23,    24,    25,    26,    27,    12,    13,    20,    37,
      69,    47,    69,    42,    42,    42,    29,    20,    37,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    50,
      58,    58,    66,    68,    66,    58,    58,    38,    69,    47,
      37,    38,    20,    58,    58,    58,    39,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    51,    51,    51,    51,
      51,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      56,    57,    57,    57,    57,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      64,    64,    64,    64,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    67,    67,    68,
      69,    69,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     2,     1,     1,     1,     1,
       1,     2,     2,     1,     2,     5,     3,     6,     2,     5,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     6,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     4,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     4,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     1,     1,     1,
       3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 3:
#line 117 "compiler_hw2.y"
                                        {
        // printf("Stmt1\n");
    }
#line 1591 "y.tab.c"
    break;

  case 4:
#line 120 "compiler_hw2.y"
                         {
        // printf("Stmt2\n");
    }
#line 1599 "y.tab.c"
    break;

  case 5:
#line 123 "compiler_hw2.y"
                              {
        // printf("Stmt3\n");    
    }
#line 1607 "y.tab.c"
    break;

  case 7:
#line 130 "compiler_hw2.y"
                      {
        // printf("declaration\n");
    }
#line 1615 "y.tab.c"
    break;

  case 9:
#line 134 "compiler_hw2.y"
                 {
        // printf("expression\n");
    }
#line 1623 "y.tab.c"
    break;

  case 10:
#line 137 "compiler_hw2.y"
               {
        // printf("loopstmt\n");
    }
#line 1631 "y.tab.c"
    break;

  case 11:
#line 143 "compiler_hw2.y"
                    {
        printf("PRINT %s\n", (yyvsp[0].type));
    }
#line 1639 "y.tab.c"
    break;

  case 12:
#line 153 "compiler_hw2.y"
                    {
        ;
    }
#line 1647 "y.tab.c"
    break;

  case 14:
#line 160 "compiler_hw2.y"
                        {
        current_scope_level++;
    }
#line 1655 "y.tab.c"
    break;

  case 15:
#line 163 "compiler_hw2.y"
                                                    {
        // printf("------While END------\n");
        // current_scope_level++;
    }
#line 1664 "y.tab.c"
    break;

  case 16:
#line 170 "compiler_hw2.y"
                                    {
        // printf("LoopCondition1\n");
    }
#line 1672 "y.tab.c"
    break;

  case 17:
#line 173 "compiler_hw2.y"
                                                   {
        // printf("LoopCondition2\n");
    }
#line 1680 "y.tab.c"
    break;

  case 18:
#line 180 "compiler_hw2.y"
                 {
        insert_symbol((yyvsp[0].id), (yyvsp[-1].type), yylineno, "-");
    }
#line 1688 "y.tab.c"
    break;

  case 19:
#line 183 "compiler_hw2.y"
                                    {        
        insert_symbol((yyvsp[-3].id), "array", yylineno, (yyvsp[-4].type));        
    }
#line 1696 "y.tab.c"
    break;

  case 20:
#line 186 "compiler_hw2.y"
                                   {          
        insert_symbol((yyvsp[-2].id), (yyvsp[-3].type), yylineno, "-");
    }
#line 1704 "y.tab.c"
    break;

  case 21:
#line 195 "compiler_hw2.y"
          { 
        (yyval.type) = "int";
    }
#line 1712 "y.tab.c"
    break;

  case 22:
#line 198 "compiler_hw2.y"
            { 
        (yyval.type) = "float";
    }
#line 1720 "y.tab.c"
    break;

  case 23:
#line 201 "compiler_hw2.y"
             { 
        (yyval.type) = "string";
    }
#line 1728 "y.tab.c"
    break;

  case 24:
#line 204 "compiler_hw2.y"
           { 
        (yyval.type) = "bool";
    }
#line 1736 "y.tab.c"
    break;

  case 30:
#line 218 "compiler_hw2.y"
                           {
        printf("ASSIGN\n");
    }
#line 1744 "y.tab.c"
    break;

  case 31:
#line 221 "compiler_hw2.y"
                                              {                   
        printf("ASSIGN\n");
    }
#line 1752 "y.tab.c"
    break;

  case 32:
#line 224 "compiler_hw2.y"
                                       {
        printf("ADD_ASSIGN\n");
    }
#line 1760 "y.tab.c"
    break;

  case 33:
#line 227 "compiler_hw2.y"
                                       {
        printf("SUB_ASSIGN\n");
    }
#line 1768 "y.tab.c"
    break;

  case 34:
#line 230 "compiler_hw2.y"
                                       {
        printf("MUL_ASSIGN\n");
    }
#line 1776 "y.tab.c"
    break;

  case 35:
#line 233 "compiler_hw2.y"
                                       {
        printf("QUO_ASSIGN\n");
    }
#line 1784 "y.tab.c"
    break;

  case 36:
#line 236 "compiler_hw2.y"
                                       {
        printf("REM_ASSIGN\n");
    }
#line 1792 "y.tab.c"
    break;

  case 37:
#line 242 "compiler_hw2.y"
                                {
        printf("ADD\n");
    }
#line 1800 "y.tab.c"
    break;

  case 38:
#line 245 "compiler_hw2.y"
                                {
        printf("SUB\n");
    }
#line 1808 "y.tab.c"
    break;

  case 39:
#line 248 "compiler_hw2.y"
                                {
        printf("MUL\n");
    }
#line 1816 "y.tab.c"
    break;

  case 40:
#line 251 "compiler_hw2.y"
                                {
        printf("QUO\n");
    }
#line 1824 "y.tab.c"
    break;

  case 41:
#line 254 "compiler_hw2.y"
                                {
        printf("REM\n");
    }
#line 1832 "y.tab.c"
    break;

  case 42:
#line 260 "compiler_hw2.y"
                           {
        printf("F to I\n");
    }
#line 1840 "y.tab.c"
    break;

  case 43:
#line 263 "compiler_hw2.y"
                             {        
        printf("I to F\n");
    }
#line 1848 "y.tab.c"
    break;

  case 44:
#line 269 "compiler_hw2.y"
                  {
        (yyval.type) = "bool";
    }
#line 1856 "y.tab.c"
    break;

  case 45:
#line 272 "compiler_hw2.y"
                  {
        (yyval.type) = "bool";
    }
#line 1864 "y.tab.c"
    break;

  case 46:
#line 278 "compiler_hw2.y"
                                {
        printf("OR\n");
    }
#line 1872 "y.tab.c"
    break;

  case 47:
#line 281 "compiler_hw2.y"
                                 {
        printf("AND\n");
    }
#line 1880 "y.tab.c"
    break;

  case 48:
#line 287 "compiler_hw2.y"
                                {
        printf("GTR\n"); 
    }
#line 1888 "y.tab.c"
    break;

  case 49:
#line 290 "compiler_hw2.y"
                                { 
        printf("LST\n"); 
    }
#line 1896 "y.tab.c"
    break;

  case 50:
#line 293 "compiler_hw2.y"
                                { 
        printf("GEQ\n"); 
    }
#line 1904 "y.tab.c"
    break;

  case 51:
#line 296 "compiler_hw2.y"
                                { 
        printf("LEQ\n"); 
    }
#line 1912 "y.tab.c"
    break;

  case 52:
#line 299 "compiler_hw2.y"
                                { 
        printf("EQL\n"); 
    }
#line 1920 "y.tab.c"
    break;

  case 53:
#line 302 "compiler_hw2.y"
                                { 
        printf("NEQ\n"); 
    }
#line 1928 "y.tab.c"
    break;

  case 54:
#line 308 "compiler_hw2.y"
           { 
        printf("TRUE\n");
        (yyval.type) = "bool";
    }
#line 1937 "y.tab.c"
    break;

  case 55:
#line 312 "compiler_hw2.y"
            { 
        printf("FALSE\n"); 
        (yyval.type) = "bool";
    }
#line 1946 "y.tab.c"
    break;

  case 57:
#line 320 "compiler_hw2.y"
                            {
        (yyval.type) = (yyvsp[-3].id);
    }
#line 1954 "y.tab.c"
    break;

  case 58:
#line 323 "compiler_hw2.y"
                 {        
        printf("STRING_LIT %s\n", (yyvsp[0].s_val));
        (yyval.type) = "string";
    }
#line 1963 "y.tab.c"
    break;

  case 61:
#line 329 "compiler_hw2.y"
           {
        (yyval.type) = "bool";
    }
#line 1971 "y.tab.c"
    break;

  case 62:
#line 332 "compiler_hw2.y"
                   {
        printf("INC\n");
    }
#line 1979 "y.tab.c"
    break;

  case 63:
#line 335 "compiler_hw2.y"
                   {
        printf("DEC\n");
    }
#line 1987 "y.tab.c"
    break;

  case 64:
#line 338 "compiler_hw2.y"
              {        
        printf("POS\n");     
    }
#line 1995 "y.tab.c"
    break;

  case 65:
#line 341 "compiler_hw2.y"
              {        
        printf("NEG\n");        
    }
#line 2003 "y.tab.c"
    break;

  case 66:
#line 344 "compiler_hw2.y"
                     {
        printf("NOT\n");
    }
#line 2011 "y.tab.c"
    break;

  case 67:
#line 350 "compiler_hw2.y"
              {         
        printf("INT_LIT %d\n", (yyvsp[0].i_val));
        (yyval.type) = "int";
    }
#line 2020 "y.tab.c"
    break;

  case 68:
#line 354 "compiler_hw2.y"
                {         
        printf("FLOAT_LIT %f\n", (yyvsp[0].f_val));
        (yyval.type) = "float";        
    }
#line 2029 "y.tab.c"
    break;

  case 69:
#line 361 "compiler_hw2.y"
            {        
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id), lookup_symbol((yyvsp[0].id)));
        (yyval.id) = getType((yyvsp[0].id));
    }
#line 2038 "y.tab.c"
    break;

  case 70:
#line 368 "compiler_hw2.y"
                        { 
        (yyval.type)=(yyvsp[-1].type);
    }
#line 2046 "y.tab.c"
    break;

  case 71:
#line 371 "compiler_hw2.y"
          {        
        current_scope_level++;        
        // printf("--- Bracket Start ---\n");
    }
#line 2055 "y.tab.c"
    break;

  case 72:
#line 375 "compiler_hw2.y"
          {              
        dump_symbol();
        current_scope_level--;
        // printf("--- Bracket END ---\n");  
    }
#line 2065 "y.tab.c"
    break;


#line 2069 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 382 "compiler_hw2.y"


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    create_symbol();
    yyparse();
    
    dump_symbol();
	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void create_symbol(void){
    ;
}

static void insert_symbol(char* var_name, char* var_type, int lineno, char* element){    
    node = (struct symbol_table*)malloc(sizeof(struct symbol_table));
    node->next = NULL;
    node->scope_level = current_scope_level;
    /* node->index = index_in_each_scope[current_scope_level]; */
    /* index_in_each_scope[current_scope_level]++;     */
    strcpy(node->name, var_name);
    strcpy(node->type, var_type);
    node->address = address;
    address++;
    node->lineno = lineno;
    node->printed = 0;
    strcpy(node->element_type,element);

    if(head == NULL){
        head = node;
    }
    else{
        current = head;
        while(current->next != NULL){
            current = current->next;            
        }
        current->next = node;
    }
    printf("> Insert {%s} into symbol table (scope level: %d)\n",node->name, node->scope_level); 
}

static int lookup_symbol(char* var_name){
    current = head;
    if(head == NULL){
        return -1;
    }
    else{
        while(current->next != NULL){
            // **current->scope_level == current_scope_level**
            // make sure that current->scope_level is match current_scope_level

            // **current->scope_level == 0**
            // return current->address when the variable is define in global(scope_level 0)
            if(!strcmp(current->name, var_name) && (current->scope_level == current_scope_level || current->scope_level == 0) && current->printed == 0){
                return current->address;
            }
            current = current->next;            
        }
        if(!strcmp(current->name, var_name) && (current->scope_level == current_scope_level || current->scope_level == 0) && current->printed == 0){
            return current->address;
        }        
    }
    return 0;    
}

static void dump_symbol(void){    
    printf("> Dump symbol table (scope level: %d)\n", current_scope_level);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");    
    printList(head);

}

void printList(struct symbol_table* head){
    // printf("Linked_List:");
    int index = 0;
    if(head == NULL){
        perror("Error:Head is NULL!");
        return;
    }
    else{
        current = head;
        while(current->next != NULL){
            // printed means the variable is dumped(printed)
            if(current->scope_level == current_scope_level && current->printed == 0){
                printf("%-10d%-10s%-10s%-10d%-10d%s\n", index++, current->name, current->type, current->address, current->lineno, current->element_type);
                current->printed = 1;            
            }
            current = current->next;
        }
        if(current->scope_level == current_scope_level && current->printed == 0){
            printf("%-10d%-10s%-10s%-10d%-10d%s\n", index++, current->name, current->type, current->address, current->lineno, current->element_type);            
            current->printed = 1;
        }
    }
}

char* getType(char* var_name){
    if(head == NULL){
        perror("Error: Head is NULL");
        exit(EXIT_FAILURE);
    }
    else{        
        current = head;

        //FIXME: Try to use the following code to replace getType access linkedlist with go through node content before checking current->next != NULL

        /* do {
            if(!strcmp(current->name, var_name)){
                // If type is array, then return its element_type
                if(!strcmp(current->type, "array")){
                    return current->element_type;
                }                
                else
                    return current->type;
            }                       
        } while(current->next != NULL); */
        
        while(current->next != NULL){
            if(!strcmp(current->name, var_name)){
                // If type is array, then return its element_type
                if(!strcmp(current->type, "array")){
                    return current->element_type;
                }                
                else
                    return current->type;
            }
            current = current->next;
        }
        // current->next == NULL
        if(!strcmp(current->name, var_name)){
            // If type is array, then return its element_type
            if(!strcmp(current->type, "array")){
                return current->element_type;
            }                
            else
                return current->type;
        }        
    }
    return NULL;
}
