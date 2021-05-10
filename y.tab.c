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
#line 2 "compiler_hw2.y"

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
    int for_button = 0;
    int while_button = 0;
    bool scope_toggle = false;
    bool scope_toggle2 = false;
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
    // void TypeCheck(char* ,char*,char*,int ,char* );
    void TypeEqual(char* a,char*b,int line,char* action);

#line 122 "y.tab.c"

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
    LSS = 273,
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
#define LSS 273
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

#line 263 "y.tab.c"

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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  55
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   523

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       0,   104,   104,   107,   110,   113,   119,   120,   123,   124,
     127,   133,   143,   147,   155,   160,   167,   170,   173,   181,
     184,   187,   190,   195,   196,   197,   198,   199,   204,   210,
     213,   216,   219,   222,   225,   230,   238,   245,   249,   253,
     262,   266,   272,   273,   277,   287,   299,   303,   307,   311,
     315,   319,   325,   329,   335,   338,   341,   345,   349,   352,
     356,   359,   362,   367,   372,   379,   383,   389,   396,   399,
     403,   408,   413
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "QUO", "REM", "INT",
  "FLOAT", "BOOL", "STRING", "INC", "DEC", "GEQ", "LEQ", "EQL", "NEQ",
  "LSS", "GTR", "ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "QUO_ASSIGN", "REM_ASSIGN", "LAND", "LOR", "NOT", "SEMICOLON", "IF",
  "ELSE", "WHILE", "FOR", "PRINT", "TRUE", "FALSE", "'['", "']'", "'{'",
  "'}'", "'('", "')'", "INT_LIT", "FLOAT_LIT", "STRING_LIT", "IDENT",
  "$accept", "Program", "StatementList", "Statement", "PrintStmt",
  "IfStmt", "LoopStmt", "DeclarationStmt", "Type", "Expression",
  "AssignmentExpr", "ArithmeticExpr", "ConversionExpr", "BoolExpr",
  "LogicalExpr", "CompareExpr", "Bool", "TermExpr", "Num", "ID", "Bracket", YY_NULLPTR
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
     125,    40,    41,   292,   293,   294,   295
};
# endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-71)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     128,   -37,   -37,   -80,   -80,   -80,   -80,    50,   147,   -80,
     147,   -30,   147,   -80,   -80,   -80,   -80,   216,   -80,   -80,
     -80,   -80,     9,   128,    -9,   -80,   -80,   -80,   -80,   -14,
     473,   -80,   -80,   -80,   -80,   -80,   -80,   -80,    35,   -80,
     -16,   147,   -80,   -80,   147,   -80,   -80,    50,   -80,   -80,
      50,   -80,   -28,    -2,   279,   -80,    13,   -80,   -15,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,   -80,   -80,    50,
      50,   128,   419,   235,   235,   -80,   -80,    50,    50,   119,
     119,    74,    74,    74,    98,    98,    98,    98,    98,    98,
     284,   284,   -80,   -80,   -80,   473,   473,    98,    12,   172,
      50,   -80,     8,   -80,   473,   369,    57,   496,   446,    50,
     -80,    50,    50,   394,    98,   308,   -80,   147,   128,   128,
     339
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    19,    20,    22,    21,     0,    12,    13,
       0,     0,     0,    52,    53,    69,    70,     0,    65,    66,
      56,    67,     0,     2,     0,     6,     8,    10,     7,     0,
       9,    23,    24,    25,    27,    42,    43,    59,    26,    57,
      54,    58,    62,    63,     0,    64,    58,     0,    72,    71,
       0,    11,     0,     0,     0,     1,     5,     4,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    61,     0,
       0,     0,     0,     0,     0,    68,     3,     0,     0,    35,
      36,    37,    38,    39,    48,    49,    50,    51,    47,    46,
      30,    31,    32,    33,    34,    45,    44,    28,     0,     0,
       0,    40,    54,    41,    18,     0,    55,    14,     0,     0,
      17,     0,     0,     0,    29,     0,    55,     0,     0,     0,
      15
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   -80,   -79,   -22,   -80,   -80,   -80,   -80,   -80,    -4,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -59,    72,   -32,
       0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    56,   109,    45,    79,    87,    18,    19,    48,    55,
      49,    50,    51,    54,    83,    59,    60,    61,    62,    63,
      57,    80,    88,    41,   111,   113,    64,    65,    66,    67,
      68,    69,    58,    70,    71,    72,    73,    74,    75,    76,
      84,    81,    86,    54,    48,   119,    82,    77,    78,   129,
     116,   112,   112,     1,     2,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    42,    43,   107,   108,   121,     7,     0,
      44,    41,    10,   114,   115,    13,    14,    56,     0,    15,
      16,    17,     0,    18,    19,    20,    21,    72,    73,    74,
       0,    59,    60,    61,    62,    63,   118,    56,     0,    41,
       0,     0,     0,     0,     0,   123,     0,   124,   125,    70,
      71,    72,    73,    74,    61,    62,    63,   128,    41,   130,
      81,     1,     2,     0,     0,     0,     3,     4,     5,     6,
      70,    71,    72,    73,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     0,     8,     9,
      10,    11,    12,    13,    14,     0,     0,    15,    16,    17,
       0,    18,    19,    20,    21,     1,     2,    44,     0,    10,
       3,     4,     5,     6,     0,     0,    15,    16,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     0,     8,     9,    10,    11,    12,    13,    14,     0,
       0,    15,   117,    17,     0,    18,    19,    20,    21,     1,
       2,     0,     0,     0,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       0,     0,     0,     0,     7,     0,    44,     0,    10,     0,
       0,    13,    14,     0,     0,    15,    16,    17,     0,    18,
      19,    20,    21,     7,     0,    44,     0,    10,     0,     0,
      13,    14,     0,     0,    15,    16,    47,     0,    18,    19,
      20,    21,    59,    60,    61,    62,    63,     0,     0,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,     0,
      70,    71,    72,    73,    74,    75,    76,    72,    73,    74,
       0,    59,    60,    61,    62,    63,     0,     0,     0,     0,
       0,    85,    64,    65,    66,    67,    68,    69,     0,    70,
      71,    72,    73,    74,    75,    76,     0,     0,     0,     0,
       0,     0,     0,     0,   -58,   -58,   -58,     0,     0,     0,
     127,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,     0,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,     0,     0,    44,
       0,    10,    59,    60,    61,    62,    63,     0,     0,     0,
     -71,     0,     0,    64,    65,    66,    67,    68,    69,     0,
      70,    71,    72,    73,    74,    75,    76,    59,    60,    61,
      62,    63,     0,     0,     0,     0,     0,   120,    64,    65,
      66,    67,    68,    69,     0,    70,    71,    72,    73,    74,
      75,    76,    59,    60,    61,    62,    63,     0,     0,     0,
       0,     0,   126,    64,    65,    66,    67,    68,    69,     0,
      70,    71,    72,    73,    74,    75,    76,     0,   110,    59,
      60,    61,    62,    63,     0,     0,     0,     0,     0,     0,
      64,    65,    66,    67,    68,    69,     0,    70,    71,    72,
      73,    74,    75,    76,     0,   122,    59,    60,    61,    62,
      63,     0,     0,     0,     0,     0,     0,    64,    65,    66,
      67,    68,    69,     0,    70,    71,    72,    73,    74,    75,
      76,   -70,   -70,   -70,     0,     0,     0,     0,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,     0,   -70,   -70,   -70,
     -70,   -70,   -70,   -70
};

