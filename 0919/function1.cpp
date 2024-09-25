//���� �Լ�
//��ī�� ǥ�� �Լ� 
void make_card (trump m_card [])
{
	int i, j;
	char shape [4] [3]={"��", "��", "��","��"};
	for (i=0; i<4; i++)
	{
		for(j=i*13; j<i*13+13; j++)
		{
			m_card[j].order=i;
			strcpy(m_card[j].shape, shape[i]);
			m_card[j].number=j%13+1;
			switch (m_card[j].number)
			{
				case 1:
					m_card[j].number='A';
					break;
				case 11:
					m_card[j].number='J';
					break;
				case 12:
					m_card[j].number='Q';
					break;
				case 13:
					m_card[j].number='K';
					break;
			}
		}
	}
}

//������� ī�� ��� �Լ� 
void display_card (trump m_card [])
{
	int i, count=0;
	for (i=0;i<52;i++)
	{
		printf("%s", m_card [i].shape) ;
		if (10<m_card [i].number)
			printf("%-2c", m_card[i].number) ;
		else
			printf ("%-2d", m_card[i]. number);
		count++;	
		if(1%13+1==13)
		{			
			printf ("\n");
			count=0;
		}
	}
}

//ī�� ���� ���1
for(i=0; i<10; i++)
{
	rnd=rand()%10;
	temp=a[rnd];
	a[rnd]=a[i];
	a[i]=temp;
} 

//ī�� ���� ���2 
for(i=0; i<10; i++)
{
	do
	{
		rnd=rand()%10;
	}while(rand==i);
	temp=a[rnd];
	a[rnd]=a[i];
	a[i]=temp;
} 

//��ī�� ���� �Լ� 
void shuffle_card (trump m_card [])
{
	int i, rnd;
	trump temp;
	srand (time(NULL)); //������ �ʱ�ȭ
	for(i=0; i<52; i++)	
	{
		rnd=rand()%52;
		temp=m_card[rnd];
		m_card[rnd]=m_card[i];
		m_card[i]=temp;
	}
}
