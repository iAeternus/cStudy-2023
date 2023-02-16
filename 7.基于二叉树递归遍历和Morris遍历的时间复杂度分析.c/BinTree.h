#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <time.h>

#define MAXS 1e7

typedef char ElementType;

//���������ݽṹ
typedef struct TreeNode
{
	ElementType Data;
	struct TreeNode* Left;
	struct TreeNode* Right;
}BinTNode, *BinTree;

//������������
BinTree CreateBinTree();

//�ݹ�ʵ��ǰ�����
void PreOrderTraverse(BinTree BT);
//�ݹ�ʵ���������
void InOrderTraverse(BinTree BT);
//�ݹ�ʵ�ֺ������
void PostOrderTraverse(BinTree BT);

//Morrisǰ�����
void Morris_DLR(BinTree BT);
//Morris�������
void Morris_LDR(BinTree BT);
//Morris�������
void Morris_LRD(BinTree BT);

/*Test����*/
void Recursion(BinTree BT);
void Morris(BinTree BT);

