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
		printf("�����ʥ����������ɫȫ������ĸ\n(eg������ ==> xg ע����ǉ������Ҫ��ȫƴ)��");
		scanf("%s", role);
		while (getchar() != '\n');

		int isCrit;//index == -1
		do
		{
			printf("�������Ƿ�Ϊ˫������ 1 �� 0 ��");
			judg->tag = scanf("%d", &isCrit);
			judg->num = (double)isCrit;
			judg->index = -1;
		} while (!isValidValue(judg));
		
		printf("��������\n");
		Attributes* att = enterAttributes();

		if (isCrit == 1)//������Ϊ˫��
		{
			printf("��ʥ��������Ϊ��%d\n", (int)(20 + calculator(att, yieldWeightsMultiply(role)) + 0.5));
		}
		else if(isCrit == 0)//��������Ϊ˫��
		{
			printf("��ʥ��������Ϊ��%d\n", (int)(calculator(att, yieldWeightsMultiply(role)) + 0.5));
		}

		do
		{
			printf("�Ƿ�������� 1 �� 0��");
			judg->tag = scanf("%d", &Tag);
			judg->num = (double)Tag;
			judg->index = -2;
		} while (!isValidValue(judg));

		printf("\n");
	}
	printf("�ټ���\n");

	free(judg);
	system("pause");
	return 0;
}