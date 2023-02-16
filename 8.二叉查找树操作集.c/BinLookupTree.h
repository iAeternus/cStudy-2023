#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElementType;
typedef struct TNode* Position;
typedef Position BinTree;

struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal(BinTree BT);//先序遍历
void InorderTraversal(BinTree BT);//中序遍历

BinTree Insert(BinTree BLT, ElementType X);
BinTree Delete(BinTree BLT, ElementType X);
Position Find(BinTree BLT, ElementType X);
Position FindMin(BinTree BLT);
Position FindMax(BinTree BLT);