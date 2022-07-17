#include "intermediate.h"

void initInterCodes() {
    //中间代码生成是否出错
    hasInterCodesError = 0;
    // 中间代码链表头尾
    interCodesHead = NULL;
    interCodesTail = NULL;
    // 变量操作数链表头
    variableOperandsHead = NULL;
    // 变量、临时变量、标签编号
    varNum = 1;
    tempNum = 1;
    labelNum = 1;
}

Operand generateOperand(OP_Kind kind, int isTemp, int num, int value, char* name) {
    Operand operand = (Operand)malloc(sizeof(struct Operand_));
    operand->kind = kind;
    if(isTemp) {
        operand->isTemp = isTemp;
        operand->u.temp.tempNum = num;
        tempNum += 1;
    } else {
        switch(kind) {
            case OP_VARIABLE:
            case OP_ARRAY:
            case OP_ADDRESS: {
                operand->u.var.varNum = num;
                operand->u.var.varName = name;
                varNum += 1;
                break;
            }
            case OP_CONSTANT: {
                operand->u.constant.constValue = value;
                break;
            }
            case OP_FUNCTION: {
                operand->u.func.funcName = name;
                break;
            }
            case OP_LABEL: {
                operand->u.label.labelNum = num;
                labelNum += 1;
                break;
            }
            default:
                break;
        }
    }
    return operand;
}

InterCode generateInterCode(IR_Kind kind, Operand op1, Operand op2, Operand op3, char* cond, int size) {
    InterCode intercode = (InterCode)malloc(sizeof(struct InterCode_));
    intercode->kind = kind;
    switch(kind) {
        case IR_LABEL:
        case IR_FUNC:
        case IR_GOTO:
        case IR_RETURN:
        case IR_ARG:
        case IR_PARAM:
        case IR_READ:
        case IR_WRITE: {
            intercode->u.unop.op1 = op1;
            break;
        }
        case IR_ASSIGN:
        case IR_CALL: {
            intercode->u.binop.op1 = op1;
            intercode->u.binop.op2 = op2;
            break;
        }
        case IR_ADD:
        case IR_SUB:
        case IR_MUL:
        case IR_DIV: {
            intercode->u.ternop.op1 = op1;
            intercode->u.ternop.op2 = op2;
            intercode->u.ternop.op3 = op3;
            break;
        }
        case IR_IF_GOTO: {
            intercode->u.ifgoto.op1 = op1;
            intercode->u.ifgoto.op2 = op2;
            intercode->u.ifgoto.op3 = op3;
            intercode->u.ifgoto.cond = cond;
            break;
        }
        case IR_DEC: {
            intercode->u.dec.op1 = op1;
            intercode->u.dec.size = size;
            break;
        }
        default:
            break;
    }
    return intercode;
}

void addInterCodes(InterCode intercode) {
    InterCodes intercodes = (InterCodes)malloc(sizeof(struct InterCodes_));
    intercodes->code = intercode;
    intercodes->prev = NULL;
    intercodes->next = NULL;
    if(!interCodesHead) {
        interCodesHead = (InterCodes)malloc(sizeof(struct InterCodes_));
        interCodesHead = intercodes;
        interCodesTail = (InterCodes)malloc(sizeof(struct InterCodes_));;
        interCodesTail = intercodes;
    } else {
        interCodesTail->next = intercodes;
        intercodes->prev = interCodesTail;
        interCodesTail = intercodes;
    }
}

void deleteInterCodes(InterCodes intercodes) {
    if(intercodes->prev == NULL && intercodes->next == NULL) {
        interCodesHead = NULL;
        interCodesTail = NULL;
    } else if(intercodes->prev == NULL && intercodes->next != NULL) {
        intercodes->next->prev = NULL;
        interCodesHead = intercodes->next;
    } else if(intercodes->prev != NULL && intercodes->next == NULL) {
        intercodes->prev->next = NULL;
        interCodesTail = intercodes->prev;
    } else {
        intercodes->prev->next = intercodes->next;
        intercodes->next->prev = intercodes->prev;
    }
    free(intercodes);
}

void addVariableOperands(Operand operand) {
    Operands variableOperand = (Operands)malloc(sizeof(struct Operands_));
    variableOperand->operand = operand;
    variableOperand->next = NULL;
    if(!variableOperandsHead) {
        variableOperandsHead = (Operands)malloc(sizeof(struct Operands_));
        variableOperandsHead = variableOperand;
    } else {
        variableOperand->next = variableOperandsHead;
        variableOperandsHead = variableOperand;
    }
    return;
}

Operand searchVariableOperands(char* name) {
    Operands variableOperand = variableOperandsHead;
    while(variableOperand) {
        if(!strcmp(variableOperand->operand->u.var.varName, name)) {
            return variableOperand->operand;
        }
        variableOperand = variableOperand->next;
    }
    return variableOperand->operand;
}

int getSize(Type type) {
    if(type) {
        switch(type->kind) {
            case BASIC: {
                return 4;
                break;
            }
            case ARRAY: {
                return type->u.array.size * getSize(type->u.array.elem);
                break;
            }
            default:
                break;
        }
    }
    return 0;
    
}

