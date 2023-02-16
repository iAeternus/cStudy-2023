#define _CRT_SECURE_NO_WARNINGS
#include "BinTree.h"

//������������
BinTree CreateBinTree()
{
	ElementType item;
	BinTree BT;
	scanf("%c", &item);
	if (item == '*')
	{
		BT = NULL;
	}
	else
	{
		BT = (BinTree)malloc(sizeof(BinTNode));
		assert(BT);
		BT->Data = item;
		BT->Left = CreateBinTree();
		BT->Right = CreateBinTree();
	}
	return BT;//���ظ��ڵ�
}

//�ݹ�ʵ���������
void PreOrderTraverse(BinTree BT)
{
	if (BT == NULL)
	{
		return;
	}
	printf("%c", BT->Data);
	PreOrderTraverse(BT->Left);
	PreOrderTraverse(BT->Right);
}

//�ݹ�ʵ���������
void InOrderTraverse(BinTree BT)
{
	if (BT == NULL)
	{
		return;
	}
	InOrderTraverse(BT->Left);
	printf("%c", BT->Data);
	InOrderTraverse(BT->Right);
}

//�ݹ�ʵ�ֺ������
void PostOrderTraverse(BinTree BT)
{
	if (BT == NULL)
	{
		return;
	}
	PostOrderTraverse(BT->Left);
	PostOrderTraverse(BT->Right);
	printf("%c", BT->Data);
}

//Morrisǰ�����
void Morris_DLR(BinTree BT)
{
	BinTree cur = BT;
	while (cur != NULL)
	{
		if (cur->Left == NULL)
		{
			printf("%c", cur->Data);
			cur = cur->Right;
		}
		else
		{
			BinTree temp = cur->Left;
			while (temp->Right != NULL && temp->Right != cur) 
			{
				temp = temp->Right;
			}

			if (temp->Right == NULL) 
			{
				temp->Right = cur;
				printf("%c", cur->Data);
				cur = cur->Left;
			}
			else 
			{
				temp->Right = NULL;
				cur = cur->Right;
			}
		}
	}
}

//Morris�������
void Morris_LDR(BinTree BT)
{
	BinTree cur = BT;
	while (cur != NULL)
	{
		if (cur->Left == NULL)
		{
			printf("%c", cur->Data);
			cur = cur->Right;
		}
		else
		{
			BinTree temp = cur->Left;
			while (temp->Right != NULL && temp->Right != cur)
			{
				temp = temp->Right;
			}

			if (temp->Right == NULL) 
			{
				temp->Right = cur;
				cur = cur->Left;
			}
			else 
			{
				temp->Right = NULL;
				printf("%c", cur->Data);
				cur = cur->Right;
			}
		}
	}
}

//Morris�������
void Morris_LRD(BinTree BT)
{
	BinTree head = (BinTree)calloc(1, sizeof(BinTNode));
	assert(head);
	BinTree cur = head;
	head->Left = BT;
	while (cur != NULL) 
	{
		if (cur->Left == NULL)
		{
			cur = cur->Right;
		}
		else 
		{
			BinTree temp = cur->Left;
			while (temp->Right != NULL && temp->Right != cur) 
			{
				temp = temp->Right;
			}

			if (temp->Right == NULL)
			{
				temp->Right = cur;
				cur = cur->Left;
			}
			else // (temp -> Right == cur��
			{ 
				temp->Right = NULL;

				BinTree index = cur->Left;
				while (index != NULL) 
				{
					printf("%c", index->Data);
					index = index->Right;
				}
				cur = cur->Right;
			}
		}
	}
	head->Left = NULL;
	free(head);
}