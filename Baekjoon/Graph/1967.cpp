#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct data{
    int node,value;
};
vector<vector<data> > g;
int n;
vector<int> bfs(int start)
{
    vector<int> dis(n+1,-1);
    vector<int> pf(0);
    vector<int> v(n+1,0);
    int f=0,s=0;
    pf.push_back(start);
    v[start]=1;
    dis[pf[f]]=0;
    while(f<=s)
    {
        for(int i=0; i<g[pf[f]].size(); i++)
        {
            if(v[g[pf[f]][i].node]==0)
            {
                v[g[pf[f]][i].node]=1;
                dis[g[pf[f]][i].node]=dis[pf[f]]+g[pf[f]][i].value;
                s++;
                pf.push_back(g[pf[f]][i].node);
            }
        }
        f++;
    }
    return dis;
}
int main()
{
    int i,j;

    scanf("%d",&n);

    g.resize(n+1);
    for(i=1; i<n; i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    vector<int> first(n+1,0);
    first=bfs(1);
    int maxa=0,maxi=0;
    for(i=1; i<=n; i++)
    {
        if(maxa<first[i])
        {
            maxa=first[i];
            maxi=i;
        }
    }
    vector<int> second(n+1,0);

    second=bfs(maxi);
    for(i=1; i<=n; i++)
    {
        maxa=max(maxa,second[i]);
    }
    printf("%d",maxa);
    return 0;
}