static const yytype_int16 yycheck[] =
{
       0,    23,    81,     7,    20,    20,    43,    44,     8,     0,
      10,    41,    12,    17,    42,     3,     4,     5,     6,     7,
      29,    37,    37,    23,    83,    84,    14,    15,    16,    17,
      18,    19,    46,    21,    22,    23,    24,    25,    26,    27,
      42,    41,    29,    47,    44,    37,    50,    12,    13,   128,
      38,    83,    84,     3,     4,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,     1,     2,    79,    80,    20,    28,    -1,
      30,    81,    32,    87,    88,    35,    36,   109,    -1,    39,
      40,    41,    -1,    43,    44,    45,    46,    23,    24,    25,
      -1,     3,     4,     5,     6,     7,   110,   129,    -1,   109,
      -1,    -1,    -1,    -1,    -1,   119,    -1,   121,   122,    21,
      22,    23,    24,    25,     5,     6,     7,   127,   128,   129,
     130,     3,     4,    -1,    -1,    -1,     8,     9,    10,    11,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    40,    41,
      -1,    43,    44,    45,    46,     3,     4,    30,    -1,    32,
       8,     9,    10,    11,    -1,    -1,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    40,    41,    -1,    43,    44,    45,    46,     3,
       4,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,    -1,
      -1,    35,    36,    -1,    -1,    39,    40,    41,    -1,    43,
      44,    45,    46,    28,    -1,    30,    -1,    32,    -1,    -1,
      35,    36,    -1,    -1,    39,    40,    41,    -1,    43,    44,
      45,    46,     3,     4,     5,     6,     7,    -1,    -1,     5,
       6,     7,    -1,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    23,    24,    25,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    42,    14,    15,    16,    17,    18,    19,    -1,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,     7,    -1,    -1,    -1,
      42,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      -1,    32,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      41,    -1,    -1,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    38,    14,    15,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    38,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     8,     9,    10,    11,    28,    30,    31,
      32,    33,    34,    35,    36,    39,    40,    41,    43,    44,
      45,    46,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    65,    65,    30,    56,    67,    41,    67,    67,
      41,    67,     8,     9,    56,     0,    50,    29,    46,     3,
       4,     5,     6,     7,    14,    15,    16,    17,    18,    19,
      21,    22,    23,    24,    25,    26,    27,    12,    13,    20,
      37,    67,    56,    42,    42,    42,    29,    20,    37,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    49,
      29,    64,    66,    64,    56,    56,    38,    40,    56,    37,
      38,    20,    29,    56,    56,    56,    38,    42,    67,    49,
      67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    50,    50,    50,    50,
      50,    51,    52,    52,    53,    53,    54,    54,    54,    55,
      55,    55,    55,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    58,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    62,    62,
      62,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    65,    66,    67,    67,
      67,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     2,     1,     1,     1,     1,
       1,     2,     1,     1,     4,    11,     2,     5,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     6,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     4,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     4,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     1,     1,     1,     3,     1,
       1,     2,     2
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
#line 107 "compiler_hw2.y"
                                        {
        // printf("Stmt1\n");
    }
#line 1611 "y.tab.c"
    break;

  case 4:
#line 110 "compiler_hw2.y"
                         {
        // printf("Stmt2\n");
    }
#line 1619 "y.tab.c"
    break;

  case 5:
#line 113 "compiler_hw2.y"
                              {
        // printf("Stmt3\n");    
    }
#line 1627 "y.tab.c"
    break;

  case 7:
#line 120 "compiler_hw2.y"
                      {
        // printf("declaration\n");
    }
#line 1635 "y.tab.c"
    break;

  case 9:
#line 124 "compiler_hw2.y"
                 {
        // printf("expression\n");
    }
#line 1643 "y.tab.c"
    break;

  case 10:
#line 127 "compiler_hw2.y"
               {
        // printf("loopstmt\n");
    }
#line 1651 "y.tab.c"
    break;

  case 11:
#line 133 "compiler_hw2.y"
                    {        
        printf("PRINT %s\n", (yyvsp[0].type));       
    }
#line 1659 "y.tab.c"
    break;

  case 12:
#line 143 "compiler_hw2.y"
         {
        if(scope_toggle)
            scope_toggle2 = true;
    }
#line 1668 "y.tab.c"
    break;

  case 13:
#line 147 "compiler_hw2.y"
           {
        scope_toggle = true;       
    }
#line 1676 "y.tab.c"
    break;

  case 14:
#line 155 "compiler_hw2.y"
                                        {        
        // if and while condition
        dump_symbol();
        current_scope_level--;
    }
#line 1686 "y.tab.c"
    break;

  case 15:
#line 160 "compiler_hw2.y"
                                                                                                     {
        // for condition        
    }
#line 1694 "y.tab.c"
    break;

  case 16:
#line 167 "compiler_hw2.y"
                 {
        insert_symbol((yyvsp[0].id), (yyvsp[-1].type), yylineno, "-");
    }
#line 1702 "y.tab.c"
    break;

  case 17:
#line 170 "compiler_hw2.y"
                                    {        
        insert_symbol((yyvsp[-3].id), "array", yylineno, (yyvsp[-4].type));        
    }
#line 1710 "y.tab.c"
    break;

  case 18:
#line 173 "compiler_hw2.y"
                                   {          
        insert_symbol((yyvsp[-2].id), (yyvsp[-3].type), yylineno, "-");
    }
#line 1718 "y.tab.c"
    break;

  case 19:
#line 181 "compiler_hw2.y"
          { 
        (yyval.type) = "int";
    }
#line 1726 "y.tab.c"
    break;

  case 20:
#line 184 "compiler_hw2.y"
            { 
        (yyval.type) = "float";
    }
#line 1734 "y.tab.c"
    break;

  case 21:
#line 187 "compiler_hw2.y"
             { 
        (yyval.type) = "string";
    }
#line 1742 "y.tab.c"
    break;

  case 22:
#line 190 "compiler_hw2.y"
           { 
        (yyval.type) = "bool";
    }
#line 1750 "y.tab.c"
    break;

  case 24:
#line 196 "compiler_hw2.y"
                     {(yyval.type) = (yyval.type);}
#line 1756 "y.tab.c"
    break;

  case 25:
#line 197 "compiler_hw2.y"
                     {(yyval.type) = (yyval.type);}
#line 1762 "y.tab.c"
    break;

  case 26:
#line 198 "compiler_hw2.y"
               {(yyval.type) = (yyval.type);}
#line 1768 "y.tab.c"
    break;

  case 27:
#line 199 "compiler_hw2.y"
               {
        (yyval.type) = "bool";
    }
#line 1776 "y.tab.c"
    break;

  case 28:
#line 204 "compiler_hw2.y"
                           {
        if(strcmp((yyvsp[-2].id),(yyvsp[0].type)) != 0){
            printf("error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", yylineno, (yyvsp[-2].id), (yyvsp[0].type));
        }
        printf("ASSIGN\n");
    }
#line 1787 "y.tab.c"
    break;

  case 29:
#line 210 "compiler_hw2.y"
                                              {                   
        printf("ASSIGN\n");
    }
#line 1795 "y.tab.c"
    break;

  case 30:
#line 213 "compiler_hw2.y"
                                       {
        printf("ADD_ASSIGN\n");
    }
#line 1803 "y.tab.c"
    break;

  case 31:
#line 216 "compiler_hw2.y"
                                       {
        printf("SUB_ASSIGN\n");
    }
#line 1811 "y.tab.c"
    break;

  case 32:
#line 219 "compiler_hw2.y"
                                       {
        printf("MUL_ASSIGN\n");
    }
#line 1819 "y.tab.c"
    break;

  case 33:
#line 222 "compiler_hw2.y"
                                       {
        printf("QUO_ASSIGN\n");
    }
#line 1827 "y.tab.c"
    break;

  case 34:
#line 225 "compiler_hw2.y"
                                       {
        printf("REM_ASSIGN\n");
    }
#line 1835 "y.tab.c"
    break;

  case 35:
#line 230 "compiler_hw2.y"
                                {        
        
        if(strcmp((yyvsp[-2].type),(yyvsp[0].type)) != 0){
            printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno, (yyvsp[-2].type), (yyvsp[0].type));
        }
        printf("ADD\n");
        // printf("$1=%s | $3=%s\n", $1, $3);        
    }
