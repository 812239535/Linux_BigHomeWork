#ifndef _TREE_H
#define _TREE_H
struct tree_node{
    char id;
    struct tree_node *left;
    struct tree_node *right;
};

struct queue_node{
    struct tree_node *treenode;
    struct queue_node *next;
};

struct queue{
    struct queue_node *front;
    struct queue_node *rear;
};

typedef struct tree_node TreeNode;
typedef struct tree_node *Tree;
typedef struct queue_node QueueNode;
typedef struct queue Queue;
void CreateTree(Tree *T);
int GetHeight(Tree T);
int MaxOfTwo(int a, int b);
int GetNodeNumber(Tree T);
void PreShow(Tree T);
void MidShow(Tree T);
void BackShow(Tree T);
void LevelShow(Tree T);
void InitQueue(Queue *q);
int IsQueueEmpty(Queue *q);
void InQueue(Queue *q, QueueNode * p);
void OutQueue(Queue *q, QueueNode **p);
void ClearTree(Tree *T);
int IsTreeEmpty(Tree T);

#endif //_TREE_H
