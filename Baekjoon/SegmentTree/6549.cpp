#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
void tree_init(vector<int> &tree,vector<int> &arr,int start,int end,int node)
{
    if(start==end){
        tree[node]=start;
    }
    else{
        tree_init(tree,arr,start,(start+end)/2,node*2);
        tree_init(tree,arr,(start+end)/2+1,end,node*2+1);
        if(arr[tree[node*2]]<arr[tree[node*2+1]]){
            tree[node]=tree[node*2];}
        else{
            tree[node]=tree[node*2+1];}
    }
}
int query(vector<int> &tree,vector<int> &arr,int start,int end,int node,int x,int y)
{
    if(start>y || end<x){
        return -1;}
    if(start>=x && end<=y){
        return tree[node];}
    int num1=query(tree,arr,start,(start+end)/2,node*2,x,y);
    int num2=query(tree,arr,(start+end)/2+1,end,node*2+1,x,y);
    if(num1==-1){
        return num2;}
    else if(num2==-1){
        return num1;
    }
    if(arr[num1]<arr[num2])
        return num1;
    return num2;
}
long long longest_arr(vector<int>&tree,vector<int>&arr,int start,int end)
{
    int n=arr.size();
    int num=query(tree,arr,1,n-1,1,start,end);
    long long area=(long long)(end-start+1)*arr[num];
    if(start<num)
        area=max(area,longest_arr(tree,arr,start,num-1));
    if(num<end)
        area=max(area,longest_arr(tree,arr,num+1,end));
    return area;
}
int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n==0) return 0;
        vector<int> arr(n+1,0);
        int i,j,k;
        for(i=1; i<=n; i++)
            scanf("%d",&arr[i]);
        int tree_size=(int)(ceil(log2(n)));
        vector<int> segment(1 << (tree_size+1),0);
        tree_init(segment,arr,1,n,1);
        printf("%lld\n",longest_arr(segment,arr,1,n));
    }
    return 0;
}