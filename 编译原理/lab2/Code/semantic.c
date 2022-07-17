#include "semantic.h"

int isSameType(Type type1, Type type2) {
    if(type1 == NULL && type2 == NULL) {
        return 1;
    }
    if(type1 == NULL || type2 == NULL) {
        return 0;
    }
    if(type1->kind != type2->kind) {
        return 0;
    }
    switch(type1->kind) {
        case BASIC:
            if(type1->u.basic == type2->u.basic) {
                return 1;
            } else {
                return 0;
            }
        case ARRAY:
            if(isSameType(type1->u.array.elem, type2->u.array.elem)) {
                return 1;
            } else {
                return 0;
            }
        case STRUCTTAG:
        case STRUCTURE:
            if(!strcmp(type1->u.structure.tagName, type2->u.structure.tagName)) {
                return 1;
            } else {
                return 0;
            }
        case FUNCTION: // TODO: 是否需要function的等价
            if(!isSameType(type1->u.function.ret, type2->u.function.ret)) {
                return 0;
            } else if(!isSameParam(type1->u.function.param, type2->u.function.param)) {
                return 0;
            } else {
                return 1;
            }
        default:
            return 0;
    }

}

int isSameParam(FieldList param1, FieldList param2) {
    if(param1 == NULL && param2 == NULL) {
        return 1;
    }
    if(param1 == NULL || param2 == NULL) {
        return 0;
    }
    while(param1 || param2) {
        if(param1 == NULL || param2 == NULL) {
            return 0;
        }
        if(!isSameType(param1->type, param2->type)) {
            return 0;
        }
        param1 = param1->tail;
        param2 = param2->tail;
    }
    return 1;
}

char* getExpContent(Node* node) {
    return "xxx"; // incompleted function
    Node* child1 = getChild(node, 0);
    Node* child3 = getChild(node, 2);
    char exp[100];
    if(!strcmp(child1->name, "Exp")) {
        Node* child2 = getChild(node, 1);
        if(!strcmp(child2->name, "ASSIGNOP") || !strcmp(child2->name, "AND") || !strcmp(child2->name, "OR") || !strcmp(child2->name, "RELOP") || !strcmp(child2->name, "PLUS") || !strcmp(child2->name, "MINUS") || !strcmp(child2->name, "STAR") || !strcmp(child2->name, "DIV")) {
            // return strcat(strcat(getExpContent(child1), child2->val.val_content), getExpContent(child3));
            sprintf(exp, "%s%s%s", getExpContent(child1), child2->val.val_content, getExpContent(child3));
        } else if(!strcmp(child2->name, "LB")) {
            Node* child4 = getChild(node, 3);
            // return strcat(strcat(strcat(getExpContent(child1), child2->val.val_content), getExpContent(child3)), child4->val.val_content);
            sprintf(exp, "%s%s%s%s", getExpContent(child1), child2->val.val_content, getExpContent(child3), child4->val.val_content);
        } else {
            // return strcat(strcat(getExpContent(child1), child2->val.val_content), child3->val.val_content);
            sprintf(exp, "%s%s%s", getExpContent(child1), child2->val.val_content, child3->val.val_content);
        }
    } else if(!strcmp(child1->name, "LP")) {
        Node* child2 = getChild(node, 1);
        // return strcat(strcat(child1->val.val_content, getExpContent(child2)), child3->val.val_content);
        sprintf(exp, "%s%s%s", child1->val.val_content, getExpContent(child2), child3->val.val_content);
    } else if(!strcmp(child1->name, "MINUS")) {
        Node* child2 = getChild(node, 1);
        // return strcat(child1->val.val_content, getExpContent(child2));
        sprintf(exp, "%s%s", child1->val.val_content, getExpContent(child2));
    } else if(!strcmp(child1->name, "NOT")) {
        Node* child2 = getChild(node, 1);
        // return strcat(child1->val.val_content, getExpContent(child2));
        sprintf(exp, "%s%s", child1->val.val_content, getExpContent(child2));
    } else if(!strcmp(child1->name, "ID")) {
        if(!child3) {
            //return child1->val.val_content;
            //sprintf(exp, "%s", child1->val.val_content);
            strcpy(exp, child1->val.val_content);
        } else {
            Node* child2 = getChild(node, 1);
            if(!strcmp(child3->name, "Args")) {
                Node* child4 = getChild(node, 3);
                // return strcat(strcat(strcat(child1->val.val_content, child2->val.val_content), getExpContent(child3)), child4->val.val_content);
                sprintf(exp, "%s%s%s%s", child1->val.val_content, child2->val.val_content, getExpContent(child3), child4->val.val_content);
            } else {
                // return strcat(strcat(child1->val.val_content, child2->val.val_content), child3->val.val_content);
                sprintf(exp, "%s%s%s", child1->val.val_content, child2->val.val_content, child3->val.val_content);
            }
        }
    } else {
        if(!strcmp(child1->name, "INT")) {
            sprintf(exp, "%u", child1->val.val_int);
        } else {
            // char num[100];
            // sprintf(num, "%f\0", child1->val.val_float);
            // return num;
            return "float number"; // 由于实现问题，这里无法转化为需要的字符串
        }
    }
    //return exp;
    char* exp1 = (char*)malloc(strlen(exp));
    strcpy(exp1, exp);
    return exp1;
}

