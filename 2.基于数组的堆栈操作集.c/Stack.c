#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

//创建并初始化堆栈
Stack CreateStack(int MaxSize)
{
	Stack S;
	if (MaxSize < MAXS)
	{
		printf("[Error] Stack size is too small.");//注意这里，可修改，下面同理
		return 0;
	}
	S = malloc(sizeof(struct SNode));
	assert(S);

	S->Data = malloc(sizeof(ElementType) * MaxSize);
	assert(S->Data);

	S->Capacity = MaxSize;
	MakeEmpty(S);

	return S;
}

//创建一个空栈
void MakeEmpty(Stack S)
{
	S->Top = EmptyTOS;
}

//判断堆栈S是不是满
bool IsFull(Stack S)
{
	return S->Top == S->Capacity - 1; //栈顶指针指向的值是否等于最大容量的值
}

//入栈
void Push(Stack S, ElementType item)
{
	if (IsFull(S))
	{
		printf("[Error] Full stack.");
	}
	else {
		S->Data[++(S->Top)] = item;
	}
}

//判断堆栈是否为空
bool IsEmpty(Stack S)
{
	return S->Top == EmptyTOS;//栈顶指向-1即为空
}

//出栈
ElementType Pop(Stack S)
{
	if (!IsEmpty(S))
	{
		return S->Data[(S->Top)--];
	}
	printf("[Error] Empty stack.");
	return 0;
}

//释放空间
void DisposeStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Data);
		free(S);
	}
}
