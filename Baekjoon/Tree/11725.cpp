#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void dfs(vector<vector<int> > &ind,vector<int> &v,vector<int>& answer,int num)
{   
    int i;
    v[num]=1;
    for(i=0; i<ind[num].size(); i++)
    {
        if(v[ind[num][i]]==0)
        {
            answer[ind[num][i]]=num;
            dfs(ind,v,answer,ind[num][i]);
        }
    }
}
int main()
{  
    int n;

    scanf("%d",&n);

    vector<int> v(n+1,0),answer(n+1,0);
    vector<vector<int> > ind(n+1,vector<int>(0));

    for(int i=0; i<n-1; i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        ind[x].push_back(y);
        ind[y].push_back(x);
    }
    dfs(ind,v,answer,1);
    for(int i=2; i<=n; i++)
    {
        printf("%d\n",answer[i]);
    }
    return 0;
}