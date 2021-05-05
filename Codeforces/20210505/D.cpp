#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    int t,testcase;

    scanf("%d",&testcase);


    vector<int>v;
    for(t=1; t<=testcase; t++)
    {
        int n,i,j; 
        long long answer=0;
        scanf("%d",&n);

        vector<int>v((n+1)*2,0);
        for(i=1; i<=n; i++)
        {
            int a;
            scanf("%d",&a);
            answer+=v[a-i+n];
            v[a-i+n]++;
        }
        printf("%lld\n",answer);
    }
    return 0;
}