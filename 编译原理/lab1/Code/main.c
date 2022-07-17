#include "parsetree.h"

int yylex();
int yyparse(void);
void yyrestart(FILE *input_file);

extern int yydebug;

/*
extern FILE* yyin;

int main(int argc, char** argv) {
    if (argc > 1) {
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return 1;
        }
    }
    while (yylex() != 0);
    return 0;
}*/
int main(int argc, char** argv) {
    if (argc <= 1) return 1;
    FILE* f = fopen(argv[1], "r");
    if (!f) {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    // yydebug = 1;
    yyparse();
    if (missLine > lastErrorLine ) {
        printf("Error type B at Line %d: %s\n", missLine, "syntax error (other errors may exist after this line)");
    }
    if(!hasError) {
        printAST(root, 0);
    }
    return 0;
}