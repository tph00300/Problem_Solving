#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t,testcase;

    scanf("%d",&testcase);

    for(t=1; t<=testcase; t++)
    {
        int n,i,j,k;

        scanf("%d",&n);

        if(n==1)
        {
            printf("1\n");
            continue;
        }
        if(n==2)
        {
            printf("-1\n");
            continue;
        }
        if(n==3)
        {
            printf("2 9 7\n4 6 3\n1 8 5\n");
            continue;
        }
        if(n%2==0)
        {
            int m=2;
            for(i=1; i<=n/2; i++)
            {
                for(j=1; j<=n; j++)
                {
                    printf("%d ",m);
                    m+=2;
                }
                printf("\n");
            }
            m=1;
            for(i=n/2+1; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                {
                    printf("%d ",m);
                    m+=2;
                }
                printf("\n");
            }
        }
        else
        {
            int m=2;
            for(i=1; i<=n/2; i++)
            {
                for(j=1; j<=n; j++)
                {
                    printf("%d ",m);
                    m+=2;
                }
                printf("\n");
            }
            for(i=(n*n)-n+1; i<=n*n; i+=2)
                printf("%d ",i);
            for(i=(n*n)-n+2; i<=n*n; i+=2)
                printf("%d ",i);
            printf("\n");
            m=1;
            for(i=1; i<=n/2; i++)
            {
                for(j=1; j<=n; j++)
                {
                    printf("%d ",m);
                    m+=2;
                }
                printf("\n");
            }
        }
    }
    return 0;
}