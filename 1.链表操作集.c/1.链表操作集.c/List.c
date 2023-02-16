#include "List.h"

//初始化链表
List InitNode()
{
	List L = malloc(sizeof(struct LinkNode));
	assert(L);

	L->Data = -1;
	L->Next = NULL;
	return L;
}

//判断链表是否为空
int IsEmpty(List L)
{
	return L->Next == NULL;
}

//测试当前位置是否为链表末尾
int IsLast(List L, Position P)
{
	return P->Next == NULL;
}

//查找
Position Find(List L, ElementType X)
{
	Position P;

	P = L->Next;
	while (P != NULL && P->Data != X)
	{
		P = P->Next;
	}
	return P;
}

//删除链表的元素X
static Position FindPrevious(List L, ElementType X)
{
	Position P;

	P = L;
	while (P->Next != NULL && P->Next->Data != X)
	{
		P = P->Next;
	}
	return P;
}
void Delete(List L, ElementType X)
{
	Position P, TmpCell;

	P = FindPrevious(L, X);
	if (!IsLast(L, P))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
	else
	{
		printf("Not Found!");
	}
}
//将一个元素插入到P所指示的位置之后
void Insert(List L, Position P, ElementType X)
{
	Position TmpCell;

	TmpCell = malloc(sizeof(struct LinkNode));
	assert(TmpCell);

	TmpCell->Data = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}
//销毁链表
void Destroy(List L)
{
	Position P, TmpCell;

	P = L->Next;
	L->Next = NULL;
	while (P != NULL)
	{
		TmpCell = P->Next;
		free(P);
		P = TmpCell;
	}
}

//遍历打印链表
ElementType Retrieve(List L)
{
	if (L == NULL)
	{
		return;
	}

	Position P = L->Next;
	while (P != NULL)
	{
		printf("%d ", P->Data);
		P = P->Next;
	}
	printf("\n");
}