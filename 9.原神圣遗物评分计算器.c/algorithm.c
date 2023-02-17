#include "attribute.h"

//判断输入是否正确
bool isValidValue(isValid* judg)
{
	while (getchar() != '\n');
	if (judg->tag == 0)
	{
		printf("输入非法，请重新输入！\n");
		return false;
	}
	else
	{
		if (!((judg->index == -1 && judg->num == 0 || judg->num == 1)
			|| (judg->index == -2 && judg->num == 0 || judg->num == 1)
			|| (judg->index == 0 && judg->num <= 23.3)
			|| (judg->index == 1 && judg->num <= 46.6)
			|| (judg->index == 2 && judg->num <= 39)
			|| (judg->index == 3 && judg->num <= 140)
			|| (judg->index == 4 && judg->num <= 35)
			|| (judg->index == 5 && judg->num <= 117)
			|| (judg->index == 6 && judg->num <= 35)
			|| (judg->index == 7 && judg->num <= 1794)
			|| (judg->index == 8 && judg->num <= 43.8)
			|| (judg->index == 9 && judg->num <= 140)))
		{
			printf("输入非法，请重新输入！\n");
			return false;
		}
	}
	return true;
}

//输入
double enter(int index)
{
	double num = 0;
	isValid* judg = (isValid*)malloc(sizeof(isValid));
	assert(judg);

	do
	{
		if (index == 0) printf("暴击率      ：");//打印说明
		if (index == 1) printf("暴击伤害    ：");
		if (index == 2) printf("元素充能效率：");
		if (index == 3) printf("元素精通    ：");
		if (index == 4) printf("攻击力百分比：");
		if (index == 5) printf("攻击力      ：");
		if (index == 6) printf("生命值百分比：");
		if (index == 7) printf("生命值      ：");
		if (index == 8) printf("防御力百分比：");
		if (index == 9) printf("防御力      ：");
		judg->tag = scanf("%lf", &num);//输入
		judg->num = num;
		judg->index = index;
	} while (!isValidValue(judg));//判断

	free(judg);
	return num;
}
Attributes* enterAttributes()
{
	double temp[11] = { -1 };//临时存放输入数据
	Attributes* att = (Attributes*)malloc(sizeof(Attributes));
	assert(att);

	for (int i = 0; i < 10; i++)//输入数据
	{
		temp[i] = enter(i);
	}
	
	att->relicCritChance = temp[0];//赋值
	att->relicCritDamage = temp[1];
	att->relicElementalCharging = temp[2];
	att->relicElementalMastery = temp[3];
	att->relicAttackPercentage = temp[4];
	att->relicAttack = temp[5];
	att->relicHealthPercentage = temp[6];
	att->relicHealth = temp[7];
	att->relicDefensePercentage = temp[8];
	att->relicDefense = temp[9];

	return att;
}

//计算函数（核心算法）
double calculator(Attributes* att, yieldWeights* yie)
{
	double critStrikeChance = att->relicCritChance * 2 * yie->CritChance;
	double critDamage = att->relicCritDamage * 1 * yie->CritDamage;
	double elementalMastery = att->relicElementalMastery * 0.33 * yie->Mastery;
	double elementalCharging = att->relicElementalCharging * 1.1979 * yie->Charging;
	double attackPercentage = att->relicAttackPercentage * 1.33 * yie->AttackPercentage;
	double healthPercentage = att->relicHealthPercentage * 1.33 * yie->HealthPercentage;
	double defensePercentage = att->relicDefensePercentage * 1.06 * yie->DefensePercentage;
	double attack = att->relicAttack * 0.398 * 0.5 * yie->Attack;
	double health = att->relicHealth * 0.026 * 0.66 * yie->Health;
	double defense = att->relicDefense * 0.355 * 0.66 * yie->Defense;

	return (critStrikeChance + critDamage + elementalMastery + elementalCharging
		+ attackPercentage + healthPercentage + defensePercentage
		+ attack + health + defense);
}