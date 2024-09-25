//사용된 함수 
//▼옥타브에 따른 음계 별 주파수를 출력하는 함수
void print_frequency(int octave)
{
	double do_scale=32.7032;
	double ratio=pow(2., 1/12.), temp; 
	int i;
	temp=do_scale*pow(2, octave-1) ;
	printf("&d옥타브 :",octave);
	for (i=0; i<12; i++)
	{
		printf ("%4ld", (unsigned long)(temp+0.5)) ;
		temp*=ratio;
	}
	printf("\n");
}

//▼옥타브에 따른 음계별 주파수를 변환하는 함수
int calc_frequency(int octave, int inx) 
{
	double do_scale=32.7032;
	double ratio=pow(2., 1/12.), temp; 
	int i;
	temp=do_scale*pow(2, octave-1) ;
	for(i=0; i<inx; i++)
	{
		temp=(int)(temp+0.5) ;
		temp*=ratio;
	}
	return(int)temp;
}

//▼숫자 키에 따라 음계의 주파수를 스피커로 출력 함수
void practice_piano (void) 
{
	int index[]={0, 2, 4, 5, 7, 9, 11, 12};
	int freq[8], code, i;
	for(i=0; i<8; i++)
		freq[i]=calc_frequency(4, index[i]);
	do
	{
		code=getch();
		if('1'<=code && code<='8')
		{
			code-=49;
			Beep(freq [code], 300);
		}
	}while(code!=27);
}
