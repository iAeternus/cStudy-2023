/*
����һ�����������ÿ�����ֶ�Ӧ��ƴ����������Ϊ����ʱ�������fu�֡�ʮ�����ֶ�Ӧ��ƴ�����£�

0: ling
1: yi
2: er
3: san
4: si
5: wu
6: liu
7: qi
8: ba
9: jiu
�����ʽ��
������һ���и���һ���������磺1234��

��ʾ�������������������������

�����ʽ��
��һ����������������Ӧ��ƴ����ÿ�����ֵ�ƴ��֮���ÿո�ֿ�����ĩû�����Ŀո���
yi er san si��

����������
-600
���������
fu liu ling ling
*/
#include <stdio.h>
#include <string.h>

#define MAXS 1000

int main()
{
    char* py[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};//�ַ�������
    char num[MAXS];
    gets(num);
    int len = strlen(num), i;
    for(i = 0; i < len; i++)
    {
        if(num[i] == '-')
        {
            printf("fu");
        }
        else
        {
            printf("%s", py[num[i] - '0']);
        }
        
        if(i != len - 1)
        {
            printf(" ");
        }
    }
    
    return 0;
}
