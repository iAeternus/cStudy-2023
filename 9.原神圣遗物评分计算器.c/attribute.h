#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

//����һ�������Ƿ�Ϸ��Ľṹ
typedef struct isValid
{
	int tag;
	int index;
	double num;
} isValid;

typedef struct relicAttributes
{
	double relicElementalCharging; //Ԫ�س���Ч��
	double relicElementalMastery;  //Ԫ�ؾ�ͨ
	double relicCritDamage;        //�����˺�
	double relicCritChance;        //������
	double relicHealthPercentage;  //����ֵ�ٷֱ�
	double relicHealth;            //����ֵ
	double relicDefensePercentage; //�������ٷֱ�
	double relicDefense;           //������
	double relicAttackPercentage;  //�������ٷֱ�
	double relicAttack;            //������
} Attributes;

typedef struct yieldWeights
{
	double Charging;               //Ԫ�س���Ч��
	double Mastery;                //Ԫ�ؾ�ͨ
	double CritDamage;             //�����˺�
	double CritChance;             //������
	double HealthPercentage;       //����ֵ�ٷֱ�
	double Health;                 //����ֵ
	double DefensePercentage;      //�������ٷֱ�
	double Defense;                //������
	double AttackPercentage;       //�������ٷֱ�
	double Attack;                 //������
} yieldWeights;

//����Ȩ��
yieldWeights* yieldWeightsMultiply(char* role);
//�ж������Ƿ���ȷ
bool isValidValue(isValid* judg);
//����
Attributes* enterAttributes();
//���㺯��
double calculator(Attributes* att, yieldWeights* yie);