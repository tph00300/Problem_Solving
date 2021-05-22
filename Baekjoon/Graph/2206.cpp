#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int map[1001][1001];
int ax[5]={0,-1,0,1,0},ay[5]={0,0,-1,0,1};
int main()
{
    int n,m,i,j;

    scanf("%d %d",&n,&m);

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            char temp;
            scanf("%c",&temp);
            if(temp=='1'){
                map[i][j]=1;
            }
            else if(temp=='0'){
                map[i][j]=-1;
            }
        }
    }
    int f=1,s=1;
    vector<int> p;
    while(f<=s)
    {
        f++;
    }
    return 0;
}