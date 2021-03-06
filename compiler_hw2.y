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
    bool validType(char* return_value);
    int reDeclared(char* var_name, char* var_type);
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
%token GEQ LEQ EQL NEQ LSS GTR
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token LAND LOR NOT
%token SEMICOLON
%token IF ELSE WHILE FOR PRINT
%token TRUE FALSE

/* Precedence of derivation of token */
%right LOR LAND
%left LSS GTR GEQ LEQ NEQ EQL
%left ASSIGN
// cannot put MUL QUO REM in the same line with ADD SUB, different line show different precedence
// MUL QUO REM should have deeper level than ADD SUB!
%left ADD SUB 
%left MUL QUO REM
%left ADD_ASSIGN SUB_ASSIGN 
%left MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%right NOT INC DEC 
%left SEMICOLON
%left '[' ']' 
%left '{' '}'
%nonassoc '(' ')'

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <id> IDENT

/* Nonterminal with return, which need to sepcify type */
%type <boool> LogicalExpr CompareExpr
%type <type> Expression ConversionExpr AssignmentExpr
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
    : StatementList Statement SEMICOLON    
    | StatementList Statement
    | Statement SEMICOLON
    | Statement
;

Statement
    : PrintStmt
    | DeclarationStmt
    | IfStmt
    | Expression
    | LoopStmt
;

PrintStmt
    : PRINT Bracket {        
        printf("PRINT %s\n", $2);       
    }

;

IfStmt    
    : Bracket Bracket StatementList '}' {
        dump_symbol();
        current_scope_level--;
    }
    | ELSE
;

LoopStmt
    : Bracket Bracket StatementList '}' {        
        // if and while condition
        dump_symbol();
        current_scope_level--;
    }
    | FOR '(' Expression SEMICOLON Expression SEMICOLON Expression ')' Bracket StatementList Bracket {
        // for condition
    }    
;

DeclarationStmt
    : Type IDENT {
        if(reDeclared($2, $1)==-1){
            insert_symbol($2, $1, yylineno, "-");
        }else{
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", yylineno, $2, reDeclared($2, $1));
        }   
    }
    | Type IDENT '[' Expression ']' {        
        if(reDeclared($2, $1)==-1){
            insert_symbol($2, "array", yylineno, $1);
        }else{
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", yylineno, $2, reDeclared($2, "array"));
        }   
    }
    | Type IDENT ASSIGN Expression {          
        insert_symbol($2, $1, yylineno, "-");
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
    | ArithmeticExpr {$$ = $$;}
    | ConversionExpr {$$ = $$;}
    | TermExpr { $$ = $$; }
    | BoolExpr { $$ = "bool"; }    
;
AssignmentExpr
    : ID ASSIGN Expression {
        if(validType($1) && validType($3)){
            if(strcmp($1,$3) != 0){
               printf("error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", yylineno, $1, $3);
            }
        }        
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
    | Num ASSIGN Expression {                
        printf("error:%d: cannot assign to %s\n", yylineno, $1);
        printf("ASSIGN\n");
    }
    | Num ADD_ASSIGN Expression {        
        printf("error:%d: cannot assign to %s\n", yylineno, $1);
        printf("ADD_ASSIGN\n");
    }
    | Num SUB_ASSIGN Expression {                
        printf("error:%d: cannot assign to %s\n", yylineno, $1);        
        printf("SUB_ASSIGN\n");
    }
    | Num MUL_ASSIGN Expression {        
        printf("error:%d: cannot assign to %s\n", yylineno, $1);        
        printf("MUL_ASSIGN\n");
    }
    | Num QUO_ASSIGN Expression {        
        printf("error:%d: cannot assign to %s\n", yylineno, $1);        
        printf("QUO_ASSIGN\n");
    }
    | Num REM_ASSIGN Expression {        
        printf("error:%d: cannot assign to %s\n", yylineno, $1);        
        printf("REM_ASSIGN\n");
    }    
;
ArithmeticExpr
    : Expression ADD Expression {                
        if(strcmp($1,$3) != 0){
            printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno, $1, $3);
        }
        printf("ADD\n");        
    }
    | Expression SUB Expression {
        if(strcmp($1,$3) != 0){
            printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno, $1, $3);
        }
        printf("SUB\n");        
    }
    | Expression MUL Expression {
        printf("MUL\n");        
    }
    | Expression QUO Expression {
        printf("QUO\n");        
    }
    | Expression REM Expression {
        if(!strcmp($1,"float")|| !strcmp($3,"float")){
            printf("error:%d: invalid operation: (operator REM not defined on float)\n", yylineno);
        }
        printf("REM\n");        
    }
;

ConversionExpr
    : '(' INT ')' TermExpr {
        printf("F to I\n");
        $$ = "int";
    }
    | '(' FLOAT ')' TermExpr {        
        printf("I to F\n");
        $$ = "float";
    }
;

BoolExpr
    : LogicalExpr { $$ = $$; }
    | CompareExpr { $$ = $$; }
;

