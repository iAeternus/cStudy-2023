#include "LinkNode.h"

//初始化链表
MyLinkedList* myLinkedListCreate() 
{
    MyLinkedList* head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    assert(head);

    head->next = NULL;
    return head;
}

//获取链表中第 index 个节点的值。如果索引无效，则返回-1。
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

//在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
void myLinkedListAddAtHead(MyLinkedList* obj, int val) 
{
    MyLinkedList* nHead = (MyLinkedList*)malloc(sizeof(MyLinkedList));//定义新节点
    assert(nHead);

    nHead->val = val;//设置新节点，在 obj（头结点）与原第一个节点之间插入 nHead
    nHead->next = obj->next;
    obj->next = nHead;
}

//将值为 val 的节点追加到链表的最后一个元素。
void myLinkedListAddAtTail(MyLinkedList* obj, int val) 
{
    MyLinkedList* cur = obj;
    while (cur->next != NULL)
    {
        cur = cur->next;//找到最后一个节点
    }

    MyLinkedList* nTail = (MyLinkedList*)malloc(sizeof(MyLinkedList));//定义新节点
    assert(nTail);

    nTail->val = val;//设置新节点
    nTail->next = NULL;

    cur->next = nTail;//连接新节点
}

//在链表中的第 index 个节点之前添加值为 val  的节点。
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
    if (0 == index)//对头结点单独操作
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    MyLinkedList* cur = obj->next;
    for (int i = 1; cur != NULL; i++)//不包括头结点
    {
        if (i == index)
        {
            MyLinkedList* nNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
            assert(nNode);
            //设置新节点
            nNode->val = val;
            //链接节点 (要在第 index 个结点之前插入节点，就必须知道第 index 个节点之前一个节点，即 cur->next)
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

//如果索引 index 有效，则删除链表中的第 index 个节点。
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) 
{
    if (0 == index)//对头结点单独操作
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
    for (int i = 1; cur != NULL && cur->next != NULL; i++)//不包括头结点
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

//销毁链表
void myLinkedListFree(MyLinkedList* obj) 
{
    while (obj)
    {
        MyLinkedList* temp = obj;
        obj = obj->next;
        free(temp);
    }
}