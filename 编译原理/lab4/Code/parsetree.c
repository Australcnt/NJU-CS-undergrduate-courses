#include "parsetree.h"

int hasError = 0;
Node* root = NULL;
int missLine = 0;
int lastErrorLine = 0;

Node* createNode(char* name, int line, SymbolType type, char* val) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->name = name;
    p->line = line;
    p->type = type;
    //if(type != NON_TERMINAL && type != NON_TERMINAL_NULL) printf("++++++++++++++++++++++++ val: %s, type: %d, ", val, type);
    switch(type) {
        case TOKEN_TYPE:  strcpy(p->val.val_content, val); 
        //printf("%s: %s\n", p->name, p->val.val_content);             
        break;
        case TOKEN_FLOAT: sscanf(val, "%f", &p->val.val_float);
        //printf("%s: %f\n", p->name, p->val.val_float);  
        break;
        case TOKEN_OCT:   sscanf(val, "%o", &p->val.val_int); 
        //printf("%s: %d\n", p->name, p->val.val_int);   
        break;
        case TOKEN_HEX:   sscanf(val, "%x", &p->val.val_int); 
        //printf("%s: %d\n", p->name, p->val.val_int);   
        break;
        case TOKEN_INT:   sscanf(val, "%u", &p->val.val_int); 
        //printf("%s: %d\n", p->name, p->val.val_int);   
        break;
        case TOKEN_ID:    strcpy(p->val.val_content, val);
        //printf("%s: %s\n", p->name, p->val.val_content);             
        break;
        case TOKEN_OTHER: strcpy(p->val.val_content, val);
        //printf("%s: %s\n", p->name, p->val.val_content);             
        break;
        default: break;
    }
    p->firstChild = NULL;
    p->nextSibling = NULL;
    return p;
}

void addChild(Node* parent, int childNum, ...) {
    va_list childList;
    va_start(childList, childNum);
    Node* tmp = (Node*)va_arg(childList, Node*);
    /*switch(tmp->type) {
            case TOKEN_TYPE:   printf("-----------------------------------------------------------------%s: %s\n", tmp->name, tmp->val.val_content); break;
            case TOKEN_FLOAT:  printf("-----------------------------------------------------------------%s: %f\n", tmp->name, tmp->val.val_float);   break;
            case TOKEN_OCT:    printf("-----------------------------------------------------------------%s: %d\n", tmp->name, tmp->val.val_int);     break;
            case TOKEN_HEX:    printf("-----------------------------------------------------------------%s: %d\n", tmp->name, tmp->val.val_int);     break;
            case TOKEN_INT:    printf("-----------------------------------------------------------------%s: %d\n", tmp->name, tmp->val.val_int);     break;
            case TOKEN_ID:     printf("-----------------------------------------------------------------%s: %s\n", tmp->name, tmp->val.val_content); break;
            case TOKEN_OTHER:  printf("-----------------------------------------------------------------%s\n", tmp->name);                           break;
            case NON_TERMINAL: printf("-----------------------------------------------------------------%s\n", tmp->name);                           break;
            default: break;
    }*/
    parent->firstChild = tmp;
    for(int i = 0; i < childNum - 1; i++) {
        tmp->nextSibling = (Node*)va_arg(childList, Node*);
        tmp = tmp->nextSibling;
        /*switch(tmp->type) {
            case TOKEN_TYPE:   printf("-----------------------------------------------------------------%s: %s\n", tmp->name, tmp->val.val_content); break;
            case TOKEN_FLOAT:  printf("-----------------------------------------------------------------%s: %f\n", tmp->name, tmp->val.val_float);   break;
            case TOKEN_OCT:    printf("-----------------------------------------------------------------%s: %d\n", tmp->name, tmp->val.val_int);     break;
            case TOKEN_HEX:    printf("-----------------------------------------------------------------%s: %d\n", tmp->name, tmp->val.val_int);     break;
            case TOKEN_INT:    printf("-----------------------------------------------------------------%s: %d\n", tmp->name, tmp->val.val_int);     break;
            case TOKEN_ID:     printf("-----------------------------------------------------------------%s: %s\n", tmp->name, tmp->val.val_content); break;
            case TOKEN_OTHER:  printf("-----------------------------------------------------------------%s\n", tmp->name);                           break;
            case NON_TERMINAL: printf("-----------------------------------------------------------------%s\n", tmp->name);                           break;
            default: break;
        }*/
    }
    va_end(childList);
}

Node* getChild(Node* parent, int idx) {
    Node* child = parent->firstChild;
    for(int i = 0; i< idx; i++) {
        if(child == NULL) {
            break;
        }
        child = child->nextSibling;
    }
    return child;
}

void printAST(Node* cur, int depth) {
    if(cur->type != NON_TERMINAL_NULL) {
        for(int i = 0; i < depth; i++) {
            printf("  ");
        }
        switch(cur->type) {
            case TOKEN_TYPE:  printf("%s: %s\n", cur->name, cur->val.val_content); break;
            case TOKEN_FLOAT: printf("%s: %f\n", cur->name, cur->val.val_float);   break;
            case TOKEN_OCT:   printf("%s: %d\n", cur->name, cur->val.val_int);     break;
            case TOKEN_HEX:   printf("%s: %d\n", cur->name, cur->val.val_int);     break;
            case TOKEN_INT:   printf("%s: %d\n", cur->name, cur->val.val_int);     break;
            case TOKEN_ID:    printf("%s: %s\n", cur->name, cur->val.val_content); break;
            case TOKEN_OTHER: printf("%s\n", cur->name);                           break;
            case NON_TERMINAL:   printf("%s (%d)\n", cur->name, cur->line);        break;
            default: break;
        }
        if(cur->firstChild) {
            printAST(cur->firstChild, depth + 1);
        }
    }
    if(cur->nextSibling) {
        printAST(cur->nextSibling, depth);
    }
}
