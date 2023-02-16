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

//�ڶ���������BLT���ҵ�X�����ظý���ָ�룻����Ҳ����򷵻ؿ�ָ��
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

//���ض���������BLT����СԪ����ָ��
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

//���ض���������BLT�����Ԫ����ָ��
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

//��X�������������BLT�����ؽ�����ĸ����ָ��
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

//��X�Ӷ���������BLT��ɾ���������ؽ�����ĸ����ָ�룻���X�������У����ӡһ��Not Found������ԭ���ĸ����ָ��
BinTree Delete(BinTree BLT, ElementType X)
{
    BinTree Temp;
    if (BLT == NULL)//������
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
            if (BLT->Left && BLT->Right)//���Ҷ��Ӷ�����
            {
                Temp = FindMax(BLT->Left);
                BLT->Data = Temp->Data;
                BLT->Left = Delete(BLT->Left, BLT->Data);
            }
            else//ֻ��һ�����ӻ���û��
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