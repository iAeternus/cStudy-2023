#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

int main()
{
    ElementType data;
    //��ʼ������
    LinkQueue LQ;
    CreateQueue(&LQ);
    //���
    ElementType i;
    for (i = 1; i < 9; i++)
    {
        EnterLinkQueue(&LQ, i);
    }
    printf("�����е�Ԫ��Ϊ��");
    //��ӡ������Ԫ��
    PrintLinkQueue(&LQ);
    printf("\n");
    //ȡ��ͷԪ��
    data = GetHead(&LQ, &data);
    printf("��ͷԪ��Ϊ��%d\n", data);
    printf("\n");
    //����
    DeleteLinkQueue(&LQ, &data);
    printf("���ӵ�Ԫ��Ϊ��%d\n", data);
    printf("\n");
    printf("�����е�Ԫ��Ϊ��");
    PrintLinkQueue(&LQ);
    printf("\n");
    data = GetHead(&LQ, &data);
    printf("��ͷԪ��Ϊ��%d\n", data);
    printf("\n");
    ClearQueue(&LQ);
    system("pause");

	return 0;
}