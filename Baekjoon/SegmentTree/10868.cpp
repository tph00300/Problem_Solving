#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
void tree_init(vector<int> &tree,vector<int> &arr,int node,int start,int end)
{
    if(start==end)
    {
        tree[node]=start;
        return;
    }
    tree_init(tree,arr,node*2,start,(start+end)/2);
    tree_init(tree,arr,node*2+1,(start+end)/2+1,end);
    if(arr[tree[node*2]]<arr[tree[node*2+1]])
    {
        tree[node]=tree[node*2];
    }
    else{
        tree[node]=tree[node*2+1];
    }
}
int query(vector<int> &tree,vector<int> &arr,int node,int start,int end,int x,int y)
{
    if(start > y || end < x)
        return -1;
    if(start >= x && end <=y)
        return tree[node];
    int num1=query(tree,arr,node*2,start,(start+end)/2,x,y);
    int num2=query(tree,arr,node*2+1,(start+end)/2+1,end,x,y);
    if(num1==-1)
    {
        return num2;
    }else if(num2==-1)
    {
        return num1;
    }
    if(arr[num1]<arr[num2])
    {
        return num1;
    }
    return num2;
    
}
int main()
{
    int n,m;
    int i,j,k;
    
    scanf("%d %d",&n,&m);

    int tree_size=(int)(ceil(log2(n)));
    vector<int> tree(1<<(tree_size+1),0);
    vector<int> arr(n+1,0);

    for(i=1; i<=n; i++)
        scanf("%d",&arr[i]);
    tree_init(tree,arr,1,1,n);
    for(i=1; i<=m; i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",arr[query(tree,arr,1,1,n,x,y)]);
    }
    return 0;
}