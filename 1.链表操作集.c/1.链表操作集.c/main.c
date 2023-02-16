#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

int main()
{
    List L = InitNode();//初始化链表
    Position P = L;
    for (int i = 0; i < MAXS; i++)
    {
        Insert(L, P, i + 1);
    }

    printf("链表元素的地址为：\n");
    for (int i = 0; i < MAXS; i++)
    {
        P = Find(L, i + 1);
        printf("%2d: %p\n", i + 1, P);
    }

    printf("链表元素为：             ");
    Retrieve(L);

    printf("删除元素 8 后链表元素为：");
    Position P1 = Find(L, 8);
    Delete(L, 8);
    Position P2 = Find(L, 8);
    Retrieve(L);

    if (P1 != P2)
    {
        printf("删除之前节点 8 的地址为%p, 删除之后节点 8 的地址为%p = NULL, 二者明显不同, 删除成功\n", P1, P2);
    }
    else
    {
        printf("删除之前节点 8 的地址为%p, 删除之后节点 8 的地址为%p, 二者相同，删除失败\n", P1, P2);
    }

    Destroy(L);

    system("pause");
    return 0;
}