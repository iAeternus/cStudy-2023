#define _CRT_SECURE_NO_WARNINGS
#include "AVLTREE.h"

int main()
{
	AVLTree T = NULL;
	Position P;

	//����1 ~ 30
	for (int i = 1; i <= 30; i++)
	{
		T = Insert(T, i);
	}
	PrintTree(T);
	printf("\n");

	P = FindMin(T);
	printf("\n��СԪΪ��%d\n", P->Data);
	P = FindMax(T);
	printf("\n���ԪΪ��%d\n", P->Data);

	printf("--------------------------------------------------------------------------------");

	//ɾ�����е�18
	printf("\nɾ�����е�18\n\n");
	T = Delete(T, 18);
	PrintTree(T);
	printf("\n\n");

	//����18
	P = Find(T, 18);

	//���AVL��
	MakeEmpty(T);
	if (T != P)
	{
		printf("\n�����ϣ�\n");
	}

	system("pause");
	return 0;
}