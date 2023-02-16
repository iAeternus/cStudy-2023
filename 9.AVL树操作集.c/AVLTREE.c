#define _CRT_SECURE_NO_WARNINGS
#include "AVLTREE.h"

static int Height(Position P);
static int Max(int a, int b);
static Position SingleRotationWithLeft(Position K2);
static Position doubleRotationWithLeft(Position K3);
static Position SingleRotationWithRight(Position K2);
static Position doubleRotationWithRight(Position K3);

//计算AVL节点的高度
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

//清空AVL树
void MakeEmpty(AVLTree T)
{
	if (T != NULL)//递归终止
    {
	    MakeEmpty(T->Left);
	    MakeEmpty(T->Right);
		free(T);
	}
}

//查找
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
	//不然就是找到了，不进行任何操作
	return T;
}

//递归实现查找最小元位置
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

//非递归实现查找最大元位置
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

//返回两者之间的较大值
static int Max(int a, int b)
{
	return (a > b ? a : b);
}

//左单旋转（LL型状态）
static Position SingleRotationWithLeft(Position K2)
{
	Position K1;

	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), K2->Height) + 1;

	return K1;//新的根节点
}

//左双旋转（LR型状态）先左旋在右旋
static Position doubleRotationWithLeft(Position K3)
{
	K3->Left = SingleRotationWithRight(K3->Left);
	return SingleRotationWithLeft(K3);
}

//右单旋转（RR型状态）
static Position SingleRotationWithRight(Position K2)
{
	Position K1;

	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Right), K2->Height) + 1;

	return K1;//新的根节点
}

//右双旋转（RL型状态）先右旋在左旋
static Position doubleRotationWithRight(Position K3)
{
	K3->Right = SingleRotationWithLeft(K3->Right);
	return SingleRotationWithRight(K3);
}

//插入
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
	/*else x 已经在树中，我们什么都不做*/

	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

//删除
AVLTree Delete(AVLTree T, ElementType X)
{
	Position TmpCell;
	if (T == NULL)
	{
		printf("Element not found!");
	}
	else if (X < T->Data)//往左走
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
	else if (X > T->Data)//往右走
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
	else if (X == T->Data)//如果就是要删除的节点
	{
		if (T->Left && T->Right)//有两个儿子
		{
			/*
			如果BT的左子树比右子树高
            则找出BT的左子树中的最大节点
            将该最大节点的值赋值给BT
            删除该最大节点
            这类似于用BT的左子树中最大节点做BT的替身
            删除BT的左子树中最大节点之后，AVL树仍然是平衡的
			*/
			if (Height(T->Left) > Height(T->Right))
			{
				Position min = FindMax(T->Left);
				T->Data = min->Data;
				T->Left = Delete(T->Left, min->Data);
			}
			/*
			如果BT的左子树比右子树低
            则找出BT的左子树中的最小节点
            将该最小节点的值赋值给BT
            删除该最小节点
            这类似于用BT的右子树中最小节点做BT的替身
            删除BT的左子树中最小节点之后，AVL树仍然是平衡的
			*/
			else
			{
				Position max = FindMin(T->Right);
				T->Data = max->Data;
				T->Right = Delete(T->Right, max->Data);
			}
		}
		else//有一个或零个儿子
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

//遍历
ElementType Retrieve(Position P)
{
	return P->Data;
}

//打印AVL树
void PrintTree(AVLTree T)
{
	if (T != NULL)
	{
		PrintTree(T->Left);
		printf("%d ", T->Data);
		PrintTree(T->Right);
	}
}