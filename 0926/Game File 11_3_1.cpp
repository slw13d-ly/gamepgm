#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void draw_check02(int r, int c);
void gotoxy(int x, int y);
void number_display(int n);
void display_rule(int n, char question[][10]);
void make_question(int n, char question[][10]);
void game_control(char question[][10], int n, int *count);
void clear_text(void);
void set_color(int color);
void start_screen();
void game_intro();
int select_difficulty();

int main(void) 
{
    int n, count = 0;
    char question[10][10] = {0};
    long pst, seconds, minutes;
    clock_t start, end;

    srand(time(NULL));

    start_screen();
    game_intro();

    n = select_difficulty();
    system("cls");
    draw_check02(n, n);
    number_display(n);
    display_rule(n, question);
    number_display(n);
    start = clock();
    
    do 
	{
        game_control(question, n, &count);
    } while (count < n * n / 2);

    gotoxy(2, 18);
    printf("모두 맞았습니다. 종료합니다.\n");
    end = clock();
    pst = (end - start) / CLOCKS_PER_SEC;
    minutes = pst / 60;
    seconds = pst - minutes * 60;
    gotoxy(2, 19);
    printf("경과시간 : %ld분 %ld 초\n", minutes, seconds);
    return 0;
}

void start_screen() 
{
    system("cls");
    printf("========================================\n");
    printf("         문자 퍼즐 맞추기 게임        \n");
    printf("========================================\n");
    printf("  두 개의 문자를 찾는 퍼즐 게임입니다.\n");
    printf("\n");
    printf("  아무 키나 눌러서 시작하세요...\n");
    getch();
}

void game_intro() 
{
    system("cls");
    printf("  [게임 설명]:\n");
    printf("  이 게임은 격자 모양의 판에 숨겨진 두 개의 문자를 찾는 게임입니다.\n");
    printf("  사용자는 숫자를 입력하여 두 개의 셀을 선택하고,\n");
    printf("  일치하는 문자가 있는지 확인합니다.\n");
	printf("  틀린 횟수가 5번을 초과하면 게임도 종료됩니다.\n");
    printf("  문자 @를 찾으면 게임이 종료되니, 찾지 않도록 주의하세요.\n");
	printf("\n");
    printf("  준비가 되면 아무 키나 누르세요...\n");
    getch();
}

int select_difficulty() 
{
    int n;
    system("cls");
    printf("난이도 선택:\n");
    printf("1. 하 (3행)\n");
    printf("2. 중 (5행)\n");
    printf("3. 상 (7행)\n");
    printf("원하는 난이도의 숫자를 선택하고 Enter를 누르세요: ");
    int choice;
    scanf("%d", &choice);

    while (choice < 1 || choice > 3) 
	{
        printf("잘못 입력하셨습니다. 1, 2, 3 중에서 선택하세요: ");
        scanf("%d", &choice);
    }

    switch (choice) 
	{
        case 1: n = 3; break;
        case 2: n = 5; break;
        case 3: n = 7; break;
    }
    return n;
}

void display_rule(int n, char question[][10])
{
    gotoxy(2, 16);
    printf("위와 같은 격자모양의 숫자 뒤에는 \n");
    gotoxy(2, 17);
    printf("같은 모양의 문자가 두개씩 숨어 있습니다.\n");
    gotoxy(2, 18);
    printf("아무키나 누르면 정답화면이 잠시 나타납니다. \n");
	getch();
    clear_text();
    make_question(n, question);
    gotoxy(2, 16);
    printf("정답 화면은 위와 같습니다.\n");
    gotoxy(2, 17);
    printf("5초 뒤에 문제 풀이를 시작합니다.\n");
    Sleep(5000);
    clear_text();
}