void printOperand(FILE* file, Operand operand) {
    switch(operand->kind) {
        case OP_VARIABLE:
        case OP_ARRAY:
        case OP_ADDRESS: {
            if(operand->isTemp) {
                fprintf(file, "t%d", operand->u.var.varNum);
            } else {
                fprintf(file, "v%d", operand->u.var.varNum);
            }
            break;
        }
        case OP_CONSTANT: {
            fprintf(file, "#%d", operand->u.constant.constValue);
            break;
        }
        case OP_FUNCTION: {
            fprintf(file, "%s", operand->u.func.funcName);
            break;
        }
        case OP_LABEL: {
            fprintf(file, "label%d", operand->u.label.labelNum);
            break;
        }
        default:
            break;
    }
    return;
}

void printInterCodes(FILE* file) {
    InterCodes interCodes = interCodesHead;
    while(interCodes) {
        switch(interCodes->code->kind) {
            case IR_LABEL: {
                fprintf(file, "LABEL ");
                printOperand(file, interCodes->code->u.unop.op1);
                fprintf(file, " :");
                break;
            }
            case IR_FUNC: {
                fprintf(file, "FUNCTION ");
                printOperand(file, interCodes->code->u.unop.op1);
                fprintf(file, " :");
                break;
            }
            case IR_GOTO: {
                fprintf(file, "GOTO ");
                printOperand(file, interCodes->code->u.unop.op1);
                break;
            }
            case IR_RETURN: {
                fprintf(file, "RETURN ");
                if(interCodes->code->u.unop.op1->kind == OP_ADDRESS) {
                    fprintf(file, "&");
                }
                printOperand(file, interCodes->code->u.unop.op1);
                break;
            }
            case IR_ARG: {
                fprintf(file, "ARG ");
                if(interCodes->code->u.unop.op1->kind == OP_ARRAY) {
                    fprintf(file, "&");
                }
                printOperand(file, interCodes->code->u.unop.op1);
                break;
            }
            case IR_PARAM: {
                fprintf(file, "PARAM ");
                printOperand(file, interCodes->code->u.unop.op1);
                break;
            }
            case IR_READ: {
                fprintf(file, "READ ");
                printOperand(file, interCodes->code->u.unop.op1);
                break;
            }
            case IR_WRITE: {
                fprintf(file, "WRITE ");
                if(interCodes->code->u.unop.op1->kind == OP_ADDRESS) {
                    fprintf(file, "*");
                }
                printOperand(file, interCodes->code->u.unop.op1);
                break;
            }
            case IR_ASSIGN: {
                if(interCodes->code->u.binop.op1->kind == OP_ADDRESS && interCodes->code->u.binop.op2->kind != OP_ARRAY) {
                    fprintf(file, "*");
                }
                printOperand(file, interCodes->code->u.binop.op1);
                fprintf(file, " := ");
                if(interCodes->code->u.binop.op2->kind == OP_ADDRESS) {
                    fprintf(file, "*");
                } else if(interCodes->code->u.binop.op2->kind == OP_ARRAY) {
                    fprintf(file, "&");
                }
                printOperand(file, interCodes->code->u.binop.op2);
                break;
            }
            case IR_CALL: {
                printOperand(file, interCodes->code->u.binop.op1);
                fprintf(file, " := CALL ");
                printOperand(file, interCodes->code->u.binop.op2);
                break;
            }
            case IR_ADD: {
                printOperand(file, interCodes->code->u.ternop.op1);
                fprintf(file, " := ");
                if(interCodes->code->u.ternop.op2->kind == OP_ARRAY) {
                    fprintf(file, "&");
                } else if(interCodes->code->u.ternop.op2->kind == OP_ADDRESS && interCodes->code->u.ternop.op1->kind != OP_ADDRESS) {
                    fprintf(file, "*");
                }
                printOperand(file, interCodes->code->u.ternop.op2);
                fprintf(file, " + ");
                if(interCodes->code->u.ternop.op3->kind == OP_ADDRESS) {
                    fprintf(file, "*");
                }
                printOperand(file, interCodes->code->u.ternop.op3);
                break;
            }
            case IR_SUB: {
                printOperand(file, interCodes->code->u.ternop.op1);
                fprintf(file, " := ");
                if(interCodes->code->u.ternop.op2->kind == OP_ADDRESS) {
                    fprintf(file, "*");
                }
                printOperand(file, interCodes->code->u.ternop.op2);
                fprintf(file, " - ");
                if(interCodes->code->u.ternop.op3->kind == OP_ADDRESS) {
                    fprintf(file, "*");
                }
                printOperand(file, interCodes->code->u.ternop.op3);
                break;
            }
            case IR_MUL:
             {
                printOperand(file, interCodes->code->u.ternop.op1);
                fprintf(file, " := ");
                if(interCodes->code->u.ternop.op2->kind == OP_ADDRESS) {
                    fprintf(file, "*");
                }
                printOperand(file, interCodes->code->u.ternop.op2);
                fprintf(file, " * ");
                if(interCodes->code->u.ternop.op3->kind == OP_ADDRESS) {
                    fprintf(file, "*");
                }
                printOperand(file, interCodes->code->u.ternop.op3);
                break;
            }
            case IR_DIV:
             {
                printOperand(file, interCodes->code->u.ternop.op1);
                fprintf(file, " := ");
                if(interCodes->code->u.ternop.op2->kind == OP_ADDRESS) {
                    fprintf(file, "*");
                }
                printOperand(file, interCodes->code->u.ternop.op2);
                fprintf(file, " / ");
                if(interCodes->code->u.ternop.op3->kind == OP_ADDRESS) {
                    fprintf(file, "*");
                }
                printOperand(file, interCodes->code->u.ternop.op3);
                break;
            }
            case IR_IF_GOTO: {
                fprintf(file, "IF ");
                if(interCodes->code->u.ifgoto.op1->kind == OP_ADDRESS) {
                    fprintf(file, "*");
                }
                printOperand(file, interCodes->code->u.ifgoto.op1);
                fprintf(file, " %s ", interCodes->code->u.ifgoto.cond);
                if(interCodes->code->u.ifgoto.op2->kind == OP_ADDRESS) {
                    fprintf(file, "*");
                }
                printOperand(file, interCodes->code->u.ifgoto.op2);
                fprintf(file, " GOTO ");
                printOperand(file, interCodes->code->u.ifgoto.op3);
                break;
            }
            case IR_DEC: {
                fprintf(file, "DEC ");
                printOperand(file, interCodes->code->u.dec.op1);
                fprintf(file, " %d", interCodes->code->u.dec.size);
                break;
            }
            default:
                break;
        }
        fprintf(file, "\n");
        interCodes = interCodes->next;
    }
    return;
}

