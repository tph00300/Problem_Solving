#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct location{
    int x,y;
};
int map[1001][1001];
vector<vector<vector<int> > > v(1001,vector<vector<int> >(1001,vector<int>(2,-1))); 
int n,m;
int x[5]={0,-1,0,1,0},y[5]={0,0,1,0,-1};
queue<location> p;
int bfs()
{
    p.push({1,1});
    if(map[1][1]!=1)
        v[1][1][0]=0;
    v[1][1][1]=0;
    while(!p.empty())
    {
        for(int i=1; i<=4; i++)
        {
            location temp=p.front();
            int tx=temp.x+x[i];
            int ty=temp.y+y[i];
            if(tx<=0 || ty<=0 || tx>n || ty>m)
                continue;
            if(map[tx][ty]==0 && v[temp.x][temp.y][0]!=-1 && (v[tx][ty][0]>v[temp.x][temp.y][0]+1 || v[tx][ty][0]==-1))
            {
                p.push({tx,ty});
                v[tx][ty][0]=v[temp.x][temp.y][0]+1;
            }
            if(map[tx][ty]==0 && v[temp.x][temp.y][1]!=-1 && (v[tx][ty][1]>v[temp.x][temp.y][1]+1 || v[tx][ty][1]==-1))
            {
                p.push({tx,ty});
                v[tx][ty][1]=v[temp.x][temp.y][1]+1;
            }
            if(map[tx][ty]==1 && v[temp.x][temp.y][0]!=-1 && (v[tx][ty][1]>v[temp.x][temp.y][0]+1 || v[tx][ty][1]==-1))
            {
                p.push({tx,ty});
                v[tx][ty][1]=v[temp.x][temp.y][0]+1;
            }
        }
        p.pop();
    }
    int result=max(v[n][m][0],v[n][m][1]);
    if(result!=-1)
        result++;
    return result;
}
int main()
{
    int i,j;
    scanf("%d %d ",&n,&m);

    for(i=1; i<=n; i++)
    {  
        char temp[m+1];
        scanf("%s",temp);
        for(j=1; j<=m; j++)
        {
            if(temp[j-1]=='0'){
                map[i][j]=0;
            }
            else{
                map[i][j]=1;
            }
        }
    }
    printf("%d",bfs());
    return 0;
}