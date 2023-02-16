/*
输入样例：
10
5 8 6 2 4 1 0 10 9 7
5
6 3 10 0 5
5
5 7 0 10 3

输出样例：
Preorder: 5 2 1 0 4 8 6 7 10 9
6 is found
3 is not found
10 is found
10 is the largest key
0 is found
0 is the smallest key
5 is found
Not Found
Inorder: 1 2 4 6 8 9
*/
#define _CRT_SECURE_NO_WARNINGS
#include "BinLookupTree.h"

int main()
{
    BinTree BLT, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BLT = NULL;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        BLT = Insert(BLT, X);
    }
    printf("Preorder:"); 
    PreorderTraversal(BLT);
    printf("\n");

    MinP = FindMin(BLT);
    MaxP = FindMax(BLT);
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        Tmp = Find(BLT, X);
        if (Tmp == NULL)
        {
            printf("%d is not found\n", X);
        }
        else
        {
            printf("%d is found\n", Tmp->Data);
            if (Tmp == MinP)
            {
                printf("%d is the smallest key\n", Tmp->Data);
            }
            if (Tmp == MaxP)
            {
                printf("%d is the largest key\n", Tmp->Data);
            }
        }
    }
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        BLT = Delete(BLT, X);
    }
    printf("Inorder:");
    InorderTraversal(BLT); 
    printf("\n");

    return 0;
}