LogicalExpr
    : Expression LOR Expression {
        if(strcmp($1, "bool") != 0){
            printf("error:%d: invalid operation: (operator OR not defined on %s)\n", yylineno, $1);
        }
        else if(strcmp($3, "bool") != 0){
            printf("error:%d: invalid operation: (operator OR not defined on %s)\n", yylineno, $3);
        }
        $$ = $1;
        printf("OR\n");
    }
    | Expression LAND Expression {
        if(strcmp($1, "bool") != 0){
            printf("error:%d: invalid operation: (operator AND not defined on %s)\n", yylineno, $1);
        }
        else if(strcmp($3, "bool") != 0){
            printf("error:%d: invalid operation: (operator AND not defined on %s)\n", yylineno, $3);
        }
        $$ = $1;
        printf("AND\n");
    }
;

CompareExpr
    : Expression GTR Expression {
        $$ = $1;
        printf("GTR\n");
    }
    | Expression LSS Expression { 
        $$ = $1;
        printf("LSS\n"); 
    }
    | Expression GEQ Expression { 
        $$ = $1;
        printf("GEQ\n"); 
    }
    | Expression LEQ Expression { 
        $$ = $1;
        printf("LEQ\n"); 
    }
    | Expression EQL Expression { 
        $$ = $1;
        printf("EQL\n"); 
    }
    | Expression NEQ Expression { 
        $$ = $1;
        printf("NEQ\n"); 
    }
;

Bool
    : TRUE {
        $$ = "bool";
        printf("TRUE\n");        
    }
    | FALSE { 
        $$ = "bool";
        printf("FALSE\n");        
    }
;

TermExpr
    : ID {
        $$ = $1;
    }
    | ID '[' Expression ']' {
        $$ = $1;
    }
    | STRING_LIT {        
        printf("STRING_LIT %s\n", $1);
        $$ = "string";
    }
    | Num {
        $$ = $1;        
    }
    | Bracket {
        $$ = $$;
    }
    | Bool {
        $$ = $$;        
    }
    | TermExpr INC {
        printf("INC\n");
    }
    | TermExpr DEC {
        printf("DEC\n");
    }
    | ADD Num {          
        printf("POS\n");
        $$ = $2;        
    }
    | SUB Num {        
        printf("NEG\n");        
        $$ = $2;        
    } 
    | NOT Expression {
        printf("NOT\n");
        $$ = $2;
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
        if(lookup_symbol($1) == -2){
            printf("error:%d: undefined: %s\n", yylineno, $1);
        }
        else{
            printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1));
            $$ = getType($1);
        }                
    }
;

Bracket
    : '(' Expression ')'{        
        $$ = $2;
    }
    | '{' {        
        current_scope_level++;        
    }
    | '}' {
        dump_symbol();
        current_scope_level--;
    }
    | WHILE Bracket {
        if(strcmp($2,"bool")!=0){
            printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, $2);
        }
    }
    | IF Bracket {
        if(strcmp($2,"bool")!=0){
            printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, $2);
        }
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
    int temp_scope_level = current_scope_level;
    current = head;
    if(head == NULL){
        return -1;
    }
    else{
        // go through the whole linkedList with scope_level == current_scope_level (local variable)
        while(current->next != NULL){
            if(!strcmp(current->name, var_name) && (current->scope_level == current_scope_level) && current->printed == 0){
                return current->address;
            }                                                
            current = current->next;
        }                
        if(!strcmp(current->name, var_name) && (current->scope_level == current_scope_level) && current->printed == 0){
            return current->address;
        }
        
        // go through the whole linkedList again with scope_level == temp_scope_level (global variable)
        while(temp_scope_level >= 0){
            current = head;
            while(current->next != NULL){
                /* printf("Loop tracking: scope:%d\n", temp_scope_level); */
                if(!strcmp(current->name, var_name) && (current->scope_level == temp_scope_level) && current->printed == 0){
                    return current->address;
                }
                current = current->next;
            }
            if(!strcmp(current->name, var_name) && (current->scope_level == temp_scope_level) && current->printed == 0){
                return current->address;
            }
            temp_scope_level--;
        }
        
        return -2;// ident not found, return -2
    }    
}

static void dump_symbol(void){                                                  
    printf("> Dump symbol table (scope level: %d)\n", current_scope_level);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");    
    printList(head);
}

void printList(struct symbol_table* head){    
    int index = 0;
    if(head == NULL){
        /* perror("Error:Head is NULL"); */
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
        perror("Error: Head is NULL?????????");
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

int reDeclared(char* var_name, char* var_type){
    if(head == NULL){        
        return -1;
    }
    else{
        current = head;
        // we can ignore to check type at here because redeclared is only work on same variable name
        while(current->next != NULL){
            if(!strcmp(current->name, var_name) && current->scope_level == current_scope_level){
                return current->lineno;
            }
            current = current->next;
        }
        if(!strcmp(current->name, var_name) && current->scope_level == current_scope_level){
            return current->lineno;
        }
    }
    return -1;
}

bool validType(char* return_value){
    // return TRUE means that return_value $$ is var_type,not variable name
    if(!strcmp(return_value, "int"))
        return true;    
    else if(!strcmp(return_value, "float"))
        return true;    
    else
        return false;
}