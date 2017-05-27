#include <stdio.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#include "include/Tree.h"
#include "include/Stack.h"
#include "include/Queue.h"

#define true 1
#define false 0



typedef struct tree_node TreeNode;
typedef struct tree_node *Tree;
typedef struct queue_node QueueNode;
typedef struct queue Queue;


int main(void) {
	Tree t;

    printf("输入二叉树的前序遍历序列，用*代替空节点(例如：ABC***DE**F**)：\n");
    CreateTree(&t);

    printf("\n二叉树创建完毕，高度为%d，节点数为%d。", GetHeight(t), GetNodeNumber(t));

    printf("\n前序遍历：");
    PreShow(t);

    printf("\n中序遍历：");
    MidShow(t);

    printf("\n后序遍历：");
    BackShow(t);

    printf("\n层序遍历：");
    LevelShow(t);

    ClearTree(&t);
    if (IsTreeEmpty(t))
    {
        printf("\n二叉树已经删除。");
    }
    printf("\n*******************\n\n");

    STACK S ;
    int val;
    int i;

    init(&S);

    {
        push(&S,1);
        push(&S,2);
        push(&S,3);
        push(&S,4);
        push(&S,5);
        push(&S,6);
    }

    traverse(&S);

    pop(&S ,&val);
    
        printf("出栈成功，出栈元素为%d\n",val);
    
 
    traverse(&S);

    printf("销毁栈，");
    clear(&S);

    traverse(&S);


printf("\n*******************\n\n");
	QUEUE Q;

    initQ(&Q);

    {
        en_queue(&Q,1);
        en_queue(&Q,2);
        en_queue(&Q,3);
        en_queue(&Q,4);
        en_queue(&Q,5);
        en_queue(&Q,6);
        en_queue(&Q,7);
        en_queue(&Q,8);
    }

    traverse_queue(&Q);

    if(out_queue(&Q,&val))
    {
        printf("出队成功，队列出队元素为 : %d\n",val);
    }
    else
    {
        printf("出队失败！");
    }

    traverse_queue(&Q);


	return 0;
}
