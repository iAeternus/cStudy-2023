#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAXS 1024

typedef char ElementType;

//���ݽṹ
typedef struct LinkedStackNode
{
	ElementType Data;
	struct LinkedStackNode* Next;
}LinkedStackNode, *LinkedStack;

//ջ�ĳ�ʼ��
LinkedStack CreateStack();
//�ж�ջ�Ƿ�Ϊ��
bool IsEmpty(LinkedStack Top);
//��ջ
void Push(LinkedStack Top, ElementType item);
//��ջ
void Pop(LinkedStack Top, ElementType* item);
//ȡջ������Ԫ��
ElementType GetTop(LinkedStack Top);
/*��׺ת��׺����*/
void Change(LinkedStack Top, ElementType str[]);