void semanticAnalysis(Node* node) {
    if(node) {
        anonymousStructNum = 0;
        Program(node);
    }
    return;
}

// Program -> ExtDefList
void Program(Node* node) {
    initSymbolTable();
    initScopeStack();
    Node* child1 = getChild(node, 0);
    ExtDefList(child1);
    return;
}

// ExtDefList -> ExtDef ExtDefList
// | Empty
void ExtDefList(Node* node) {
    Node* child1 = getChild(node, 0);
    if(child1) {
        Node* child2 = getChild(node, 1);
        ExtDef(child1);
        ExtDefList(child2);
    }
    return;
}

// ExtDef -> Specifier ExtDecList SEMI
// | Specifier SEMI
// | Specifier FunDec CompSt
void ExtDef(Node* node) {
    Node* child1 = getChild(node, 0);
    Node* child2 = getChild(node, 1);
    Type type = Specifier(child1);
    if(!strcmp(child2->name, "ExtDecList")) {
        ExtDecList(child2, type);
    } else if(!strcmp(child2->name, "FunDec")) {
        Node* child3 = getChild(node, 2);
        FieldList param =  FunDec(child2, type);
        CompSt(child3, type, param);
    }
    return;
}

// ExtDecList -> VarDec
// | VarDec COMMA ExtDecList
void ExtDecList(Node* node, Type type) {
     Node* child1 = getChild(node, 0);
     VarDec(child1, type, CONTEXT_EXT);
     Node* child3 = getChild(node, 2);
     if(child3) {
         ExtDecList(child3, type);
     }
     return;
}

// Specifier -> TYPE
// | StructSpecifier
Type Specifier(Node* node) {
    Node* child1 = getChild(node, 0);
    Type type = NULL;
    if(!strcmp(child1->name, "TYPE")) {
        type = (Type)malloc(sizeof(struct Type_));
        type->kind = BASIC;
        if(!strcmp(child1->val.val_content, "int")) {
            type->u.basic = BASIC_INT;
        } else if(!strcmp(child1->val.val_content, "float")) {
            type->u.basic = BASIC_FLOAT;
        }
    } else {
        type = StructSpecifier(child1);
    }
    return type;
}

