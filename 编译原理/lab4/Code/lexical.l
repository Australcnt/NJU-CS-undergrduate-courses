%{
    #include "syntax.tab.h"
    #include "parsetree.h"
    
    int yycolumn = 1;
    #define YY_USER_ACTION \
        yylloc.first_line = yylloc.last_line = yylineno; \
        yylloc.first_column = yycolumn; \
        yylloc.last_column = yycolumn + yyleng - 1; \
        yycolumn += yyleng;
%}

%option yylineno

DELIM           [ \n\r\t\v\f]
WS              {DELIM}+
STRUCT          "struct"
RETURN          "return"
IF              "if"
ELSE            "else"
WHILE           "while"
TYPE            "int"|"float"
RELOP           ">"|"<"|">="|"<="|"=="|"!="
SEMI            ";"
COMMA           ","
ASSIGNOP        "="
PLUS            "+"
MINUS           "-"
STAR            "*"
DIV             "/"
AND             "&&"
OR              "||"
NOT             "!"
DOT             "."
LP              "("
RP              ")"
LB              "["
RB              "]"
LC              "{"
RC              "}"
DIGIT           [0-9]
DIGITS          {DIGIT}+
LETTER_         [a-zA-Z_]
FLOAT           {DIGITS}\.{DIGITS}
OCTERROR        0[0-7]*[8-9]+[0-9]*
OCT             0[0-7]+
HEXERROR        0[xX][0-9a-fA-F]*[g-zG-Z]+[0-9a-zA-Z]*|0[xX] 
HEX             0[xX][0-9a-fA-F]+
IDERROR         {DIGIT}+{LETTER_}({LETTER_}|{DIGIT})*
INT             0|[1-9]{DIGIT}*
ID              {LETTER_}({LETTER_}|{DIGIT})*

%%

\n              { yycolumn = 1; }
{WS}            { /*printf("WS\n");*/ }
{STRUCT}        { /*printf("STRUCT\n");*/   yylval.node = createNode("STRUCT",   yylineno, TOKEN_OTHER, yytext); return STRUCT; }
{RETURN}        { /*printf("RETURN\n");*/   yylval.node = createNode("RETURN",   yylineno, TOKEN_OTHER, yytext); return RETURN; }
{IF}            { /*printf("IF\n");*/       yylval.node = createNode("IF",       yylineno, TOKEN_OTHER, yytext); return IF; }
{ELSE}          { /*printf("ELSE\n");*/     yylval.node = createNode("ELSE",     yylineno, TOKEN_OTHER, yytext); return ELSE; }
{WHILE}         { /*printf("WHILE\n");*/    yylval.node = createNode("WHILE",    yylineno, TOKEN_OTHER, yytext); return WHILE; }
{TYPE}          { /*printf("TYPE\n");*/     yylval.node = createNode("TYPE",     yylineno, TOKEN_TYPE,  yytext); return TYPE; }
{RELOP}         { /*printf("RELOP\n");*/    yylval.node = createNode("RELOP",    yylineno, TOKEN_OTHER, yytext); return RELOP; }
{SEMI}          { /*printf("SEMI\n");*/     yylval.node = createNode("SEMI",     yylineno, TOKEN_OTHER, yytext); return SEMI; }
{COMMA}         { /*printf("COMMA\n");*/    yylval.node = createNode("COMMA",    yylineno, TOKEN_OTHER, yytext); return COMMA; }
{ASSIGNOP}      { /*printf("ASSIGNOP\n");*/ yylval.node = createNode("ASSIGNOP", yylineno, TOKEN_OTHER, yytext); return ASSIGNOP; }
{PLUS}          { /*printf("PLUS\n");*/     yylval.node = createNode("PLUS",     yylineno, TOKEN_OTHER, yytext); return PLUS; }
{MINUS}         { /*printf("MINUS\n");*/    yylval.node = createNode("MINUS",    yylineno, TOKEN_OTHER, yytext); return MINUS; }
{STAR}          { /*printf("STAR\n");*/     yylval.node = createNode("STAR",     yylineno, TOKEN_OTHER, yytext); return STAR; }
{DIV}           { /*printf("DIV\n");*/      yylval.node = createNode("DIV",      yylineno, TOKEN_OTHER, yytext); return DIV; }
{AND}           { /*printf("AND\n");*/      yylval.node = createNode("AND",      yylineno, TOKEN_OTHER, yytext); return AND; }
{OR}            { /*printf("OR\n");*/       yylval.node = createNode("OR",       yylineno, TOKEN_OTHER, yytext); return OR; }
{NOT}           { /*printf("NOT\n");*/      yylval.node = createNode("NOT",      yylineno, TOKEN_OTHER, yytext); return NOT; }
{DOT}           { /*printf("DOT\n");*/      yylval.node = createNode("DOT",      yylineno, TOKEN_OTHER, yytext); return DOT; }
{LP}            { /*printf("LP\n");*/       yylval.node = createNode("LP",       yylineno, TOKEN_OTHER, yytext); return LP; }
{RP}            { /*printf("RP\n");*/       yylval.node = createNode("RP",       yylineno, TOKEN_OTHER, yytext); return RP; }
{LB}            { /*printf("LB\n");*/       yylval.node = createNode("LB",       yylineno, TOKEN_OTHER, yytext); return LB; }
{RB}            { /*printf("RB\n");*/       yylval.node = createNode("RB",       yylineno, TOKEN_OTHER, yytext); return RB; }
{LC}            { /*printf("LC\n");*/       yylval.node = createNode("LC",       yylineno, TOKEN_OTHER, yytext); return LC; }
{RC}            { /*printf("RC\n");*/       yylval.node = createNode("RC",       yylineno, TOKEN_OTHER, yytext); return RC; }
{FLOAT}         { /*printf("FLOAT\n");*/    yylval.node = createNode("FLOAT",    yylineno, TOKEN_FLOAT, yytext); return FLOAT; }                
{OCTERROR}      { printf("Error type A at Line %d: Illegal octal number \'%s\'\n", yylineno, yytext); hasError = 1;
                                            yylval.node = createNode("INT",      yylineno, TOKEN_OCT,   yytext); return INT; }
{OCT}           { /*printf("OCT\n");*/      yylval.node = createNode("INT",      yylineno, TOKEN_OCT,   yytext); return INT; }
{HEXERROR}      { printf("Error type A at Line %d: Illegal hexadecimal number \'%s\'\n", yylineno, yytext); hasError = 1;
                                            yylval.node = createNode("INT",      yylineno, TOKEN_HEX,   yytext); return INT; }
{HEX}           { /*printf("HEX\n");*/      yylval.node = createNode("INT",      yylineno, TOKEN_HEX,   yytext); return INT; }
{IDERROR}       { printf("Error type A at Line %d: Illegal ID \'%s\'\n", yylineno, yytext); hasError = 1;
                                            yylval.node = createNode("ID",       yylineno, TOKEN_ID,    yytext); return ID; }
{INT}           { /*printf("INT\n");*/      yylval.node = createNode("INT",      yylineno, TOKEN_INT,   yytext); return INT; }
{ID}            { /*printf("ID\n");*/       yylval.node = createNode("ID",       yylineno, TOKEN_ID,    yytext); return ID; }
.               { printf("Error type A at Line %d: Mysterious characters \'%s\'\n", yylineno, yytext); hasError = 1; }

%%
