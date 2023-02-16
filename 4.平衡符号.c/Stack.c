#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

//ջ�ĳ�ʼ������ջ�ĳ�ʼ�����ǹ���һ����ջ����ջ��ָ��top��ָͷ����ָ������ΪNULL����Ϊ��ʱջ�л�û������Ԫ��
LinkedStack CreateStack()
{
	LinkedStack Top = (LinkedStackNode*)malloc(sizeof(LinkedStackNode));
	if (Top != NULL)
	{
		Top->Next = NULL;
	}
	return Top;
}

//�ж�ջ�Ƿ�Ϊ�գ�����ջtopΪ�գ��򷵻�TRUE����1�������򷵻�FALSE����0��
bool IsEmpty(LinkedStack Top)
{
	return Top->Next == NULL;
}

//��ջ��������Ԫ��x������ջ��ջ��������ͷ����ָ����ָ���²����ջ��Ԫ��
void Push(LinkedStack Top, ElementType item)
{
	LinkedStackNode* node = (LinkedStackNode*)malloc(sizeof(LinkedStackNode));
	assert(node);

	node->Data = item;
	node->Next = Top->Next;
	Top->Next = node;
}

//��ջ��ɾ��ջ������Ԫ�أ���ͨ��item������ɾ�����ݵ�ֵ
void Pop(LinkedStack Top, ElementType* item)
{
	LinkedStackNode* temp;
	assert(Top->Next);

	temp = Top->Next;
	*item = temp->Data;
	Top->Next = temp->Next;
	free(temp);
}

//ȡջ������Ԫ�أ���ȡջ��Ԫ�أ���������ֵ�����������ջ�����������ջ��Ԫ�ز���ɾ�������Բ����޸�ͷ����ָ����
ElementType GetTop(LinkedStack Top)
{
	assert(Top->Next);
	return Top->Next->Data;
}