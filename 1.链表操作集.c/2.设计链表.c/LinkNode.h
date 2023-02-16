#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct LinkNode;
typedef struct LinkNode MyLinkedList;

struct LinkNode
{
    int val;
    MyLinkedList* next;
};

//初始化链表
MyLinkedList* myLinkedListCreate();
//获取链表中第 index 个节点的值。如果索引无效，则返回-1。
int myLinkedListGet(MyLinkedList* obj, int index);
//在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
void myLinkedListAddAtHead(MyLinkedList* obj, int val);
//将值为 val 的节点追加到链表的最后一个元素。
void myLinkedListAddAtTail(MyLinkedList* obj, int val);
//在链表中的第 index 个节点之前添加值为 val  的节点。
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);
//如果索引 index 有效，则删除链表中的第 index 个节点。
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);
//销毁链表
void myLinkedListFree(MyLinkedList* obj);