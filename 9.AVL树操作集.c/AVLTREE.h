#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct AVLNode;
typedef struct AVLNode* Position;
typedef struct AVLNode* AVLTree;
typedef int ElementType;

//清空AVL树
void MakeEmpty(AVLTree T);
//查找
Position Find(AVLTree T, ElementType X);
//递归实现查找最大元位置
Position FindMin(AVLTree T);
//非递归实现查找最小元位置
Position FindMax(AVLTree T);
//插入
AVLTree Insert(AVLTree T, ElementType X);
//删除
AVLTree Delete(AVLTree T, ElementType X);
//遍历
ElementType Retrieve(Position P);
//打印AVL树
void PrintTree(AVLTree T);

struct AVLNode
{
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};