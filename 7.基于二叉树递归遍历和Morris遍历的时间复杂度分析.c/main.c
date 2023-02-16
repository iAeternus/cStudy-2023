/*
����������
ACDH**G***BE**F**

���������
�ݹ�ʵ�ֶ������ı���
ǰ�������ACDHGBEF
���������HDGCAEBF
���������HGDCEFBA
*/
#define _CRT_SECURE_NO_WARNINGS
#include "BinTree.h"

int main()
{
	printf("�������������Ԫ��(�����ʽΪ��չ����������,����������*)��\n");
	BinTree BT = CreateBinTree();

	printf("\n�ݹ�ʵ�ֶ������ı���\n");
	printf("ǰ�������");
	PreOrderTraverse(BT);
	printf("\n");
	printf("���������");
	InOrderTraverse(BT);
	printf("\n");
	printf("���������");
	PostOrderTraverse(BT);
	printf("\n");

	printf("\nMorrisǰ�����\n");
	printf("ǰ�������");
	Morris_DLR(BT);
	printf("\n");
	printf("���������");
	Morris_LDR(BT);
	printf("\n");
	printf("���������");
	Morris_LRD(BT);
	printf("\n");

	/*��������ʱ�����*/
	/*�ݹ鷽��*/
	for (int i = 0; i < 100; i++)
	{
		clock_t t1 = clock();
		for (int i = 0; i < MAXS; i++)
		{
			Recursion(BT);
		}
		clock_t t2 = clock();
		printf("%g %6.2e\n", (double)(t2 - t1), (double)(t2 - t1) / CLK_TCK / MAXS);//ʱ��������Ϊ��λ
	}
	printf("\n");

	/*Morris����*/
	for (int i = 0; i < 100; i++)
	{
		clock_t t3 = clock();
		for (int i = 0; i < MAXS; i++)
		{
			Morris(BT);
		}
		clock_t t4 = clock();
		printf("%g %6.2e\n", (double)(t4 - t3), (double)(t4 - t3) / CLK_TCK / MAXS);//ʱ��������Ϊ��λ
	}

	return 0;
}

/*
				   _ooOoo_
				  o8888888o
				  88" . "88
				  (| -_- |)
				  O\  =  /O
			   ____/`---'\____
			 .'  \\|     |//  `.
			/  \\|||  :  |||//  \
		   /  _||||| -:- |||||-  \
		   |   | \\\  -  /// |   |
		   | \_|  ''\---/''  |   |
		   \  .-\__  `-`  ___/-. /
		 ___`. .'  /--.--\  `. . __
	  ."" '<  `.___\_<|>_/___.'  >'"".
	 | | :  `- \`.;`\ _ /`;.`/ - ` : | |
	 \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
				   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			���汣��       ����BUG
*/