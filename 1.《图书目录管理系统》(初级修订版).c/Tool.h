#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

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

//图书馆
typedef struct library
{
	Book book[MAXS];
	int num;
}library, * Lib;

void menu(Lib lib);

//输入 A a
void Append(Lib lib);
//升序输出全部图书 S s
void Show(Lib lib);
//输入书名显示图书 F f
void Find(Lib lib);
//输入书号删除图书 R r
void Remove(Lib lib);
//输入书号修改图书信息 M m
void Modify(Lib lib);