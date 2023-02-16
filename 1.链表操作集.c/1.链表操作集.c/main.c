#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

int main()
{
    List L = InitNode();//��ʼ������
    Position P = L;
    for (int i = 0; i < MAXS; i++)
    {
        Insert(L, P, i + 1);
    }

    printf("����Ԫ�صĵ�ַΪ��\n");
    for (int i = 0; i < MAXS; i++)
    {
        P = Find(L, i + 1);
        printf("%2d: %p\n", i + 1, P);
    }

    printf("����Ԫ��Ϊ��             ");
    Retrieve(L);

    printf("ɾ��Ԫ�� 8 ������Ԫ��Ϊ��");
    Position P1 = Find(L, 8);
    Delete(L, 8);
    Position P2 = Find(L, 8);
    Retrieve(L);

    if (P1 != P2)
    {
        printf("ɾ��֮ǰ�ڵ� 8 �ĵ�ַΪ%p, ɾ��֮��ڵ� 8 �ĵ�ַΪ%p = NULL, �������Բ�ͬ, ɾ���ɹ�\n", P1, P2);
    }
    else
    {
        printf("ɾ��֮ǰ�ڵ� 8 �ĵ�ַΪ%p, ɾ��֮��ڵ� 8 �ĵ�ַΪ%p, ������ͬ��ɾ��ʧ��\n", P1, P2);
    }

    Destroy(L);

    system("pause");
    return 0;
}