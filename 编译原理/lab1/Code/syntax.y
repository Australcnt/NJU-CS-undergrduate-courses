%{
    #include "lex.yy.c"
    #include "parsetree.h"

    // #define YYDEBUG 1
    int yyerror(char *msg);
    void printError(char *msg, int line);
%}

%locations
%start Program

/* declared types */
%union {
    struct Node* node;
}

/* declared tokens */
%token <node> STRUCT RETURN IF ELSE WHILE TYPE
%token <node> RELOP SEMI COMMA ASSIGNOP PLUS MINUS STAR DIV AND OR NOT DOT LP RP LB RB LC RC
%token <node> FLOAT INT ID

/* declared non-terminals */
%type <node> Program ExtDefList ExtDef ExtDecList
%type <node> Specifier StructSpecifier OptTag Tag
%type <node> VarDec FunDec VarList ParamDec
%type <node> CompSt StmtList Stmt
%type <node> DefList Def DecList Dec
%type <node> Exp Args

/* precedence and associativity*/
%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT NEG
%left LP RP LB RB DOT

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

/* High-level Definitions */
Program : ExtDefList                          { $$ = createNode("Program", @$.first_line, NON_TERMINAL, NULL); addChild($$, 1, $1); root = $$; }
    ;

ExtDefList : ExtDef ExtDefList                { $$ = createNode("ExtDefList", @$.first_line, NON_TERMINAL, NULL); addChild($$, 2, $1, $2); }
    | /* Empty */                             { $$ = createNode("ExtDefList", @$.first_line, NON_TERMINAL_NULL, NULL); }
    ;

