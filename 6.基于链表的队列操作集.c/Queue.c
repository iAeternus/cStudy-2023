#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

//初始化队列
void CreateQueue(LinkQueue* LQ)
{
    LinkQueueNode* pHead = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    assert(pHead);
    LQ->front = LQ->rear = pHead; //队头和队尾指向头结点
    LQ->front->Next = NULL;
}

//判断队列是否为空
bool IsEmpty(LinkQueue* LQ)
{
    return LQ->front->Next == NULL;
}

//入队操作
void EnterLinkQueue(LinkQueue* LQ, ElementType item)
{
    LinkQueueNode* pNewNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    assert(pNewNode);
    pNewNode->Data = item;//将数据元素赋值给结点的数据域
    pNewNode->Next = NULL;//将结点的指针域置空
    LQ->rear->Next = pNewNode;//将原来队列的队尾指针指向新结点
    LQ->rear = pNewNode;//将队尾指针指向新结点
}

//出队操作
void DeleteLinkQueue(LinkQueue* LQ, ElementType* item)
{
    if (IsEmpty(LQ))
    {
        printf("队列空！");
        return;
    }
    //pDel指向队头元素，由于队头指针front指向头结点，所以pDel指向头结点的下一个结点
    LinkQueueNode* pDel = LQ->front->Next;
    *item = pDel->Data;//将要出队的元素赋给data
    LQ->front->Next = pDel->Next;//使指向头结点的指针指向pDel的下一个结点
    //如果队列中只有一个元素,将队列置空
    if (LQ->rear == pDel)
    {
        LQ->rear = LQ->front;
    }
    free(pDel);//释放pDel指向的空间
}

//取队头元素
ElementType GetHead(LinkQueue* LQ, ElementType* item)
{
    if (IsEmpty(LQ))
    {
        printf("队列空！");
        return 0;
    }
    LinkQueueNode* pCur = LQ->front->Next;//pCur指向队列的第一个元素，即头结点的下一个结点
    *item = pCur->Data;//将队头元素值赋给item
    return *item;//返回队头元素值
}

//清空队列
void ClearQueue(LinkQueue* LQ)
{
    while (LQ->front->Next != NULL)
    {
        LQ->rear = LQ->front->Next;//队尾指针指向队头指针的下一个结点
        free(LQ->front);//释放队头指针指向的结点
        LQ->front = LQ->rear;//队头指针指向队尾指针
    }
}

//打印队列中的元素
void PrintLinkQueue(LinkQueue* LQ)
{
    assert(LQ);
    LinkQueueNode* pCur;
    pCur = LQ->front->Next;
    while (pCur)
    {
        printf("%-3d", pCur->Data);
        pCur = pCur->Next;
    }
    printf("\n");
}