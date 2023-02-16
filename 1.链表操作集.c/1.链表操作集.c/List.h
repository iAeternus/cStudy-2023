#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXS 10//����������ڵ���

struct LinkNode;
typedef struct LinkNode* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

//����ڵ����ݽṹ
struct LinkNode
{
	ElementType Data;
	Position Next;
};

//��ʼ������
List InitNode();
//�ж������Ƿ�Ϊ��
int IsEmpty(List L);
//���Ե�ǰλ���Ƿ�Ϊ����ĩβ
int IsLast(List L, Position P);
//����
Position Find(List L, ElementType X);
//ɾ�������Ԫ��X
void Delete(List L, ElementType X);
//��һ��Ԫ�ز��뵽P��ָʾ��λ��֮��
void Insert(List L, Position P, ElementType X);
//��������
void Destroy(List L);
//������ӡ����
ElementType Retrieve(List L);
