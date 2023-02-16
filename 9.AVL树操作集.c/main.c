#define _CRT_SECURE_NO_WARNINGS
#include "AVLTREE.h"

int main()
{
	AVLTree T = NULL;
	Position P;

	//插入1 ~ 30
	for (int i = 1; i <= 30; i++)
	{
		T = Insert(T, i);
	}
	PrintTree(T);
	printf("\n");

	P = FindMin(T);
	printf("\n最小元为：%d\n", P->Data);
	P = FindMax(T);
	printf("\n最大元为：%d\n", P->Data);

	printf("--------------------------------------------------------------------------------");

	//删除其中的18
	printf("\n删除其中的18\n\n");
	T = Delete(T, 18);
	PrintTree(T);
	printf("\n\n");

	//查找18
	P = Find(T, 18);

	//清空AVL树
	MakeEmpty(T);
	if (T != P)
	{
		printf("\n清空完毕！\n");
	}

	system("pause");
	return 0;
}