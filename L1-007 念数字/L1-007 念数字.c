/*
输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出fu字。十个数字对应的拼音如下：

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
输入格式：
输入在一行中给出一个整数，如：1234。

提示：整数包括负数、零和正数。

输出格式：
在一行中输出这个整数对应的拼音，每个数字的拼音之间用空格分开，行末没有最后的空格。如
yi er san si。

输入样例：
-600
输出样例：
fu liu ling ling
*/
#include <stdio.h>
#include <string.h>

#define MAXS 1000

int main()
{
    char* py[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};//字符串数组
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
