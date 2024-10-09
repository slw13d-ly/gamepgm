//도형의 연속적인 이동과 회전 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void rotation_right(int m[][3]);
void move_shape(int m[][3]);
void print_shape(int m[][3]);
void move_control(int m[][3]);
void gotoxy(int x, int y);
void print_direction(void);
void clear_shape(int m[][3]);

int x=35, y=12;
int inx=0, iny=0;

int main(void)
{
	int shape1[3][3]= {0,1,0,
			       0,1,0,
			       1,1,1};
	move_control(shape1);
	return 0;
}

void rotation_right(int m[][3])
{
	int i, j;
	int temp[3][3];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			temp[j][2-i]=m[i][j];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			m[i][j]=temp[i][j];
}

void print_direction(void)
{
	gotoxy(25, 1);
	printf("화살표:이동,  스페이스 키:회전");
}

void move_control(int m[][3])
{
	char key;
	do
	{
		while(!kbhit())
		{
			// system("cls"); 화면이 깜빡이는 것을 수정하기 위해 삭제 
			move_shape(m);		
		}
		key=getch();
		switch(key)
		{
			case 32 : 
				rotation_right(m);
				break;
			case 72 : 
				inx=0; iny=-1;
				break;
			case 75 : 
				inx=-1; iny=0;
				break;
			case 77 : 
				inx=1; iny=0;
				break;
			case 80 : 
				inx=0; iny=1;
				break;
			default :
				break;
		}
	}while(key!=27);
	printf("\n");
}

void print_shape(int m[][3])		
{
	int i, j;
	for(i=0;i<3;i++)
	{
		gotoxy(x,y+i);
		for(j=0;j<3;j++)
			if (m[i][j]==1)
				printf("□");
			else
				printf("  ");
	}
}

void clear_shape(int m[][3])		
{
	int i, j;
	for(i=0;i<3;i++)
	{
		gotoxy(x,y+i);
		for(j=0;j<3;j++)
			printf("  ");  // 빈 공간으로 덮어씀 
	}
}

void move_shape(int m[][3])		
{
	clear_shape(m);  // 현재 도형을 지움
	x=x+inx;
	y=y+iny;
	
	// 경계 조건 처리
	if (y>23)
		y=23;
	else if (y<2)
		y=2;
	if (x>75)
		x=75;
	else if (x<1)
		x=1;

	print_shape(m);  // 새로운 위치에 도형을 그림
	print_direction();
	Sleep(100);
}

void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