void interCodesGeneration(Node* node) {
    if(node) {
        initInterCodes();
        translate_Program(node);
    }
    return;
}

// Program -> ExtDefList
void translate_Program(Node* node) {
    Node* child1 = getChild(node, 0);
    translate_ExtDefList(child1);
    return;
}

// ExtDefList -> ExtDef ExtDefList
// | Empty
void translate_ExtDefList(Node* node) {
    Node* child1 = getChild(node, 0);
    if(child1) {
        Node* child2 = getChild(node, 1);
        translate_ExtDef(child1);
        translate_ExtDefList(child2);
    }
    return;
}

// ExtDef -> Specifier ExtDecList SEMI
// | Specifier SEMI
// | Specifier FunDec CompSt
void translate_ExtDef(Node* node) {
    Node* child1 = getChild(node, 0);
    Node* child2 = getChild(node, 1);
    translate_Specifier(child1);
    if(!strcmp(child2->name, "ExtDecList")) {
        // 不存在全局变量
    } else if(!strcmp(child2->name, "FunDec")) {
        Node* child3 = getChild(node, 2);
        translate_FunDec(child2);
        translate_CompSt(child3);
    }
    return;
}

// ExtDecList -> VarDec
// | VarDec COMMA ExtDecList
void translate_ExtDecList(Node* node) {
    return;
}

// Specifier -> TYPE
// | StructSpecifier
void translate_Specifier(Node* node) {
    return;
}

// StructSpecifier : STRUCT OptTag LC DefList RC
// | STRUCT Tag
void translate_StructSpecifier(Node* node) {
    return;
}

// OptTag -> ID
// | Empty
void translate_OptTag(Node* node) {
    return;
}

// Tag -> ID
void translate_Tag(Node* node) {
    return;
}

// VarDec -> ID
// | VarDec LB INT RB
Operand translate_VarDec(Node* node, int isParam) {
    Operand operand = (Operand)malloc(sizeof(struct Operand_));
    Node* child1 = getChild(node, 0);
    if(!strcmp(child1->name, "ID")) {
        SymbolNode symbol = searchSymbolTable(child1->val.val_content, 0, BASIC); // 不存在结构体变量
        switch(symbol->type->kind) {
            case BASIC: {
                operand = generateOperand(OP_VARIABLE, 0, varNum, 0, symbol->name);
                addVariableOperands(operand);
                break;
            }
            case ARRAY: {
                if(isParam) {
                    operand = generateOperand(OP_ADDRESS, 0, varNum, 0, symbol->name);
                    addVariableOperands(operand);
                } else {
                    operand = generateOperand(OP_ARRAY, 0, varNum, 0, symbol->name);
                    addVariableOperands(operand);
                    addInterCodes(generateInterCode(IR_DEC, operand, NULL, NULL, NULL, getSize(symbol->type)));
                }
                break;
            }
            default:
                break;
        }
    } else {
        operand = translate_VarDec(child1, isParam);
    }
    return operand;
}

