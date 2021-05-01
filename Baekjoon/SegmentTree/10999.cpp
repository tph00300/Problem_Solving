#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
ll tree_init(vector<ll> &tree,vector<ll> &arr,int node,int start,int end)
{
    if(start==end)
        return tree[node]=arr[start];
    return tree[node]=tree_init(tree,arr,node*2,start,(start+end)/2)+tree_init(tree,arr,node*2+1,(start+end)/2+1,end);  
}
void update_lazy(vector<ll> &tree,vector<ll> &lazy,int node,int start,int end)
{
    if(lazy[node]!=0)
    {
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}
ll query(vector<ll> &tree,vector<ll> &lazy,int node,int start,int end,int x,int y)
{
    update_lazy(tree,lazy,node,start,end);
    if(start > y || end < x)
        return 0;
    if(start >=x && end<=y)
        return tree[node];
    return query(tree,lazy,node*2,start,(start+end)/2,x,y)+query(tree,lazy,node*2+1,(start+end)/2+1,end,x,y);
}
ll tree_change(vector<ll> &tree,vector<ll> &lazy,int node,int start,int end,int x,int y,long long diff)
{
    update_lazy(tree,lazy,node,start,end);
    if(start > y || end < x)
        return tree[node];
    if(start>=x && end<=y)
    {
        tree[node]+=(end-start+1)*diff;
        if(start!=end)
        {
            lazy[node*2]+=diff;
            lazy[node*2+1]+=diff;
        }
        return tree[node];
    }
    return tree[node]=tree_change(tree,lazy,node*2,start,(start+end)/2,x,y,diff)+tree_change(tree,lazy,node*2+1,(start+end)/2+1,end,x,y,diff);
}
int main()
{
    int n,m,k;
    int i;

    scanf("%d %d %d",&n,&m,&k);

    vector<ll> arr(n+1,0);
    int tree_size=(int)(ceil(log2(n)));
    vector<ll> tree(1<<(tree_size+1),0);
    vector<ll> lazy(1<<(tree_size+1),0);
    for(i=1; i<=n; i++)
        scanf("%lld",&arr[i]);
    ll a= tree_init(tree,arr,1,1,n);
    for(i=1; i<=m+k; i++)
    {
        int a,b,c;
        ll d;
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%d %d %lld",&b,&c,&d);
            ll temp=tree_change(tree,lazy,1,1,n,b,c,d);
        }
        if(a==2)
        {
            scanf("%d %d",&b,&c);
            printf("%lld\n",query(tree,lazy,1,1,n,b,c));
        }
    }
    return 0;
}