#ifndef _STACK_H
#define _STACK_H
typedef struct Node
{
    int data;
    struct Node *pNext;
}NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
}STACK, *PSTACK;

void init(PSTACK pS);
void push(PSTACK pS , int val);
void traverse(PSTACK pS);
int empty(PSTACK pS);
int pop(PSTACK pS , int *val);
void clear(PSTACK pS);

#endif //_STACK_H
