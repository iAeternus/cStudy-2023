#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

//��������ʼ����ջ
Stack CreateStack(int MaxSize)
{
	Stack S;
	if (MaxSize < MAXS)
	{
		printf("[Error] Stack size is too small.");//ע��������޸ģ�����ͬ��
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

//����һ����ջ
void MakeEmpty(Stack S)
{
	S->Top = EmptyTOS;
}

//�ж϶�ջS�ǲ�����
bool IsFull(Stack S)
{
	return S->Top == S->Capacity - 1; //ջ��ָ��ָ���ֵ�Ƿ�������������ֵ
}

//��ջ
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

//�ж϶�ջ�Ƿ�Ϊ��
bool IsEmpty(Stack S)
{
	return S->Top == EmptyTOS;//ջ��ָ��-1��Ϊ��
}

//��ջ
ElementType Pop(Stack S)
{
	if (!IsEmpty(S))
	{
		return S->Data[(S->Top)--];
	}
	printf("[Error] Empty stack.");
	return 0;
}

//�ͷſռ�
void DisposeStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Data);
		free(S);
	}
}
