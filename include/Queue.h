#ifndef _QUEUE_H
#define _QUEUE_H


typedef struct Queue
{
    int *pBase;     //定义数组pBase
    int front;
    int rear;
}QUEUE;

void initQ(QUEUE *pQ);
int full_queue(QUEUE *pQ);
int en_queue(QUEUE *pQ , int val);
void traverse_queue(QUEUE *pQ);
int empty_queue(QUEUE *pQ);
int out_queue(QUEUE *pQ , int *pVal);

#endif //_QUEUE_H
