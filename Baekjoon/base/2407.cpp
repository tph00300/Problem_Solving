#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
string map[101][101];
string bigadd(string a,string b)
{
    string result;
    int sum=0;
    while(!a.empty() || !b.empty() || sum)
    {
        if(!a.empty())
        {
            sum+=a.back()-'0';
            a.pop_back();
        }
        if(!b.empty())
        {
            sum+=b.back()-'0';
            b.pop_back();
        }
        result.push_back((sum%10)+'0');
        sum/=10;
    }
    reverse(result.begin(),result.end());
    return result;
}
int main()
{
    int i,j;

    for(i=1; i<=100; i++)
    {
        char temp[11]={0,};
        map[i][i]='1';
        map[i][1]=to_string(i);
        map[i][i-1]=to_string(i);
    }
    for(i=3; i<=100; i++)
    {
        for(j=2; j<=i-2; j++)
        {
            map[i][j]=bigadd(map[i-1][j],map[i-1][j-1]);
        }
    }
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%s",map[n][m].c_str());
    return 0;
}