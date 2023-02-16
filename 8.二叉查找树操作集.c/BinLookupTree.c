#define _CRT_SECURE_NO_WARNINGS
#include "BinLookupTree.h"

void PreorderTraversal(BinTree BT)
{
    if (BT == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}
void InorderTraversal(BinTree BT)
{
    if (BT == NULL)
    {
        return;
    }
    else
    {
        InorderTraversal(BT->Left);
        printf("%d ", BT->Data);
        InorderTraversal(BT->Right);
    }
}

//在二叉搜索树BLT中找到X，返回该结点的指针；如果找不到则返回空指针
Position Find(BinTree BLT, ElementType X)
{
    if (BLT == NULL)
    {
        return NULL;
    }
    if (X < BLT->Data)
    {
        return Find(BLT->Left, X);
    }
    else if (X > BLT->Data)
    {
        return Find(BLT->Right, X);
    }
    else
    {
        return BLT;
    }
}

//返回二叉搜索树BLT中最小元结点的指针
Position FindMin(BinTree BLT)
{
    if (!BLT)
    {
        return NULL;
    }
    else
    {
        if (BLT->Left == NULL)
        {
            return BLT;
        }
        else
        {
            return FindMin(BLT->Left);
        }           
    }
}

//返回二叉搜索树BLT中最大元结点的指针
Position FindMax(BinTree BLT)
{
    if (!BLT)
    {
        return NULL;
    }
    else
    {
        if (BLT->Right == NULL)
        {
            return BLT;
        }
        else
        {
            return FindMax(BLT->Right);
        }           
    }
}

//将X插入二叉搜索树BLT并返回结果树的根结点指针
BinTree Insert(BinTree BLT, ElementType X)
{
    if (!BLT)
    {
        BLT = (BinTree)malloc(sizeof(struct TNode));
        assert(BLT);
        BLT->Data = X;
        BLT->Left = BLT->Right = NULL;
    }
    else
    {
        if (X < BLT->Data)
        {
            BLT->Left = Insert(BLT->Left, X);
        }
        else
        {
            BLT->Right = Insert(BLT->Right, X);
        }
    }
    return BLT;
}

//将X从二叉搜索树BLT中删除，并返回结果树的根结点指针；如果X不在树中，则打印一行Not Found并返回原树的根结点指针
BinTree Delete(BinTree BLT, ElementType X)
{
    BinTree Temp;
    if (BLT == NULL)//不存在
    {
        printf("Not Found\n");
    }
    else
    {
        if (X > BLT->Data)
        {
            BLT->Right = Delete(BLT->Right, X);
        }
        else if (X < BLT->Data)
        {
            BLT->Left = Delete(BLT->Left, X);
        }
        else
        {
            if (BLT->Left && BLT->Right)//左右儿子都存在
            {
                Temp = FindMax(BLT->Left);
                BLT->Data = Temp->Data;
                BLT->Left = Delete(BLT->Left, BLT->Data);
            }
            else//只有一个儿子或者没有
            {
                Temp = BLT;
                if (!BLT->Left)
                {
                    BLT = BLT->Right;
                }
                else
                {
                    BLT = BLT->Left;
                }

                free(Temp);
            }
        }
    }
    return BLT;
}