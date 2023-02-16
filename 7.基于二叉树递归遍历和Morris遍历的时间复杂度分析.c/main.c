/*
输入样例：
ACDH**G***BE**F**

输出样例：
递归实现二叉树的遍历
前序遍历：ACDHGBEF
中序遍历：HDGCAEBF
后序遍历：HGDCEFBA
*/
#define _CRT_SECURE_NO_WARNINGS
#include "BinTree.h"

int main()
{
	printf("请输入二叉树的元素(输入格式为扩展二叉树序列,空子树输入*)：\n");
	BinTree BT = CreateBinTree();

	printf("\n递归实现二叉树的遍历\n");
	printf("前序遍历：");
	PreOrderTraverse(BT);
	printf("\n");
	printf("中序遍历：");
	InOrderTraverse(BT);
	printf("\n");
	printf("后序遍历：");
	PostOrderTraverse(BT);
	printf("\n");

	printf("\nMorris前序遍历\n");
	printf("前序遍历：");
	Morris_DLR(BT);
	printf("\n");
	printf("中序遍历：");
	Morris_LDR(BT);
	printf("\n");
	printf("后序遍历：");
	Morris_LRD(BT);
	printf("\n");

	/*程序运行时间测量*/
	/*递归方案*/
	for (int i = 0; i < 100; i++)
	{
		clock_t t1 = clock();
		for (int i = 0; i < MAXS; i++)
		{
			Recursion(BT);
		}
		clock_t t2 = clock();
		printf("%g %6.2e\n", (double)(t2 - t1), (double)(t2 - t1) / CLK_TCK / MAXS);//时间结果以秒为单位
	}
	printf("\n");

	/*Morris方案*/
	for (int i = 0; i < 100; i++)
	{
		clock_t t3 = clock();
		for (int i = 0; i < MAXS; i++)
		{
			Morris(BT);
		}
		clock_t t4 = clock();
		printf("%g %6.2e\n", (double)(t4 - t3), (double)(t4 - t3) / CLK_TCK / MAXS);//时间结果以秒为单位
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
			佛祖保佑       永无BUG
*/