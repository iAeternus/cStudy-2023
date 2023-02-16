#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <time.h>

#define MAXS 1e7

typedef char ElementType;

//二叉树数据结构
typedef struct TreeNode
{
	ElementType Data;
	struct TreeNode* Left;
	struct TreeNode* Right;
}BinTNode, *BinTree;

//先序建立二叉树
BinTree CreateBinTree();

//递归实现前序遍历
void PreOrderTraverse(BinTree BT);
//递归实现中序遍历
void InOrderTraverse(BinTree BT);
//递归实现后序遍历
void PostOrderTraverse(BinTree BT);

//Morris前序遍历
void Morris_DLR(BinTree BT);
//Morris中序遍历
void Morris_LDR(BinTree BT);
//Morris后序遍历
void Morris_LRD(BinTree BT);

/*Test函数*/
void Recursion(BinTree BT);
void Morris(BinTree BT);

