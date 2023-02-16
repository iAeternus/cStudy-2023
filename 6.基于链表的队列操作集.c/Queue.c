#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

//��ʼ������
void CreateQueue(LinkQueue* LQ)
{
    LinkQueueNode* pHead = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    assert(pHead);
    LQ->front = LQ->rear = pHead; //��ͷ�Ͷ�βָ��ͷ���
    LQ->front->Next = NULL;
}

//�ж϶����Ƿ�Ϊ��
bool IsEmpty(LinkQueue* LQ)
{
    return LQ->front->Next == NULL;
}

//��Ӳ���
void EnterLinkQueue(LinkQueue* LQ, ElementType item)
{
    LinkQueueNode* pNewNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    assert(pNewNode);
    pNewNode->Data = item;//������Ԫ�ظ�ֵ������������
    pNewNode->Next = NULL;//������ָ�����ÿ�
    LQ->rear->Next = pNewNode;//��ԭ�����еĶ�βָ��ָ���½��
    LQ->rear = pNewNode;//����βָ��ָ���½��
}

//���Ӳ���
void DeleteLinkQueue(LinkQueue* LQ, ElementType* item)
{
    if (IsEmpty(LQ))
    {
        printf("���пգ�");
        return;
    }
    //pDelָ���ͷԪ�أ����ڶ�ͷָ��frontָ��ͷ��㣬����pDelָ��ͷ������һ�����
    LinkQueueNode* pDel = LQ->front->Next;
    *item = pDel->Data;//��Ҫ���ӵ�Ԫ�ظ���data
    LQ->front->Next = pDel->Next;//ʹָ��ͷ����ָ��ָ��pDel����һ�����
    //���������ֻ��һ��Ԫ��,�������ÿ�
    if (LQ->rear == pDel)
    {
        LQ->rear = LQ->front;
    }
    free(pDel);//�ͷ�pDelָ��Ŀռ�
}

//ȡ��ͷԪ��
ElementType GetHead(LinkQueue* LQ, ElementType* item)
{
    if (IsEmpty(LQ))
    {
        printf("���пգ�");
        return 0;
    }
    LinkQueueNode* pCur = LQ->front->Next;//pCurָ����еĵ�һ��Ԫ�أ���ͷ������һ�����
    *item = pCur->Data;//����ͷԪ��ֵ����item
    return *item;//���ض�ͷԪ��ֵ
}

//��ն���
void ClearQueue(LinkQueue* LQ)
{
    while (LQ->front->Next != NULL)
    {
        LQ->rear = LQ->front->Next;//��βָ��ָ���ͷָ�����һ�����
        free(LQ->front);//�ͷŶ�ͷָ��ָ��Ľ��
        LQ->front = LQ->rear;//��ͷָ��ָ���βָ��
    }
}

//��ӡ�����е�Ԫ��
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