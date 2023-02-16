#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

int main()
{
    ElementType data;
    //初始化队列
    LinkQueue LQ;
    CreateQueue(&LQ);
    //入队
    ElementType i;
    for (i = 1; i < 9; i++)
    {
        EnterLinkQueue(&LQ, i);
    }
    printf("队列中的元素为：");
    //打印队列中元素
    PrintLinkQueue(&LQ);
    printf("\n");
    //取队头元素
    data = GetHead(&LQ, &data);
    printf("队头元素为：%d\n", data);
    printf("\n");
    //出队
    DeleteLinkQueue(&LQ, &data);
    printf("出队的元素为：%d\n", data);
    printf("\n");
    printf("队列中的元素为：");
    PrintLinkQueue(&LQ);
    printf("\n");
    data = GetHead(&LQ, &data);
    printf("队头元素为：%d\n", data);
    printf("\n");
    ClearQueue(&LQ);
    system("pause");

	return 0;
}