#line 1848 "y.tab.c"
    break;

  case 36:
#line 238 "compiler_hw2.y"
                                {
        if(strcmp((yyvsp[-2].type),(yyvsp[0].type)) != 0){
            printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno, (yyvsp[-2].type), (yyvsp[0].type));
        }
        printf("SUB\n");
        // printf("$1=%s | $3=%s\n", $1, $3);        
    }
#line 1860 "y.tab.c"
    break;

  case 37:
#line 245 "compiler_hw2.y"
                                {
        printf("MUL\n");
        // printf("$1=%s | $3=%s\n", $1, $3);        
    }
#line 1869 "y.tab.c"
    break;

  case 38:
#line 249 "compiler_hw2.y"
                                {
        printf("QUO\n");
        // printf("$1=%s | $3=%s\n", $1, $3);        
    }
#line 1878 "y.tab.c"
    break;

  case 39:
#line 253 "compiler_hw2.y"
                                {
        if(!strcmp((yyvsp[-2].type),"float")|| !strcmp((yyvsp[0].type),"float")){
            printf("error:%d: invalid operation: (operator REM not defined on float)\n", yylineno);
        }
        printf("REM\n");
        // printf("$1=%s | $3=%s\n", $1, $3);        
    }
#line 1890 "y.tab.c"
    break;

  case 40:
