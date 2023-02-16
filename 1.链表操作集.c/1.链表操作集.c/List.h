#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXS 10//测试用链表节点数

struct LinkNode;
typedef struct LinkNode* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

//定义节点数据结构
struct LinkNode
{
	ElementType Data;
	Position Next;
};

//初始化链表
List InitNode();
//判断链表是否为空
int IsEmpty(List L);
//测试当前位置是否为链表末尾
int IsLast(List L, Position P);
//查找
Position Find(List L, ElementType X);
//删除链表的元素X
void Delete(List L, ElementType X);
//将一个元素插入到P所指示的位置之后
void Insert(List L, Position P, ElementType X);
//销毁链表
void Destroy(List L);
//遍历打印链表
ElementType Retrieve(List L);
