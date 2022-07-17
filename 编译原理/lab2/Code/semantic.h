#ifndef _SEMANTIC_H_
#define _SEMANTIC_H_

#include "symboltable.h"
#include "parsetree.h"

typedef struct Type_* Type;
typedef struct FieldList_* FieldList;

struct Type_ {
    Kind kind;
    union {
        // 基本类型：int和float
        Basic basic;
        // 数组类型：元素类型、数组大小
        struct { Type elem; int size; } array;
        // 结构体名or结构体变量类型：结构体名、域的链表
        struct {char* tagName; FieldList field; } structure; // TODO: 是否需要name
        // 函数类型：参数的链表、返回值类型
        struct { FieldList param; Type ret; } function; // TODO: 是否需要name
    } u;
};

struct FieldList_ {
    char* name; // 域的名字
    Type type; // 域的类型
    FieldList tail; // 下一个域
};

int anonymousStructNum;
char semanticErrorMsg[100];

int isSameType(Type type1, Type type2);
int isSameParam(FieldList param1, FieldList param2);
char* getExpContent(Node* node);

void semanticAnalysis(Node* node);
void Program(Node* node);
void ExtDefList(Node* node);
void ExtDef(Node* node);
void ExtDecList(Node* node, Type type);
Type Specifier(Node* node);
Type StructSpecifier(Node* node);
char* OptTag(Node* node);
char* Tag(Node* node);
FieldList VarDec(Node* node, Type type, Context context);
FieldList FunDec(Node* node, Type type);
FieldList VarList(Node* node, Context context);
FieldList ParamDec(Node* node, Context context);
void CompSt(Node* node, Type type, FieldList param);
void StmtList(Node* node, Type type);
void Stmt(Node* node, Type type);
FieldList DefList(Node* node, Context context);
FieldList Def(Node* node, Context context);
FieldList DecList(Node* node, Type type, Context context);
FieldList Dec(Node* node, Type type, Context context);
Type Exp(Node* node);
FieldList Args(Node* node);

#endif