#line 262 "compiler_hw2.y"
                           {
        printf("F to I\n");
        (yyval.type) = "int";
    }
#line 1899 "y.tab.c"
    break;

  case 41:
#line 266 "compiler_hw2.y"
                             {        
        printf("I to F\n");
        (yyval.type) = "float";
    }
#line 1908 "y.tab.c"
    break;

  case 42:
#line 272 "compiler_hw2.y"
                  { (yyval.type) = (yyval.type);}
#line 1914 "y.tab.c"
    break;

  case 43:
#line 273 "compiler_hw2.y"
                  { (yyval.type) = (yyval.type);}
#line 1920 "y.tab.c"
    break;

  case 44:
#line 277 "compiler_hw2.y"
                                {
        if(strcmp((yyvsp[-2].type), "bool") != 0){
            printf("error:%d: invalid operation: (operator OR not defined on %s)\n", yylineno, (yyvsp[-2].type));
        }
        else if(strcmp((yyvsp[0].type), "bool") != 0){
            printf("error:%d: invalid operation: (operator OR not defined on %s)\n", yylineno, (yyvsp[0].type));
        }
        (yyval.boool) = (yyvsp[-2].type);
        printf("OR\n");
    }
#line 1935 "y.tab.c"
    break;

  case 45:
#line 287 "compiler_hw2.y"
                                 {
        if(strcmp((yyvsp[-2].type), "bool") != 0){
            printf("error:%d: invalid operation: (operator AND not defined on %s)\n", yylineno, (yyvsp[-2].type));
        }
        else if(strcmp((yyvsp[0].type), "bool") != 0){
            printf("error:%d: invalid operation: (operator AND not defined on %s)\n", yylineno, (yyvsp[0].type));
        }
        (yyval.boool) = (yyvsp[-2].type);
        printf("AND\n");
    }
