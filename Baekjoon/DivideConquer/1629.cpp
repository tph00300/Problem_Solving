#include <iostream>
#include <algorithm>
using namespace std;
long long answer(int a,int b, int c)
{   
    if(b==1)
        return a%c;
    long long cnt=answer(a,b/2,c);
    cnt=(cnt*cnt)%c;
    if(b%2==1)
    {
        cnt=(cnt*a)%c;
    }
    return cnt;
}
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);

    printf("%lld",answer(a,b,c));
    return 0;
}