ExtDef : Specifier ExtDecList SEMI            { $$ = createNode("ExtDef", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    | Specifier SEMI                          { $$ = createNode("ExtDef", @$.first_line, NON_TERMINAL, NULL); addChild($$, 2, $1, $2); }
    | Specifier FunDec CompSt                 { $$ = createNode("ExtDef", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    // Error Recovery
    | error SEMI                              { printError("error SEMI: Missing type or Wrong type", @1.first_line); yyerrok; }
    | Specifier error                         { printError("Specifier error: Missing ';'", @1.last_line); yyerrok; }
    | error CompSt                            { printError("error CompSt: Missing type or Wrong type", @1.first_line); yyerrok; }
    //| error Specifier SEMI                    { printError("error Specifier SEMI", @1.first_line); yyerrok; }
    //| Specifier error SEMI
    //| error RP
    //| error RC
    //| error Specifier error CompSt
    //| error ExtDef
    //| error CompSt
    //| Specifier error CompSt
    ;

ExtDecList : VarDec                           { $$ = createNode("ExtDecList", @$.first_line, NON_TERMINAL, NULL); addChild($$, 1, $1); }
    | VarDec COMMA ExtDecList                 { $$ = createNode("ExtDecList", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    // Error Recovery
    | VarDec error ExtDecList                 { printError("VarDec error ExtDecList: Missing ','", @2.first_line); yyerrok;}
    //| VarDec error                            { printError("VarDec error: Missing ';'", @1.last_line); yyerrok;}
    ;

/* Specifier */
Specifier : TYPE                              { $$ = createNode("Specifier", @$.first_line, NON_TERMINAL, NULL); addChild($$, 1, $1); }
    | StructSpecifier                         { $$ = createNode("Specifier", @$.first_line, NON_TERMINAL, NULL); addChild($$, 1, $1); }
    ;

StructSpecifier : STRUCT OptTag LC DefList RC { $$ = createNode("StructSpecifier", @$.first_line, NON_TERMINAL, NULL); addChild($$, 5, $1, $2, $3, $4, $5); }
    | STRUCT Tag                              { $$ = createNode("StructSpecifier", @$.first_line, NON_TERMINAL, NULL); addChild($$, 2, $1, $2); }
    // Error Recovery
    | STRUCT OptTag LC error RC               { printError("STRUCT OptTag LC error RC: Wrong struct definition", @4.first_line); yyerrok; }
    | STRUCT OptTag error RC                  { printError("STRUCT OptTag error RC: Missing '{'", @3.first_line); yyerrok; }
    | STRUCT error LC DefList RC              { printError("STRUCT error LC DefList RC: Wrong struct name", @2.first_line); yyerrok; }
    | error OptTag LC DefList RC              { printError("error OptTag LC DefList RC: Missing or wrong type", @1.first_line); yyerrok; }
    //| error RC
    //| STRUCT error RC
    //| error OptTag LC DefList RC
    //| STRUCT OptTag LC DefList error RC
    ;

OptTag : ID                                   { $$ = createNode("OptTag", @$.first_line, NON_TERMINAL, NULL); addChild($$, 1, $1); }
    | /* Empty */                             { $$ = createNode("OptTag", @$.first_line, NON_TERMINAL_NULL, NULL); }
    ;

Tag : ID                                      { $$ = createNode("Tag", @$.first_line, NON_TERMINAL, NULL); addChild($$, 1, $1); }
    ;

/* Declarators */
VarDec : ID                                   { $$ = createNode("VarDec", @$.first_line, NON_TERMINAL, NULL); addChild($$, 1, $1); }
    | VarDec LB INT RB                        { $$ = createNode("VarDec", @$.first_line, NON_TERMINAL, NULL); addChild($$, 4, $1, $2, $3, $4); }
    // Error Recovery
    | VarDec LB error RB                      { printError("VarDec LB error RB: Missing ']'", @3.first_line); yyerrok; }
    | error RB                                { printError("error RB: Missing ']'", @1.last_line); yyerrok; }
    //| VarDec LB error                         { printError("VarDec LB error: Missing ']'", @3.first_line); yyerrok; }
    //| error RB                                { printError("Missing ']'", @1.first_line); yyerrok; }
    //| VarDec LB error SEMI                    { printError("Missing ']'", @3.first_line); yyerrok; }
    ;

FunDec : ID LP VarList RP                     { $$ = createNode("FunDec", @$.first_line, NON_TERMINAL, NULL); addChild($$, 4, $1, $2, $3, $4); }
    | ID LP RP                                { $$ = createNode("FunDec", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    // Error Recovery
    | ID LP error RP                          { printError("ID LP error RP: Wrong arguments between ()", @3.first_line); yyerrok; }
    | ID error RP                             { printError("ID LP error: Missing '('", @2.first_line); yyerrok; }
    | error LP VarList RP                     { printError("error LP VarList RP: Wrong function name", @1.first_line); yyerrok; }
    //| ID LP error                             { printError("ID LP error: Missing ')'", @3.first_line); yyerrok; }
    //| error RP                                { printError("syntax error", @1.first_line); yyerrok; }
    ;

VarList : ParamDec COMMA VarList              { $$ = createNode("VarList", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    | ParamDec                                { $$ = createNode("VarList", @$.first_line, NON_TERMINAL, NULL); addChild($$, 1, $1); }
    ;

ParamDec : Specifier VarDec                   { $$ = createNode("ParamDec", @$.first_line, NON_TERMINAL, NULL); addChild($$, 2, $1, $2); }
    // Error Recovery
    //| error COMMA                           { printError("Missing ';'", @1.first_line); yyerrok; }
    //| error RP                              { printError("Missing ')'", @1.first_line); yyerrok; }
    ;

/* Statements */
CompSt : LC DefList StmtList RC               { $$ = createNode("CompSt", @$.first_line, NON_TERMINAL, NULL); addChild($$, 4, $1, $2, $3, $4); }
    // Error Recovery
    //| LC StmtList error RC                    { printError("LC StmtList error RC: Lack DefList", @3.first_line); yyerrok; }
    | LC error RC                             { printError("LC error RC: Wrong statements", @2.first_line); yyerrok;}
    //| error RC                                { printError("error RC: Missing '}'", @1.first_line); yyerrok; }
    //| LC DefList error RC
    ;

StmtList : Stmt StmtList                      { $$ = createNode("StmtList", @$.first_line, NON_TERMINAL, NULL); addChild($$, 2, $1, $2); }
    | /* Empty */                             { $$ = createNode("StmtList", @$.first_line, NON_TERMINAL_NULL, NULL); }
    // Error Recovery
    //| error StmtList                          { printError("error StmtList", @1.first_line); yyerrok; }
    //| Stmt error StmtList                     { printError("Stmt error StmtList", @2.first_line); yyerrok; }
    //| error StmtList                          { printError("error StmtList: StmtList Missing ';'", @1.first_line); yyerrok; }
    ;

Stmt : Exp SEMI                               { $$ = createNode("Stmt", @$.first_line, NON_TERMINAL, NULL); addChild($$, 2, $1, $2); }
    | CompSt                                  { $$ = createNode("Stmt", @$.first_line, NON_TERMINAL, NULL); addChild($$, 1, $1); }
    | RETURN Exp SEMI                         { $$ = createNode("Stmt", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE { $$ = createNode("Stmt", @$.first_line, NON_TERMINAL, NULL); addChild($$, 5, $1, $2, $3, $4, $5); }
    | IF LP Exp RP Stmt ELSE Stmt             { $$ = createNode("Stmt", @$.first_line, NON_TERMINAL, NULL); addChild($$, 7, $1, $2, $3, $4, $5, $6, $7); }
    | WHILE LP Exp RP Stmt                    { $$ = createNode("Stmt", @$.first_line, NON_TERMINAL, NULL); addChild($$, 5, $1, $2, $3, $4, $5); }
    // Error Recovery
    | error SEMI                              { printError("error SEMI: Wrong expression", @1.first_line); yyerrok; }
    | RETURN Exp error                        { printError("RETURN Exp error: Missing ';'", @2.last_line); yyerrok; }
    | RETURN error SEMI                       { printError("RETURN error SEMI: Wrong return value", @2.first_line); yyerrok; }
    | IF error RP ELSE Stmt                   { printError("IF error RP ELSE Stmt : Missing '('", @2.first_line); yyerrok; }
    | IF LP error ELSE Stmt                   { printError("IF LP error ELSE Stmt : Missing ')'", @3.first_line); yyerrok; }
    | WHILE error RP Stmt                     { printError("IF error RP ELSE Stmt : Missing '('", @2.first_line); yyerrok; }
    //| Exp error                               { printError("Exp error: Missing ';'", @2.first_line); yyerrok; }
    //| Exp error SEMI                          { printError("Exp error SEMI: Missing ';'", @2.first_line); yyerrok; }
    //| WHILE error RC
    //| error                                   { printError("Missing ';'", @1.first_line); yyerrok; }
    //| error Stmt
    //| IF LP error RP Stmt %prec LOWER_THAN_ELSE
    //| IF LP error RP Stmt ELSE Stmt           { printError("Missing ';'", @1.first_line); yyerrok; }
    //| WHILE LP error RP Stmt
	//| Exp LB error SEMI                       { printError("Missing ']'", @3.first_line); yyerrok; }
	//| IF LP error SEMI                        { printError("Missing ')'", @3.first_line); yyerrok; }
	//| LP Exp error SEMI                       { printError("Missing ')'", @3.first_line); yyerrok; }
	//| ID LP error SEMI                        { printError("Missing ')'", @3.first_line); yyerrok; }
    ;

/* Local Definitions */
DefList : Def DefList                         { $$ = createNode("DefList", @$.first_line, NON_TERMINAL, NULL); addChild($$, 2, $1, $2); }
    | /* Empty */                             { $$ = createNode("DefList", @$.first_line, NON_TERMINAL_NULL, NULL); }
    ;

Def : Specifier DecList SEMI                  { $$ = createNode("Def", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    // Error Recovery
    | Specifier error SEMI                    { printError("Specifier error SEMI: Missing or wrong ID", @2.first_line); yyerrok; }
    | error DecList SEMI                      { printError("error DecList SEMI: Missing or wrong type", @1.first_line); yyerrok; }
    
    //| Specifier DecList error SEMI            { printError("Specifier DecList error SEMI: Missing ';'", @3.first_line); yyerrok; }
    //| Specifier DecList error                 { printError("Specifier DecList error: Missing ';'", @3.first_line); yyerrok; }
    //| Specifier error                         { printError("Specifier error: Missing ';'", @2.first_line); yyerrok; }
    //| error SEMI
    //| Specifier DecList error SEMI
    ;

DecList : Dec                                 { $$ = createNode("DecList", @$.first_line, NON_TERMINAL, NULL); addChild($$, 1, $1); }
    | Dec COMMA DecList                       { $$ = createNode("DecList", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    // Error Recovery
    | Dec error DecList                       { printError("Dec error DecList: Missing ','", @2.first_line); yyerrok; }
    | Dec error                               { printError("Dec error: Missing ';''", @1.last_line); yyerrok; }
    //| Dec COMMA error                         { printError("Dec COMMA error: Missing ';''", @2.last_line); yyerrok; }
    ;

Dec : VarDec                                  { $$ = createNode("Dec", @$.first_line, NON_TERMINAL, NULL); addChild($$, 1, $1); }
    | VarDec ASSIGNOP Exp                     { $$ = createNode("Dec", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    // Error Recovery
    | VarDec ASSIGNOP error                   { printError("VarDec ASSIGNOP error: Wrong expression", @3.first_line); yyerrok; }
    ;

/* Expressions */
Exp : Exp ASSIGNOP Exp                        { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    | Exp AND Exp                             { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    | Exp OR Exp                              { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    | Exp RELOP Exp                           { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    | Exp PLUS Exp                            { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    | Exp MINUS Exp                           { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    | Exp STAR Exp                            { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    | Exp DIV Exp                             { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    | LP Exp RP                               { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    | MINUS Exp %prec NEG                     { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 2, $1, $2); }
    | NOT Exp                                 { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 2, $1, $2); }
    | ID LP Args RP                           { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 4, $1, $2, $3, $4); }
    | ID LP RP                                { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    | Exp LB Exp RB                           { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 4, $1, $2, $3, $4); }
    | Exp DOT ID                              { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    | ID                                      { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 1, $1); }
    | INT                                     { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 1, $1); }
    | FLOAT                                   { $$ = createNode("Exp", @$.first_line, NON_TERMINAL, NULL); addChild($$, 1, $1); }
    // Error Recovery
    | Exp ASSIGNOP error                      { printError("Exp ASSIGNOP error: Wrong expression", @3.first_line); yyerrok; }
    | Exp AND error                           { printError("Exp AND error: Wrong expression", @3.first_line); yyerrok; }
    | Exp OR error                            { printError("Exp OR error: Wrong expression", @3.first_line); yyerrok; }
    | Exp RELOP error                         { printError("Exp RELOP error: Wrong expression", @3.first_line); yyerrok; }
    | Exp PLUS error                          { printError("Exp PLUS error: Wrong expression", @3.first_line); yyerrok; }
    | Exp MINUS error                         { printError("Exp MINUS error: Wrong expression", @3.first_line); yyerrok; }
    | Exp STAR error                          { printError("Exp STAR error: Wrong expression", @3.first_line); yyerrok; }
    | Exp DIV error                           { printError("Exp DIV error: Wrong expression", @3.first_line); yyerrok; }
    | LP error RP                             { printError("LP error RP: Wrong expression", @2.first_line); yyerrok; }
    | MINUS error %prec NEG                   { printError("MINUS error: Wrong expression", @2.first_line); yyerrok; }
    | NOT error                               { printError("NOT error: Wrong expression", @2.first_line); yyerrok; }
    | ID LP error RP                          { printError("ID LP error RP: Wrong arguments between ()", @3.first_line); yyerrok; }
    //| ID LP error SEMI                        { printError("ID LP error SEMI: Missing ')'", @2.last_line); yyerrok; }
    | ID LP error                             { printError("ID LP error: Missing ')'", @2.last_line); yyerrok; }
    | Exp LB error RB                         { printError("Exp LB error RB: Error arguments between []", @3.first_line); yyerrok; }
    //| Exp error RB                            { printError("Exp error RB: Missing '['", @2.first_line); yyerrok; }
    //| Exp LB error SEMI                       { printError("Exp LB error SEMI: Missing ']'", @2.last_line); yyerrok; }
    | Exp LB error                            { printError("Exp LB error: Missing ']'", @2.last_line); yyerrok; }
    ;

Args : Exp COMMA Args                         { $$ = createNode("Args", @$.first_line, NON_TERMINAL, NULL); addChild($$, 3, $1, $2, $3); }
    | Exp                                     { $$ = createNode("Args", @$.first_line, NON_TERMINAL, NULL); addChild($$, 1, $1); }
    // Error Recovery
    //| Exp error Args                          { printError("Exp error Args : Missing ','", @2.last_line); yyerrok; }
    //| error COMMA Exp
    ;

%%

int yyerror(char* msg) {
    hasError = 1;
    missLine = yylineno;
    //printf("Error type B at Line %d: %s\n", yylineno, msg);
    return 0;
}

void printError(char* msg, int line) {
    hasError = 1;
    if (line > missLine) {
        printf("Error type B at Line %d: %s\n", missLine, "syntax error");
        missLine = line;
    }
    else if (line < missLine) {
        missLine = line;
    }
    if(line != lastErrorLine) {
        printf("Error type B at Line %d: %s\n", line, msg);
        lastErrorLine = line;
    }
    /*switch(yylval.node->type) {
        case TOKEN_TYPE:  printf("Error type B at Line %d: %s, before '%s'\n", line, msg, yylval.node->val.val_content); break;
        case TOKEN_FLOAT: printf("Error type B at Line %d: %s, before '%f'\n", line, msg, yylval.node->val.val_float);   break;
        case TOKEN_OCT:   printf("Error type B at Line %d: %s, before '%d'\n", line, msg, yylval.node->val.val_int);     break;
        case TOKEN_HEX:   printf("Error type B at Line %d: %s, before '%d'\n", line, msg, yylval.node->val.val_int);     break;
        case TOKEN_INT:   printf("Error type B at Line %d: %s, before '%d'\n", line, msg, yylval.node->val.val_int);     break;
        case TOKEN_ID:    printf("Error type B at Line %d: %s, before '%s'\n", line, msg, yylval.node->val.val_content); break;
        case TOKEN_OTHER: printf("Error type B at Line %d: %s, before '%s'\n", line, msg, yylval.node->val.val_content); break;
        default: break;
    }*/
}
