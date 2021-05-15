#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector<bool> v;
vector<int> arr;
void dfs(int num,int cnt)
{
    if(cnt==m)
    {
        for(int i=0; i<m; i++)
            printf("%d ",arr[i]);
        printf("\n");
        return;
    }
    for(int i=num; i<=n; i++)
    {
        if(v[i]==0)
        {
            v[i]=1;
            arr.push_back(i);
            dfs(i+1,cnt+1);
            arr.pop_back();
            v[i]=0;
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    v.resize(n+1,false);
    dfs(1,0);
    return 0;
}