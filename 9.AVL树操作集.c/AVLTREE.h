#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct AVLNode;
typedef struct AVLNode* Position;
typedef struct AVLNode* AVLTree;
typedef int ElementType;

//���AVL��
void MakeEmpty(AVLTree T);
//����
Position Find(AVLTree T, ElementType X);
//�ݹ�ʵ�ֲ������Ԫλ��
Position FindMin(AVLTree T);
//�ǵݹ�ʵ�ֲ�����СԪλ��
Position FindMax(AVLTree T);
//����
AVLTree Insert(AVLTree T, ElementType X);
//ɾ��
AVLTree Delete(AVLTree T, ElementType X);
//����
ElementType Retrieve(Position P);
//��ӡAVL��
void PrintTree(AVLTree T);

struct AVLNode
{
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};