#line 1950 "y.tab.c"
    break;

  case 46:
#line 299 "compiler_hw2.y"
                                {
        (yyval.boool) = (yyvsp[-2].type);
        printf("GTR\n");
    }
#line 1959 "y.tab.c"
    break;

  case 47:
#line 303 "compiler_hw2.y"
                                { 
        (yyval.boool) = (yyvsp[-2].type);
        printf("LSS\n"); 
    }
#line 1968 "y.tab.c"
    break;

  case 48:
#line 307 "compiler_hw2.y"
                                { 
        (yyval.boool) = (yyvsp[-2].type);
        printf("GEQ\n"); 
    }
#line 1977 "y.tab.c"
    break;

  case 49:
#line 311 "compiler_hw2.y"
                                { 
        (yyval.boool) = (yyvsp[-2].type);
        printf("LEQ\n"); 
    }
#line 1986 "y.tab.c"
    break;

  case 50:
#line 315 "compiler_hw2.y"
                                { 
        (yyval.boool) = (yyvsp[-2].type);
        printf("EQL\n"); 
    }
#line 1995 "y.tab.c"
    break;

  case 51:
#line 319 "compiler_hw2.y"
                                { 
        (yyval.boool) = (yyvsp[-2].type);
        printf("NEQ\n"); 
    }
#line 2004 "y.tab.c"
    break;

  case 52:
#line 325 "compiler_hw2.y"
           {
        (yyval.type) = "bool";
        printf("TRUE\n");        
    }
#line 2013 "y.tab.c"
    break;

  case 53:
#line 329 "compiler_hw2.y"
            { 
        (yyval.type) = "bool";
        printf("FALSE\n");        
    }
#line 2022 "y.tab.c"
    break;

  case 54:
#line 335 "compiler_hw2.y"
         {
        (yyval.type) = (yyvsp[0].id);
    }
#line 2030 "y.tab.c"
    break;

  case 55:
#line 338 "compiler_hw2.y"
                            {
        (yyval.type) = (yyvsp[-3].id);
    }
#line 2038 "y.tab.c"
    break;

  case 56:
#line 341 "compiler_hw2.y"
                 {        
        printf("STRING_LIT %s\n", (yyvsp[0].s_val));
        (yyval.type) = "string";
    }
#line 2047 "y.tab.c"
    break;

  case 57:
#line 345 "compiler_hw2.y"
          {
        (yyval.type) = (yyvsp[0].type);
        // printf("$$ = %s\n",$$);
    }
#line 2056 "y.tab.c"
    break;

  case 58:
#line 349 "compiler_hw2.y"
              {
        (yyval.type) = (yyval.type);
    }
#line 2064 "y.tab.c"
    break;

  case 59:
#line 352 "compiler_hw2.y"
           {
        (yyval.type) = (yyval.type);
        // printf("$$ = %s\n",$$);
    }
#line 2073 "y.tab.c"
    break;

  case 60:
