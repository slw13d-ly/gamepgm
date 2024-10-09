//숫자 자리 수 분리 코드(입력될 숫자를 문자열로 처리)- 낮은 단위부터 출력 
#include <stdio.h>
#include <string.h>
int main(void)
{
  char number[20];
  int length, i;
  printf("금액을 입력하고 Enter>");
  scanf("%s", number);
  length=strlen(number);
  for(i=length;i>=0;i--)
     printf("%c\n", number[i]);
  return 0;
}
