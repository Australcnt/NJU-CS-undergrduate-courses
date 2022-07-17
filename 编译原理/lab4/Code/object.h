#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "intermediate.h"

#define REG_NUM 32
#define REG_START 8
#define REG_END 25
#define REG_SIZE (REG_END - REG_START + 1)

typedef struct VarDesc_* VarDesc;
typedef struct RegDesc_* RegDesc;
typedef struct VarListStack_* VarListStack;

struct VarDesc_ {
    Operand op;
    int regIndex;
    int offset;
    VarDesc next;
};

struct RegDesc_ {
    char* name;
    VarDesc var;
    int age;
};

struct VarListStack_ {
    int offset;
    VarDesc varList;
    VarListStack prev;
    VarListStack next;
};

RegDesc regList[REG_NUM];
VarDesc varList;
VarListStack varListStack;
int offset;

void initObjectCodes(FILE* file);
int Ensure(FILE* file, Operand op);
int Allocate(FILE *file, Operand op);
int getRegIndex(Operand op);
int isOperandEqual(Operand op1, Operand op2);
void addVarDesc(VarDesc var);
void deleteVarDesc(VarDesc var);
VarDesc getVarDesc(Operand op);
void addVarListStack();
void deleteVarListStack();
void storeAllVar(FILE* file);
void reloadAllVar(FILE* file);

void objectCodesGeneration(FILE* file);
void printObjectCodes(FILE *file);
void printPreObjectCodes(FILE *file);
void printObjectCode(FILE* file, InterCodes interCodes);


#endif