#include "LinkNode.h"

#define MAXS 15

//打印链表
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

	printf("\033[40;31m索引号  ：\033[0m");
	for (int i = 0; i < MAXS; i++)
	{
		printf("\033[40;31m%3d\033[0m", i);
	}
	printf("\n");

	printf("头插法  ：");
	for (int i = 1; i <= MAXS / 3; i++)
	{
		myLinkedListAddAtHead(LinkNode, i);//头插法
	}
	myLinkedListPrint(LinkNode);

	printf("尾插法  ：");
	for (int i = 1; i <= MAXS / 3; i++)
	{
		myLinkedListAddAtTail(LinkNode, i);//尾插法
	}
	myLinkedListPrint(LinkNode);

	printf("中间插  ：");
	for (int i = 1; i <= MAXS / 3; i++)
	{
		myLinkedListAddAtIndex(LinkNode, MAXS / 3, i);//中间插
	}
	myLinkedListPrint(LinkNode);

	printf("删除5号 ：");
	myLinkedListDeleteAtIndex(LinkNode, 5);
	myLinkedListPrint(LinkNode);

	myLinkedListFree(LinkNode);

	system("pause");
	return 0;
}