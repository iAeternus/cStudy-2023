/*
����Ҫ�������A - B�������鷳���ǣ�A��B�����ַ��� ���� �����ַ���A�а��ַ���B���������ַ�ȫɾ����ʣ�µ��ַ���ɵľ����ַ���A?B��

�����ʽ��
������2�����Ⱥ�����ַ���A��B�����ַ����ĳ��ȶ�������10^4,
���ұ�֤ÿ���ַ��������ɿɼ���ASCII��Ϳհ��ַ���ɣ�����Ի��з�������

�����ʽ��
��һ���д�ӡ��A?B�Ľ���ַ�����

����������
I love GPLT!  It's a fun game!
aeiou
���������
I lv GPLT!  It's  fn gm!
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char a[100000];
    char b[100000];
    gets(a);
    gets(b);
    int len = strlen(a), i;
    
    for(i = 0; i < len; i++)
    {
        if(strchr(b, a[i]))//�ַ������Һ������� b �в��� a[i]
        {
            continue;
        }
        else
        {
            printf("%c", a[i]);
        }
    }
    
    return 0;
}
