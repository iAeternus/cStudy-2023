#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

//描述一个数据是否合法的结构
typedef struct isValid
{
	int tag;
	int index;
	double num;
} isValid;

typedef struct relicAttributes
{
	double relicElementalCharging; //元素充能效率
	double relicElementalMastery;  //元素精通
	double relicCritDamage;        //暴击伤害
	double relicCritChance;        //暴击率
	double relicHealthPercentage;  //生命值百分比
	double relicHealth;            //生命值
	double relicDefensePercentage; //防御力百分比
	double relicDefense;           //防御力
	double relicAttackPercentage;  //攻击力百分比
	double relicAttack;            //攻击力
} Attributes;

typedef struct yieldWeights
{
	double Charging;               //元素充能效率
	double Mastery;                //元素精通
	double CritDamage;             //暴击伤害
	double CritChance;             //暴击率
	double HealthPercentage;       //生命值百分比
	double Health;                 //生命值
	double DefensePercentage;      //防御力百分比
	double Defense;                //防御力
	double AttackPercentage;       //攻击力百分比
	double Attack;                 //攻击力
} yieldWeights;

//收益权重
yieldWeights* yieldWeightsMultiply(char* role);
//判断输入是否正确
bool isValidValue(isValid* judg);
//输入
Attributes* enterAttributes();
//计算函数
double calculator(Attributes* att, yieldWeights* yie);