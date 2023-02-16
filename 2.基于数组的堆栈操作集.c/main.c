#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

int main()
{
	Stack m;
	m = CreateStack(MAXS);
	printf("¶ÑÕ»ÈÝÁ¿Îª£º%d\n", MAXS);
	int i = 1;
	while (!IsFull(m))
	{
		printf("ÈëÕ»£º%2d µØÖ·Îª£º%p\n", i, &m->Top);
		Push(m, i++);
	}

	if (IsFull(m))
	{
		printf("Õ»ÒÑÂú\n");
	}
	else
	{
		printf("Õ»Î´Âú\n");
	}

	printf("---------------------------------\n");

	while (!IsEmpty(m))
	{
		printf("³öÕ»£º%2d µØÖ·Îª£º%p\n", Pop(m), &m->Top);
	}

	if (IsEmpty(m))
	{
		printf("Õ»ÒÑ¿Õ\n");
	}
	else
	{
		printf("Õ»Î´¿Õ\n");
	}
	printf("\n");
	DisposeStack(m);

	system("pause");
	return 0;
}