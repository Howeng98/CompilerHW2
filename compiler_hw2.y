/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    #include "string.h"
    #include "stdbool.h"
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    extern char* yytext;
    // extern char var_name[50];

    // char var_type[6];
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
    static int lookup_symbol(char* name);
    static void dump_symbol(void);
    void printList(struct symbol_table* head);
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */

%union {
    int i_val;
    float f_val;
    char *s_val;
    char *id;
    char *boool;
    char *type;    
}


/* Token without return */
%token ADD SUB MUL QUO REM
%token INT FLOAT BOOL STRING
%token INC DEC
%token GEQ LEQ EQL NEQ LST GTR
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token LAND LOR NOT
%token SEMICOLON
%token IF ELSE WHILE FOR PRINT
%token TRUE FALSE



%right LOR LAND
%left LST GTR GEQ LEQ NEQ EQL
%left ASSIGN
%left ADD SUB
%left ADD_ASSIGN SUB_ASSIGN
%left MUL QUO REM
%left MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%right NOT INC DEC 
%left '[' ']'
%nonassoc '(' ')'
%left SEMICOLON
%right Unary

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <id> IDENT

/* Nonterminal with return, which need to sepcify type */
%type <boool> LogicalExpr CompareExpr
%type <type> Expression ConversionExpr AssignmentExpr LoopCondition BoolExpr Assign ArithmeticExpr TermExpr Bool Num Type Bracket 
%type <id>   ID


/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : StatementList
;

StatementList
    : StatementList Statement SEMICOLON
    | Statement SEMICOLON
;

Statement
    : PRINT Bracket {
        printf("PRINT %s\n", $2);
    }
    | DeclarationStmt            
    | IfStmt
    | Expression
    | LoopStmt
    | Expression    
;

IfStmt
    : IF Expression {
        ;
    }
    | ELSE
;

LoopStmt
    : FOR LoopCondition
;

LoopCondition
    : Expression '{' {
        ;
    }
    | Expression ';' Expression ';' Expression '{' {
        ;
    }
;

DeclarationStmt
    : Type IDENT {
        insert_symbol($2, $1, yylineno, "-");
    }
    | IDENT '[' Expression ']' Type
    | IDENT Type '=' Expression
;

AssignmentExpr
    : IDENT '=' Expression {
        printf("ASSIGN\n");
    }
    | IDENT '[' Expression ']' '=' Expression
    | IDENT ADD_ASSIGN Expression
    | IDENT SUB_ASSIGN Expression
    | IDENT MUL_ASSIGN Expression
    | IDENT QUO_ASSIGN Expression
    | IDENT REM_ASSIGN Expression
;

Assign
    : ASSIGN { 
        $$ = "ASSIGN";
    }
    | ADD_ASSIGN { 
        $$ = "ADD_ASSIGN";
    }
    | SUB_ASSIGN { 
        $$ = "SUB_ASSIGN";
    }
    | MUL_ASSIGN { 
        $$ = "MUL_ASSIGN";
    }
    | QUO_ASSIGN { 
        $$ = "QUO_ASSIGN";
    }
    | REM_ASSIGN { 
        $$ = "REM_ASSIGN";
    }
;

Type
    : INT { 
        $$ = "int";
    }
    | FLOAT { 
        $$ = "float";
    }
    | STRING { 
        $$ = "string";
    }
    | BOOL { 
        $$ = "bool";
    }
;

Expression
    : AssignmentExpr 
    | ArithmeticExpr
    | ConversionExpr
    | TermExpr
    | BoolExpr      
;

ArithmeticExpr
    : Expression ADD Expression {
        printf("ADD\n");
    }
    | Expression SUB Expression {
        printf("SUB\n");
    }
    | Expression MUL Expression {
        printf("MUL\n");
    }
    | Expression QUO Expression {
        printf("QUO\n");
    }
    | Expression REM Expression {
        printf("REM\n");
    }
;

ConversionExpr
    : INT '(' IDENT ')'     {;}
    | FLOAT '(' IDENT ')'   {;}
    | INT '(' Num ')'       {;}
    | FLOAT '(' Num ')'     {;}
;

BoolExpr
    : LogicalExpr {
        $$ = "bool";
    }
    | CompareExpr {
        $$ = "bool";
    }
;

LogicalExpr
    : Expression LOR Expression {
        printf("OR\n");
    }
    | Expression LAND Expression {
        printf("AND\n");
    }
;

CompareExpr
    : Expression GTR Expression {
        printf("GTR\n"); 
    }
    | Expression LST Expression { 
        printf("LST\n"); 
    }
    | Expression GEQ Expression { 
        printf("GEQ\n"); 
    }
    | Expression LEQ Expression { 
        printf("LEQ\n"); 
    }
    | Expression EQL Expression { 
        printf("EQL\n"); 
    }
    | Expression NEQ Expression { 
        printf("NEQ\n"); 
    }
;

Bool
    : TRUE { 
        printf("TRUE\n");
        $$ = "bool";
    }
    | FALSE { 
        printf("FALSE\n"); 
        $$ = "bool";
    }
;

Num
    : INT_LIT { 
        printf("INT_LIT %d\n", $1); $$ = "int";
    }
    | FLOAT_LIT { 
        printf("FLOAT_LIT %f\n", $1); $$ = "float";
    }
;

TermExpr
    : ID 
    | ID '[' Expression ']'
    | Num
    | Bracket
    | Bool {
        $$ = "bool";
    }
    | TermExpr INC {
        printf("INC\n");
    }
    | TermExpr DEC {
        printf("DEC\n");
    }
    | ADD Num {        
        printf("POS\n");
        // $$ = $2;        
    }
    | SUB Num {        
        printf("NEG\n");        
        // $$ = $2;
    } 
    | NOT Expression {
        printf("NOT\n");
    }
;

ID
    : IDENT {
        // printf("IDENT (name)\n");
        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1));
    }
;

Bracket
    : '(' Expression ')'    { 
        $$=$2;
    }
    | '{'                   {;}
    | '}'                   {;}
;

%%

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
    node->index = index_in_each_scope[current_scope_level];
    index_in_each_scope[current_scope_level]++;
    strcpy(node->name, var_name);
    strcpy(node->type, var_type);
    node->address = address;
    address++;
    node->lineno = lineno;
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
            if(!strcmp(current->name, var_name) && current->scope_level==current_scope_level){
                return current->address;
            }else{
                current = current->next;
            }
        }
        if(!strcmp(current->name, var_name) && current->scope_level==current_scope_level){
                return current->address;
        }
        return -1;
    }    
}

static void dump_symbol(void){
    printf("> Dump symbol table (scope level: %d)\n", current_scope_level);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");    
    printList(head);

}

void printList(struct symbol_table* head){
    // printf("Linked_List:");
    if(head == NULL){
        // perror("Error:Head is NULL!");
        return;
    }
    else{
        current = head;
        while(current->next != NULL){
            printf("%-10d%-10s%-10s%-10d%-10d%s\n", current->index, current->name, current->type, current->address, current->lineno, current->element_type);
            current = current->next;
        }
        printf("%-10d%-10s%-10s%-10d%-10d%s\n", current->index, current->name, current->type, current->address, current->lineno, current->element_type);
    }
}