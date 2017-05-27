#include "include/Tree.h"
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

//创建二叉树
void CreateTree(Tree *T)
{
    char ch;

    scanf("%c", &ch);
    if (ch == '*')
    {
        *T = NULL;
    }
    else
    {
        *T = (Tree)malloc(sizeof(TreeNode));
        (*T)->id = ch;
        CreateTree(&(*T)->left);
        CreateTree(&(*T)->right);
    }
}

//获得二叉树的高度
int GetHeight(Tree T)
{
    if (T)
    {
        return MaxOfTwo(GetHeight(T->left), GetHeight(T->right)) + 1;
    }
    else
    {
        return 0;
    }
}

//两数较大值
int MaxOfTwo(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

//获得二叉树的节点数
int GetNodeNumber(Tree T)
{
    if (T)
    {
        return GetNodeNumber(T->left) + GetNodeNumber(T->right) + 1;
    }
    else
    {
        return 0;
    }
}

//前序遍历
void PreShow(Tree T)
{
    if (!T)
    {
        return;
    }

    printf("%c ", T->id);
    PreShow(T->left);
    PreShow(T->right);
}

//中序遍历
void MidShow(Tree T)
{
    if (!T)
    {
        return;
    }

    MidShow(T->left);
    printf("%c ", T->id);
    MidShow(T->right);
}

//后序遍历
void BackShow(Tree T)
{
    if (!T)
    {
        return;
    }

    BackShow(T->left);
    BackShow(T->right);
    printf("%c ", T->id);
}

//层序遍历
void LevelShow(Tree T)
{
    if (!T)
    {
        return;
    }

    Queue m_queue;
    Queue *Q;
    QueueNode *p, *q;

    Q = &m_queue;
    InitQueue(Q); //队列初始化

    p = (QueueNode *)malloc(sizeof(QueueNode));
    p->next = NULL;
    p->treenode = T;
    InQueue(Q, p); //根节点进队

    while (!IsQueueEmpty(Q))
    {
        OutQueue(Q, &q); //当前队首节点出队
        printf("%c ", q->treenode->id);

        if (q->treenode->left) //左孩子非空，则左孩子进队
        {
            p = (QueueNode *)malloc(sizeof(QueueNode));
            p->next = NULL;
            p->treenode = q->treenode->left;
            InQueue(Q, p);
        }
        if (q->treenode->right) //右孩子非空，则右孩子进队
        {
            p = (QueueNode *)malloc(sizeof(QueueNode));
            p->next = NULL;
            p->treenode = q->treenode->right;
            InQueue(Q, p);
        }
    }
}

//初始化队列
void InitQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

//队列是否为空
int IsQueueEmpty(Queue *q)
{
    if (q->front)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//进队
void InQueue(Queue *q, QueueNode * p)
{
    if (IsQueueEmpty(q))
    {
        q->front = p;
        q->rear = p;
    }
    else
    {
        q->rear->next = p;
        q->rear = p;
    }
}

//出队
void OutQueue(Queue *q, QueueNode **p)
{
    *p = q->front;

    if (q->front == q->rear) //只有1个节点
    {
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        q->front = q->front->next;
    }
}

//清除二叉树
void ClearTree(Tree *T)
{
    if (!*T)
    {
        return;
    }

    ClearTree(&(*T)->left);
    ClearTree(&(*T)->right);
    free(*T);
    *T = NULL;
}

//二叉树是否为空
int IsTreeEmpty(Tree T)
{
    if (T)
    {
        return false;
    }
    else
    {
        return true;
    }
}
