#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> result;
vector<int> ind(100001,0);
vector<int> inorder,postorder;
void preorder(int instart,int inend,int poststart,int postend)
{
    if(instart>inend || poststart>postend)
        return;
    result.push_back(postorder[postend]);
    int temp=ind[postorder[postend]];
    int lsize=temp-instart;
    preorder(instart,temp-1,poststart,poststart+lsize-1);
    preorder(temp+1,inend,poststart+lsize,postend-1);
}
int main()
{
    int n;

    scanf("%d",&n);

    inorder.resize(n+1,0);
    postorder.resize(n+1,0);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&inorder[i]);
        ind[inorder[i]]=i;
    }
    for(int i=0; i<n; i++)
        scanf("%d",&postorder[i]);
    preorder(0,n-1,0,n-1);
    for(int i=0; i<result.size(); i++)
        printf("%d ",result[i]);
    return 0;
}