// StructSpecifier : STRUCT OptTag LC DefList RC
// | STRUCT Tag
Type StructSpecifier(Node* node) {
    Node* child2 = getChild(node, 1);
    Type type = NULL;
    if(!strcmp(child2->name, "OptTag")) {
        Node* child4 = getChild(node, 3);
        char* optTag = OptTag(child2); // TODO: 能否这样赋值?
        SymbolNode symbol = searchSymbolTable(optTag, scopeDepth, BASIC); // 与变量重名也算
        if(symbol) {
            // ERROR16
            // printf("Error type %d at Line %d: %s\n", 16, child2->line, strcat(strcat("Duplicated name \"", optTag), "\""));
            sprintf(semanticErrorMsg, "%s%s%s", "Duplicated name \"", optTag, "\"");
            printf("Error type %d at Line %d: %s\n", 16, child2->line, semanticErrorMsg);
            if(symbol->type->kind == STRUCTTAG) {
                return symbol->type;
            } else {
                return NULL;
            }
        }
        enterScope();
        type = (Type)malloc(sizeof(struct Type_));
        type->kind = STRUCTURE;
        type->u.structure.tagName = optTag; // TODO: 能否这样赋值?
        type->u.structure.field = DefList(child4, CONTEXT_STRUCT); // TODO: 如何赋值？
        exitScope();
        Type optTagType = (Type)malloc(sizeof(struct Type_));
        optTagType->kind = STRUCTTAG;
        optTagType->u.structure.tagName = optTag; // TODO: 能否这样赋值?
        optTagType->u.structure.field = type->u.structure.field; // TODO: 如何赋值？
        symbol = createSymbol(optTagType, optTag, scopeDepth);
        insertSymbolTable(symbol);
    } else {
        char* tag = Tag(child2); // TODO: 能否这样赋值?
        SymbolNode symbol = searchSymbolTable(tag, scopeDepth, STRUCTTAG);
        if(!symbol) {
            // ERROR17
            // printf("Error type %d at Line %d: %s\n", 17, child2->line, strcat(strcat("Undefined structure \"", tag), "\""));
            sprintf(semanticErrorMsg, "%s%s%s", "Undefined structure \"", tag, "\"");
            printf("Error type %d at Line %d: %s\n", 17, child2->line, semanticErrorMsg);
            return NULL;
        }
        type = (Type)malloc(sizeof(struct Type_)); // TODO: 如何赋值？
        type->kind = STRUCTURE;
        type->u.structure = symbol->type->u.structure;
        // type = symbol->type; // TODO: 如何赋值？
        // type->kind = STRUCTURE; // TODO: 如何赋值？
    }
    return type;
}

// OptTag -> ID
// | Empty
char* OptTag(Node* node) {
     Node* child1 = getChild(node, 0);
     if(child1) {
         return child1->val.val_content;
     } else {
         anonymousStructNum += 1;
         char tmp[100];
         sprintf(tmp, "%dstruct", anonymousStructNum);
         char* anonymousStructName = (char*)malloc(strlen(tmp));
         strcpy(anonymousStructName, tmp);
         return anonymousStructName; // TODO: 为匿名结构体赋予特殊名字，如1struct
     }
}

// Tag -> ID
char* Tag(Node* node) {
     Node* child1 = getChild(node, 0);
     return child1->val.val_content;
}

// VarDec -> ID
// | VarDec LB INT RB
FieldList VarDec(Node* node, Type type, Context context) {
    Node* child1 = getChild(node, 0);
    FieldList field = (FieldList)malloc(sizeof(struct FieldList_));
    if(!strcmp(child1->name, "ID")) {
        if(type) {
            switch(context) {
                case CONTEXT_EXT:
                case CONTEXT_LOCAL:
                case CONTEXT_PARAM: { // 加{}，防止symbol重复定义
                    SymbolNode symbol = searchSymbolTable(child1->val.val_content, scopeDepth, type->kind);
                    if(symbol && (symbol->depth == scopeDepth || symbol->type->kind == STRUCTTAG)) {
                        // ERROR3
                        // printf("Error type %d at Line %d: %s\n", 3, child1->line, strcat(strcat("Redefined variable \"", child1->val.val_content), "\""));
                        sprintf(semanticErrorMsg, "%s%s%s", "Redefined variable \"", child1->val.val_content, "\"");
                        printf("Error type %d at Line %d: %s\n", 3, child1->line, semanticErrorMsg);
                    } else {
                        symbol = createSymbol(type, child1->val.val_content, scopeDepth);
                        insertSymbolTable(symbol);
                    }
                    break;
                }
                case CONTEXT_STRUCT: { // 加{}，防止symbol重复定义
                    SymbolNode symbol = searchSymbolTable(child1->val.val_content, scopeDepth, STRUCTFIELD);
                    if(symbol) {
                        // ERROR15
                        // printf("Error type %d at Line %d: %s\n", 15, child1->line, strcat(strcat("Redefined field \"", child1->val.val_content), "\""));
                        sprintf(semanticErrorMsg, "%s%s%s", "Redefined field \"", child1->val.val_content, "\"");
                        printf("Error type %d at Line %d: %s\n", 15, child1->line, semanticErrorMsg);
                    } else {
                        symbol = createSymbol(type, child1->val.val_content, scopeDepth);
                        insertSymbolTable(symbol);
                    }
                    break;
                }
                default:
                    break;
            }
        }
        field->name = child1->val.val_content; // TODO: 能否这样赋值?
        field->type = type; // TODO: 是否需要参考symbol->type // TODO: 如何赋值？
        field->tail = NULL;
    } else {
        Node* child3 = getChild(node, 2);
        Type nextType = (Type)malloc(sizeof(struct Type_));
        nextType->kind = ARRAY;
        nextType->u.array.elem = type; // TODO: 如何赋值？
        nextType->u.array.size = child3->val.val_int;
        field->type = type; // TODO: 如何赋值？
        field->tail = VarDec(child1, nextType, context);
        field->name = field->tail->name;
    }
    return field;
}

