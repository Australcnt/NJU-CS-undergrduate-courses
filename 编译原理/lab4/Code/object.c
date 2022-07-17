#include "object.h"

void initObjectCodes(FILE* file) {
    // 寄存器初始化
    for(int i = 0; i < REG_NUM; i++) {
        regList[i] = (RegDesc)malloc(sizeof(struct RegDesc_));
        regList[i]->age = 0;
        regList[i]->var = NULL;
    }

    regList[0]->name = "$zero";

	regList[1]->name = "$at";

	regList[2]->name = "$v0";
	regList[3]->name = "$v1";

	regList[4]->name = "$a0";
	regList[5]->name = "$a1";
	regList[6]->name = "$a2";
	regList[7]->name = "$a3";

	regList[8]->name = "$t0";
	regList[9]->name = "$t1";
	regList[10]->name = "$t2";
	regList[11]->name = "$t3";
	regList[12]->name = "$t4";
	regList[13]->name = "$t5";
	regList[14]->name = "$t6";
	regList[15]->name = "$t7";

	regList[16]->name = "$s0";
	regList[17]->name = "$s1";
	regList[18]->name = "$s2";
	regList[19]->name = "$s3";
	regList[20]->name = "$s4";
	regList[21]->name = "$s5";
	regList[22]->name = "$s6";
	regList[23]->name = "$s7";		

	regList[24]->name = "$t8";
	regList[25]->name = "$t9";

	regList[26]->name = "$k0";
	regList[27]->name = "$k1";

	regList[28]->name = "$gp";

	regList[29]->name = "$sp";

	regList[30]->name = "$fp";

	regList[31]->name = "$ra";

    //变量描述符表栈初始化
    varListStack = (VarListStack)malloc(sizeof(struct VarListStack_));
    varListStack->varList = NULL;
    varListStack->offset = -8;
    varListStack->prev = NULL;
    varListStack->next = NULL;

    return;
}

int Ensure(FILE* file, Operand op) {
    int result = -1;
    if(op->kind == OP_CONSTANT) {
        result = Allocate(file, op);
        //fprintf(file, "\tli %s, %d\n", regList[result]->name, op->u.constant.constValue);
        return result;
    }
    result = getRegIndex(op);
    //printf("%d, %d\n", result, op->kind);
    if(result >= 0) {
        return result;
    } else {
        result = Allocate(file, op);
        // TODO: lw
        //fprintf(file, "\tlw %s, %d($fp)\n", regList[result]->name, regList[result]->var->offset);
    }
    return result;
}

int Allocate(FILE *file, Operand op) {
    int result = -1;
    for(int r = REG_START; r <= REG_END; r++) {
        if(regList[r]->var) {
            regList[r]->age = (regList[r]->age + 1) % REG_SIZE;
            //printf("%d, %d\n", regList[r]->age, REG_SIZE);
        }
    }
    for(int r = REG_START; r <= REG_END; r++) {
        if(!regList[r]->var) { // 若有空闲的寄存器，则直接存储
            VarDesc var = getVarDesc(op);
            if(var) {
                regList[r]->var = var;
            } else {
                regList[r]->var = (VarDesc)malloc(sizeof(struct VarDesc_));
                regList[r]->var->op = op;
                regList[r]->var->regIndex = r;
                regList[r]->var->offset = -1;
                regList[r]->var->next = NULL;
                regList[r]->age = 1;
                addVarDesc(regList[r]->var);
            }
            result = r;
            break;
        } else {
            if (regList[r]->age == 0 || (r == REG_END && result == -1)){ // 若没有空闲的寄存器，则将age最大的寄存器中的内容溢出到内存
                // TODO: spill result
                if(regList[r]->var->offset == -1) {
                    fprintf(file, "\taddi $sp, $sp, -4\n");
                    varListStack->offset -= 4;
                    regList[r]->var->offset = varListStack->offset;
                    fprintf(file, "\tsw %s, 0($sp)\n", regList[r]->name);
                }
                // deleteVarDesc(regList[r]->var);
                regList[r]->var->regIndex = -1;
                result = r;
                VarDesc var = getVarDesc(op);
                if(var) {
                    regList[r]->var = var;
                } else {
                    regList[r]->var = (VarDesc)malloc(sizeof(struct VarDesc_));
                    regList[r]->var->op = op;
                    regList[r]->var->regIndex = r;
                    regList[r]->var->offset = -1;
                    regList[r]->var->next = NULL;
                    regList[r]->age = 1;
                    addVarDesc(regList[r]->var);
                }
                break;
            }
        }
    }
    return result;
}

int getRegIndex(Operand op) {
    VarDesc var = varListStack->varList;
    while(var) {
        if(isOperandEqual(op, var->op)) {
            return var->regIndex;
        }
        var = var->next;
    }
    return -1;
}

int isOperandEqual(Operand op1, Operand op2) {
    if(op1->kind != op2->kind) {
        return 0;
    }
    if(op1->isTemp != op2->isTemp) {
        return 0;
    }
    if(op1->isTemp) {
        if(op1->u.temp.tempNum != op2->u.temp.tempNum) {
            return 0;
        }
    }
    switch(op1->kind) {
        case OP_VARIABLE:
        case OP_ARRAY:
        case OP_ADDRESS: {
            if(op1->u.var.varNum != op2->u.var.varNum) {
                return 0;
            }
            break;
        }
        case OP_CONSTANT: {
            if(op1->u.constant.constValue != op2->u.constant.constValue) {
                return 0;
            }
            break;
        }
        case OP_FUNCTION: {
            if(strcmp(op1->u.func.funcName, op2->u.func.funcName)) {
                return 0;
            }
            break;
        }
        case OP_LABEL: {
            if(op1->u.label.labelNum != op2->u.label.labelNum) {
                return 0;
            }
            break;
        }
        default: break;
    }
    return 1;
}

