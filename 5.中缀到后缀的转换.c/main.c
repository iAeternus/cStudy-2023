/*
1.创建栈
2.从左向右顺序获取中缀表达式
	a.数字直接输出
	b.运算符
		情况一：遇到左括号直接入栈，遇到右括号将栈中左括号之后入栈的运算符全部弹栈输出，
		同时左括号出栈但是不输出。

		情况二：遇到乘号和除号直接入栈，直到遇到优先级比它更低的运算符，依次弹栈。

		情况三：遇到加号和减号，如果此时栈空，则直接入栈，否则，将栈中优先级高的运算符依次弹栈
	   （注意：加号和减号属于同一个优先级，所以也依次弹栈）直到栈空或则遇到左括号为止，停止弹栈。（因为左括号要匹配右括号时才弹出）。

		情况四：获取完后，将栈中剩余的运算符号依次弹栈输出

例:比如将:2*(9+6/3-5)+4转化为后缀表达式 2 9 6 3 / + 5 - * 4 +
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

int main()
{
	ElementType str[MAXS];
	LinkedStack L = CreateStack();
	printf("请输入中缀表达式：");
	gets_s(str, MAXS - 1);
	printf("对应的后缀表达式为：");
	Change(L, str);
	printf("\n");
	system("pause");

	return 0;
}

/*中缀转后缀函数*/
void Change(LinkedStack Top, ElementType str[])
{
	int i = 0;
	ElementType e;
	while (str[i] != '\0')
	{
		while (isdigit(str[i]) || isalpha(str[i]))/*过滤数字字符，直接输出，直到下一位不是数字字符打印空格跳出循环 */
		{
			printf("%c", str[i++]);
			if (!isdigit(str[i]))
			{
				printf(" ");
			}
		}
		/*加减运算符优先级最低，如果栈顶元素为空则直接入栈，否则将栈中存储
		的运算符全部弹栈，如果遇到左括号则停止，将弹出的左括号从新压栈，因为左
		括号要和右括号匹配时弹出，这个后面单独讨论。弹出后将优先级低的运算符压入栈中*/
		if (str[i] == '+' || str[i] == '-')
		{
			if (IsEmpty(Top))
			{
				Push(Top, str[i]);
			}
			else
			{
				do
				{
					Pop(Top, &e);
					if (e == '(')
					{
						Push(Top, e);
					}
					else
					{
						printf("%c ", e);
					}
				} while (!IsEmpty(Top) && e != '(');

				Push(Top, str[i]);
			}
		}
		/*当遇到右括号时，把括号里剩余的运算符弹出，直到匹配到左括号为止
		左括号只弹出不打印（右括号也不压栈）*/
		else if (str[i] == ')')
		{
			Pop(Top, &e);
			while (e != '(')
			{
				printf("%c ", e);
				Pop(Top, &e);
			}
		}
		/*乘、除、左括号都是优先级高的，直接压栈*/
		else if (str[i] == '*' || str[i] == '/' || str[i] == '(')
		{
			Push(Top, str[i]);
		}

		else if (str[i] == '\0')
		{
			break;
		}

		else
		{
			printf("\n输入格式错误！\n");
			return;
		}
		i++;
	}
	/*最后把栈中剩余的运算符依次弹栈打印*/
	while (!IsEmpty(Top))
	{
		Pop(Top, &e);
		printf("%c ", e);
	}
}