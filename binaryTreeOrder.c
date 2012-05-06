/*
 * Copyright (c) 2012-~ simon.H
 *
 * The source code is released for free distribution under the terms of the GNU General Public License
 *
 *
 * Author: Simon Hou
 * Created Time: 2012.05.06
 * File Name: binaryTreeOrder.c
 * Description: 使用先序扩展建立二叉树， 实现了二叉树的先序递归遍历,中序递归遍历,后序递归遍历，再利用队列 实现层序遍历
 * Input : abd##e##cf##g##
 */
#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;

typedef char TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct QueueNode{
    BiTree data;
    struct QueueNode *next;
}LinkQueueNode; //定义队列中每个节点

typedef struct
{
    LinkQueueNode *front;
    LinkQueueNode *rear;
}LinkQueue; // 定义队列

//队列初始化
void InitQueue(LinkQueue *Q)
{
    Q->front = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    if(Q->front != NULL)
    {
        Q->rear = Q->front;
        Q->front->next = NULL;
    }
    else
        printf("分配失败\n");

}

//入队操作
Status EnQueue(LinkQueue *Q, BiTree T)
{
    LinkQueueNode *newNode;
    newNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    if(newNode != NULL);
    {
        newNode->data = T;   //这里队列存储的是树的节点指针？
        newNode->next = NULL;
        Q->rear->next = newNode; //把拥有T->data元素的新节点newNode赋给原队尾节点的后继
        Q->rear = newNode;  //当前节点设置为队尾节点
    }
    return OK;
}

//出队操作
Status DeQueue(LinkQueue *Q, BiTree *T)
{
    LinkQueueNode *p;
    if(Q->front == Q->rear)
        return ERROR;
    p = Q->front->next;
    Q->front->next = p->next;
    if(Q->rear == p)  //p指针指向队尾的时候
        Q->rear = Q->front;
    *T = p->data;
    free(p);
}

//队列判断为空
Status QueueIsEmpty(LinkQueue *Q)
{
    if(Q->front == Q->rear)
        return OK;
    else
        return ERROR;
}

// 构造空二叉树
Status InitBiTree(BiTree *T)
{
	(*T) = NULL;
	return OK;
}

//销毁二叉树
void DestroyBiTree(BiTree *T)
{
	if(*T)
	{
		if((*T)->lchild)
			DestroyBiTree(&((*T)->lchild));
		if((*T)->rchild)
			DestroyBiTree(&((*T)->rchild));
		free(*T);
		(*T) = NULL;  //free之后记得置空是个好习惯
	}
}

//按先序次序输入二叉树中节点的值，构造二叉链表示的二叉树,'#'表示节点为空
BiTree* CreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf("%c",&ch);

	if(ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!(*T))          //构造失败
			exit(OVERFLOW);
		(*T)->data = ch; // 生成根节点
		CreateBiTree(&((*T)->lchild));//构造左子树
		CreateBiTree(&((*T)->rchild));//构造右子树
	}
	return(*T);
}
// 判断二叉树是否为空
Status BiTreeEmpty(BiTree T)
{
	if(T)
		return ERROR;
	else
		return OK;
}
//返回T的深度
int BiTreeDepth(BiTree T)
{
	int i,j;
	if(!T)
		return ERROR;
	if(T->lchild)
		i = BiTreeDepth(T->lchild);
	else
		i = 0;
	if(T->rchild)
		j = BiTreeDepth(T->rchild);
	else
		j = 0;
	return i > j? i+1:j+1;
}

// 前序遍历
void PreOrderPrint(BiTree T)
{
	if(T == NULL)
		return;
	printf("%c",T->data); // 显示节点数据，可以更改为其他对节点操作
	PreOrderPrint(T->lchild);//先序遍历左子树
	PreOrderPrint(T->rchild); //再先序遍历右子树

}
//  中序遍历
void InOrderPrint(BiTree T)
{
	if(T == NULL)
		return;
	InOrderPrint(T->lchild);//先序遍历左子树
	printf("%c",T->data); // 显示节点数据，可以更改为其他对节点操作
	InOrderPrint(T->rchild); //再先序遍历右子树

}
// 后序遍历
void PostOrderPrint(BiTree T)
{
	if(T == NULL)
		return;
	PostOrderPrint(T->lchild);//先序遍历左子树
	PostOrderPrint(T->rchild); //再先序遍历右子树
	printf("%c",T->data); //  最后显示节点数据，可以更改为其他对节点操作
}

//层次遍历，利用了队列的存储特性，
void LayerOrderPrint(BiTree T)
{
    BiTree *x;

    x = (BiTree*)malloc(sizeof(BiTree));
    if(NULL == x)
        printf("内存分配失败！\n");

    LinkQueue *Q;
    Q = (LinkQueue*)malloc(sizeof(LinkQueue));
    InitQueue(Q);
    EnQueue(Q,T);           //T入栈，先压入根节点
    while(!QueueIsEmpty(Q)) //非空，一直到全部弹出为止
    {
        DeQueue(Q,x);       //弹出压入的节点
        printf("%c",(*x)->data);
        if((*x)->lchild)    //同时判断有无左孩子节点，如果存在压入队列
            EnQueue(Q,(*x)->lchild);
        if((*x)->rchild)    //再判断有无右孩子节点，如果存在压入队列
            EnQueue(Q,(*x)->rchild);
    }
}
int main()
{
	BiTree T,P;
//	BiTree *t = &T;
    printf("Please In put the Post Order number:\n");
	P = CreateBiTree(&T);

	printf("\nPostOrderPrint:\n");
	PreOrderPrint(P);

	printf("\nInOrderPrint:\n");
	InOrderPrint(P);

	printf("\nPostOrderPrint:\n");
	PostOrderPrint(P);

	printf("\nLayerOrder:\n");
	LayerOrderPrint(T);

	return 0;

}