void game_control(char question[][10], int n, int *count)
{
    static int wrong_count = 0;
    int user1, user2, row1, row2, col1, col2;

    gotoxy(2, 16);
    printf("첫번째 숫자를 입력하고 Enter>");
    scanf("%d", &user1);
    row1 = user1 / n;
    col1 = user1 % n;
    gotoxy(2, 17);
    printf("두번째 숫자를 입력하고 Enter>");
    scanf("%d", &user2);
    row2 = user2 / n;
    col2 = user2 % n;

    if (question[row1][col1] == '@') 
    {   
        set_color(12);
        gotoxy(3 + 4 * col1, 2 + 2 * row1);
        printf("%2c", question[row1][col1]);
        gotoxy(3 + 4 * col2, 2 + 2 * row2);
        printf("%2c", question[row2][col2]);
        set_color(7);
        gotoxy(2, 20);
        printf("@기호를 찾았습니다. 게임을 종료합니다.\n");
        exit(0);
    }

    if (question[row2][col2] == '@') 
    {
        set_color(12);
        gotoxy(3 + 4 * col1, 2 + 2 * row1);
        printf("%2c", question[row1][col1]);
        gotoxy(3 + 4 * col2, 2 + 2 * row2);
        printf("%2c", question[row2][col2]);
        set_color(7);
        gotoxy(2, 20);
        printf("@기호를 찾았습니다. 게임을 종료합니다.\n");
        exit(0);
    }

    if (question[row1][col1] == question[row2][col2])
    {
        *count += 1;
        gotoxy(32, 4);
        printf("맞은 개수:%2d개(총 %2d개)", *count, n * n / 2);

        set_color(10);
        gotoxy(3 + 4 * col1, 2 + 2 * row1);
        printf("%2c", question[row1][col1]);

        gotoxy(3 + 4 * col2, 2 + 2 * row2);
        printf("%2c", question[row2][col2]);

        set_color(7);
        gotoxy(2, 16);
        printf("                                                 ");
        gotoxy(2, 17);
        printf("맞았습니다. 아무키나 누르면 다시 시작합니다.");
        getch();
        clear_text();
    }
    else
    {
        wrong_count++;
        gotoxy(3 + 4 * col1, 2 + 2 * row1);
        printf("%2c", question[row1][col1]);
        gotoxy(3 + 4 * col2, 2 + 2 * row2);
        printf("%2c", question[row2][col2]);
        Sleep(3000);
        gotoxy(3 + 4 * col1, 2 + 2 * row1);
        printf("%2d", user1);
        gotoxy(3 + 4 * col2, 2 + 2 * row2);
        printf("%2d", user2);

        gotoxy(32, 5);
        printf("틀린 횟수: %d\n", wrong_count);

        gotoxy(2, 18);
        printf("틀렸습니다. 아무키나 누르면 시작합니다. ");
		getch();
        clear_text();

        if (wrong_count >= 5) 
        {
            gotoxy(2, 20);
            printf("틀린 횟수가 5번을 초과했습니다. 게임을 종료합니다.\n");
            exit(0);
        }
    }
}

void clear_text(void)
{
    int i, j;
    for (i = 16; i < 19; i++)
    {
        gotoxy(2, i);
        for (j = 0; j < 50; j++)
            printf(" ");
    }
}

void number_display(int n)
{
    int i, j, count = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            gotoxy(3 + 4 * j, 2 + 2 * i);
            printf("%2d", count);
            count++;
        }
}

void set_color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void make_question(int n, char question[][10])
{
    int number, i, j, ran, count = 0;
    char chr[26], temp;
    int row, col;

    srand(time(NULL));
    number = n * n / 2;


    for (i = 0; i < 26; i++) 
	{
        chr[i] = 65 + i;
    }

    row = rand() % n;
    col = rand() % n;
    question[row][col] = '@';

    int positions[100], pos_index = 0;
    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; j++) 
		{
            if (i == row && j == col) continue;
            positions[pos_index++] = i * n + j;
        }
    }

    for (i = 0; i < pos_index; i++) 
	{
        int rand_pos = rand() % pos_index;
        int temp = positions[i];
        positions[i] = positions[rand_pos];
        positions[rand_pos] = temp;
    }

    for (i = 0; i < number; i++) 
	{
        int pos1 = positions[count++];
        int pos2 = positions[count++];
        question[pos1 / n][pos1 % n] = chr[i % 26];
        question[pos2 / n][pos2 % n] = chr[i % 26];
    }

    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; j++) 
		{
            if (question[i][j] >= 'A' && question[i][j] <= 'Z') 
			{
                set_color(10);
            } else if (question[i][j] == '@') 
			{
                set_color(14);
            } else 
			{
                set_color(7);
            }
            gotoxy(3 + 4 * j, 2 + 2 * i);
            printf("%2c", question[i][j]);
        }
    }
    set_color(7);
}

void draw_check02(int r, int c)
{
    int i, j;

    printf(" ┌");
    for (j = 0; j < c; j++) 
	{
        printf("───");
        if (j < c - 1) 
		{
            printf("┬");
        }
    }
    printf("┐\n");

    for (i = 0; i < r; i++) 
	{
        printf(" │");
        for (j = 0; j < c; j++) 
		{
            printf("   ");
            printf("│");
        }
        printf("\n");
        
        if (i < r - 1) 
		{
            printf(" ├");
            for (j = 0; j < c; j++) 
			{
                printf("───");
                if (j < c - 1) 
				{
                    printf("┼");
                }
            }
            printf("┤\n");
        }
    }

    printf(" └");
    for (j = 0; j < c; j++) 
	{
        printf("───");
        if (j < c - 1) 
		{
            printf("┴");
        }
    }
    printf("┘\n");
}

void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
