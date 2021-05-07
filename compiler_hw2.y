// TODO: Deadline 2021/05/27 23:59

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
%left '{' '}'
%nonassoc '(' ')'
%left SEMICOLON


/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <id> IDENT

/* Nonterminal with return, which need to sepcify type */
%type <boool> LogicalExpr CompareExpr
%type <type> Expression ConversionExpr AssignmentExpr LoopCondition
%type <type> BoolExpr ArithmeticExpr TermExpr Bool Num Type Bracket 
%type <id>   ID

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : StatementList 
;

StatementList
    : StatementList Statement SEMICOLON {
        // printf("Stmt1\n");
    }
    | Statement SEMICOLON{
        // printf("Stmt2\n");
    }
    | StatementList Statement {
        // printf("Stmt3\n");    
    }    
;

Statement
    : PrintStmt
    | DeclarationStmt {
        // printf("declaration\n");
    }
    | IfStmt
    | Expression {
        // printf("expression\n");
    }
    | LoopStmt {
        // printf("loopstmt\n");
    }
;

PrintStmt
    : PRINT Bracket {
        printf("PRINT %s\n", $2);
    }
    | PRINT '(' ID ')' {
        printf("PRINT %s\n", getType($3));
    }
;

IfStmt
    : IF Expression {
        ;
    }
    | ELSE
;

LoopStmt
    : FOR LoopCondition {
        current_scope_level++;
    }
    | WHILE Expression Bracket StatementList Bracket{
        // printf("------While END------\n");
        // current_scope_level++;
    }
;

LoopCondition
    : Expression Bracket Expression {
        // printf("LoopCondition1\n");
    }
    | Expression ';' Expression ';' Expression '{' {
        // printf("LoopCondition2\n");
    }
;


DeclarationStmt
    : Type IDENT {
        insert_symbol($2, $1, yylineno, "-");
    }
    | Type IDENT '[' Expression ']' {        
        insert_symbol($2, "array", yylineno, $1);        
    }
    | Type IDENT ASSIGN Expression {          
        insert_symbol($2, $1, yylineno, "-");
    }
    /* | Type IDENT ASSIGN STRING_LIT SEMICOLON{
        printf("STRING_LIT %s\n", $4);
    } */
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

AssignmentExpr
    : ID ASSIGN Expression {
        printf("ASSIGN\n");
    }
    | ID '[' Expression ']' ASSIGN Expression {                   
        printf("ASSIGN\n");
    }
    | Expression ADD_ASSIGN Expression {
        printf("ADD_ASSIGN\n");
    }
    | Expression SUB_ASSIGN Expression {
        printf("SUB_ASSIGN\n");
    }
    | Expression MUL_ASSIGN Expression {
        printf("MUL_ASSIGN\n");
    }
    | Expression QUO_ASSIGN Expression {
        printf("QUO_ASSIGN\n");
    }
    | Expression REM_ASSIGN Expression {
        printf("REM_ASSIGN\n");
    }
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

TermExpr
    : ID
    | ID '[' Expression ']' {
        $$ = getType($1);
    }
    | STRING_LIT {
        printf("STRING_LIT %s\n", $1);
    }
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
    }
    | SUB Num {        
        printf("NEG\n");        
    } 
    | NOT Expression {
        printf("NOT\n");
    }    
;

Num
    : INT_LIT {         
        printf("INT_LIT %d\n", $1);
        $$ = "int";
    }
    | FLOAT_LIT {         
        printf("FLOAT_LIT %f\n", $1);
        $$ = "float";        
    }
;

ID
    : IDENT {        
        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1));
    }
;

Bracket
    : '(' Expression ')'{ 
        $$=$2;
    }    
    | '{' {        
        current_scope_level++;        
        // printf("--- Bracket Start ---\n");
    }
    | '}' {              
        dump_symbol();
        current_scope_level--;
        // printf("--- Bracket END ---\n");  
    }
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