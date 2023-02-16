#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

//栈的初始化：链栈的初始化就是构造一个空栈，将栈顶指针top所指头结点的指针域置为NULL，因为此时栈中还没有数据元素
LinkedStack CreateStack()
{
	LinkedStack Top = (LinkedStackNode*)malloc(sizeof(LinkedStackNode));
	if (Top != NULL)
	{
		Top->Next = NULL;
	}
	return Top;
}

//判断栈是否为空：若链栈top为空，则返回TRUE（或1），否则返回FALSE（或0）
bool IsEmpty(LinkedStack Top)
{
	return Top->Next == NULL;
}

//入栈：将数据元素x插入链栈的栈顶，设置头结点的指针域指向新插入的栈顶元素
void Push(LinkedStack Top, ElementType item)
{
	LinkedStackNode* node = (LinkedStackNode*)malloc(sizeof(LinkedStackNode));
	assert(node);

	node->Data = item;
	node->Next = Top->Next;
	Top->Next = node;
}

//出栈：删除栈顶数据元素，并通过item返回所删除数据的值
void Pop(LinkedStack Top, ElementType* item)
{
	LinkedStackNode* temp;
	assert(Top->Next);

	temp = Top->Next;
	*item = temp->Data;
	Top->Next = temp->Next;
	free(temp);
}

//取栈顶数据元素：读取栈顶元素，并返回其值，该运算与出栈运算的区别是栈顶元素并不删除，所以不用修改头结点的指针域
ElementType GetTop(LinkedStack Top)
{
	assert(Top->Next);
	return Top->Next->Data;
}