// FunDec -> ID LP VarList RP
// | ID LP RP
void translate_FunDec(Node* node) {
    Node* child1 = getChild(node, 0);
    Node* child3 = getChild(node, 2);
    addInterCodes(generateInterCode(IR_FUNC, generateOperand(OP_FUNCTION, 0, 0, 0, child1->val.val_content), NULL, NULL, NULL, 0));
    if(!strcmp(child3->name, "VarList")) {
        translate_VarList(child3);
    }
    return;
}

// VarList -> ParamDec COMMA VarList
// | ParamDec
void translate_VarList(Node* node) {
    Node* child1 = getChild(node, 0);
    Node* child3 = getChild(node, 2);
    translate_ParamDec(child1);
    if(child3) {
        translate_VarList(child3);
    }
    return;
}

// ParamDec -> Specifier VarDec
void translate_ParamDec(Node* node) {
    Node* child2 = getChild(node, 1);
    addInterCodes(generateInterCode(IR_PARAM, translate_VarDec(child2, 1), NULL, NULL, NULL, 0));
    return;

}

// CompSt -> LC DefList StmtList RC
void translate_CompSt(Node* node) {
    Node* child2 = getChild(node, 1);
    Node* child3 = getChild(node, 2);
    translate_DefList(child2);
    translate_StmtList(child3);
}

// StmtList -> Stmt StmtList
// | Empty
void translate_StmtList(Node* node) {
    Node* child1 = getChild(node, 0);
    if(child1) {
        Node* child2 = getChild(node, 1);
        translate_Stmt(child1);
        translate_StmtList(child2);
    }
    return;
}

// Stmt -> Exp SEMI
// | CompSt
// | RETURN Exp SEMI
// | IF LP Exp RP Stmt
// | IF LP Exp RP Stmt ELSE Stmt
// | WHILE LP Exp RP Stmt
void translate_Stmt(Node* node) {
    Node* child1 = getChild(node, 0);
    if(!strcmp(child1->name, "Exp")) {
        translate_Exp(child1, NULL);
    } else if(!strcmp(child1->name, "CompSt")) {
        translate_CompSt(child1);
    } else if(!strcmp(child1->name, "RETURN")) {
        Node* child2 = getChild(node, 1);
        Operand temp1 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
        translate_Exp(child2, temp1);
        addInterCodes(generateInterCode(IR_RETURN, temp1, NULL, NULL, NULL, 0));
    } else if(!strcmp(child1->name, "IF")) {
        Node* child3 = getChild(node, 2);
        Node* child5 = getChild(node, 4);
        Node* child7 = getChild(node, 6);
        Operand label1 = generateOperand(OP_LABEL, 0, labelNum, 0, NULL);
        Operand label2 = generateOperand(OP_LABEL, 0, labelNum, 0, NULL);
        translate_Cond(child3, label1, label2);
        addInterCodes(generateInterCode(IR_LABEL, label1, NULL, NULL, NULL, 0));
        translate_Stmt(child5);
        if(!child7) {
            addInterCodes(generateInterCode(IR_LABEL, label2, NULL, NULL, NULL, 0));
        } else {
            Operand label3 = generateOperand(OP_LABEL, 0, labelNum, 0, NULL);
            addInterCodes(generateInterCode(IR_GOTO, label3, NULL, NULL, NULL, 0));
            addInterCodes(generateInterCode(IR_LABEL, label2, NULL, NULL, NULL, 0));
            translate_Stmt(child7);
            addInterCodes(generateInterCode(IR_LABEL, label3, NULL, NULL, NULL, 0));
        }
    } else {
        Node* child3 = getChild(node, 2);
        Node* child5 = getChild(node, 4);
        Operand label1 = generateOperand(OP_LABEL, 0, labelNum, 0, NULL);
        Operand label2 = generateOperand(OP_LABEL, 0, labelNum, 0, NULL);
        Operand label3 = generateOperand(OP_LABEL, 0, labelNum, 0, NULL);
        addInterCodes(generateInterCode(IR_LABEL, label1, NULL, NULL, NULL, 0));
        translate_Cond(child3, label2, label3);
        addInterCodes(generateInterCode(IR_LABEL, label2, NULL, NULL, NULL, 0));
        translate_Stmt(child5);
        addInterCodes(generateInterCode(IR_GOTO, label1, NULL, NULL, NULL, 0));
        addInterCodes(generateInterCode(IR_LABEL, label3, NULL, NULL, NULL, 0));
    }
    return;
}

// DefList -> Def DefList
// | Empty
void translate_DefList(Node* node) {
    Node* child1 = getChild(node, 0);
    if(child1) {
        Node* child2 = getChild(node, 1);
        translate_Def(child1);
        translate_DefList(child2);
    }
    return;
}

// Def -> Specifier DecList SEMI
void translate_Def(Node* node) {
    Node* child2 = getChild(node, 1);
    translate_DecList(child2);
    return;
}

// DecList -> Dec
// | Dec COMMA DecList
void translate_DecList(Node* node) {
    Node* child1 = getChild(node, 0);
    Node* child3 = getChild(node, 2);
    translate_Dec(child1);
    if(child3) {
        translate_DecList(child3);
    }
    return;
}