// FunDec -> ID LP VarList RP
// | ID LP RP
FieldList FunDec(Node* node, Type type) {
    Node* child1 = getChild(node, 0);
    Node* child3 = getChild(node, 2);
    FieldList field = NULL;
    SymbolNode symbol = searchSymbolTable(child1->val.val_content, scopeDepth, FUNCTION);
    int isRedefined = 0;
    if(symbol && symbol->depth == scopeDepth) {
        // ERROR4
        // printf("Error type %d at Line %d: %s\n", 4, child1->line, strcat(strcat("Redefined function \"", child1->val.val_content), "\""));
        sprintf(semanticErrorMsg, "%s%s%s", "Redefined function \"", child1->val.val_content, "\"");
        printf("Error type %d at Line %d: %s\n", 4, child1->line, semanticErrorMsg);
        isRedefined = 1;
        // TODO: 是否需要返回symbol->type->u.function.field
    }
    Type function = (Type)malloc(sizeof(struct Type_));
    function->kind = FUNCTION;
    if(!strcmp(child3->name, "VarList")) {
        enterScope();
        function->u.function.param = VarList(child3, CONTEXT_PARAM);
        function->u.function.ret = type; // TODO: 如何赋值？
        field = function->u.function.param;
        exitScope();
    } else {
        function->u.function.param = NULL;
        function->u.function.ret = type; // TODO: 如何赋值？
    }
    symbol = createSymbol(function, child1->val.val_content, scopeDepth);
    symbol->isRedefined = isRedefined; // TODO: 重复定义
    insertSymbolTable(symbol);
    return field;
}

// VarList -> ParamDec COMMA VarList
// | ParamDec
FieldList VarList(Node* node, Context context) {
    Node* child1 = getChild(node, 0);
    Node* child3 = getChild(node, 2);
    FieldList field = ParamDec(child1, context);
    if(child3) {
        field->tail = VarList(child3, context);
    }
    return field;
}

// ParamDec -> Specifier VarDec
FieldList ParamDec(Node* node, Context context) {
    Node* child1 = getChild(node, 0);
    Node* child2 = getChild(node, 1);
    Type type = Specifier(child1);
    FieldList field = (FieldList)malloc(sizeof(struct FieldList_));
    FieldList vardec = VarDec(child2, type, context);
    field->name = vardec->name; // TODO: 能否这样赋值?
    FieldList tmp = vardec;
    while(tmp->tail) {
        tmp = tmp->tail;
    }
    field->type = tmp->type; // TODO: 如何赋值？
    field->tail = NULL;
    return field;
}

// CompSt -> LC DefList StmtList RC
void CompSt(Node* node, Type type, FieldList param) {
    Node* child2 = getChild(node, 1);
    Node* child3 = getChild(node, 2);
    enterScope();
    SymbolNode symbol = NULL;
    while(param) {
        symbol = (SymbolNode)malloc(sizeof(struct SymbolNode_));
        symbol->name = param->name; // TODO: 能否这样赋值?
        symbol->type = param->type; // TODO: 如何赋值？
        symbol->depth = scopeDepth;
        symbol->hashNext = NULL;
        symbol->scopeNext = NULL;
        insertSymbolTable(symbol);
        param = param->tail;
    }
    DefList(child2, CONTEXT_LOCAL);
    StmtList(child3, type);
    exitScope();
    return;
}

