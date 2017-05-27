#include "include/Stack.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define true 1
#define false 0

//栈的初始化
void init(PSTACK pS)
{
    pS -> pTop = (PNODE)malloc(sizeof(NODE));

    if(NULL == pS -> pTop)
    {
        printf("动态内存分配失败！");
        exit(-1);
    }
    else
    {
        pS -> pBottom = pS -> pTop;
        pS -> pTop -> pNext = NULL;
    }

    return ;
}

//插入元素到栈顶
void push(PSTACK pS , int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));

    pNew -> data = val;
    pNew -> pNext = pS -> pTop;
    pS -> pTop = pNew;

    return ;
}

//遍历栈S
void traverse(PSTACK pS)
{
    PNODE p = pS -> pTop;

    printf("栈内元素为：");
    while(p != pS -> pBottom)
    {
        printf("%d   ", p -> data);
        p = p -> pNext;
    }

    printf("\n");
    return ;
}

//判断栈是否为空
int empty(PSTACK pS)
{
    if(pS -> pTop == pS -> pBottom)
    {
        return true;
    }
    else
        return false;
}

//删除栈顶元素并将其值赋给*val
int pop(PSTACK pS , int *val)
{
    if(empty(pS))
    {
        return false;
    }
    else
    {
        PNODE r = pS -> pTop;
        *val = r -> data;
        pS -> pTop = r -> pNext;
        free(r);
        r = NULL;
    }
}

//清空栈S
void clear(PSTACK pS)
{
    if(empty(pS))
    {
        return;
    }
    else
    {
        PNODE p = pS -> pTop;
        PNODE q = NULL;

        while(p != pS -> pBottom)
        {
            q = p -> pNext;
            free(p);
            p = q ;
        }

        pS -> pTop = pS -> pBottom;

        return;
    }
}