// Dec -> VarDec
// | VarDec ASSIGNOP Exp
void translate_Dec(Node* node) {
    Node* child1 = getChild(node, 0);
    Node* child3 = getChild(node, 2);
    Operand operand = translate_VarDec(child1, 0);
    if(child3) {
        Operand temp1 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
        translate_Exp(child3, temp1);
        addInterCodes(generateInterCode(IR_ASSIGN, operand, temp1, NULL, NULL, 0));
    }
    return;
}

// Exp -> Exp ASSIGNOP Exp
// | Exp AND Exp
// | Exp OR Exp
// | Exp RELOP Exp
// | Exp PLUS Exp
// | Exp MINUS Exp
// | Exp STAR Exp
// | Exp DIV Exp
// | LP Exp RP
// | MINUS Exp
// | NOT Exp
// | ID LP Args RP
// | ID LP RP
// | Exp LB Exp RB
// | Exp DOT ID
// | ID
// | INT
// | FLOAT
void translate_Exp(Node* node, Operand place) {
    Node* child1 = getChild(node, 0);
    Node* child3 = getChild(node, 2);
    if(!strcmp(child1->name, "Exp") || !strcmp(child1->name, "NOT")) {
        Node* child2 = getChild(node, 1);
        if(!strcmp(child2->name, "ASSIGNOP")) {
            /*Node* subChild1 = getChild(child1, 0);
            Node* subChild3 = getChild(child1, 2);
            if(!strcmp(subChild1->name, "ID")) {
                Operand operand1 = searchVariableOperands(subChild1->val.val_content);
                if(operand1->kind == OP_VARIABLE) {    
                    Operand temp1 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
                    translate_Exp(child3, temp1);
                    addInterCodes(generateInterCode(IR_ASSIGN, operand1, temp1, NULL, NULL, 0));
                    if(place) {
                        addInterCodes(generateInterCode(IR_ASSIGN, place, operand1, NULL, NULL, 0));
                    }
                } else {
                    // TODO:数组赋值
                    Operand temp2 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
                    translate_Exp(child3, temp2);
                    Operand temp3 = (Operand)malloc(sizeof(struct Operand_));
                    Operand temp4 = (Operand)malloc(sizeof(struct Operand_));
                    if(operand1->kind == OP_ARRAY) {
                        temp3 = generateOperand(OP_ADDRESS, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
                        addInterCodes(generateInterCode(IR_ASSIGN, temp3, operand1, NULL, NULL, 0));
                    } else {
                        temp3 = operand1; // 优化：若temp1为地址则无需重新获得起始地址
                    }
                    if(temp2->kind == OP_ARRAY) {
                        temp4 = generateOperand(OP_ADDRESS, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
                        addInterCodes(generateInterCode(IR_ASSIGN, temp4, temp2, NULL, NULL, 0));
                    } else {
                        temp4 = temp2; // 优化：若temp2为地址则无需重新获得起始地址
                    }
                    int temp3Size = getSize(Exp(child1));
                    int temp4Size = getSize(Exp(child3));
                    int size = temp3Size;
                    if(temp3Size > temp4Size) {
                        size = temp4Size;
                    }
                    for(int offset = 0; offset < size - 4; offset += 4) {
                        addInterCodes(generateInterCode(IR_ASSIGN, temp3, temp4, NULL, NULL, 0));
                        addInterCodes(generateInterCode(IR_ADD, temp3, temp3, generateOperand(OP_CONSTANT, 0, 0, 4, NULL), NULL, 0));
                        addInterCodes(generateInterCode(IR_ADD, temp4, temp4, generateOperand(OP_CONSTANT, 0, 0, 4, NULL), NULL, 0));
                    }
                    addInterCodes(generateInterCode(IR_ASSIGN, temp3, temp4, NULL, NULL, 0));
                    if(place) {
                        addInterCodes(generateInterCode(IR_ASSIGN, place, operand1, NULL, NULL, 0));
                    }
                }
            } else if(!strcmp(subChild3->name, "Exp")) { // TODO: 数组元素赋值
                Operand temp1 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
                translate_Exp(child1, temp1);
                Operand temp2 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
                translate_Exp(child3, temp2);
                if(temp1->kind == OP_VARIABLE) { // 数组元素为基本类型
                    addInterCodes(generateInterCode(IR_ASSIGN, temp1, temp2, NULL, NULL, 0));
                } else { // 数组元素为数组
                    Operand temp3 = (Operand)malloc(sizeof(struct Operand_));
                    Operand temp4 = (Operand)malloc(sizeof(struct Operand_));
                    if(temp1->kind == OP_ARRAY) {
                        temp3 = generateOperand(OP_ADDRESS, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
                        addInterCodes(generateInterCode(IR_ASSIGN, temp3, temp1, NULL, NULL, 0));
                    } else {
                        temp3 = temp1; // 优化：若temp1为地址则无需重新获得起始地址
                    }
                    if(temp2->kind == OP_ARRAY) {
                        temp4 = generateOperand(OP_ADDRESS, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
                        addInterCodes(generateInterCode(IR_ASSIGN, temp4, temp2, NULL, NULL, 0));
                    } else {
                        temp4 = temp2; // 优化：若temp2为地址则无需重新获得起始地址
                    }
                    int temp3Size = getSize(Exp(child1));
                    int temp4Size = getSize(Exp(child3));
                    int size = temp3Size;
                    if(temp3Size > temp4Size) {
                        size = temp4Size;
                    }
                    for(int offset = 0; offset < size - 4; offset += 4) {
                        addInterCodes(generateInterCode(IR_ASSIGN, temp3, temp4, NULL, NULL, 0));
                        addInterCodes(generateInterCode(IR_ADD, temp3, temp3, generateOperand(OP_CONSTANT, 0, 0, 4, NULL), NULL, 0));
                        addInterCodes(generateInterCode(IR_ADD, temp4, temp4, generateOperand(OP_CONSTANT, 0, 0, 4, NULL), NULL, 0));
                    }
                    addInterCodes(generateInterCode(IR_ASSIGN, temp3, temp4, NULL, NULL, 0));
                }
                if(place) {
                    addInterCodes(generateInterCode(IR_ASSIGN, place, temp1, NULL, NULL, 0));
                }
            } else {
                // 不存在结构体变量
                printf("Cannot translate: Code contains variables or parameters of structure type.\n");
                exit(-1);
            }*/
            Operand temp1 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
            translate_Exp(child1, temp1);
            Operand temp2 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
            translate_Exp(child3, temp2);
            if(temp1->kind == OP_VARIABLE) { // 基本类型赋值
                addInterCodes(generateInterCode(IR_ASSIGN, temp1, temp2, NULL, NULL, 0));
            } else { // TODO: 数组赋值
                Operand temp3 = (Operand)malloc(sizeof(struct Operand_));
                Operand temp4 = (Operand)malloc(sizeof(struct Operand_));
                if(temp1->kind == OP_ARRAY) {
                    temp3 = generateOperand(OP_ADDRESS, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
                    addInterCodes(generateInterCode(IR_ASSIGN, temp3, temp1, NULL, NULL, 0));
                } else {
                    temp3 = temp1; // 优化：若temp1为地址则无需重新获得起始地址
                }
                if(temp2->kind == OP_ARRAY) {
                    temp4 = generateOperand(OP_ADDRESS, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
                    addInterCodes(generateInterCode(IR_ASSIGN, temp4, temp2, NULL, NULL, 0));
                } else {
                    temp4 = temp2; // 优化：若temp2为地址则无需重新获得起始地址
                }
                int temp3Size = getSize(Exp(child1));
                int temp4Size = getSize(Exp(child3));
                int size = temp3Size;
                if(temp3Size > temp4Size) {
                    size = temp4Size;
        }
                for(int offset = 0; offset < size - 4; offset += 4) {
                    addInterCodes(generateInterCode(IR_ASSIGN, temp3, temp4, NULL, NULL, 0));
                    addInterCodes(generateInterCode(IR_ADD, temp3, temp3, generateOperand(OP_CONSTANT, 0, 0, 4, NULL), NULL, 0));
                    addInterCodes(generateInterCode(IR_ADD, temp4, temp4, generateOperand(OP_CONSTANT, 0, 0, 4, NULL), NULL, 0));
                }
                addInterCodes(generateInterCode(IR_ASSIGN, temp3, temp4, NULL, NULL, 0));
            }
            if(place) {
                addInterCodes(generateInterCode(IR_ASSIGN, place, temp1, NULL, NULL, 0));
            }
        } else if(!strcmp(child2->name, "RELOP") || !strcmp(child1->name, "NOT") || !strcmp(child2->name, "AND") || !strcmp(child2->name, "OR")) {
            Operand label1 = generateOperand(OP_LABEL, 0, labelNum, 0, NULL);
            Operand label2 = generateOperand(OP_LABEL, 0, labelNum, 0, NULL);
            if(place) {
                addInterCodes(generateInterCode(IR_ASSIGN, place, generateOperand(OP_CONSTANT, 0, 0, 0, NULL), NULL, NULL, 0));
                translate_Cond(node, label1, label2);
                addInterCodes(generateInterCode(IR_LABEL, label1, NULL, NULL, NULL, 0));
                addInterCodes(generateInterCode(IR_ASSIGN, place, generateOperand(OP_CONSTANT, 0, 0, 1, NULL), NULL, NULL, 0));
                addInterCodes(generateInterCode(IR_LABEL, label2, NULL, NULL, NULL, 0));
            }
        } else if(!strcmp(child2->name, "PLUS")) {
            Operand temp1 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
            translate_Exp(child1, temp1);
            Operand temp2 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
            translate_Exp(child3, temp2);
            if(place){
                if(temp1->kind == OP_CONSTANT && temp2->kind == OP_CONSTANT) { // TODO: 优化：直接将place修改为计算结果的常量
                    place->kind = OP_CONSTANT;
                    place->isTemp = 0;
                    place->u.constant.constValue = temp1->u.constant.constValue + temp2->u.constant.constValue;;
                } else {
                    addInterCodes(generateInterCode(IR_ADD, place, temp1, temp2, NULL, 0));
                }
            }
        } else if(!strcmp(child2->name, "MINUS")) {
            Operand temp1 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
            translate_Exp(child1, temp1);
            Operand temp2 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
            translate_Exp(child3, temp2);
            if(place){
                if(temp1->kind == OP_CONSTANT && temp2->kind == OP_CONSTANT) { // TODO: 优化：直接将place修改为计算结果的常量
                    place->kind = OP_CONSTANT;
                    place->isTemp = 0;
                    place->u.constant.constValue = temp1->u.constant.constValue - temp2->u.constant.constValue;;
                } else {
                    addInterCodes(generateInterCode(IR_SUB, place, temp1, temp2, NULL, 0));
                }
            }
        } else if(!strcmp(child2->name, "STAR")) {
            Operand temp1 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
            translate_Exp(child1, temp1);
            Operand temp2 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
            translate_Exp(child3, temp2);
            if(place){
                if(temp1->kind == OP_CONSTANT && temp2->kind == OP_CONSTANT) { // TODO: 优化：直接将place修改为计算结果的常量
                    place->kind = OP_CONSTANT;
                    place->isTemp = 0;
                    place->u.constant.constValue = temp1->u.constant.constValue * temp2->u.constant.constValue;;
                } else {
                    addInterCodes(generateInterCode(IR_MUL, place, temp1, temp2, NULL, 0));
                }
            }
        } else if(!strcmp(child2->name, "DIV")) {
            Operand temp1 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
            translate_Exp(child1, temp1);
            Operand temp2 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
            translate_Exp(child3, temp2);
            if(place){
                if(temp1->kind == OP_CONSTANT && temp2->kind == OP_CONSTANT) { // TODO: 优化：直接将place修改为计算结果的常量
                    place->kind = OP_CONSTANT;
                    place->isTemp = 0;
                    place->u.constant.constValue = temp1->u.constant.constValue / temp2->u.constant.constValue;;
                } else {
                    addInterCodes(generateInterCode(IR_DIV, place, temp1, temp2, NULL, 0));
                }
            }
        } else if(!strcmp(child2->name, "LB")) {
            Operand temp1 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
            translate_Exp(child1, temp1);
            Operand temp2 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
            translate_Exp(child3, temp2);
            Operand temp3 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
            Type temp1Type = Exp(child1);
            // temp3->u.value = getSize(temp1Type) / temp1Type->u.array.size * temp2->u.value;
            int width = getSize(temp1Type) / temp1Type->u.array.size;
            addInterCodes(generateInterCode(IR_MUL, temp3, temp2, generateOperand(OP_CONSTANT, 0, 0, width, NULL), NULL, 0));
            if(place) {
                place->kind = OP_ADDRESS;
                addInterCodes(generateInterCode(IR_ADD, place, temp1, temp3, NULL, 0));
            }
        } else {
            // 不存在结构体变量
            printf("Cannot translate: Code contains variables or parameters of structure type.\n");
            exit(-1);
        }
    } else if(!strcmp(child1->name, "LP")) {
        Node* child2 = getChild(node, 1);
        translate_Exp(child2, place);
    } else if(!strcmp(child1->name, "MINUS")) {
        Node* child2 = getChild(node, 1);
        Operand temp1 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
        translate_Exp(child2, temp1);
        if(place) {
            if(temp1->kind == OP_ADDRESS) {
                addInterCodes(generateInterCode(IR_SUB, place, generateOperand(OP_CONSTANT, 0, 0, 0, NULL), temp1, NULL, 0));
            } else {
                // addInterCodes(generateInterCode(IR_SUB, place, generateOperand(OP_CONSTANT, 0, 0, 0, NULL), temp1, NULL, 0));
                place->kind = OP_CONSTANT; // TODO: 优化：直接将place修改为计算结果的常量
                place->isTemp = 0;
                place->u.constant.constValue = 0 - temp1->u.constant.constValue;
            }
        }
    } else if(!strcmp(child1->name, "ID")) {
        if(!child3) {
            Operand operand = searchVariableOperands(child1->val.val_content);
            if(place) {
                //addInterCodes(generateInterCode(IR_ASSIGN, place, operand, NULL, NULL, 0)); // 不能直接赋值
                //place = operand; // TODO: 优化：直接将place修改为变量
                place->kind = operand->kind;
                place->isTemp = operand->isTemp;
                place->u = operand->u;
                tempNum -= 1;
            }
        } else {
            if(strcmp(child3->name, "Args")) {
                if(!strcmp(child1->val.val_content, "read")) {
                    if(place) {
                        addInterCodes(generateInterCode(IR_READ, place, NULL, NULL, NULL, 0));
                    }
                } else {
                    if(place) {
                        addInterCodes(generateInterCode(IR_CALL, place, generateOperand(OP_FUNCTION, 0, 0, 0, child1->val.val_content), NULL, NULL ,0));
                    } else {
                        Operand temp1 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
                        addInterCodes(generateInterCode(IR_CALL, temp1, generateOperand(OP_FUNCTION, 0, 0, 0, child1->val.val_content), NULL, NULL ,0));
                    }
                }
            } else {
                Operands argOperandsHead = translate_Args(child3, NULL);
                if(!strcmp(child1->val.val_content, "write")) {
                    addInterCodes(generateInterCode(IR_WRITE, argOperandsHead->operand, NULL, NULL, NULL, 0));
                    if(place) {
                        addInterCodes(generateInterCode(IR_ASSIGN, place, generateOperand(OP_CONSTANT, 0, 0, 0, NULL), NULL, NULL, 0));
                    }
                } else {
                    Operands argOperands = argOperandsHead;
                    while(argOperands) {
                        addInterCodes(generateInterCode(IR_ARG, argOperands->operand, NULL, NULL, NULL, 0));
                        argOperands = argOperands->next;
                    }
                    if(place) {
                        addInterCodes(generateInterCode(IR_CALL, place, generateOperand(OP_FUNCTION, 0, 0, 0, child1->val.val_content), NULL, NULL, 0));
                    } else {
                        Operand temp1 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
                        addInterCodes(generateInterCode(IR_CALL, temp1, generateOperand(OP_FUNCTION, 0, 0, 0, child1->val.val_content), NULL, NULL ,0));
                    }
                }
            }
        }
    } else {
        if(!strcmp(child1->name, "INT")) {
            if(place) {
                // addInterCodes(generateInterCode(IR_ASSIGN, place, generateOperand(OP_CONSTANT, 0, 0, child1->val.val_int, NULL), NULL, NULL, 0));
                // place = generateOperand(OP_CONSTANT, 0, 0, child1->val.val_int, NULL); // 不能直接赋值
                place->kind = OP_CONSTANT;// TODO: 优化：直接将place修改为常量
                place->isTemp = 0;
                place->u.constant.constValue = child1->val.val_int;
            }
        } else {
            // 不存在浮点型常量
        }
    }
    return;
}

// Args -> Exp COMMA Args
// | Exp
Operands translate_Args(Node* node, Operands argOperandsHead) {
    Node* child1 = getChild(node, 0);
    Node* child3 = getChild(node, 2);
    Operand temp1 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
    translate_Exp(child1, temp1);
    if(!argOperandsHead) {
        argOperandsHead =  (Operands)malloc(sizeof(struct Operands_));
        argOperandsHead->operand = temp1;
        argOperandsHead->next = NULL;
    } else {
        Operands argOperands = (Operands)malloc(sizeof(struct Operands_));
        argOperands->operand = temp1;
        argOperands->next = argOperandsHead;
        argOperandsHead = argOperands;
    }
    if(child3) {
        argOperandsHead = translate_Args(child3, argOperandsHead);
    }
    return argOperandsHead;
}

// Exp(Cond) -> Exp AND Exp
// | Exp OR Exp
// | Exp RELOP Exp
// | NOT Exp
void translate_Cond(Node* node, Operand label_true, Operand label_false) {
    Node* child1 = getChild(node, 0);
    Node* child2 = getChild(node, 1);
    Node* child3 = getChild(node, 2);
    if(!strcmp(child1->name, "NOT")) {
        translate_Cond(child2, label_false, label_true);
    } else {
        if(child2 && !strcmp(child2->name, "AND")) {
            Operand label1 = generateOperand(OP_LABEL, 0, labelNum, 0, NULL);
            translate_Cond(child1, label1, label_false);
            addInterCodes(generateInterCode(IR_LABEL, label1, NULL, NULL, NULL, 0));
            translate_Cond(child3, label_true, label_false);
        } else if(child2 && !strcmp(child2->name, "OR")) {
            Operand label1 = generateOperand(OP_LABEL, 0, labelNum, 0, NULL);
            translate_Cond(child1, label_true, label1);
            addInterCodes(generateInterCode(IR_LABEL, label1, NULL, NULL, NULL, 0));
            translate_Cond(child3, label_true, label_false);
        } else if(child2 && !strcmp(child2->name, "RELOP")) {
            Operand temp1 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
            translate_Exp(child1, temp1);
            Operand temp2 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
            translate_Exp(child3, temp2);
            addInterCodes(generateInterCode(IR_IF_GOTO, temp1, temp2, label_true, child2->val.val_content, 0));
            addInterCodes(generateInterCode(IR_GOTO, label_false, NULL, NULL, NULL, 0));
        } else {
            Operand temp1 = generateOperand(OP_VARIABLE, 1, tempNum, 0, NULL); // 初始化为OP_VARIABLE，在translate_Exp中可能被修改为OP_ADDRESS
            translate_Exp(node, temp1);
            addInterCodes(generateInterCode(IR_IF_GOTO, temp1, generateOperand(OP_CONSTANT, 0, 0, 0, NULL), label_true, "!=", 0));
            addInterCodes(generateInterCode(IR_GOTO, label_false, NULL, NULL, NULL, 0));
        }
    }
}