#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define EmptyTOS (-1)
#define MAXS (10)

typedef int ElementType, Position;
struct SNode
{
	ElementType* Data;/*存储元素的数组*/
	Position Top;/*栈顶指针*/
	int Capacity;/*堆栈最大容量*/
};
typedef struct SNode* Stack;

Stack CreateStack(int MaxSize);
void MakeEmpty(Stack S);
bool IsFull(Stack S);
void Push(Stack S, ElementType item);
bool IsEmpty(Stack S);
ElementType Pop(Stack S);
void DisposeStack(Stack S);
