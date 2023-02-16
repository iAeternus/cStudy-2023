#define _CRT_SECURE_NO_WARNINGS
#include "BinTree.h"

/*Testº¯Êý*/
void Recursion(BinTree BT)
{
	if (BT == NULL)
	{
		return;
	}
	Recursion(BT->Left);
	Recursion(BT->Right);
}

void Morris(BinTree BT)
{
	BinTree cur = BT;
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
			else
			{
				temp->Right = NULL;
				cur = cur->Right;
			}
		}
	}
}