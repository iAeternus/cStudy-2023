/*
Check if parenthesis ( ), brackets [ ], and braces { } are balanced.
栈的应用————平衡符号
*/

/*
栈的两种实现方式：链式存储和顺序存储(数组)。栈的一个主要应用是平衡符号。
初学者在编写代码并且编译时，难免会因为少写了一个')'和被编译器报错。也就
是说，编译器会去匹配括号是否匹配。当你输入了一个'('，很自然编译器回去检
查你是否有另一个')'符号与之匹配。如果所有的括号都能够成对出现，那么编译
器是能够通过的。否则编译器会报错。例如字符序列“(a+b)”是匹配的，而字符序
列"(a+b]"则不是。

在检测括号匹配的算法中使用到了栈.
算法描述如下：创建一个空栈，读取字符序列直到结尾。如果字符是开放符号
'<'(''[''{'，将其入栈；如果是一个封闭符号'>')'']''}'，则当栈为空时报错。
否则，将栈顶元素弹出。如果弹出的符号不是对应的开放符号，则报错。当字
符序列结束，判断栈是否为空，为空则报错。
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

int main()
{
	char ch[MAXS] = { 0 };
	gets_s(ch, MAXS - 1);
	LinkedStack L = CreateStack();
	CheckSymbol(ch, L);

	return 0;
}

void CheckSymbol(char* ch, LinkedStack Top)
{
	ElementType item = 0;
	printf("%s\n", ch);
	while (*ch != '\0')
	{
		switch (*ch)
		{
		case '<':
		case '(':
		case '[':
		case '{':
			Push(Top, *ch);
			break;

		case '>':
			if (IsEmpty(Top))
			{
				printf("The symbols not balance!\n");
				return;
			}
			else
			{
				if (GetTop(Top) == '<')
				{
					Pop(Top, &item);
				}
				else
				{
					printf("The symbols not balance!\n");
					return;
				}
			}
			break;
		case ')':
			if (IsEmpty(Top))
			{
				printf("The symbols not balance!\n");
				return;
			}
			else
			{
				if (GetTop(Top) == '(')
				{
					Pop(Top, &item);
				}
				else
				{
					printf("The symbols not balance!\n");
					return;
				}
			}
			break;
		case ']':
			if (IsEmpty(Top))
			{
				printf("The symbols not balance!\n");
				return;
			}
			else
			{
				if (GetTop(Top) == '[')
				{
					Pop(Top, &item);
				}
				else
				{
					printf("The symbols not balance!\n");
					return;
				}
			}
			break;
		case '}':
			if (IsEmpty(Top))
			{
				printf("The symbols not balance!\n");
				return;
			}
			else
			{
				if (GetTop(Top) == '{')
				{
					Pop(Top, &item);
				}
				else
				{
					printf("The symbols not balance!\n");
					return;
				}
			}
			break;
		default:
			break;
		}
		ch++;
	}
	if (IsEmpty(Top))
	{
		printf("The Symbols Balance!\n");
	}
	else
	{
		printf("The symbols not balance!\n");
	}
}