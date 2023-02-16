#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

int main()
{
	LinkedStack L = CreateStack();

	int cnt = 0;
	ElementType data = 0;
	printf("请输入进栈元素总数：");
	if (scanf("%d", &cnt))
	{
		for (int i = 1; i <= cnt; i++)
		{
			printf("请输入第%d个元素：", i);
			if (scanf("%d", &data))
			{
				Push(L, data);
			}
		}

		ElementType item = 0;
		for (int j = 1; j <= cnt; j++)
		{
			Pop(L, &item);
			printf("%d出栈\n", item);
		}
	}
	
	return 0;
}