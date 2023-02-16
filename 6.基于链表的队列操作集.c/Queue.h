#pragma once
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int ElementType;

//�������ݽṹ
typedef struct Node
{
    ElementType Data;
    struct Node* Next;
}LinkQueueNode;

//�������ݽṹ
typedef struct
{
    LinkQueueNode* front;
    LinkQueueNode* rear;
}LinkQueue;

//��ʼ������
void CreateQueue(LinkQueue* LQ);
//�ж϶����Ƿ�Ϊ��
bool IsEmpty(LinkQueue* LQ);
//��Ӳ���
void EnterLinkQueue(LinkQueue* LQ, ElementType item);
//���Ӳ���
void DeleteLinkQueue(LinkQueue* LQ, ElementType* item);
//ȡ��ͷԪ��
ElementType GetHead(LinkQueue* LQ, ElementType* item);
//��ն���
void ClearQueue(LinkQueue* LQ);
//��ӡ�����е�Ԫ��
void PrintLinkQueue(LinkQueue* LQ);