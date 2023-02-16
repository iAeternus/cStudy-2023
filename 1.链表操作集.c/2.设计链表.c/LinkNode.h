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

//��ʼ������
MyLinkedList* myLinkedListCreate();
//��ȡ�����е� index ���ڵ��ֵ�����������Ч���򷵻�-1��
int myLinkedListGet(MyLinkedList* obj, int index);
//������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ㡣
void myLinkedListAddAtHead(MyLinkedList* obj, int val);
//��ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
void myLinkedListAddAtTail(MyLinkedList* obj, int val);
//�������еĵ� index ���ڵ�֮ǰ���ֵΪ val  �Ľڵ㡣
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);
//������� index ��Ч����ɾ�������еĵ� index ���ڵ㡣
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);
//��������
void myLinkedListFree(MyLinkedList* obj);