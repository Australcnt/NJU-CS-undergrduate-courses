#ifndef _SYMBOLTABLE_H_
#define _SYMBOLTABLE_H_

#include <stdio.h>
#include <string.h>
#include <assert.h>

#define SYMBOL_TABLE_SIZE 0x3fff

typedef enum { BASIC_INT, BASIC_FLOAT } Basic;
typedef enum { CONTEXT_EXT, CONTEXT_LOCAL, CONTEXT_STRUCT, CONTEXT_PARAM } Context;
typedef enum { BASIC, ARRAY, STRUCTTAG, STRUCTURE, STRUCTFIELD, FUNCTION } Kind;

typedef struct Type_ Type_;
typedef struct FieldList_ FieldList_;
typedef struct Type_* Type;
typedef struct FieldList_* FieldList;
typedef struct SymbolNode_* SymbolNode;
typedef struct ScopeStackHead_* ScopeStackHead;

struct SymbolNode_ {
	char* name;
    Type type;
    int depth;
    int isRedefined;
	SymbolNode hashNext;
	SymbolNode scopeNext;
};

struct ScopeStackHead_ {
    SymbolNode scopeNext;
    ScopeStackHead scopeStackNext;
};

SymbolNode symbolTable[SYMBOL_TABLE_SIZE];
ScopeStackHead scopeStack;
int scopeDepth;

unsigned int hash(char* name);
void initSymbolTable();
void initScopeStack();
void enterScope();
SymbolNode createSymbol(Type type, char *name, int depth);
void insertSymbolTable(SymbolNode symbol);
SymbolNode searchSymbolTable(char* name, int depth, Kind kind);
void exitScope();

#endif