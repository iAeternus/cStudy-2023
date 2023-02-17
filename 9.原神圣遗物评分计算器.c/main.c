#include "attribute.h"

int main()
{	
	isValid* judg = (isValid*)malloc(sizeof(isValid));
	assert(judg);

	int Tag = 1;//index == -2
	while (Tag)
	{
		Tag = 0;

		char role[10] = { 0 };
		printf("输入该圣遗物所属角色全称首字母\n(eg：霄宫 ==> xg 注：优菈、科莱要输全拼)：");
		scanf("%s", role);
		while (getchar() != '\n');

		int isCrit;//index == -1
		do
		{
			printf("主词条是否为双爆？是 1 否 0 ：");
			judg->tag = scanf("%d", &isCrit);
			judg->num = (double)isCrit;
			judg->index = -1;
		} while (!isValidValue(judg));
		
		printf("副词条：\n");
		Attributes* att = enterAttributes();

		if (isCrit == 1)//主词条为双爆
		{
			printf("该圣遗物评分为：%d\n", (int)(20 + calculator(att, yieldWeightsMultiply(role)) + 0.5));
		}
		else if(isCrit == 0)//主词条不为双爆
		{
			printf("该圣遗物评分为：%d\n", (int)(calculator(att, yieldWeightsMultiply(role)) + 0.5));
		}

		do
		{
			printf("是否继续？是 1 否 0：");
			judg->tag = scanf("%d", &Tag);
			judg->num = (double)Tag;
			judg->index = -2;
		} while (!isValidValue(judg));

		printf("\n");
	}
	printf("再见！\n");

	free(judg);
	system("pause");
	return 0;
}