void addVarDesc(VarDesc var) {
    if(!varListStack->varList) {
        varListStack->varList = var;
    } else {
        VarDesc curVar = varListStack->varList;
        while(curVar->next) {
            curVar = curVar->next;
        }
        curVar->next = var;
    }
    return ;
}

void deleteVarDesc(VarDesc var) {
    VarDesc curVar = varListStack->varList;
    VarDesc preVar = NULL;
    while(curVar) {
        if(isOperandEqual(curVar->op, var->op)) {
            if(preVar) {
                preVar->next = curVar->next;
            } else {
                varListStack->varList = curVar->next;
            }
        }
        return;
    }
    return;
}

VarDesc getVarDesc(Operand op) {
    VarDesc curVar = varListStack->varList;
    while (curVar) {
        if(isOperandEqual(curVar->op, op)) {
            return curVar;
        }
        curVar = curVar->next;
    }
    return NULL;
}

void addVarListStack() {
    VarListStack curVarList = (VarListStack)malloc(sizeof(struct VarListStack_));
    curVarList->varList = NULL;
    curVarList->offset = -8;
    curVarList->prev = NULL;
    curVarList->next = NULL;
    if(!varListStack) {
        varListStack = curVarList;
    } else {
        varListStack->next = curVarList;
        curVarList->prev = varListStack;
        varListStack = curVarList;
    }
    for(int i = REG_START; i <= REG_END; i++) {
        regList[i]->age = 0;
        regList[i]->var = NULL;
    }
    return;
}

void deleteVarListStack() {
    if(!varListStack->prev) {
        varListStack = NULL;
    } else {
        varListStack = varListStack->prev;
        int varNum = 0;
        VarDesc var = varListStack->varList;
        while(var) {
            if(REG_START <= var->regIndex && var->regIndex <= REG_END) {
                varNum += 1;
                regList[var->regIndex]->age = varNum; // 无法恢复以前的age，按寄存器顺序进行重新设置
                regList[var->regIndex]->var = var;
            }
            var = var->next;
        }
    }
    return;
}

void storeAllVar(FILE* file) {
    /*int varNum = 0;
    for(int r = REG_START; r <= REG_END; r++) {
        if(regList[r]->var) {
            varNum += 1;
        }
    }
    fprintf(file, "\taddi $sp, $sp, %d\n", 0 - varNum * 4);
    varListStack->offset -= varNum * 4;
    for(int r = REG_START, i = 0; r <= REG_END; r++) {
        if(regList[r]->var) {
            fprintf(file, "\tsw %s, %d($sp)\n", regList[r]->name, i * 4);
            i += 1;
        }
    }*/
    VarDesc var = varListStack->varList;
    int varNum = 0;
    int j = 0;
    while(var) {
        if(REG_START <= var->regIndex && var->regIndex <= REG_END) {
            j += 1;
        }
        varNum += 1;
        var = var->next;
    }
    var = varListStack->varList;
    fprintf(file, "\taddi $sp, $sp, %d\n", 0 - j * 4);
    for(int i = 0, j = 0; i < varNum; i++) {
        if(REG_START <= var->regIndex && var->regIndex <= REG_END) {
            fprintf(file, "\tsw %s, %d($sp)\n", regList[var->regIndex]->name, j * 4);
            j += 1;
        }
        var = var->next;
    }
    return;
}

void reloadAllVar(FILE* file) {
    /*VarDesc var = varListStack->varList;
    int varNum = 0;
    while(var) {
        varNum += 1;
        var = var->next;
    }
    var = varListStack->varList;
    int j = 0;
    for(int i = 0; i < varNum; i++) {
        if(REG_START <= var->regIndex && var->regIndex <= REG_END) {
            fprintf(file, "\tlw %s, %d($sp)\n", regList[var->regIndex]->name, j * 4);
            j += 1;
        }
        var = var->next;
    }
    fprintf(file, "\taddi $sp, $sp, %d\n", j * 4);*/
    VarDesc var = varListStack->varList;
    int varNum = 0;
    int regVarNum = 0;
    while(var) {
        if(REG_START <= var->regIndex && var->regIndex <= REG_END) {
            regVarNum += 1;
        }
        varNum += 1;
        var = var->next;
    }
    var = varListStack->varList;
    int j = 0;
    for(int i = 0; i < varNum; i++) {
        if(REG_START <= var->regIndex && var->regIndex <= REG_END) {
            fprintf(file, "\tlw %s, %d($sp)\n", regList[var->regIndex]->name, j * 4 - regVarNum * 4 - 4 * 4);
            j += 1;
        }
        var = var->next;
    }
    fprintf(file, "\tlw $a0, %d($sp)\n", -16);
    fprintf(file, "\tlw $a1, %d($sp)\n", -12);
    fprintf(file, "\tlw $a2, %d($sp)\n", -8);
    fprintf(file, "\tlw $a3, %d($sp)\n", -4);
    // fprintf(file, "\taddi $sp, $sp, %d\n", j * 4);
    return;
}

void objectCodesGeneration(FILE* file) {
    initObjectCodes(file);
    printObjectCodes(file);
    return;
}

void printObjectCodes(FILE *file) {
    printPreObjectCodes(file);
    InterCodes interCodes = interCodesHead;
    while(interCodes) {
        printObjectCode(file, interCodes);
        interCodes = interCodes->next;
    }
    return;
}

