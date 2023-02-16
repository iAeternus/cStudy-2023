#include "LinkNode.h"

//��ʼ������
MyLinkedList* myLinkedListCreate() 
{
    MyLinkedList* head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    assert(head);

    head->next = NULL;
    return head;
}

//��ȡ�����е� index ���ڵ��ֵ�����������Ч���򷵻�-1��
int myLinkedListGet(MyLinkedList* obj, int index)
{
    MyLinkedList* cur = obj->next;
    for (int i = 0; cur != NULL; i++)
    {
        if (i == index)
        {
            return cur->val;
        }
        else
        {
            cur = cur->next;
        }
    }
    return -1;
}

//������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ㡣
void myLinkedListAddAtHead(MyLinkedList* obj, int val) 
{
    MyLinkedList* nHead = (MyLinkedList*)malloc(sizeof(MyLinkedList));//�����½ڵ�
    assert(nHead);

    nHead->val = val;//�����½ڵ㣬�� obj��ͷ��㣩��ԭ��һ���ڵ�֮����� nHead
    nHead->next = obj->next;
    obj->next = nHead;
}

//��ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
void myLinkedListAddAtTail(MyLinkedList* obj, int val) 
{
    MyLinkedList* cur = obj;
    while (cur->next != NULL)
    {
        cur = cur->next;//�ҵ����һ���ڵ�
    }

    MyLinkedList* nTail = (MyLinkedList*)malloc(sizeof(MyLinkedList));//�����½ڵ�
    assert(nTail);

    nTail->val = val;//�����½ڵ�
    nTail->next = NULL;

    cur->next = nTail;//�����½ڵ�
}

//�������еĵ� index ���ڵ�֮ǰ���ֵΪ val  �Ľڵ㡣
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
    if (0 == index)//��ͷ��㵥������
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    MyLinkedList* cur = obj->next;
    for (int i = 1; cur != NULL; i++)//������ͷ���
    {
        if (i == index)
        {
            MyLinkedList* nNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
            assert(nNode);
            //�����½ڵ�
            nNode->val = val;
            //���ӽڵ� (Ҫ�ڵ� index �����֮ǰ����ڵ㣬�ͱ���֪���� index ���ڵ�֮ǰһ���ڵ㣬�� cur->next)
            nNode->next = cur->next;
            cur->next = nNode;

            return;
        }
        else
        {
            cur = cur->next;
        }
    }

}

//������� index ��Ч����ɾ�������еĵ� index ���ڵ㡣
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) 
{
    if (0 == index)//��ͷ��㵥������
    {
        MyLinkedList* temp = obj->next;
        if (temp)
        {
            obj->next = temp->next;
            free(temp);
        }
        return;
    }
    MyLinkedList* cur = obj->next;
    for (int i = 1; cur != NULL && cur->next != NULL; i++)//������ͷ���
    {
        if (i == index)
        {
            MyLinkedList* temp = cur->next;
            if (temp)
            {
                cur->next = temp->next;
                free(temp);
            }
            return;
        }
        else
        {
            cur = cur->next;
        }
    }
}

//��������
void myLinkedListFree(MyLinkedList* obj) 
{
    while (obj)
    {
        MyLinkedList* temp = obj;
        obj = obj->next;
        free(temp);
    }
}