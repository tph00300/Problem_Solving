#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    int t,testcase;

    scanf("%d",&testcase);

    for(t=1; t<=testcase; t++)
    {
        long long n,i,j,k;
        long long answer=0;
        scanf("%lld",&n);
        for(i=1; i<=9; i++)
        {
            long long a=i;
            while(a<=n)
            {
                answer+=1;
                a*=10;
                a+=i;
            }
        }
        printf("%lld\n",answer);
    }
    return 0;
}