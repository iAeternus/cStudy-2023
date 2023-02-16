#pragma once
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int ElementType;

//链表数据结构
typedef struct Node
{
    ElementType Data;
    struct Node* Next;
}LinkQueueNode;

//队列数据结构
typedef struct
{
    LinkQueueNode* front;
    LinkQueueNode* rear;
}LinkQueue;

//初始化队列
void CreateQueue(LinkQueue* LQ);
//判断队列是否为空
bool IsEmpty(LinkQueue* LQ);
//入队操作
void EnterLinkQueue(LinkQueue* LQ, ElementType item);
//出队操作
void DeleteLinkQueue(LinkQueue* LQ, ElementType* item);
//取队头元素
ElementType GetHead(LinkQueue* LQ, ElementType* item);
//清空队列
void ClearQueue(LinkQueue* LQ);
//打印队列中的元素
void PrintLinkQueue(LinkQueue* LQ);