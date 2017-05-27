#include "include/Queue.h"


#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0


//循环队列的初始化
void initQ(QUEUE *pQ)
{
    pQ -> pBase = (int *)malloc(sizeof(int)*6);   //分配内存，数组长度为6

    pQ -> front = 0;
    pQ -> rear = 0;

    return;
}

//判断循环队列是否为满
int full_queue(QUEUE *pQ)
{
    if((pQ -> rear + 1) % 6 == pQ -> front)
    {
        return true;
    }
    else
        return false;
}

//入队操作
int en_queue(QUEUE *pQ , int val)
{
    if(full_queue(pQ))
    {
        return false;
    }
    else
    {
        pQ -> pBase[pQ -> rear] = val;
        pQ -> rear = (pQ -> rear + 1) % 6;

        return true;
    }
}

//遍历循环队列
void traverse_queue(QUEUE *pQ)
{
    int i = pQ -> front;

    printf("遍历队列：");
    while(i != pQ -> rear)
    {
        printf("%d\t", pQ -> pBase[i]);

        i = (i + 1) % 6 ;
    }

    printf("\n");

    return;
}

//判断循环队列是否为空
int empty_queue(QUEUE *pQ)
{
    if(pQ -> front == pQ -> rear)
    {
        return true;
    }
    else
        return false;
}

//循环队列的出队操作
int out_queue(QUEUE *pQ , int *pVal)
{
    if(empty_queue(pQ))
    {
        return false;
    }
    else
    {
        *pVal = pQ -> pBase[pQ -> front];
        pQ -> front = (pQ -> front + 1) % 6;

        return true;
    }
}

