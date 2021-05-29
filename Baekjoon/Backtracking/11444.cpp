#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
const long long mod = 1000000007LL;
using namespace std;
map <long long, long long> v;
long long fibo(long long num)
{
    if(num<=0){
        return 0;
    } else if(num==1||num==2){
        return 1;
    }else if(v.count(num)>0){
        return v[num];
    }else{
        if(num%2==0)
        {
            long long temp1=fibo(num/2);
            long long temp2=fibo((num/2)-1);
            v[num]=((2LL*temp2+temp1)*temp1)%mod;
            return v[num];
        }else{
            long long temp1=fibo((num+1)/2);
            long long temp2=fibo((num+1)/2-1);
            v[num]=((temp1*temp1)+(temp2*temp2))%mod;
            return v[num];
        }
    }
}
int main()
{
    long long n;
    scanf("%lld",&n);

    printf("%lld",fibo(n));
    return 0;
}