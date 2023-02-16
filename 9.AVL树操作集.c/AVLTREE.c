#define _CRT_SECURE_NO_WARNINGS
#include "AVLTREE.h"

static int Height(Position P);
static int Max(int a, int b);
static Position SingleRotationWithLeft(Position K2);
static Position doubleRotationWithLeft(Position K3);
static Position SingleRotationWithRight(Position K2);
static Position doubleRotationWithRight(Position K3);

//����AVL�ڵ�ĸ߶�
static int Height(Position P)
{
	if (P == NULL)
	{
		return -1;
	}
	else
	{
		return P->Height;
	}
}

//���AVL��
void MakeEmpty(AVLTree T)
{
	if (T != NULL)//�ݹ���ֹ
    {
	    MakeEmpty(T->Left);
	    MakeEmpty(T->Right);
		free(T);
	}
}

//����
Position Find(AVLTree T, ElementType X)
{
	if (T == NULL)
	{
		printf("Element %d is not found!\n", X);
	}
	else if (X < T->Data)
	{
		return Find(T->Left, X);
	}
	else if (X > T->Data)
	{
		return Find(T->Right, X);
	}
	//��Ȼ�����ҵ��ˣ��������κβ���
	return T;
}

//�ݹ�ʵ�ֲ�����СԪλ��
Position FindMin(AVLTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	else if (T->Left == NULL)
	{
		return T;
	}
	else
	{
		return FindMin(T->Left);
	}
}

//�ǵݹ�ʵ�ֲ������Ԫλ��
Position FindMax(AVLTree T)
{
	if (T != NULL)
	{
		while (T->Right != NULL)
		{
			T = T->Right;
		}
	}
	return T;
}

//��������֮��Ľϴ�ֵ
static int Max(int a, int b)
{
	return (a > b ? a : b);
}

//����ת��LL��״̬��
static Position SingleRotationWithLeft(Position K2)
{
	Position K1;

	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), K2->Height) + 1;

	return K1;//�µĸ��ڵ�
}

//��˫��ת��LR��״̬��������������
static Position doubleRotationWithLeft(Position K3)
{
	K3->Left = SingleRotationWithRight(K3->Left);
	return SingleRotationWithLeft(K3);
}

//�ҵ���ת��RR��״̬��
static Position SingleRotationWithRight(Position K2)
{
	Position K1;

	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Right), K2->Height) + 1;

	return K1;//�µĸ��ڵ�
}

//��˫��ת��RL��״̬��������������
static Position doubleRotationWithRight(Position K3)
{
	K3->Right = SingleRotationWithLeft(K3->Right);
	return SingleRotationWithRight(K3);
}

//����
AVLTree Insert(AVLTree T, ElementType X)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct AVLNode));
		assert(T);

		T->Data = X;
		T->Height = 0;
		T->Left = T->Right = NULL;
	}
	else if (X < T->Data)
	{
		T->Left = Insert(T->Left, X);
		if (Height(T->Left) - Height(T->Right) == 2)
		{
			if (X < T->Left->Data)
			{
				T = SingleRotationWithLeft(T);
			}
			else
			{
				T = doubleRotationWithLeft(T);
			}
		}
	}
	else if (X > T->Data)
	{
		T->Right = Insert(T->Right, X);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (X > T->Right->Data)
			{
				T = SingleRotationWithRight(T);
			}
			else
			{
				T = doubleRotationWithRight(T);
			}
		}
	}
	/*else x �Ѿ������У�����ʲô������*/

	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

//ɾ��
AVLTree Delete(AVLTree T, ElementType X)
{
	Position TmpCell;
	if (T == NULL)
	{
		printf("Element not found!");
	}
	else if (X < T->Data)//������
	{
		T->Left = Delete(T->Left, X);
		if (Height(T->Left) - Height(T->Right) == 2)
		{
			if (X < T->Left->Data)
			{
				T = SingleRotationWithLeft(T);
			}
			else
			{
				T = doubleRotationWithLeft(T);
			}
		}
	}
	else if (X > T->Data)//������
	{
		T->Right = Delete(T->Right, X);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (X > T->Right->Data)
			{
				T = SingleRotationWithRight(T);
			}
			else
			{
				T = doubleRotationWithRight(T);
			}
		}
	}
	else if (X == T->Data)//�������Ҫɾ���Ľڵ�
	{
		if (T->Left && T->Right)//����������
		{
			/*
			���BT������������������
            ���ҳ�BT���������е����ڵ�
            �������ڵ��ֵ��ֵ��BT
            ɾ�������ڵ�
            ����������BT�������������ڵ���BT������
            ɾ��BT�������������ڵ�֮��AVL����Ȼ��ƽ���
			*/
			if (Height(T->Left) > Height(T->Right))
			{
				Position min = FindMax(T->Left);
				T->Data = min->Data;
				T->Left = Delete(T->Left, min->Data);
			}
			/*
			���BT������������������
            ���ҳ�BT���������е���С�ڵ�
            ������С�ڵ��ֵ��ֵ��BT
            ɾ������С�ڵ�
            ����������BT������������С�ڵ���BT������
            ɾ��BT������������С�ڵ�֮��AVL����Ȼ��ƽ���
			*/
			else
			{
				Position max = FindMin(T->Right);
				T->Data = max->Data;
				T->Right = Delete(T->Right, max->Data);
			}
		}
		else//��һ�����������
		{
			TmpCell = T;
			if (T->Left == NULL)
			{
				T = T->Right;
			}
			else if (T->Right == NULL)
			{
				T = T->Left;
			}
			free(TmpCell);
		}
	}

	return T;
}

//����
ElementType Retrieve(Position P)
{
	return P->Data;
}

//��ӡAVL��
void PrintTree(AVLTree T)
{
	if (T != NULL)
	{
		PrintTree(T->Left);
		printf("%d ", T->Data);
		PrintTree(T->Right);
	}
}