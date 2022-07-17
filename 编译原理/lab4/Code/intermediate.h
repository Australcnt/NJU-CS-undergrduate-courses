#ifndef _INTERMEDIATE_H_
#define _INTERMEDIATE_H_

#include "semantic.h"

typedef struct Operand_* Operand;
typedef struct Operands_* Operands;
typedef struct InterCode_* InterCode;
typedef struct InterCodes_* InterCodes;

typedef enum { OP_VARIABLE, OP_ARRAY, OP_CONSTANT, OP_ADDRESS, OP_FUNCTION, OP_LABEL } OP_Kind;
typedef enum {
    IR_LABEL,         // LABEL x :
    IR_FUNC,          // FUNCTION f :
    IR_ASSIGN,        // x := y, x := &y, x := *y, *x := y
    IR_ADD,           // x := y + z
    IR_SUB,           // x := y - z
    IR_MUL,           // x := y * z
    IR_DIV,           // x := y / z
    IR_GOTO,          // GOTO x
    IR_IF_GOTO,       // IF x [relop] y GOTO z
    IR_RETURN,        // RETURN x
    IR_DEC,           // DEC x [size]
    IR_ARG,           // ARG x
    IR_CALL,          // x := CALL f
    IR_PARAM,         // PARAM x
    IR_READ,          // READ x
    IR_WRITE          // WRITE x
} IR_Kind;

struct Operand_ {
    OP_Kind kind;
    int isTemp;
    union {
        struct { int varNum; char* varName; } var;
        struct { int tempNum; } temp;
        struct { int labelNum; } label;
        struct { int constValue; } constant;
        struct { char* funcName; } func;
    } u;
};

struct Operands_ {
    Operand operand;
    Operands next;
};

struct InterCode_ {
    IR_Kind kind;
    union {
        // IR_LABEL, IR_FUNC, IR_GOTO, IR_RETURN, IR_ARG, IR_PARAM, IR_READ, IR_WRITE
        struct { Operand op1; } unop;

        // IR_ASSIGN, IR_CALL
        struct { Operand op1, op2; } binop;

        // IR_ADD, IR_SUB, IR_MUL, IR_DIV
        struct { Operand op1, op2, op3; } ternop;

        // IR_IF_GOTO
        struct { Operand op1, op2, op3; char* cond; } ifgoto;

        // IR_DEC
        struct { Operand op1; int size; } dec;
    } u;
};

struct InterCodes_ {
    InterCode code;
    InterCodes prev, next;
};

int hasInterCodesError;
InterCodes interCodesHead, interCodesTail;
int varNum, tempNum, labelNum;
Operands variableOperandsHead;

void initInterCodes();
Operand generateOperand(OP_Kind kind, int isTemp, int num, int value, char* name);
InterCode generateInterCode(IR_Kind kind, Operand op1, Operand op2, Operand op3, char* cond, int size);
void addInterCodes(InterCode intercode);
void deleteInterCodes(InterCodes intercodes);
void addVariableOperands(Operand operand);
Operand searchVariableOperands(char* name);
int getSize(Type type);
void printOperand(FILE* file, Operand operand);
void printInterCodes(FILE* file);

void interCodesGeneration(Node* node);
void translate_Program(Node* node);
void translate_ExtDefList(Node* node);
void translate_ExtDef(Node* node);
void translate_ExtDecList(Node* node);
void translate_Specifier(Node* node);
void translate_StructSpecifier(Node* node);
void translate_OptTag(Node* node);
void translate_Tag(Node* node);
Operand translate_VarDec(Node* node, int isParam);
void translate_FunDec(Node* node);
void translate_VarList(Node* node);
void translate_ParamDec(Node* node);
void translate_CompSt(Node* node);
void translate_StmtList(Node* node);
void translate_Stmt(Node* node);
void translate_DefList(Node* node);
void translate_Def(Node* node);
void translate_DecList(Node* node);
void translate_Dec(Node* node);
void translate_Exp(Node* node, Operand place);
Operands translate_Args(Node* node, Operands argOperandsHead);
void translate_Cond(Node* node, Operand label_true, Operand label_false);

#endif