void printPreObjectCodes(FILE *file) {
    fprintf(file, ".data\n");
	fprintf(file, "_prompt: .asciiz \"Enter an integer:\"\n");
	fprintf(file, "_ret: .asciiz \"\\n\"\n");
	fprintf(file, ".globl main\n");
	fprintf(file, ".text\n");
	fprintf(file, "read:\n");
	fprintf(file, "\tli $v0, 4\n");
	fprintf(file, "\tla $a0, _prompt\n");
	fprintf(file, "\tsyscall\n");
	fprintf(file, "\tli $v0, 5\n");
	fprintf(file, "\tsyscall\n");
	fprintf(file, "\tjr $ra\n");
    fprintf(file, "\n");
	fprintf(file, "write:\n");
	fprintf(file, "\tli $v0, 1\n");
	fprintf(file, "\tsyscall\n");
	fprintf(file, "\tli $v0, 4\n");
	fprintf(file, "\tla $a0, _ret\n");
	fprintf(file, "\tsyscall\n");
	fprintf(file, "\tmove $v0, $0\n");
	fprintf(file, "\tjr $ra\n");
    return;
}

void printObjectCode(FILE* file, InterCodes interCodes) {
    InterCode interCode = interCodes->code;
    switch(interCode->kind) {
        case IR_LABEL: {
            fprintf(file, "label%d:\n", interCode->u.unop.op1->u.label.labelNum);
            break;
        }
        case IR_FUNC: {
            fprintf(file, "\n%s:\n", interCode->u.unop.op1->u.func.funcName);
            if(!strcmp(interCode->u.unop.op1->u.func.funcName, "main")) {
                fprintf(file, "\tmove $fp, $sp\n");
                varListStack->offset = 0;
            } else {
                //addVarListStack();
            }
            InterCodes curParam = interCodes->next;
            int paramNum = 0;
            while(curParam->code->kind == IR_PARAM) {
                paramNum += 1;
                curParam = curParam->next;
            }
            curParam = interCodes->next;
            //if(paramNum > 4) {
            //    fprintf(file, "\taddi $sp, $sp, %d\n", 0 - (paramNum - 4) * 4);
                for(int i = 0; i < paramNum; i++) {
                    VarDesc var = (VarDesc)malloc(sizeof(struct VarDesc_));
                    var->op = curParam->code->u.unop.op1;
                    if(i <= 4) {
                        var->regIndex = i + 4;
                        var->offset = -1;
                    } else {
                        var->regIndex = -1;
                        var->offset = (i - 5) * 4;
                    }
                    var->next = NULL;
                    addVarDesc(var);
                    curParam = curParam->next;
                }
            //}
            break;
        }
        case IR_ASSIGN: {
            if(interCode->u.binop.op1->kind == OP_ADDRESS && interCode->u.binop.op2->kind != OP_ARRAY) {
                // *x := y
                int op1RegIndex = Ensure(file, interCode->u.binop.op1);
                int op2RegIndex = Ensure(file, interCode->u.binop.op2);
                if(interCode->u.binop.op2->kind == OP_CONSTANT) {
                    fprintf(file, "\tli %s, %d\n", regList[op2RegIndex]->name, interCode->u.binop.op2->u.constant.constValue);
                }
                fprintf(file, "\tsw %s, 0(%s)\n", regList[op2RegIndex]->name, regList[op1RegIndex]->name);  
            } else if(interCode->u.binop.op2->kind == OP_ADDRESS) {
                // x := *y
                int op1RegIndex = Ensure(file, interCode->u.binop.op1);
                int op2RegIndex = Ensure(file, interCode->u.binop.op2);
                fprintf(file, "\tlw %s, 0(%s)\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name);  
            } else if(interCode->u.binop.op2->kind == OP_ARRAY) {
                // x := &y
                int op1RegIndex = Ensure(file, interCode->u.binop.op1);
                int op2RegIndex = Ensure(file, interCode->u.binop.op2);
                //fprintf(file, "\tla %s, %s\n", regList[op2RegIndex]->name, );
                // 直接计算地址，节省指令
                fprintf(file, "\taddi %s, $fp, %d\n", regList[op1RegIndex]->name, regList[op2RegIndex]->var->offset);
                //fprintf(file, "\tmove %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name);
            } else {
                if(interCode->u.binop.op2->kind == OP_CONSTANT) {
                    int op1RegIndex = Ensure(file, interCode->u.binop.op1);
                    fprintf(file, "\tli %s, %d\n", regList[op1RegIndex]->name, interCode->u.binop.op2->u.constant.constValue);

                } else {
                    int op1RegIndex = Ensure(file, interCode->u.binop.op1);
                    int op2RegIndex = Ensure(file, interCode->u.binop.op2);
                    fprintf(file, "\tmove %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name);  
                }
            }
            break;
        }
        case IR_ADD: {
            if(interCode->u.ternop.op2->kind == OP_CONSTANT && interCode->u.ternop.op3->kind == OP_CONSTANT) {
                // x := #k1 + #k2
                int op1RegIndex = Ensure(file, interCode->u.ternop.op1);
                fprintf(file, "\tli %s, %d\n", regList[op1RegIndex]->name, interCode->u.ternop.op2->u.constant.constValue + interCode->u.ternop.op3->u.constant.constValue);
            } else if(interCode->u.ternop.op2->kind != OP_CONSTANT && interCode->u.ternop.op3->kind == OP_CONSTANT) {
                int op1RegIndex = Ensure(file, interCode->u.ternop.op1);
                int op2RegIndex = Ensure(file, interCode->u.ternop.op2);
                if(interCode->u.ternop.op2->kind == OP_ARRAY) {
                    // x := &y + #k（不会出现*x）
                    // 直接计算地址，节省指令
                    fprintf(file, "\taddi %s, $fp, %d\n", regList[op1RegIndex]->name, regList[op2RegIndex]->var->offset + interCode->u.ternop.op3->u.constant.constValue);
                } else if(interCodes->code->u.ternop.op2->kind == OP_ADDRESS && interCodes->code->u.ternop.op1->kind != OP_ADDRESS) {
                    // x := *y + #k
                    // 先将op2指向的内容存在op2的寄存器，用过后，再将op2从内存记载回op2原来的寄存器
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->name);
                    //fprintf(file, "\taddi %s, %s, %d\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name,, interCode->u.ternop.op3->u.constant.constValue);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->var->offset);
                    fprintf(file, "\tlw $v1, 0(%s)\n", regList[op2RegIndex]->name);
                    fprintf(file, "\taddi %s, $v1, %d\n", regList[op1RegIndex]->name, interCode->u.ternop.op3->u.constant.constValue);
                } else {
                    // x := y + #k
                    fprintf(file, "\taddi %s, %s, %d\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, interCode->u.ternop.op3->u.constant.constValue);
                }
            } else {
                int op1RegIndex = Ensure(file, interCode->u.ternop.op1);
                int op2RegIndex = Ensure(file, interCode->u.ternop.op2);
                int op3RegIndex = Ensure(file, interCode->u.ternop.op3);
                if(interCode->u.ternop.op2->kind == OP_ARRAY) {
                    // x := &y + z（不会出现*z）
                    // 先将op2的地址存在op2的寄存器，用过后，再将op2从内存加载回op2原来的寄存器
                    //fprintf(file, "\taddi %s, $fp, %d\n", regList[op2RegIndex]->name, regList[op2RegIndex]->var->offset);
                    //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name,, regList[op3RegIndex]->name);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->var->offset);
                    fprintf(file, "\taddi $v1, $fp, %d\n", regList[op2RegIndex]->var->offset);
                    fprintf(file, "\tadd %s, $v1, %s\n", regList[op1RegIndex]->name, regList[op3RegIndex]->name);
                } else if(interCodes->code->u.ternop.op2->kind == OP_ADDRESS && interCodes->code->u.ternop.op3->kind != OP_ADDRESS && interCodes->code->u.ternop.op1->kind != OP_ADDRESS) {
                    // x := *y + z
                    // 先将op2指向的内容存在op2的寄存器，用过后，再将op2从内存记载回op2原来的寄存器
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->name);
                    //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->var->offset);
                    fprintf(file, "\tlw $v1, 0(%s)\n", regList[op2RegIndex]->name);
                    fprintf(file, "\tadd %s, $v1, %s\n", regList[op1RegIndex]->name, regList[op3RegIndex]->name);
                } else if(interCodes->code->u.ternop.op2->kind != OP_ADDRESS && interCodes->code->u.ternop.op3->kind == OP_ADDRESS && interCodes->code->u.ternop.op1->kind != OP_ADDRESS) {
                    // x := y + *z
                    // 先将op3指向的内容存在op3的寄存器，用过后，再将op3从内存记载回op3原来的寄存器
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->var->offset);
                    fprintf(file, "\tlw $v1, 0(%s)\n", regList[op3RegIndex]->name);
                    fprintf(file, "\tadd %s, $v1, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name);
                } else if(interCodes->code->u.ternop.op2->kind == OP_ADDRESS && interCodes->code->u.ternop.op3->kind == OP_ADDRESS && interCodes->code->u.ternop.op1->kind != OP_ADDRESS) {
                    // x := *y + *z
                    // 先将op2和op3指向的内容存在op2和op3的寄存器，用过后，再将op2和op3从内存记载回op2和op3原来的寄存器
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->name);
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->var->offset);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->var->offset);
                    fprintf(file, "\tlw $v0, 0(%s)\n", regList[op2RegIndex]->name); // 暂用一下$v0寄存器
                    fprintf(file, "\tlw $v1, 0(%s)\n", regList[op3RegIndex]->name);
                    fprintf(file, "\tadd %s, $v0, $v1\n", regList[op1RegIndex]->name);
                } else {
                    // x := y + z
                    fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                }
            }
            break;
        }
        case IR_SUB: {
            if(interCode->u.ternop.op2->kind == OP_CONSTANT && interCode->u.ternop.op3->kind == OP_CONSTANT) {
                // x := #k1 - #k2
                int op1RegIndex = Ensure(file, interCode->u.ternop.op1);
                fprintf(file, "\tli %s, %d\n", regList[op1RegIndex]->name, interCode->u.ternop.op2->u.constant.constValue - interCode->u.ternop.op3->u.constant.constValue);
            } else if(interCode->u.ternop.op2->kind != OP_CONSTANT && interCode->u.ternop.op3->kind == OP_CONSTANT) {
                int op1RegIndex = Ensure(file, interCode->u.ternop.op1);
                int op2RegIndex = Ensure(file, interCode->u.ternop.op2);
                if(interCode->u.ternop.op2->kind == OP_ARRAY) {
                    // x := &y - #k（不会出现*x）
                    // 直接计算地址，节省指令
                    fprintf(file, "\taddi %s, $fp, %d\n", regList[op1RegIndex]->name, regList[op2RegIndex]->var->offset + interCode->u.ternop.op3->u.constant.constValue);
                } else if(interCodes->code->u.ternop.op2->kind == OP_ADDRESS && interCodes->code->u.ternop.op1->kind != OP_ADDRESS) {
                    // x := *y - #k
                    // 先将op2指向的内容存在op2的寄存器，用过后，再将op2从内存记载回op2原来的寄存器
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->name);
                    //fprintf(file, "\taddi %s, %s, %d\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name,, interCode->u.ternop.op3->u.constant.constValue);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->var->offset);
                    fprintf(file, "\tlw $v1, 0(%s)\n", regList[op2RegIndex]->name);
                    fprintf(file, "\taddi %s, $v1, %d\n", regList[op1RegIndex]->name, 0 - interCode->u.ternop.op3->u.constant.constValue);
                } else {
                    // x := y - #k
                    fprintf(file, "\taddi %s, %s, %d\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, 0 - interCode->u.ternop.op3->u.constant.constValue);
                }
            } else {
                int op1RegIndex = Ensure(file, interCode->u.ternop.op1);
                int op2RegIndex = Ensure(file, interCode->u.ternop.op2);
                int op3RegIndex = Ensure(file, interCode->u.ternop.op3);
                if(interCode->u.ternop.op2->kind == OP_ARRAY) {
                    // x := &y - z（不会出现*z）
                    // 先将op2的地址存在op2的寄存器，用过后，再将op2从内存加载回op2原来的寄存器
                    //fprintf(file, "\taddi %s, $fp, %d\n", regList[op2RegIndex]->name, regList[op2RegIndex]->var->offset);
                    //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name,, regList[op3RegIndex]->name);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->var->offset);
                    fprintf(file, "\taddi $v1, $fp, %d\n", regList[op2RegIndex]->var->offset);
                    fprintf(file, "\tsub %s, $v1, %s\n", regList[op1RegIndex]->name, regList[op3RegIndex]->name);
                } else if(interCodes->code->u.ternop.op2->kind == OP_ADDRESS && interCodes->code->u.ternop.op3->kind != OP_ADDRESS && interCodes->code->u.ternop.op1->kind != OP_ADDRESS) {
                    // x := *y - z
                    // 先将op2指向的内容存在op2的寄存器，用过后，再将op2从内存记载回op2原来的寄存器
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->name);
                    //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->var->offset);
                    fprintf(file, "\tlw $v1, 0(%s)\n", regList[op2RegIndex]->name);
                    fprintf(file, "\tsub %s, $v1, %s\n", regList[op1RegIndex]->name, regList[op3RegIndex]->name);
                } else if(interCodes->code->u.ternop.op2->kind != OP_ADDRESS && interCodes->code->u.ternop.op3->kind == OP_ADDRESS && interCodes->code->u.ternop.op1->kind != OP_ADDRESS) {
                    // x := y - *z
                    // 先将op3指向的内容存在op3的寄存器，用过后，再将op3从内存记载回op3原来的寄存器
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->var->offset);
                    fprintf(file, "\tlw $v1, 0(%s)\n", regList[op3RegIndex]->name);
                    fprintf(file, "\tsub %s, $v1, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name);
                } else if(interCodes->code->u.ternop.op2->kind == OP_ADDRESS && interCodes->code->u.ternop.op3->kind == OP_ADDRESS && interCodes->code->u.ternop.op1->kind != OP_ADDRESS) {
                    // x := *y - *z
                    // 先将op2和op3指向的内容存在op2和op3的寄存器，用过后，再将op2和op3从内存记载回op2和op3原来的寄存器
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->name);
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->var->offset);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->var->offset);
                    fprintf(file, "\tlw $v0, 0(%s)\n", regList[op2RegIndex]->name); // 暂用一下$v0寄存器
                    fprintf(file, "\tlw $v1, 0(%s)\n", regList[op3RegIndex]->name);
                    fprintf(file, "\tsub %s, $v0, $v1\n", regList[op1RegIndex]->name);
                } else {
                    // x := y - z
                    fprintf(file, "\tsub %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                }
            }
            break;
        }
        case IR_MUL: {
            if(interCode->u.ternop.op2->kind == OP_CONSTANT && interCode->u.ternop.op3->kind == OP_CONSTANT) {
                // x := #k1 * #k2
                int op1RegIndex = Ensure(file, interCode->u.ternop.op1);
                fprintf(file, "\tli %s, %d\n", regList[op1RegIndex]->name, interCode->u.ternop.op2->u.constant.constValue * interCode->u.ternop.op3->u.constant.constValue);
            } else {
                int op1RegIndex = Ensure(file, interCode->u.ternop.op1);
                int op2RegIndex = Ensure(file, interCode->u.ternop.op2);
                int op3RegIndex = Ensure(file, interCode->u.ternop.op3);
                if(interCode->u.ternop.op2->kind == OP_CONSTANT) {
                    fprintf(file, "\tli %s, %d\n", regList[op2RegIndex]->name, interCode->u.ternop.op2->u.constant.constValue);
                }
                if(interCode->u.ternop.op3->kind == OP_CONSTANT) {
                    fprintf(file, "\tli %s, %d\n", regList[op3RegIndex]->name, interCode->u.ternop.op3->u.constant.constValue);
                }
                if(interCodes->code->u.ternop.op2->kind == OP_ADDRESS && interCodes->code->u.ternop.op3->kind != OP_ADDRESS && interCodes->code->u.ternop.op1->kind != OP_ADDRESS) {
                    // x := *y * z, x := *y * #k
                    // 先将op2指向的内容存在op2的寄存器，用过后，再将op2从内存记载回op2原来的寄存器
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->name);
                    //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->var->offset);
                    fprintf(file, "\tlw $v1, 0(%s)\n", regList[op2RegIndex]->name);
                    fprintf(file, "\tmul %s, $v1, %s\n", regList[op1RegIndex]->name, regList[op3RegIndex]->name);
                } else if(interCodes->code->u.ternop.op2->kind != OP_ADDRESS && interCodes->code->u.ternop.op3->kind == OP_ADDRESS && interCodes->code->u.ternop.op1->kind != OP_ADDRESS) {
                    // x := y * *z, x := #k * *z
                    // 先将op3指向的内容存在op3的寄存器，用过后，再将op3从内存记载回op3原来的寄存器
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->var->offset);
                    fprintf(file, "\tlw $v1, 0(%s)\n", regList[op3RegIndex]->name);
                    fprintf(file, "\tmul %s, $v1, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name);
                } else if(interCodes->code->u.ternop.op2->kind == OP_ADDRESS && interCodes->code->u.ternop.op3->kind == OP_ADDRESS && interCodes->code->u.ternop.op1->kind != OP_ADDRESS) {
                    // x := *y * *z
                    // 先将op2和op3指向的内容存在op2和op3的寄存器，用过后，再将op2和op3从内存记载回op2和op3原来的寄存器
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->name);
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->var->offset);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->var->offset);
                    fprintf(file, "\tlw $v0, 0(%s)\n", regList[op2RegIndex]->name); // 暂用一下$v0寄存器
                    fprintf(file, "\tlw $v1, 0(%s)\n", regList[op3RegIndex]->name);
                    fprintf(file, "\tmul %s, $v0, $v1\n", regList[op1RegIndex]->name);
                } else {
                    // x := y * z, x := y * #k, x := #k * z, x := #k1 * #k2
                    fprintf(file, "\tmul %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                }
            }
            break;
        }
        case IR_DIV: {
            if(interCode->u.ternop.op2->kind == OP_CONSTANT && interCode->u.ternop.op3->kind == OP_CONSTANT) {
                // x := #k1 / #k2
                int op1RegIndex = Ensure(file, interCode->u.ternop.op1);
                fprintf(file, "\tli %s, %d\n", regList[op1RegIndex]->name, interCode->u.ternop.op2->u.constant.constValue / interCode->u.ternop.op3->u.constant.constValue);
            } else {
                int op1RegIndex = Ensure(file, interCode->u.ternop.op1);
                int op2RegIndex = Ensure(file, interCode->u.ternop.op2);
                int op3RegIndex = Ensure(file, interCode->u.ternop.op3);
                if(interCode->u.ternop.op2->kind == OP_CONSTANT) {
                    fprintf(file, "\tli %s, %d\n", regList[op2RegIndex]->name, interCode->u.ternop.op2->u.constant.constValue);
                }
                if(interCode->u.ternop.op3->kind == OP_CONSTANT) {
                    fprintf(file, "\tli %s, %d\n", regList[op3RegIndex]->name, interCode->u.ternop.op3->u.constant.constValue);
                }
                if(interCodes->code->u.ternop.op2->kind == OP_ADDRESS && interCodes->code->u.ternop.op3->kind != OP_ADDRESS && interCodes->code->u.ternop.op1->kind != OP_ADDRESS) {
                    // x := *y / z, x := *y / #k
                    // 先将op2指向的内容存在op2的寄存器，用过后，再将op2从内存记载回op2原来的寄存器
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->name);
                    //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->var->offset);
                    fprintf(file, "\tlw $v1, 0(%s)\n", regList[op2RegIndex]->name);
                    fprintf(file, "\tdiv %s, $v1, %s\n", regList[op1RegIndex]->name, regList[op3RegIndex]->name);
                } else if(interCodes->code->u.ternop.op2->kind != OP_ADDRESS && interCodes->code->u.ternop.op3->kind == OP_ADDRESS && interCodes->code->u.ternop.op1->kind != OP_ADDRESS) {
                    // x := y / *z, x := #k / *z
                    // 先将op3指向的内容存在op3的寄存器，用过后，再将op3从内存记载回op3原来的寄存器
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->var->offset);
                    fprintf(file, "\tlw $v1, 0(%s)\n", regList[op3RegIndex]->name);
                    fprintf(file, "\tdiv %s, $v1, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name);
                } else if(interCodes->code->u.ternop.op2->kind == OP_ADDRESS && interCodes->code->u.ternop.op3->kind == OP_ADDRESS && interCodes->code->u.ternop.op1->kind != OP_ADDRESS) {
                    // x := *y / *z
                    // 先将op2和op3指向的内容存在op2和op3的寄存器，用过后，再将op2和op3从内存记载回op2和op3原来的寄存器
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->name);
                    //fprintf(file, "\tlw %s, 0(%s)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->var->offset);
                    //fprintf(file, "\tlw %s, %d($fp)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->var->offset);
                    fprintf(file, "\tlw $v0, 0(%s)\n", regList[op2RegIndex]->name); // 暂用一下$v0寄存器
                    fprintf(file, "\tlw $v1, 0(%s)\n", regList[op3RegIndex]->name);
                    fprintf(file, "\tdiv %s, $v0, $v1\n", regList[op1RegIndex]->name);
                } else {
                    // x := y / z, x := y / #k, x := #k / z, x := #k1 / #k2
                    fprintf(file, "\tdiv %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                }
            }
            break;
        }
        case IR_GOTO: {
            fprintf(file, "\tj label%d\n", interCode->u.unop.op1->u.label.labelNum);
            break;
        }
        case IR_IF_GOTO: {
            int op1RegIndex = Ensure(file, interCode->u.ifgoto.op1);
            int op2RegIndex = Ensure(file, interCode->u.ifgoto.op2);
            if(interCode->u.ifgoto.op1->kind == OP_CONSTANT) {
                fprintf(file, "\tli %s, %d\n", regList[op1RegIndex]->name, interCode->u.ifgoto.op1->u.constant.constValue);
            }
            if(interCode->u.ifgoto.op2->kind == OP_CONSTANT) {
                fprintf(file, "\tli %s, %d\n", regList[op2RegIndex]->name, interCode->u.ifgoto.op2->u.constant.constValue);
            }
            if(interCodes->code->u.ifgoto.op1->kind == OP_ADDRESS && interCodes->code->u.ifgoto.op2->kind != OP_ADDRESS) {
                // IF *x [relop] y GOTO z, IF *x [relop] #k GOTO z
                // 先将op2指向的内容存在op2的寄存器，用过后，再将op2从内存记载回op2原来的寄存器
                //fprintf(file, "\tlw %s, 0(%s)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->name);
                //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                //fprintf(file, "\tlw %s, %d($fp)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->var->offset);
                fprintf(file, "\tlw $v1, 0(%s)\n", regList[op1RegIndex]->name);
                if(!strcmp(interCode->u.ifgoto.cond, "==")) {
                    fprintf(file, "\tbeq $v1, %s, label%d\n", regList[op2RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                } else if(!strcmp(interCode->u.ifgoto.cond, "!=")) {
                    fprintf(file, "\tbne $v1, %s, label%d\n", regList[op2RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                } else if(!strcmp(interCode->u.ifgoto.cond, ">")) {
                    fprintf(file, "\tbgt $v1, %s, label%d\n", regList[op2RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                } else if(!strcmp(interCode->u.ifgoto.cond, "<")) {
                    fprintf(file, "\tblt $v1, %s, label%d\n", regList[op2RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                } else if(!strcmp(interCode->u.ifgoto.cond, ">=")) {
                    fprintf(file, "\tbge $v1, %s, label%d\n", regList[op2RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                } else {
                    fprintf(file, "\tble $v1, %s, label%d\n", regList[op2RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                }
            } else if(interCodes->code->u.ifgoto.op1->kind != OP_ADDRESS && interCodes->code->u.ifgoto.op2->kind == OP_ADDRESS) {
                // IF x [relop] *y GOTO z, IF #k [relop] *y GOTO z
                // 先将op3指向的内容存在op3的寄存器，用过后，再将op3从内存记载回op3原来的寄存器
                //fprintf(file, "\tlw %s, 0(%s)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->name);
                //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                //fprintf(file, "\tlw %s, %d($fp)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->var->offset);
                fprintf(file, "\tlw $v1, 0(%s)\n", regList[op2RegIndex]->name);
                if(!strcmp(interCode->u.ifgoto.cond, "==")) {
                    fprintf(file, "\tbeq %s, $v1, label%d\n", regList[op1RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                } else if(!strcmp(interCode->u.ifgoto.cond, "!=")) {
                    fprintf(file, "\tbne %s, $v1, label%d\n", regList[op1RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                } else if(!strcmp(interCode->u.ifgoto.cond, ">")) {
                    fprintf(file, "\tbgt %s, $v1, label%d\n", regList[op1RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                } else if(!strcmp(interCode->u.ifgoto.cond, "<")) {
                    fprintf(file, "\tblt %s, $v1, label%d\n", regList[op1RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                } else if(!strcmp(interCode->u.ifgoto.cond, ">=")) {
                    fprintf(file, "\tbge %s, $v1, label%d\n", regList[op1RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                } else {
                    fprintf(file, "\tble %s, $v1, label%d\n", regList[op1RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                }
            } else if(interCodes->code->u.ifgoto.op1->kind == OP_ADDRESS && interCodes->code->u.ifgoto.op2->kind == OP_ADDRESS) {
                // IF *x [relop] *y GOTO z
                // 先将op2和op3指向的内容存在op2和op3的寄存器，用过后，再将op2和op3从内存记载回op2和op3原来的寄存器
                //fprintf(file, "\tlw %s, 0(%s)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->name);
                //fprintf(file, "\tlw %s, 0(%s)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->name);
                //fprintf(file, "\tadd %s, %s, %s\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, regList[op3RegIndex]->name);
                //fprintf(file, "\tlw %s, %d($fp)\n", regList[op2RegIndex]->name, regList[op2RegIndex]->var->offset);
                //fprintf(file, "\tlw %s, %d($fp)\n", regList[op3RegIndex]->name, regList[op3RegIndex]->var->offset);
                fprintf(file, "\tlw $v0, 0(%s)\n", regList[op1RegIndex]->name); // 暂用一下$v0寄存器
                fprintf(file, "\tlw $v1, 0(%s)\n", regList[op2RegIndex]->name);
                if(!strcmp(interCode->u.ifgoto.cond, "==")) {
                    fprintf(file, "\tbeq $v0, $v1, label%d\n", interCode->u.ifgoto.op3->u.label.labelNum);
                } else if(!strcmp(interCode->u.ifgoto.cond, "!=")) {
                    fprintf(file, "\tbne $v0, $v1, label%d\n", interCode->u.ifgoto.op3->u.label.labelNum);
                } else if(!strcmp(interCode->u.ifgoto.cond, ">")) {
                    fprintf(file, "\tbgt $v0, $v1, label%d\n", interCode->u.ifgoto.op3->u.label.labelNum);
                } else if(!strcmp(interCode->u.ifgoto.cond, "<")) {
                    fprintf(file, "\tblt $v0, $v1, label%d\n", interCode->u.ifgoto.op3->u.label.labelNum);
                } else if(!strcmp(interCode->u.ifgoto.cond, ">=")) {
                    fprintf(file, "\tbge $v0, $v1, label%d\n", interCode->u.ifgoto.op3->u.label.labelNum);
                } else {
                    fprintf(file, "\tble $v0, $v1, label%d\n", interCode->u.ifgoto.op3->u.label.labelNum);
                }
            } else {
                // IF x [relop] y GOTO z, IF x [relop] #k GOTO z, IF #k [relop] y GOTO z, IF #k1 [relop] #k2 GOTO z
                if(!strcmp(interCode->u.ifgoto.cond, "==")) {
                    fprintf(file, "\tbeq %s, %s, label%d\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                } else if(!strcmp(interCode->u.ifgoto.cond, "!=")) {
                    fprintf(file, "\tbne %s, %s, label%d\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                } else if(!strcmp(interCode->u.ifgoto.cond, ">")) {
                    fprintf(file, "\tbgt %s, %s, label%d\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                } else if(!strcmp(interCode->u.ifgoto.cond, "<")) {
                    fprintf(file, "\tblt %s, %s, label%d\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                } else if(!strcmp(interCode->u.ifgoto.cond, ">=")) {
                    fprintf(file, "\tbge %s, %s, label%d\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                } else {
                    fprintf(file, "\tble %s, %s, label%d\n", regList[op1RegIndex]->name, regList[op2RegIndex]->name, interCode->u.ifgoto.op3->u.label.labelNum);
                }
            }
            break;
        }
        case IR_RETURN: {
            if(interCode->u.unop.op1->kind == OP_CONSTANT) {
                fprintf(file, "\tli $v0, %d\n", interCode->u.unop.op1->u.constant.constValue);
            } else {
                int op1RegIndex = Ensure(file, interCode->u.unop.op1);
                fprintf(file, "\tmove $v0, %s\n", regList[op1RegIndex]->name);
            }
            fprintf(file, "\tjr $ra\n");
            //deleteVarListStack();
            break;
        }
        case IR_DEC: {
            fprintf(file, "\taddi $sp, $sp, %d\n", 0 - interCode->u.dec.size);
            varListStack->offset -= interCode->u.dec.size;
            VarDesc var = (VarDesc)malloc(sizeof(struct VarDesc_));
            var->op = interCode->u.dec.op1;
            var->offset = varListStack->offset;
            //printf("%d\n", var->offset);
            var->regIndex = -1;
            var->next = NULL;
            addVarDesc(var);
            break;
        }
        case IR_ARG: {
            // 在IR_CALL中处理
            break;
        }
        case IR_CALL: {
            fprintf(file, "\taddi $sp, $sp, %d\n", 0 - 4 * 4);
            fprintf(file, "\tsw $a0, %d($sp)\n", 0);
            fprintf(file, "\tsw $a1, %d($sp)\n", 4);
            fprintf(file, "\tsw $a2, %d($sp)\n", 8);
            fprintf(file, "\tsw $a3, %d($sp)\n", 12);
            // 将传入的参数保存/压栈
            InterCodes curArg = interCodes->prev;
            int argNum = 0;
            while(curArg->code->kind == IR_ARG) {
                argNum += 1;
                curArg = curArg->prev;
            }
            if(argNum > 4) {
                fprintf(file, "\taddi $sp, $sp, %d\n", 0 - (argNum - 4) * 4);
                varListStack->offset -= (argNum - 4) * 4;
            }
            int op1RegIndex = -1;
            curArg = curArg->next;
            for(int i = 1; i <= argNum; i++) {
                op1RegIndex = Ensure(file, curArg->code->u.unop.op1);
                if(curArg->code->u.unop.op1->kind == OP_CONSTANT) {
                    fprintf(file, "\tli %s, %d\n", regList[op1RegIndex]->name, curArg->code->u.unop.op1->u.constant.constValue);
                }
                if(i <= 4) {
                    fprintf(file, "\tmove %s, %s\n", regList[i + 3]->name, regList[op1RegIndex]->name);
                } else {
                    fprintf(file, "\tsw %s, %d($sp)\n", regList[op1RegIndex]->name, (i - 5) * 4);
                    regList[op1RegIndex]->var->offset = (i - 5) * 4;
                }
                curArg = curArg->next;
            }
            // 将$8~$25寄存器中存储的所有变量压栈
            storeAllVar(file);
            addVarListStack();
            // 将$fp和$ra压栈
            fprintf(file, "\taddi $sp, $sp, -8\n");
            fprintf(file, "\tsw $fp, 4($sp)\n");
            fprintf(file, "\tsw $ra, 0($sp)\n");
            // 设置调用函数的$fp
            fprintf(file, "\taddi $fp, $sp, 8\n");
            // 跳转
            fprintf(file, "\tjal %s\n", interCode->u.binop.op2->u.func.funcName);
            // 恢复$ra，$fp和$sp
            fprintf(file, "\tlw $ra, -8($fp)\n");
            fprintf(file, "\tlw $fp, -4($fp)\n");
            fprintf(file, "\taddi $sp, $fp, %d\n", varListStack->prev->offset);
            // 恢复上级函数暂时压栈的变量到对应寄存器中
            deleteVarListStack();
            reloadAllVar(file);
            // 将返回值载入op1的寄存器
            op1RegIndex = Ensure(file, interCode->u.binop.op1);
            fprintf(file, "\tmove %s, $v0\n", regList[op1RegIndex]->name);
            break;
        }
        case IR_PARAM: {
            // 在IR_FUNC中处理
            break;
        }
        case IR_READ: {
            fprintf(file, "\taddi $sp, $sp, -4\n");
            fprintf(file, "\tsw $ra, 0($sp)\n");
            fprintf(file, "\tjal read\n");
            fprintf(file, "\tlw $ra, 0($sp)\n");
            fprintf(file, "\taddi $sp, $sp, 4\n");
            int op1RegIndex = Ensure(file, interCode->u.unop.op1);
            fprintf(file, "\tmove %s, $v0\n", regList[op1RegIndex]->name);
            break;
        }
        case IR_WRITE: {
            int op1RegIndex = Ensure(file, interCode->u.unop.op1);
            fprintf(file, "\taddi $sp, $sp, -8\n");
            fprintf(file, "\tsw $a0, 4($sp)\n");
            fprintf(file, "\tsw $ra, 0($sp)\n");
            if(interCode->u.unop.op1->kind == OP_CONSTANT) {
                fprintf(file, "\tli %s, %d\n", regList[op1RegIndex]->name, interCode->u.unop.op1->u.constant.constValue);
            }
            fprintf(file, "\tmove $a0, %s\n", regList[op1RegIndex]->name);			
            fprintf(file, "\tjal write\n");
            fprintf(file, "\tlw $a0, 4($sp)\n");
            fprintf(file, "\tlw $ra, 0($sp)\n");			
            fprintf(file, "\taddi $sp, $sp, 8\n");		
            break;
        }
        default: break;
    }
}