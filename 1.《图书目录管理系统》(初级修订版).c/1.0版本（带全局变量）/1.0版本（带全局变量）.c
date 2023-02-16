#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAXS 1000

//日期
struct Date
{
	int year;
	int month;
	int day;
};

//图书信息
typedef struct BookInformation
{
	char ISBN[14];
	char Title[31];
	char Author[21];
	char Publisher[31];
	struct Date PubDate;
	double Price;
}Book, * BookPtr;

void menu(Book a[]);

//输入 A a
void Append();
//升序输出全部图书 S s
void Show(Book* book);
//输入书名显示图书 F f
void Find(Book* book);
//输入书号删除图书 R r
void Remove(Book* book);
//输入书号修改图书信息 M m
void Modify(Book* book);

Book book[MAXS];
int k;

int main()
{
	menu(book);
	return 0;
}

void menu(Book a[])
{
	char ch;
	do
	{
		printf("Append Find Remove Modify Show Quit > ");
		scanf(" %c", &ch);
		while (getchar() != '\n');
		ch = toupper(ch);
		switch (ch)
		{
		case 'A':
			Append();
			break;
		case 'S':
			Show(a);
			break;
		case 'F':
			Find(a);
			break;
		case 'R':
			Remove(a);
			break;
		case 'M':
			Modify(a);
			break;
		case 'Q':
			printf("Thank you! Goodbye!");
			break;
		default:
			printf("Incorrect choice!\n");
			break;
		}
	} while (ch != 'Q');

	return 0;
}

//判断日期是否正确
int IsLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}
void IsValidDate(int i)
{
	int tag = 1;
	char arr[2][13] = { {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
	while (tag)
	{
		tag = 0;
		if (!(book[i].PubDate.year > 0 && book[i].PubDate.month >= 1
			&& book[i].PubDate.month <= 12 && book[i].PubDate.day >= 1
			&& book[i].PubDate.day <= arr[IsLeapYear(book[i].PubDate.year)][book[i].PubDate.month - 1]))
		{
			printf("Incorrect date! Please reenter: ");
			scanf("%d/%d/%d", &book[i].PubDate.year, &book[i].PubDate.month, &book[i].PubDate.day);
			while (getchar() != '\n');
			tag = 1;
		}
	}
}

//输入 A a
void Input(int i)
{
	printf("     ISBN: ");
	gets(book[i].ISBN);

	printf("    Title: ");
	gets(book[i].Title);

	printf("   Author: ");
	gets(book[i].Author);

	printf("Publisher: ");
	gets(book[i].Publisher);

	printf(" Pub date: ");
	scanf("%d/%d/%d", &book[i].PubDate.year, &book[i].PubDate.month, &book[i].PubDate.day);
	while (getchar() != '\n');
	IsValidDate(i);

	printf("    Price: ");
	scanf("%lf", &book[i].Price);
	while (getchar() != '\n');
}
void Append()
{
	Input(k);
	k++;
}

//升序输出全部图书 S s
void sort(Book* book, int len)
{
	len = k;
	while (len--)
	{
		int i; 
		for (i = 0; i < len; i++)
		{
			if (strcmp(book[i].ISBN, book[i + 1].ISBN) > 0)
			{
				Book Temp = book[i];
				book[i] = book[i + 1];
				book[i + 1] = Temp;
			}
		}
	}
}
void Show(Book* book)
{
	sort(book, k);
	printf("ISBN--------- Title------------------------- Author-------------- Publisher--------------------- Pub-date-- Price---\n");
	int i;
	for (i = 0; i < k; i++)
	{
		printf("%-14s%-31s%-21s%-31s", book[i].ISBN, book[i].Title, book[i].Author, book[i].Publisher);
		printf("%04d/%02d/%02d ", book[i].PubDate.year, book[i].PubDate.month, book[i].PubDate.day);
		printf("%8.2f\n", book[i].Price);
	}
}

//输入书名显示图书 F f
void FindTitle(Book* book, char* Title)
{
	int Hash[MAXS] = { -1 };
	int i, j = 0;
	for (i = 0; i < k; i++)
	{
		if (strcmp(book[i].Title, Title) == 0)
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
	int l;
	for (l = 0; l < j; l++)
	{
		printf("%-14s%-31s%-21s%-31s", book[Hash[l]].ISBN, book[Hash[l]].Title, book[Hash[l]].Author, book[Hash[l]].Publisher);
		printf("%04d/%02d/%02d ", book[Hash[l]].PubDate.year, book[Hash[l]].PubDate.month, book[Hash[l]].PubDate.day);
		printf("%8.2f\n", book[Hash[l]].Price);
	}
}
void Find(Book* book)
{
	Book temp = { 0 };
	printf("Title: ");
	gets(temp.Title);
	FindTitle(book, temp.Title);
}

//输入书号删除图书 R r
int FindISBN(Book* book, char* ISBN)
{
	int ret = -1;
	int i;
	for (i = 0; i < k; i++)
	{
		if (strcmp(book[i].ISBN, ISBN) == 0)
		{
			ret = i;
			break;
		}
	}
	return ret;
}
void Delete(Book* book, char* ISBN)
{
	int i = FindISBN(book, ISBN), j;
	for (j = i; j < k; j++)
	{
		book[j] = book[j + 1];
	}
	k--;
}
void Remove(Book* book)
{
	Book temp = { 0 };
	printf("ISBN: ");
	gets(temp.ISBN);
	if (FindISBN(book, temp.ISBN) == -1)
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
			Delete(book, temp.ISBN);
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
void Modify(Book* book)
{
	Book temp = { 0 };
	printf("ISBN: ");
	gets(temp.ISBN);
	int i = FindISBN(book, temp.ISBN);
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
			Input(i);
			return;
		case 'N':
			return;
		default:
			printf("Incorrect answer!\n");
			break;
		}
	}
}

