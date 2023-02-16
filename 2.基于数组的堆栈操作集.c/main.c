#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

int main()
{
	Stack m;
	m = CreateStack(MAXS);
	printf("��ջ����Ϊ��%d\n", MAXS);
	int i = 1;
	while (!IsFull(m))
	{
		printf("��ջ��%2d ��ַΪ��%p\n", i, &m->Top);
		Push(m, i++);
	}

	if (IsFull(m))
	{
		printf("ջ����\n");
	}
	else
	{
		printf("ջδ��\n");
	}

	printf("---------------------------------\n");

	while (!IsEmpty(m))
	{
		printf("��ջ��%2d ��ַΪ��%p\n", Pop(m), &m->Top);
	}

	if (IsEmpty(m))
	{
		printf("ջ�ѿ�\n");
	}
	else
	{
		printf("ջδ��\n");
	}
	printf("\n");
	DisposeStack(m);

	system("pause");
	return 0;
}