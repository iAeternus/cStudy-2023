#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef int ElementType;

//数据结构
typedef struct LinkedStackNode
{
	ElementType Data;
	struct LinkedStackNode* Next;
}LinkedStackNode, *LinkedStack;

//栈的初始化
LinkedStack CreateStack();
//判断栈是否为空
bool IsEmpty(LinkedStack Top);
//入栈
void Push(LinkedStack Top, ElementType item);
//出栈
void Pop(LinkedStack Top, ElementType* item);
//取栈顶数据元素
ElementType GetTop(LinkedStack Top);
