#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector<int> arr;
void making(vector<int> &cnt,vector<int>&v)
{
    if(cnt.size()==m)
    {
        for(int i=0; i<m; i++)
            printf("%d ",cnt[i]);
        printf("\n");
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(!v[i])
        {
            v[i]=1;
            cnt.push_back(arr[i]);
            making(cnt,v);
            cnt.pop_back();
            v[i]=0;
        }
    }
    return;
}
int main()
{
    int i,j,k;

    scanf("%d %d",&n,&m);
    
    for(i=1; i<=n; i++)
    {
        int x;
        scanf("%d",&x);
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    vector<int> v(n+1,0);
    vector<int> cnt;
    making(cnt,v);
    return 0;
}