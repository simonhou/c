/*
* Copyright (c) 2012-~ simon.H
*
* The source code is released for free distribution under the terms of the GNU General Public License
*
*
* Author: Simon Hou
* Created Time: 2012.05.06
* File Name: SingleLinkedList.c
* Description:  实现单向链表的建立，包括头插法，和尾插法，以及一个链表反转非递归实现
* Input : abd##e##cf##g##
*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node,*LinkList;


void InitList(LinkList L)
{
    L = (Node*)malloc(sizeof(Node));
    if(L == NULL)
        printf("申请内存空间失败\n");
    L->next = NULL;

}
//创建链表，尾插法
LinkList ListCreateR()
{
    LinkList L;
    L = (Node*)malloc(sizeof(Node));
    L->next = NULL;
    Node *rNode = L; //rNode始终指向尾节点，开始时指向头节点
    ElemType x;

    while(scanf("%d",&x) != EOF)
    {
        Node *p;
        p = (Node*)malloc(sizeof(Node));  //申请新的节点
        p->data = x;
        rNode->next = p;
        rNode = p;
    }
    rNode->next = NULL;  //不要忘记尾结点要指向NULL
    return L;

}

//创建链表，头插法
LinkList ListCreateH()
{
   // InitList(L);
    Node *L;
    L = (Node*)malloc(sizeof(Node));
    L->next = NULL;

    ElemType x;

    while(scanf("%d", &x) != EOF)
    {
        Node *pNode;
        pNode = (Node*)malloc(sizeof(Node));
        pNode->data = x;
        pNode->next = L->next;
        L->next = pNode;
    }
    return L;
}

void printList(LinkList L)
{
    Node *temp;
    temp = L;
    while(temp != NULL)
    {
        printf("%6d", temp->data);
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////
// Reverse a list iteratively
// Input: L - the head of the original list
// Output: the head of the reversed head
///////////////////////////////////////////////////////////////////////
LinkList ListReverse(LinkList L)
{
    LinkList ReverseHead = NULL;  //新链表的头节点
    Node *pNode = L;
    Node *pPrev = NULL;
    while(pNode != NULL)   //遍历到尾节点时停止
    {
        Node *pNext = pNode->next; //（1）

        if(pNext == NULL)
            ReverseHead = pNode;
        pNode->next = pPrev;    //交换反转
        pPrev = pNode;          //(2)
        pNode = pNext;          //(3)
    }
    return ReverseHead;     //Return the new head

}

int main()
{
 //   LinkList L;
    LinkList LR;
    LinkList revL;
//    L = ListCreateH();
    LR = ListCreateR();
    printf("\nThe number of list is:\n");
    //printf("%d\n",L->next->data);
//    printList(L);
    printList(LR);
    printf("\nReverse list:\n");
    revL = ListReverse(LR);
    printList(revL);
    return 0;
}
