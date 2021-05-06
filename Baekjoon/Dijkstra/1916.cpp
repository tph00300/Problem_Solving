#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2147483647
using namespace std;
struct edge{
    int to,cost;
    edge() {}
    edge(int t,int c){
        to=t;
        cost=c;
    }
    bool operator<(const edge &o) const {
        return cost > o.cost;
    }
};
priority_queue<edge> pq;
vector<int> dist;
void dijkstra(vector<vector<edge> > &adj,int start,int n)
{
    dist[start]=0;
    pq.push(edge(start,0));

    while(!pq.empty())
    {
        edge cnt= pq.top();
        pq.pop();
        if(dist[cnt.to]<cnt.cost)
            continue;
        for(int i=0; i<adj[cnt.to].size(); i++)
        {
            edge next=adj[cnt.to][i];
            if(dist[next.to]>next.cost+dist[cnt.to])
            {
                dist[next.to]=next.cost+dist[cnt.to];
                pq.push(edge(next.to,next.cost+dist[cnt.to]));
            }
        }
    }
    return;
}
int main()
{
    int n,m,i,j,k;

    scanf("%d %d",&n,&m);

    vector<vector<edge> > adj(n+1);
    dist.resize(n+1,INF);
    for(i=1; i<=m; i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        adj[x].push_back(edge(y,z));
    }
    int start,end;
    scanf("%d %d",&start,&end);
    dijkstra(adj,start,n);
    printf("%d",dist[end]);
    return 0;
}