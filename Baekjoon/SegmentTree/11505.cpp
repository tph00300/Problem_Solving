#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MOD 1000000007
using namespace std;
void tree_init(vector<long long> &tree,vector<long long> &arr,int node,int start,int end){
    if(start==end){
        tree[node]=arr[start];
        return;
    }
    tree_init(tree,arr,node*2,start,(start+end)/2);
    tree_init(tree,arr,node*2+1,(start+end)/2+1,end);
    tree[node]=((tree[node*2]%MOD)*(tree[node*2+1]%MOD))%MOD;
}
long long query(vector<long long> &tree,int node,int start,int end,int x,int y)
{
    // printf("%d %d %d %d\n",start,end,x,y);
    if(start > y || end < x)
        return 1;
    if(start >=x && end <=y)
        return tree[node];
    long long num1=query(tree,node*2,start,(start+end)/2,x,y);
    long long num2=query(tree,node*2+1,(start+end)/2+1,end,x,y);
    return (num1*num2)%MOD;
}
void tree_change(vector<long long> &tree,vector<long long> &arr,int node,int start,int end,int x,int y)
{
    printf("%d %d %d %d\n",start,end,x,y);
    if(start==end)
    {
        tree[node]=y;
        return;
    }
    if(x<=(start+end)/2)
    {
        tree_change(tree,arr,node*2,start,(start+end)/2,x,y);
        tree[node]=((tree[node*2]%MOD)*(tree[node*2+1]%MOD))%MOD;
    }else{
        tree_change(tree,arr,node*2+1,(start+end)/2+1,end,x,y);
        tree[node]=((tree[node*2]%MOD)*(tree[node*2+1]%MOD))%MOD;
    }
}
int main()
{
    int n,m,k;
    int i,j;

    scanf("%d %d %d",&n,&m,&k);

    vector<long long> arr(n+1,0);
    int tree_size=(int)(ceil(log2(n)));
    vector<long long> tree(1<<(tree_size+1),0);
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&arr[i]);
    }
    tree_init(tree,arr,1,1,n);
    for(i=1; i<=m+k; i++)
    {
        int command,x,y;

        scanf("%d %d %d",&command,&x,&y);
        if(command==1)
        {
            tree_change(tree,arr,1,1,n,x,y);
            arr[x]=y;
        }
        else if(command==2)
        {
            long long num=query(tree,1,1,n,x,y);
            printf("%lld\n",num);
        }
    }
    return 0;
}