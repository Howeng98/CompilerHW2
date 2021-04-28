/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    extern char* yytext;
    extern char var_name[50];

    char var_type[6];
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
    static void insert_symbol();
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
    /* ... */
}

/* Token without return */
%token VAR
%token ADD SUB MUL QUO REM
%token INT FLOAT BOOL STRING
%token INC DEC
%token GEQ LEQ EQL NEQ LST GTR
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token LAND LOR NOT
%token NEWLINE SEMICOLON
%token IF ELSE WHILE FOR PRINT PRINTLN
%token TRUE FALSE

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <s_val> IDENT

/* Nonterminal with return, which need to sepcify type */

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : StatementList     
;

StatementList
    : StatementList Statement
    | Statement
;

Statement
    : DeclarationStmt    
    | AssignmentStmt
    | IncDecStmt
    | Block
    | IfStmt
    | WhileStmt
    | ForStmt
    | PrintStmt
    | Expression
;

Type
    : TypeName
;

TypeName
    : INT   {
        // printf("Int here\n");
        strcpy(var_type,"int");
    }
    | FLOAT {
        // printf("Float here\n");
        strcpy(var_type,"float");
    }
    | STRING    {
        printf("String here\n");
    }
    | BOOL  {
        printf("Bool here\n");
    }
;

Expression
    : UnaryExpr    
    | Expression ADD Expression SEMICOLON{
        printf("ADD\n");
    }
    | Expression SUB Expression SEMICOLON{
        printf("SUB\n");
    }
    | Expression MUL Expression SEMICOLON{
        printf("MUL\n");
    }
    | Expression QUO Expression SEMICOLON{
        printf("QUO\n");
    }
    | Expression REM Expression SEMICOLON{
        printf("REM\n");
    }
;

UnaryExpr
    : PrimaryExpr    
    | unary_op UnaryExpr
    | binary_op
;

unary_op
    : NOT
;

binary_op
    : LOR
    | LAND
    | cmp_op
    | add_op
    | mul_op
;

cmp_op
    : EQL
    | NEQ
    | LST
    | LEQ
    | GTR
    | GEQ
;

add_op
    : ADD {        
        printf("ADD\n");
    }
    | SUB {
        printf("SUB\n");
    }
;

mul_op
    : MUL {
        printf("MUL\n");
    }
    | QUO {
        printf("QUO\n");
    }
    | REM {
        printf("REM\n");
    }
;


PrimaryExpr
    : Operand 
    | IndexExpr
    | ConversionExpr
;

Operand
    : Literal
    | IDENT {
        printf("IDENT (name=%s, address=%d)\n", var_name, lookup_symbol(var_name));
    }
    | '(' Expression ')'
;

Literal
    : INT_LIT {
        printf("INT_LIT %d\n", $<i_val>$);
    }
    | FLOAT_LIT {
        printf("FLOAT_LIT %f\n", $<f_val>$);
    }
    | STRING_LIT {
        ;
    }
;

IndexExpr
    : PrimaryExpr '[' Expression ']'
;

ConversionExpr
    : Type '(' Expression ')'
;


DeclarationStmt
    : Type IDENT '[' ASSIGN Expression ']' SEMICOLON
    | Type IDENT '[' Expression ']' SEMICOLON
    | Type IDENT SEMICOLON {
        insert_symbol();
    }
;

AssignmentExpr
    : Expression assign_op Expression
;

AssignmentStmt
    : AssignmentExpr SEMICOLON
;

assign_op
    : ASSIGN
    | ADD_ASSIGN
    | SUB_ASSIGN
    | MUL_ASSIGN
    | QUO_ASSIGN
    | REM_ASSIGN
;

IncDecExpr
    : INC {
        printf("INC\n");
    }
    | DEC {
        printf("DEC\n");
    }
;

IncDecStmt
    : Expression IncDecExpr SEMICOLON
;

Block
    : '{' StatementList '}'
;

// StatementList
//     : { Statement }
// ;

IfStmt
    : IF Condition Block 
    | ELSE
;

Condition
    : Expression
;

WhileStmt
    : WHILE '(' Condition ')' Block
;

ForStmt
    : FOR '(' ForClause ')' Block
;

ForClause
    : InitStmt SEMICOLON Condition SEMICOLON PostStmt
;

InitStmt
    : SimpleExpr
;

PostStmt
    : SimpleExpr
;

SimpleExpr
    : AssignmentExpr
    | Expression
    | IncDecExpr
;

PrintStmt
    : PRINT '(' Expression ')' SEMICOLON
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

static void insert_symbol(void){
    node = (struct symbol_table*)malloc(sizeof(struct symbol_table));
    node->next = NULL;
    node->index = index_in_each_scope[current_scope_level];
    index_in_each_scope[current_scope_level]++;
    strcpy(node->name, var_name);
    strcpy(node->type, var_type);
    node->address = address;
    address++;
    node->lineno = yylineno;
    strcpy(node->element_type,"-");

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
        perror("Error:Head is NULL!");
        exit(EXIT_FAILURE);
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