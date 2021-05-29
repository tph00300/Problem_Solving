#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
vector<vector<vector<int> > > v(1001,vector<vector<int> >(1001,vector<int>(2,-1)));
vector<vector<int> > map(1001,vector<int>(1001));
struct data{
    int x,y;
    bool v;
};
int x[5]={0,-1,0,1,0},y[5]={0,0,1,0,-1};
int n,m;
queue<data> q;
int bfs()
{
    int i,j,k;
    v[1][1][0]=1;
    q.push({1,1,false});
    while(!q.empty())
    {
        data temp=q.front();
        for(i=1; i<=4; i++)
        {
            int tx=temp.x+x[i];
            int ty=temp.y+y[i];
            if(tx<=0 || ty<=0 || tx>n || ty>m)
                continue;
            if(temp.v==false){ // 벽을 부수지 않은 상태
                if(map[tx][ty]==1){ // 벽을 부술려고하는 경우
                    if(v[tx][ty][1]==-1 || (v[tx][ty][1]>v[temp.x][temp.y][0]+1)){
                        v[tx][ty][1]=v[temp.x][temp.y][0]+1;
                        q.push({tx,ty,true});
                    }
                }
                else{  // 벽을 부수지 않을려는 경우
                    if(v[tx][ty][0]==-1 || (v[tx][ty][0]>v[temp.x][temp.y][0]+1)){
                        v[tx][ty][0]=v[temp.x][temp.y][0]+1;
                        q.push({tx,ty,false});
                    }
                }
            }
            else{ //벽을 이미 부순 상태
                if(map[tx][ty]==0){
                    if(v[tx][ty][1]==-1 || (v[tx][ty][1]>v[temp.x][temp.y][1]+1)){
                        v[tx][ty][1]=v[temp.x][temp.y][1]+1;
                        q.push({tx,ty,true});
                    }
                }
            }
        }
        q.pop();
    }
    if(v[n][m][0]==-1 && v[n][m][1]==-1)
        return -1;
    if(v[n][m][0]!=-1 && v[n][m][1]==-1)
        return v[n][m][0];
    if(v[n][m][0]==-1 && v[n][m][1]!=-1)
        return v[n][m][1];
    int result=min(v[n][m][0],v[n][m][1]);
    return result;
}
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    
    for(i=1; i<=n; i++)
    {
        char temp[m+1];
        
        scanf("%s",temp);
        for(j=1; j<=m; j++)
        {
            if(temp[j-1]=='0'){
                map[i][j]=0;
            }
            else if(temp[j-1]=='1'){
                map[i][j]=1;
            }
        }
    }
    printf("%d",bfs());
    return 0;
}