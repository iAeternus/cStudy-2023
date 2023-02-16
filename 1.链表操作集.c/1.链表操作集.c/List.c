#include "List.h"

//��ʼ������
List InitNode()
{
	List L = malloc(sizeof(struct LinkNode));
	assert(L);

	L->Data = -1;
	L->Next = NULL;
	return L;
}

//�ж������Ƿ�Ϊ��
int IsEmpty(List L)
{
	return L->Next == NULL;
}

//���Ե�ǰλ���Ƿ�Ϊ����ĩβ
int IsLast(List L, Position P)
{
	return P->Next == NULL;
}

//����
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

//ɾ�������Ԫ��X
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
//��һ��Ԫ�ز��뵽P��ָʾ��λ��֮��
void Insert(List L, Position P, ElementType X)
{
	Position TmpCell;

	TmpCell = malloc(sizeof(struct LinkNode));
	assert(TmpCell);

	TmpCell->Data = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}
//��������
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

//������ӡ����
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