// StmtList -> Stmt StmtList
// | Empty
void StmtList(Node* node, Type type) {
    Node* child1 = getChild(node, 0);
    if(child1) {
        Node* child2 = getChild(node, 1);
        Stmt(child1, type);
        StmtList(child2, type);
    }
    return;
}

// Stmt -> Exp SEMI
// | CompSt
// | RETURN Exp SEMI
// | IF LP Exp RP Stmt
// | IF LP Exp RP Stmt ELSE Stmt
// | WHILE LP Exp RP Stmt
void Stmt(Node* node, Type type) {
    Node* child1 = getChild(node, 0);
    if(!strcmp(child1->name, "Exp")) {
        Exp(child1);
    } else if(!strcmp(child1->name, "CompSt")) {
        CompSt(child1, type, NULL); // TODO: type还是NULL(if中可能有return？)
    } else if(!strcmp(child1->name, "RETURN")) {
        Node* child2 = getChild(node, 1);
        Type ret = Exp(child2);
        if(!isSameType(type, ret)) {
            // ERROR8
            // printf("Error type %d at Line %d: %s\n", 8, child2->line, "Type mismatched for return");
            sprintf(semanticErrorMsg, "%s", "Type mismatched for return");
            printf("Error type %d at Line %d: %s\n", 8, child2->line, semanticErrorMsg);
        }
    } else {
        Node* child3 = getChild(node, 2);
        Type cond = Exp(child3);
        if (!(cond && cond->kind == BASIC && cond->u.basic == BASIC_INT)) {
            // ERROR7
            // printf("Error type %d at Line %d: %s\n", 7, child3->line, "Type mismatched for operands");
            sprintf(semanticErrorMsg, "%s", "Type mismatched for operands");
            printf("Error type %d at Line %d: %s\n", 7, child3->line, semanticErrorMsg);
        }
        Node* child5 = getChild(node, 4);
        Node* child7 = getChild(node, 6);
        Stmt(child5, type); // TODO: type还是NULL(if中可能有return？)
        if(child7) {
            Stmt(child7, type); // TODO: type还是NULL(if中可能有return？)
        }
    }
    return;
}

// DefList -> Def DefList
// | Empty
FieldList DefList(Node* node, Context context) {
    Node* child1 = getChild(node, 0);
    FieldList field = NULL;
    if(child1) {
        Node* child2 = getChild(node, 1);
        field = Def(child1, context); // TODO: field是否可能为NULL
        if(field) {
            FieldList tmp = field;
            while(tmp->tail) {
                tmp = tmp->tail;
            }
            tmp->tail = DefList(child2, context);
        } else {
            field = DefList(child2, context);
        }
    }
    return field;
}

// Def -> Specifier DecList SEMI
FieldList Def(Node* node, Context context) {
    Node* child1 = getChild(node, 0);
    Node* child2 = getChild(node, 1);
    Type type = Specifier(child1);
    FieldList field = DecList(child2, type, context);
    return field;
}

// DecList -> Dec
// | Dec COMMA DecList
FieldList DecList(Node* node, Type type, Context context) {
    Node* child1 = getChild(node, 0);
    Node* child3 = getChild(node, 2);
    FieldList field = Dec(child1, type, context); // TODO: field是否可能为NULL
    if(child3) {
        if(field) {
            field->tail = DecList(child3, type, context);
        } else {
            field = DecList(child3, type, context);
        }
    }
    return field;
}

