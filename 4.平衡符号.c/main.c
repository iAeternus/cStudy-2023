/*
Check if parenthesis ( ), brackets [ ], and braces { } are balanced.
ջ��Ӧ�á�������ƽ�����
*/

/*
ջ������ʵ�ַ�ʽ����ʽ�洢��˳��洢(����)��ջ��һ����ҪӦ����ƽ����š�
��ѧ���ڱ�д���벢�ұ���ʱ���������Ϊ��д��һ��')'�ͱ�����������Ҳ��
��˵����������ȥƥ�������Ƿ�ƥ�䡣����������һ��'('������Ȼ��������ȥ��
�����Ƿ�����һ��')'������֮ƥ�䡣������е����Ŷ��ܹ��ɶԳ��֣���ô����
�����ܹ�ͨ���ġ�����������ᱨ�������ַ����С�(a+b)����ƥ��ģ����ַ���
��"(a+b]"���ǡ�

�ڼ������ƥ����㷨��ʹ�õ���ջ.
�㷨�������£�����һ����ջ����ȡ�ַ�����ֱ����β������ַ��ǿ��ŷ���
'<'(''[''{'��������ջ�������һ����շ���'>')'']''}'����ջΪ��ʱ����
���򣬽�ջ��Ԫ�ص�������������ķ��Ų��Ƕ�Ӧ�Ŀ��ŷ��ţ��򱨴�����
�����н������ж�ջ�Ƿ�Ϊ�գ�Ϊ���򱨴�
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