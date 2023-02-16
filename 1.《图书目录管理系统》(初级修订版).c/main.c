#include "Tool.h"

int main()
{
	Lib lib = (Lib)malloc(sizeof(library));
	assert(lib);

	lib->num = 0;//初始化书库数目为0

	menu(lib);
	return 0;
}

void menu(Lib lib)
{
	char ch;
	do
	{
		printf("Append Find Remove Modify Show Quit > ");
		scanf(" %c", &ch);
		while (getchar() != '\n');
		ch = toupper(ch);
		switch (ch)
		{
		case 'A':
			Append(lib);
			break;
		case 'S':
			Show(lib);
			break;
		case 'F':
			Find(lib);
			break;
		case 'R':
			Remove(lib);
			break;
		case 'M':
			Modify(lib);
			break;
		case 'Q':
			printf("Thank you! Goodbye!");
			break;
		default:
			printf("Incorrect choice!\n");
			break;
		}
	} while (ch != 'Q');
}