// Dec -> VarDec
// | VarDec ASSIGNOP Exp
FieldList Dec(Node* node, Type type, Context context) {
    Node* child1 = getChild(node, 0);
    Node* child3 = getChild(node, 2);
    FieldList vardec = VarDec(child1, type, context);
    FieldList field = (FieldList)malloc(sizeof(struct FieldList_));
    field->name = vardec->name; // TODO: 能否这样赋值?
    FieldList tmp = vardec;
    while(tmp->tail) {
        tmp = tmp->tail;
    }
    field->type = tmp->type; // TODO: 如何赋值？
    field->tail = NULL;
    if(child3) {
        if(context == CONTEXT_STRUCT) {
            // ERROR15
            // printf("Error type %d at Line %d: %s\n", 15, child1->line, strcat(strcat("Redefined field \"", field->name), "\""));
            sprintf(semanticErrorMsg, "%s%s%s", "Illegal initialization \"", field->name, "\"");
            printf("Error type %d at Line %d: %s\n", 15, child1->line, semanticErrorMsg);
        }
        Type exp = Exp(child3);
        if(!isSameType(field->type, exp)) {
            // ERROR5
            // printf("Error type %d at Line %d: %s\n", 5, child3->line, "Type mismatched for assignment");
            sprintf(semanticErrorMsg, "%s", "Type mismatched for assignment");
            printf("Error type %d at Line %d: %s\n", 5, child3->line, semanticErrorMsg);
        }
    }
    return field;
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
Type Exp(Node* node) {
    Node* child1 = getChild(node, 0);
    Node* child3 = getChild(node, 2);
    Type type = NULL;
    if(!strcmp(child1->name, "Exp")) {
        Node* child2 = getChild(node, 1);
        if(!strcmp(child2->name, "ASSIGNOP")) {
            Node* subChild1 = getChild(child1, 0);
            Node* subChild2 = getChild(child1, 1);
            if(!((!strcmp(subChild1->name, "ID") && !subChild2) || (subChild2 && (!strcmp(subChild2->name, "LB") || !strcmp(subChild2->name, "DOT"))))) {
                // ERROR6
                // printf("Error type %d at Line %d: %s\n", 6, child1->line, "The left-hand side of an assignment must be a variable");
                sprintf(semanticErrorMsg, "%s", "The left-hand side of an assignment must be a variable");
                printf("Error type %d at Line %d: %s\n", 6, child1->line, semanticErrorMsg);
                // TODO: 返回的type是啥?
            }
            Type ltype = Exp(child1);
            Type rtype = Exp(child3);
            if(!isSameType(ltype, rtype)) {
                // ERROR5
                // printf("Error type %d at Line %d: %s\n", 5, child3->line, "Type mismatched for assignment");
                sprintf(semanticErrorMsg, "%s", "Type mismatched for assignment");
                printf("Error type %d at Line %d: %s\n", 5, child3->line, semanticErrorMsg);
            }
            type = ltype; // 如何赋值？
        } else if(!strcmp(child2->name, "AND") || !strcmp(child2->name, "OR")) {
            Type ltype = Exp(child1);
            Type rtype = Exp(child3);
            if(!(isSameType(ltype, rtype) && ltype && ltype->kind == BASIC && ltype->u.basic == BASIC_INT)) {
                // ERROR7
                // printf("Error type %d at Line %d: %s\n", 7, child3->line, "Type mismatched for operands");
                sprintf(semanticErrorMsg, "%s", "Type mismatched for operands");
                printf("Error type %d at Line %d: %s\n", 7, child3->line, semanticErrorMsg);
                type = (Type)malloc(sizeof(struct Type_)); // TODO: 如何赋值?
                type->kind = BASIC;
                type->u.basic = BASIC_INT; // 也可能是BASIC_FLOAT，故有可能引发后续错误
            } else {
                type = ltype; // 如何赋值？
            }
        } else if(!strcmp(child2->name, "RELOP") || !strcmp(child2->name, "PLUS") || !strcmp(child2->name, "MINUS") || !strcmp(child2->name, "STAR") || !strcmp(child2->name, "DIV")) {
            Type ltype = Exp(child1);
            Type rtype = Exp(child3);
            if(!(isSameType(ltype, rtype) && ltype && ltype->kind == BASIC)) {
                // ERROR7
                // printf("Error type %d at Line %d: %s\n", 7, child3->line, "Type mismatched for operands");
                sprintf(semanticErrorMsg, "%s", "Type mismatched for operands");
                printf("Error type %d at Line %d: %s\n", 7, child3->line, semanticErrorMsg);
                type = (Type)malloc(sizeof(struct Type_)); // TODO: 如何赋值?
                type->kind = BASIC;
                type->u.basic = BASIC_INT; // 也可能是BASIC_FLOAT，故有可能引发后续错误
            } else if(!strcmp(child2->name, "RELOP") && isSameType(ltype, rtype) && ltype && ltype->kind == BASIC && ltype->u.basic == BASIC_FLOAT) {
                type = (Type)malloc(sizeof(struct Type_)); // TODO: 如何赋值?
                type->kind = BASIC;
                type->u.basic = BASIC_INT; // 也可能是BASIC_FLOAT，故有可能引发后续错误
            } else {
                type = ltype; // 如何赋值？
            }
        } else if(!strcmp(child2->name, "LB")) {
            Type type1 = Exp(child1);
            Type type2 = Exp(child3);
            if(!(type1 && type1->kind == ARRAY)) {
                // ERROR10
                // printf("Error type %d at Line %d: %s\n", 10, child1->line, strcat("\"", strcat(getExpContent(child1), "\" is not an array")));
                sprintf(semanticErrorMsg, "%s%s%s", "\"", getExpContent(child1), "\" is not an array");
                printf("Error type %d at Line %d: %s\n", 10, child1->line, semanticErrorMsg);
                type = type1; // TODO: 如何赋值?
            } else {
                if(!(type2 && type2->kind == BASIC && type2->u.basic == BASIC_INT)) {
                // ERROR12
                // printf("Error type %d at Line %d: %s\n", 12, child3->line, strcat("\"", strcat(getExpContent(child3), "\" is not an integer")));
                sprintf(semanticErrorMsg, "%s%s%s", "\"", 
                getExpContent(child3), "\" is not an integer");
                printf("Error type %d at Line %d: %s\n", 12, child3->line, semanticErrorMsg);
                }
                type = type1->u.array.elem; // TODO: 如何赋值?
            }
        } else {
            Type type1 = Exp(child1);
            type = type1; // TODO: 如何赋值?
            if(!(type1 && type1->kind == STRUCTURE)) {
                // ERROR13
                // printf("Error type %d at Line %d: %s\n", 13, child1->line, "Illegal use of \".\"");
                sprintf(semanticErrorMsg, "%s", "Illegal use of \".\"");
                printf("Error type %d at Line %d: %s\n", 13, child1->line, semanticErrorMsg);
            } else {
                FieldList field = type1->u.structure.field;
                int hasField = 0;
                while(field) {
                    if(!strcmp(field->name, child3->val.val_content)) {
                        hasField = 1;
                        break;
                    }
                    field = field->tail;
                }
                if(!hasField) {
                    // ERROR14
                    // printf("Error type %d at Line %d: %s\n", 13, child3->line, strcat(strcat("Non-existent field \"", child3->val.val_content), "\""));
                    sprintf(semanticErrorMsg, "%s%s%s", "Non-existent field \"", child3->val.val_content, "\"");
                    printf("Error type %d at Line %d: %s\n", 14, child3->line, semanticErrorMsg);
                    type = NULL;
                } else {
                    type = field->type; // TODO: 如何赋值?
                }
            }
        }
    } else if(!strcmp(child1->name, "LP")) {
        Node* child2 = getChild(node, 1);
        type = Exp(child2);
    } else if(!strcmp(child1->name, "MINUS")) {
        Node* child2 = getChild(node, 1);
        type = Exp(child2);
        if(!(type && type->kind == BASIC)) {
            // ERROR7
            // printf("Error type %d at Line %d: %s\n", 7, child2->line, "Type mismatched for operands");
            sprintf(semanticErrorMsg, "%s", "Type mismatched for operands");
            printf("Error type %d at Line %d: %s\n", 7, child2->line, semanticErrorMsg);
            type = (Type)malloc(sizeof(struct Type_));
            type->kind = BASIC;
            type->u.basic = BASIC_INT; // 也可能需要BASIC_FLOAT，故有可能引发后续错误
        }
    } else if(!strcmp(child1->name, "NOT")) {
        Node* child2 = getChild(node, 1);
        type = Exp(child2);
        if(!(type && type->kind == BASIC && type->u.basic == BASIC_INT)) {
            // ERROR7
            // printf("Error type %d at Line %d: %s\n", 7, child2->line, "Type mismatched for operands");
            sprintf(semanticErrorMsg, "%s", "Type mismatched for operands");
            printf("Error type %d at Line %d: %s\n", 7, child2->line, semanticErrorMsg);
            type = (Type)malloc(sizeof(struct Type_));
            type->kind = BASIC;
            type->u.basic = BASIC_INT; // 也可能需要BASIC_FLOAT，故有可能引发后续错误
        }
    } else if(!strcmp(child1->name, "ID")) {
        if(!child3) {
            SymbolNode symbol = searchSymbolTable(child1->val.val_content, scopeDepth, BASIC); // 也有可能是ARRAY、STRUCTURE，但不影响结果
            if(!symbol || symbol->type->kind == STRUCTTAG) {
                // ERROR1
                //printf("Error type %d at Line %d: %s\n", 1, child1->line, strcat(strcat("Undefined variable \"", child1->val.val_content), "\""));
                sprintf(semanticErrorMsg, "%s%s%s", "Undefined variable \"", child1->val.val_content, "\"");
                printf("Error type %d at Line %d: %s\n", 1, child1->line, semanticErrorMsg);
                type = NULL;
            } else {
                type = symbol->type; // TODO: 如何赋值?
            }
        } else {
            SymbolNode symbol = searchSymbolTable(child1->val.val_content, scopeDepth, FUNCTION);
            if(!symbol) {
                symbol = searchSymbolTable(child1->val.val_content, scopeDepth, BASIC); // 也可以用ARRAY、STRUCTURE，但不影响结果
                if(symbol && symbol->type->kind != STRUCTTAG) {
                    // ERROR11
                    // printf("Error type %d at Line %d: %s\n", 11, child1->line, strcat("\"", strcat(child1->val.val_content, "\" is not a function")));
                    sprintf(semanticErrorMsg, "%s%s%s", "\"", child1->val.val_content, "\" is not a function");
                    printf("Error type %d at Line %d: %s\n", 11, child1->line, semanticErrorMsg);
                    type = symbol->type; // TODO: 如何赋值?
                } else {
                    // ERROR2
                    // printf("Error type %d at Line %d: %s\n", 2, child1->line, strcat(strcat("Undefined function \"", child1->val.val_content), "\""));
                    sprintf(semanticErrorMsg, "%s%s%s", "Undefined function \"", child1->val.val_content, "\"");
                    printf("Error type %d at Line %d: %s\n", 2, child1->line, semanticErrorMsg);
                    type = NULL;
                }                
            } else {
                FieldList param = NULL;
                if(!strcmp(child3->name, "Args")) {
                    param = Args(child3);
                }
                if(!isSameParam(symbol->type->u.function.param, param)) {
                    // ERROR9
                    Node* child2 = getChild(node, 1);
                    // printf("Error type %d at Line %d: %s\n", 9, child2->line, strcat(strcat("Wrong arguments for function \"", child1->val.val_content), "\""));
                    sprintf(semanticErrorMsg, "%s%s%s", "Wrong arguments for function \"", child1->val.val_content, "\"");
                    printf("Error type %d at Line %d: %s\n", 9, child2->line, semanticErrorMsg);
                }
                type = symbol->type->u.function.ret; // TODO: 如何赋值?
            }
        }
    } else {
        type = (Type)malloc(sizeof(struct Type_));
        type->kind = BASIC;
        if(!strcmp(child1->name, "INT")) {
            type->u.basic = BASIC_INT;
        } else {
            type->u.basic = BASIC_FLOAT;
        }
    }
    return type;
}

// Args -> Exp COMMA Args
// | Exp
FieldList Args(Node* node) {
    Node* child1 = getChild(node, 0);
    Node* child3 = getChild(node, 2);
    FieldList field = (FieldList)malloc(sizeof(struct FieldList_));
    field->name = NULL;
    field->type = Exp(child1);
    if(child3) {
        field->tail = Args(child3);
    } else {
        field->tail = NULL;
    }
    return field;
}
