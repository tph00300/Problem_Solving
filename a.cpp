#include <stdio.h>

int main(void) {
    int num;
   printf("배스킨라빈스 31 게임을 시작합니다.\n");
   printf("컴퓨터 숫자(1, 2, 3 중): 2\n");
   for(int i=2; i<=31;)
   {
        int cnt;
        printf("숫자를 입력(");
        if(i+1<=31)
             printf("%d",i+1);
        if(i+2<=31)
            printf(" ,%d",i+2);
        if(i+3<=31)
            printf(" ,%d",i+3);
        printf(" 중): ");
        scanf("%d",&cnt);
        if(cnt==31)
        {
           printf("컴퓨터가 이겼습니다.\n");
           return 0;
        }
        if(cnt<=31 && cnt<=i+3 && cnt>i)
        {
            i=cnt;
            printf("컴퓨터 숫자(");
            if(i+1<=31)
                printf("%d",i+1);
            if(i+2<=31)
                printf(" ,%d",i+2);
            if(i+3<=31)
                printf(" ,%d",i+3);
            printf(" 중): ");
            if(30<=i+3)
            {
                i=30;
            }
            else if(26<=i+3)
            {
                i=26;
            }
            else if(22<=i+3)
            {
                i=22;
            }
            else if(18<=i+3)
            {
                i=18;
            }
            else if(14<=i+3)
            {
                i=14;
            }
            else if(10<=i+3)
            {
                i=10;
            }
            else if(6<=i+3)
            {
                i=6;
            }
            printf("%d\n",i);
        }
        else
        {
            printf("다시 입력하세요\n");
        }
   }

   return 0;
}