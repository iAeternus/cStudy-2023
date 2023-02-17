#include "attribute.h"

//收益权重
yieldWeights* yieldWeightsMultiply(char* role)
{
	yieldWeights* yie = (yieldWeights*)malloc(sizeof(yieldWeights));
	assert(yie);

	/*
	将角色相同的收益权重归为一类，大大简化代码量
	*/

	//暴击率
	if (strcmp(role, "shgxh") == 0)
	{
		yie->CritChance = 0;
	}
	else if (strcmp(role, "yj") == 0 || strcmp(role, "wl") == 0 || strcmp(role, "dan") == 0
		|| strcmp(role, "tm") == 0 || strcmp(role, "bbl") == 0 || strcmp(role, "zy") == 0
		|| strcmp(role, "bnt") == 0)
	{
		yie->CritChance = 0.5;
	}
	else
	{
		yie->CritChance = 1;
	}

	//暴击伤害
	if (strcmp(role, "shgxh") == 0)
	{
		yie->CritDamage = 0;
	}
	else if (strcmp(role, "yj") == 0 || strcmp(role, "wl") == 0 || strcmp(role, "dan") == 0
		|| strcmp(role, "tm") == 0 || strcmp(role, "bbl") == 0 || strcmp(role, "zy") == 0
		|| strcmp(role, "bnt") == 0)
	{
		yie->CritDamage = 0.5;
	}
	else
	{
		yie->CritDamage = 1;
	}

	//元素充能效率
	if (strcmp(role, "wl") == 0 || strcmp(role, "bnt") == 0
		|| strcmp(role, "dan") == 0 || strcmp(role, "tm") == 0)
	{
		yie->Charging = 1;
	}
	else if (strcmp(role, "ldjj") == 0 || strcmp(role, "mn") == 0)
	{
		yie->Charging = 0.75;
	}
	else if (strcmp(role, "nae") == 0)
	{
		yie->Charging = 0.7;
	}
	else if (strcmp(role, "lyl") == 0 || strcmp(role, "kds") == 0 || strcmp(role, "dl") == 0
		|| strcmp(role, "kelai") == 0 || strcmp(role, "yl") == 0 || strcmp(role, "sh") == 0
		|| strcmp(role, "fywy") == 0 || strcmp(role, "xq") == 0 || strcmp(role, "zl") == 0
		|| strcmp(role, "xl") == 0 || strcmp(role, "wd") == 0 || strcmp(role, "shgxh") == 0
		|| strcmp(role, "x") == 0 || strcmp(role, "jtsl") == 0 || strcmp(role, "q") == 0
		|| strcmp(role, "bd") == 0 || strcmp(role, "bbl") == 0 || strcmp(role, "lxzc") == 0
		|| strcmp(role, "cy") == 0 || strcmp(role, "qq") == 0 || strcmp(role, "zy") == 0
		|| strcmp(role, "xy") == 0 || strcmp(role, "st") == 0 || strcmp(role, "jqr") == 0)
	{
		yie->Charging = 0.55;
	}
	else if (strcmp(role, "hlyd") == 0 || strcmp(role, "youla") == 0 || strcmp(role, "sllh") == 0)
	{
		yie->Charging = 0.3;
	}
	else
	{
		yie->Charging = 0;
	}

	//元素精通
	if (strcmp(role, "nxd") == 0 || strcmp(role, "fywy") == 0 || strcmp(role, "zy") == 0
		|| strcmp(role, "st") == 0 || strcmp(role, "jqr") == 0)
	{
		yie->Mastery = 1;
	}
	else if (strcmp(role, "nl") == 0 || strcmp(role, "sn") == 0 || strcmp(role, "tnl") == 0
		|| strcmp(role, "kelai") == 0 || strcmp(role, "lyypz") == 0 || strcmp(role, "bcsz") == 0 
		|| strcmp(role, "xl") == 0 || strcmp(role, "ht") == 0 || strcmp(role, "gy") == 0 
		|| strcmp(role, "wd") == 0 || strcmp(role, "mn") == 0 || strcmp(role, "ddly") == 0 
		|| strcmp(role, "xg") == 0 || strcmp(role, "kl") == 0 || strcmp(role, "bd") == 0 
		|| strcmp(role, "dlk") == 0 || strcmp(role, "lxzc") == 0 || strcmp(role, "lxzl") == 0 
		|| strcmp(role, "lxzf") == 0 || strcmp(role, "cy") == 0 || strcmp(role, "yf") == 0 
		|| strcmp(role, "ab") == 0 || strcmp(role, "ls") == 0)
	{
		yie->Mastery = 0.75;
	}
	else
	{
		yie->Mastery = 0;
	}

	//攻击
	if (strcmp(role, "sh") == 0 || strcmp(role, "qq") == 0)
	{
		yie->AttackPercentage = 1;
		yie->Attack = 1;
	}
	else if (strcmp(role, "nxd") == 0)
	{
		yie->AttackPercentage = 0.55;
		yie->Attack = 0.55;
	}
	else if (strcmp(role, "hlyd") == 0 || strcmp(role, "wl") == 0 || strcmp(role, "bnt") == 0
		|| strcmp(role, "ht") == 0 || strcmp(role, "shgxh") == 0 || strcmp(role, "dan") == 0
		|| strcmp(role, "tm") == 0 || strcmp(role, "bbl") == 0 || strcmp(role, "nae") == 0
		|| strcmp(role, "zy") == 0)
	{
		yie->AttackPercentage = 0.5;
		yie->Attack = 0.5;
	}
	else if (strcmp(role, "lyl") == 0 || strcmp(role, "nl") == 0 || strcmp(role, "kds") == 0
		|| strcmp(role, "yl") == 0 || strcmp(role, "yj") == 0 || strcmp(role, "abd") == 0
		|| strcmp(role, "jqr") == 0)
	{
		yie->AttackPercentage = 0;
		yie->Attack = 0;
	}
	else
	{
		yie->AttackPercentage = 0.75;
		yie->Attack = 0.75;
	}

	//生命值
	if (strcmp(role, "lyl") == 0 || strcmp(role, "nl") == 0 || strcmp(role, "kds") == 0
		|| strcmp(role, "bnt") == 0 || strcmp(role, "shgxh") == 0 || strcmp(role, "dan") == 0
		|| strcmp(role, "tm") == 0 || strcmp(role, "bbl") == 0 || strcmp(role, "jqr") == 0)
	{
		yie->HealthPercentage = 1;
		yie->Health = 1;
	}
	else if (strcmp(role, "yl") == 0 || strcmp(role, "zl") == 0 || strcmp(role, "ht") == 0)
	{
		yie->HealthPercentage = 0.8;
		yie->Health = 0.8;
	}
	else if (strcmp(role, "dl") == 0)
	{
		yie->HealthPercentage = 0.75;
		yie->Health = 0.75;
	}
	else if (strcmp(role, "sllr") == 0)
	{
		yie->HealthPercentage = 0.5;
		yie->Health = 0.5;
	}
	else
	{
		yie->HealthPercentage = 0;
		yie->Health = 0;
	}

	//防御力
	if (strcmp(role, "yj") == 0 || strcmp(role, "hlyd") == 0 || strcmp(role, "wl") == 0
		|| strcmp(role, "abd") == 0)
	{
		yie->DefensePercentage = 1;
		yie->Defense = 1;
	}
	else if (strcmp(role, "nae") == 0)
	{
		yie->DefensePercentage = 0.9;
		yie->Defense = 0.9;
	}
	else
	{
		yie->DefensePercentage = 0;
		yie->Defense = 0;
	}

	return yie;
}
