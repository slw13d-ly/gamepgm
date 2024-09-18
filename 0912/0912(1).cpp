//커서 위치 제어

#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y);
int main(void)
{
	gotoxy(2,4);
	printf("Hello");
	gotoxy(40, 20);
	printf("Hello");
	return 0;
}
	void gotoxy(int x, int y)
{
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//3단 출력

#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y);
int main(void)
{
	for(int i=1;i<=9;i++)
	{
	gotoxy(35, 5+i);
	printf("%d*%d=%2d",3,i,3*i);
	}
	printf("\n");
	return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//화면 지우기

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char ch;
	printf("문자를 입력하고 Enter>");
	scanf("%c", &ch);
	system("cls");
	printf("입력된 문자 %c\n", ch);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(void)
{
	int i, j;
	for(j=1;j<=9;j++)
	{
		system("cls");
		for(i=1;i<=9;i++)
			printf("%d*%d=%d\n", j, i, j*i);
		printf("아무키나 누르시오.\n");
		getch();
	}
	return 0;
}