#line 356 "compiler_hw2.y"
                   {
        printf("INC\n");
    }
#line 2081 "y.tab.c"
    break;

  case 61:
#line 359 "compiler_hw2.y"
                   {
        printf("DEC\n");
    }
#line 2089 "y.tab.c"
    break;

  case 62:
#line 362 "compiler_hw2.y"
              {          
        printf("POS\n");
        (yyval.type) = (yyvsp[0].type);
        // printf("$$ = %s\n",$$);
    }
#line 2099 "y.tab.c"
    break;

  case 63:
#line 367 "compiler_hw2.y"
              {        
        printf("NEG\n");        
        (yyval.type) = (yyvsp[0].type);
        // printf("$$ = %s\n",$$);
    }
#line 2109 "y.tab.c"
    break;

  case 64:
#line 372 "compiler_hw2.y"
                     {
        printf("NOT\n");
        (yyval.type) = (yyvsp[0].type);
        // printf("$$ = %s\n",$$);
    }
#line 2119 "y.tab.c"
    break;

  case 65:
#line 379 "compiler_hw2.y"
              {         
        printf("INT_LIT %d\n", (yyvsp[0].i_val));
        (yyval.type) = "int";
    }
#line 2128 "y.tab.c"
    break;

  case 66:
#line 383 "compiler_hw2.y"
                {         
        printf("FLOAT_LIT %f\n", (yyvsp[0].f_val));
        (yyval.type) = "float";
    }
#line 2137 "y.tab.c"
    break;

  case 67:
#line 389 "compiler_hw2.y"
            {        
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id), lookup_symbol((yyvsp[0].id)));
        (yyval.id) = getType((yyvsp[0].id));
    }
#line 2146 "y.tab.c"
    break;

  case 68:
#line 396 "compiler_hw2.y"
                        {        
        (yyval.type) = (yyvsp[-1].type);
    }
#line 2154 "y.tab.c"
    break;

  case 69:
#line 399 "compiler_hw2.y"
          {        
        current_scope_level++;
        // printf("--- Bracket Start ---\n");
    }
#line 2163 "y.tab.c"
    break;

  case 70:
#line 403 "compiler_hw2.y"
          {
        dump_symbol();
        current_scope_level--;
        // printf("--- Bracket END ---\n");  
    }
#line 2173 "y.tab.c"
    break;

  case 71:
#line 408 "compiler_hw2.y"
                    {
        if(strcmp((yyvsp[0].type),"bool")!=0){
            printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, (yyvsp[0].type));
        }
    }
#line 2183 "y.tab.c"
    break;

  case 72:
#line 413 "compiler_hw2.y"
                 {
        if(strcmp((yyvsp[0].type),"bool")!=0){
            printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, (yyvsp[0].type));
        }
    }
#line 2193 "y.tab.c"
    break;


#line 2197 "y.tab.c"

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
#line 421 "compiler_hw2.y"



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
    else {
        while(current->next != NULL){
            // **current->scope_level == current_scope_level**
            // make sure that current->scope_level is match current_scope_level

            // **current->scope_level == 0**
            // return current->address when the variable is define in global(scope_level 0)
            if(scope_toggle && scope_toggle2){
                current_scope_level++;
                if(!strcmp(current->name, var_name) && (current->scope_level == current_scope_level)){
                    scope_toggle = false;
                    scope_toggle2 = false;
                    current_scope_level--;
                    return current->address;
                }
                current_scope_level--;                 
            }
            else{
                if(!strcmp(current->name, var_name) && (current->scope_level == current_scope_level || current->scope_level == 0) && current->printed == 0){
                    return current->address;
                }
            }            
            current = current->next;            
        }
        if(scope_toggle && scope_toggle2){
                current_scope_level++;
                if(!strcmp(current->name, var_name) && (current->scope_level == current_scope_level)){
                    scope_toggle = false;
                    scope_toggle2 = false;
                    current_scope_level--;
                    return current->address;
                }
                current_scope_level--;
            }
        else{
            if(!strcmp(current->name, var_name) && (current->scope_level == current_scope_level || current->scope_level == 0) && current->printed == 0){
                return current->address;
            }
        }        
    }    
    return -1;    
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
        perror("Error:Head is NULL");
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
        perror("Error: Head is NULL！！！");
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

void TypeEqual(char* a,char*b,int line,char* action){
    if(strcmp(a,b)!=0)
    {
        printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",line,action,a,b);
    }  
}
