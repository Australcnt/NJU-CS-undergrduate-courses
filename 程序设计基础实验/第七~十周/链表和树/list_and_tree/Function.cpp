#include<iostream>
using namespace std;
#include"Function.h"

int m = 0;
int n = 0;
Node* list_head = NULL;
int list_tail_insert(Node* list_head, int var)
{
  Node* p = new Node;
  p->var = var;
  p->link = NULL;
  if(!list_head)
    return -1;
  else
  {
    while(list_head->link)
      list_head = list_head->link;
    list_head->link = p;
    return 0;
  }
} 

Node* list_head_insert(Node* list_head, int var)
{
  Node* p = new Node;
  p->var = var;
  if(!list_head)
  {
    p->link = NULL;
    list_head = p;
  }
  else
  {
    p->link = list_head;
    list_head = p;
  }
  return list_head;
}

Node* list_specific_insert(Node* list_head, int location, int var)
//if location is beyond length, put it at the end
{
  Node* p = new Node;
  p->var = var;
  if(location < 1)
  {
    cout << "The format is wrong" << endl;
    return list_head;
  }
  else if(location == 1)
  {
    p->link = list_head;
    list_head = p;
  }
  else if(location == 2)
  {
    p->link = list_head->link;
    list_head->link = p;
  }
  else
  {
    Node* fakehead = list_head;
    for(int i = 1; i < location - 1 && fakehead->link != NULL; i++)
      fakehead = fakehead->link;
    if(!fakehead->link)
    {
      fakehead->link = p;
      p->link = NULL;
    }
    else
    {
      p->link = fakehead->link;
      fakehead->link = p;
    }
  }
  return list_head;
}

void print_list(Node* list_head)
{
  if(!list_head)
    cout << ' ' << endl;
  else
  {
    while(list_head->link)
    {
      cout << list_head->var << ' ';
      list_head = list_head->link;
    }
    cout << list_head->var << endl;
  }
}

void reverse_print_list(Node* list_head)
{
  if(!list_head)
    cout << ' ' << endl;
  else if(!list_head->link)
    cout << list_head->var << ' ';
  else
  {
    m++;
    reverse_print_list(list_head->link);
    cout << list_head->var << ' ';
    m--;
  }
  if(m == 0)
    cout << endl;
}

void change_specific_var(Node* list_head, int old_var, int new_var)
{
  while(list_head)
  {
    if(list_head->var == old_var)
      list_head->var = new_var;
    list_head = list_head->link;
  }
}

Node* del_specific_var(Node* list_head, int del_var)
{
  if(!list_head)
    return list_head;
  else
  {
    while(list_head && list_head->var == del_var)
      list_head = list_head->link;
    Node* fakehead = list_head;
    while(fakehead && fakehead->link)
    {
      if(fakehead->link->var == del_var)
      {
        Node* cur = fakehead->link;
        fakehead->link = cur->link;
        delete(cur);
      }
      else
        fakehead = fakehead->link;
      if(!fakehead)
        break;
    }
    return list_head;
  }
}

Node* sort(Node* list_head)
{
  if(!list_head || !list_head->link)
    return list_head;
  else
  {
    Node* cur = list_head->link;
    list_head->link = NULL;
    while(cur)
    {
      Node* prev = cur;
      cur = cur->link;
      if(prev->var < list_head->var)
      {
        prev->link = list_head;
        list_head = prev;
      }
      else
      {
        Node* cur2 = list_head;
        Node* prev2 = list_head;
        while(cur2)
        {
          if(prev->var < cur2->var)
            break;
          prev2 = cur2;
          cur2 = cur2->link;
        }
        prev->link = prev2->link;
        prev2->link = prev;
      }
    }
    return list_head;
  }
}

Tree_Node* insert(Tree_Node* T, int x)
{
  if(!n)
  {
    if(!T)
      T = new Tree_Node;
    T->var = x;
    T->rchild = NULL;
    T->lchild = NULL;
    n++;
  }
  else
  {
    Tree_Node* T2 = T;
    while((x < T2->var && T2->lchild) || (x > T2->var && T2->rchild))
    {
      if(x < T2->var)
        T2 = T2->lchild;
      else
        T2 = T2->rchild;
    }
    Tree_Node* p = new Tree_Node;
    p->var = x;
    p->rchild = NULL;
    p->lchild = NULL;
    if(x < T2->var)
      T2->lchild = p;
    if(x > T2->var)
      T2->rchild = p;
  }
  return T;
}

void postorder(Tree_Node* T)
{
  while(T->lchild || T->rchild)
  {
    Tree_Node* T2 = T;
    while(T2->lchild || T2->rchild)
    {
      if(T2->lchild)
      {
        if(T2->lchild->lchild || T2->lchild->rchild)
          T2 = T2->lchild;
        else
        {
          cout << T2->lchild->var << ' ';
          Tree_Node* cur = T2->lchild;
          T2->lchild = NULL;
          delete(cur);
        }
      }
      else
      {
        if(T2->rchild->lchild || T2->rchild->rchild)
          T2 = T2->rchild;
        else
        {
          cout << T2->rchild->var << ' ';
          Tree_Node* cur = T2->rchild;
          T2->rchild = NULL;
          delete(cur);
        }
      }
    }
  }
  cout << T->var << endl;
}
