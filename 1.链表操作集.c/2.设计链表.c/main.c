#include "LinkNode.h"

#define MAXS 15

//��ӡ����
void myLinkedListPrint(MyLinkedList* obj)
{
	for (int i = 0; i < MAXS; i++)
	{
		printf("%3d", myLinkedListGet(obj, i));
	}
	printf("\n");
}

int main()
{
	MyLinkedList* LinkNode = myLinkedListCreate();

	printf("\033[40;31m������  ��\033[0m");
	for (int i = 0; i < MAXS; i++)
	{
		printf("\033[40;31m%3d\033[0m", i);
	}
	printf("\n");

	printf("ͷ�巨  ��");
	for (int i = 1; i <= MAXS / 3; i++)
	{
		myLinkedListAddAtHead(LinkNode, i);//ͷ�巨
	}
	myLinkedListPrint(LinkNode);

	printf("β�巨  ��");
	for (int i = 1; i <= MAXS / 3; i++)
	{
		myLinkedListAddAtTail(LinkNode, i);//β�巨
	}
	myLinkedListPrint(LinkNode);

	printf("�м��  ��");
	for (int i = 1; i <= MAXS / 3; i++)
	{
		myLinkedListAddAtIndex(LinkNode, MAXS / 3, i);//�м��
	}
	myLinkedListPrint(LinkNode);

	printf("ɾ��5�� ��");
	myLinkedListDeleteAtIndex(LinkNode, 5);
	myLinkedListPrint(LinkNode);

	myLinkedListFree(LinkNode);

	system("pause");
	return 0;
}