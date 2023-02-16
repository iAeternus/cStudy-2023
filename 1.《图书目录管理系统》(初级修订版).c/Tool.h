#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#define MAXS 1000

//����
struct Date
{
	int year;
	int month;
	int day;
};

//ͼ����Ϣ
typedef struct BookInformation
{
	char ISBN[14];
	char Title[31];
	char Author[21];
	char Publisher[31];
	struct Date PubDate;
	double Price;
}Book, * BookPtr;

//ͼ���
typedef struct library
{
	Book book[MAXS];
	int num;
}library, * Lib;

void menu(Lib lib);

//���� A a
void Append(Lib lib);
//�������ȫ��ͼ�� S s
void Show(Lib lib);
//����������ʾͼ�� F f
void Find(Lib lib);
//�������ɾ��ͼ�� R r
void Remove(Lib lib);
//��������޸�ͼ����Ϣ M m
void Modify(Lib lib);