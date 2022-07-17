#include "semantic.h"

unsigned int hash(char* name) {
    unsigned int val = 0, i;
    for(; *name; ++name) {
        val = (val << 2) + *name;
        if(i = val & ~SYMBOL_TABLE_SIZE) {
            val = (val ^ (i >> 12)) & SYMBOL_TABLE_SIZE;
        }
    }
    return val;
}

void initSymbolTable() {
    for(int i = 0; i < SYMBOL_TABLE_SIZE; i++) {
        symbolTable[i] = NULL;
    }
    // read, write函数插入符号表
    Type readType = (Type)malloc(sizeof(struct Type_));
    readType->kind = FUNCTION;
    readType->u.function.param = NULL;
    readType->u.function.ret = (Type)malloc(sizeof(struct Type_));
    readType->u.function.ret->kind = BASIC;
    readType->u.function.ret->u.basic = BASIC_INT;
    Type writeType = (Type)malloc(sizeof(struct Type_));
    writeType->kind = FUNCTION;
    writeType->u.function.param = (FieldList)malloc(sizeof(struct FieldList_));
    writeType->u.function.param->name = NULL;
    writeType->u.function.param->type = (Type)malloc(sizeof(struct Type_));
    writeType->u.function.param->type->kind = BASIC;
    writeType->u.function.param->type->u.basic = BASIC_INT;
    writeType->u.function.param->tail = NULL;
    writeType->u.function.ret = (Type)malloc(sizeof(struct Type_));
    writeType->u.function.ret->kind = BASIC;
    writeType->u.function.ret->u.basic = BASIC_INT;
    SymbolNode readSymbol = createSymbol(readType, "read", 0);
    SymbolNode writeSymbol = createSymbol(writeType, "write", 0);
    insertSymbolTable(readSymbol);
    insertSymbolTable(writeSymbol);
}

void enterScope() {
    scopeDepth += 1;
}

SymbolNode createSymbol(Type type, char *name, int depth) {
    if(!type) { // TODO: 看看有没有这种情况
        printf("--------------------------------------------------symbol can't have non-type");
        assert(0);
    }
    SymbolNode symbol = (SymbolNode)malloc(sizeof(struct SymbolNode_));
    symbol->name = name;
    symbol->type = type;
    symbol->depth = depth;
    symbol->isRedefined = 0;
    symbol->hashNext = NULL;
    return symbol;
}

void insertSymbolTable(SymbolNode symbol) {
    int idx = hash(symbol->name);
    if(symbolTable[idx] == NULL) {
        symbolTable[idx] = symbol;
    } else {
        symbol->hashNext = symbolTable[idx];
        symbolTable[idx] = symbol;
    }
}

SymbolNode searchSymbolTable(char* name, int depth, Kind kind) {
    int idx = hash(name);
    if(symbolTable[idx] == NULL) {
        return NULL;
    }
    SymbolNode symbol = symbolTable[idx];
    SymbolNode structTag = NULL;
    while(symbol) {
        if(!strcmp(symbol->name, name)) {
            switch(kind) {
                case BASIC:
                case ARRAY:
                case STRUCTURE:
                    if(symbol->type->kind != STRUCTFIELD && symbol->type->kind != FUNCTION && symbol->type->kind != STRUCTTAG)
                        return symbol;
                    else if(symbol->type->kind == STRUCTTAG)
                        structTag = symbol;
                    break;
                case STRUCTFIELD: // 结构体的域只在当前结构体内查找（实际类型为BASIC, ARRAY, STRCUTURE）
                    if(symbol->type->kind != STRUCTFIELD && symbol->type->kind != FUNCTION && symbol->type->kind != STRUCTTAG && symbol->depth == depth)
                        return symbol;
                    break;
                case STRUCTTAG:
                case FUNCTION: // 函数名只在所有函数中查找
                    if(symbol->type->kind == kind && !symbol->isRedefined)
                        return symbol;
                    break;
                default:
                    break;
            }
        }
        symbol = symbol->hashNext;
    }
    if(structTag) {
        return structTag;
    }
    return NULL;
}

void exitScope() {
    scopeDepth -= 1;
}