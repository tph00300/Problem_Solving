#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
vector<int> arr(41,0);
map<int,int> mp;
int n,m,half;
long long answer;
void left_count(int idx,int sum)
{
    if(idx==half)
    {
        mp[sum]++;
        return;
    }
    left_count(idx+1,sum);
    left_count(idx+1,sum+arr[idx]);
}
void right_count(int idx,int sum)
{
    if(idx==n+1)
    {
        answer+=mp[m-sum];
        return;
    }
    right_count(idx+1,sum);
    right_count(idx+1,sum+arr[idx]);
}
int main()
{
    scanf("%d %d",&n,&m);

    for(int i=1; i<=n; i++)
        scanf("%d",&arr[i]);
    half=n/2+1;
    left_count(1,0);
    right_count(half,0);
    if(m==0)
        answer--;
    printf("%lld\n",answer);
    return 0;
}