#ifndef _PARSETREE_H_
#define _PARSETREE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

typedef enum {
    TOKEN_TYPE, TOKEN_FLOAT, TOKEN_OCT, TOKEN_HEX, TOKEN_INT, TOKEN_ID, TOKEN_OTHER, NON_TERMINAL, NON_TERMINAL_NULL
} Type;

typedef struct Node {
    char* name;
    int line;
    Type type;
    union {
        unsigned val_int;
        float val_float;
        char val_content[33];
    } val;
    struct Node* firstChild;
    struct Node* nextSibling;
} Node;

extern int hasError;
extern Node* root;
extern int missLine;
extern int lastErrorLine;

Node* createNode(char* name, int line, Type type, char* val);
void addChild(Node* parent, int childNum, ...);
void printAST(Node* cur, int depth);

#endif