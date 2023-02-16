#include "Tool.h"

//判断日期是否正确
int IsLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}
void IsValidDate(Lib lib, int i)
{
	int tag = 1;
	char arr[2][13] = { {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
	while (tag)
	{
		tag = 0;
		if (!(lib->book[i].PubDate.year > 0 && lib->book[i].PubDate.month >= 1
			&& lib->book[i].PubDate.month <= 12 && lib->book[i].PubDate.day >= 1
			&& lib->book[i].PubDate.day <= arr[IsLeapYear(lib->book[i].PubDate.year)][lib->book[i].PubDate.month - 1]))
		{
			printf("Incorrect date! Please reenter: ");
			scanf("%d/%d/%d", &lib->book[i].PubDate.year, &lib->book[i].PubDate.month, &lib->book[i].PubDate.day);
			while (getchar() != '\n');
			tag = 1;
		}
	}
}
//输入 A a
void Input(Lib lib, int i)
{
	printf("     ISBN: ");
	gets(lib->book[i].ISBN);

	printf("    Title: ");
	gets(lib->book[i].Title);

	printf("   Author: ");
	gets(lib->book[i].Author);

	printf("Publisher: ");
	gets(lib->book[i].Publisher);

	printf(" Pub date: ");
	scanf("%d/%d/%d", &lib->book[i].PubDate.year, &lib->book[i].PubDate.month, &lib->book[i].PubDate.day);
	while (getchar() != '\n');
	IsValidDate(lib, i);

	printf("    Price: ");
	scanf("%lf", &lib->book[i].Price);
	while (getchar() != '\n');
}
void Append(Lib lib)
{
	Input(lib, lib->num);
	lib->num++;
}

//升序输出全部图书 S s
void sort(Lib lib)
{
	int len = lib->num;
	while (len--)
	{
		for (int i = 0; i < len; i++)
		{
			if (strcmp(lib->book[i].ISBN, lib->book[i + 1].ISBN) > 0)
			{
				Book Temp = lib->book[i];
				lib->book[i] = lib->book[i + 1];
				lib->book[i + 1] = Temp;
			}
		}
	}
}
void Show(Lib lib)
{
	sort(lib);
	printf("ISBN--------- Title------------------------- Author-------------- Publisher--------------------- Pub-date-- Price---\n");
	for (int i = 0; i < lib->num; i++)
	{
		printf("%-14s%-31s%-21s%-31s", lib->book[i].ISBN, lib->book[i].Title, lib->book[i].Author, lib->book[i].Publisher);
		printf("%04d/%02d/%02d ", lib->book[i].PubDate.year, lib->book[i].PubDate.month, lib->book[i].PubDate.day);
		printf("%8.2f\n", lib->book[i].Price);
	}
}

//输入书名显示图书 F f
void FindTitle(Lib lib, char* Title)
{
	int Hash[MAXS] = { -1 };
	int j = 0;
	for (int i = 0; i < lib->num; i++)
	{
		if (strcmp(lib->book[i].Title, Title) == 0)
		{
			Hash[j++] = i;// i 反映的是找到的元素的数组下标
		}
	}
	if (Hash[0] == -1)
	{
		printf("Not found!\n");
		return;
	}
	printf("ISBN--------- Title------------------------- Author-------------- Publisher--------------------- Pub-date-- Price---\n");
	for (int i = 0; i < j; i++)
	{
		printf("%-14s%-31s%-21s%-31s", lib->book[Hash[i]].ISBN, lib->book[Hash[i]].Title, lib->book[Hash[i]].Author, lib->book[Hash[i]].Publisher);
		printf("%04d/%02d/%02d ", lib->book[Hash[i]].PubDate.year, lib->book[Hash[i]].PubDate.month, lib->book[Hash[i]].PubDate.day);
		printf("%8.2f\n", lib->book[Hash[i]].Price);
	}
}
void Find(Lib lib)
{
	Book temp = { 0 };
	printf("Title: ");
	gets(temp.Title);
	FindTitle(lib, temp.Title);
}

//输入书号删除图书 R r
int FindISBN(Lib lib, char* ISBN)
{
	int ret = -1;
	for (int i = 0; i < lib->num; i++)
	{
		if (strcmp(lib->book[i].ISBN, ISBN) == 0)
		{
			ret = i;
			break;
		}
	}
	return ret;
}
void Delete(Lib lib, char* ISBN)
{
	int i = FindISBN(lib, ISBN);
	for (int j = i; j < lib->num; j++)
	{
		lib->book[j] = lib->book[j + 1];
	}
	lib->num--;
}
void Remove(Lib lib)
{
	Book temp = { 0 };
	printf("ISBN: ");
	gets(temp.ISBN);
	if (FindISBN(lib, temp.ISBN) == -1)
	{
		printf("Not found!\n");
		return;
	}

	char tag;
	while (1)
	{
		printf("Remove(y/n)? ");
		tag = getchar();
		while (getchar() != '\n');
		tag = toupper(tag);
		switch (tag)
		{
		case 'Y':
			Delete(lib, temp.ISBN);
			return;
		case 'N':
			return;
		default:
			printf("Incorrect answer!\n");
			break;
		}
	}
}

//输入书号修改图书信息 M m
void Modify(Lib lib)
{
	Book temp = { 0 };
	printf("ISBN: ");
	gets(temp.ISBN);
	int i = FindISBN(lib, temp.ISBN);
	if (i == -1)
	{
		printf("Not found!\n");
		return;
	}

	char tag;
	while (1)
	{
		printf("Modify(y/n)? ");
		tag = getchar();
		while (getchar() != '\n');
		tag = toupper(tag);
		switch (tag)
		{
		case 'Y':
			Input(lib, i);
			return;
		case 'N':
			return;
		default:
			printf("Incorrect answer!\n");
			break;
		}
	}
}