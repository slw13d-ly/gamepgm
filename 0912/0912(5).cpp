//범위 내의 난수 생성
// 주사위 눈금 난수 생성
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i;
	srand(time(NULL));
	for(i=1;i<=10;i++)
		printf("%2d:%d\n",i, rand()%6+1);
	return 0;
}

// 1부터 45 난수 생성
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i;
	srand(time(NULL));
	for(i=1;i<=6;i++)
		printf("%2d:%d\n",rand()%45+1);
	return 0;
}

// 1부터 45 중복 없는 난수 생성
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, j, lotto[6];
	srand(time(NULL));
	for(i=0;i<=5;i++)
	{
		lotto[i]=rand()%45+1;
		for(j=0;j<i;j++)
		{
			if (lotto[i] == lotto[j])
			{
				i--;
				break;
			}
		}
	}
	for(i=0;i<=5;i++)
		printf("%2d\n", lotto[i]);
	return 0;
}

// 1부터 45 중복 없는 난수 생성 - 정렬
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int r[], int n);
int main(void)
{
	int i, j, lotto[6];
	srand(time(NULL));
	for(i=0;i<=5;i++)
	{
		lotto[i]=rand()%45+1;
		for(j=0;j<i;j++)
		{
			if (lotto[i] == lotto[j])
			{
				i--;
				break;
			}
		}
	}
	selection_sort(lotto, 6);
	return 0;
}

void selection_sort(int r[], int n)
{
	int i, j, min, temp;
	for (i=0;i<=n;i++)
	{
		min = i;
		for (j=i+1;j<=n;j++)
			if (r[j] < r[min])
				min = j;
		temp = r[min];
		r[min] = r[i];
		r[i] = temp;
	}
	for(i=0;i<=5;i++)
			printf("%2d\n", r[i]);
}
