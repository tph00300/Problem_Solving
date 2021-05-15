#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct data{
    int x,y;
};
void preorder(vector<data>& f,vector<int>& pre,int n)
{
    pre.push_back(n);

    if(f[n].x!=0)
        preorder(f,pre,f[n].x);
    if(f[n].y!=0)
        preorder(f,pre,f[n].y);
}
void inorder(vector<data>& f,vector<int>& in,int n)
{
    if(f[n].x!=0)
        inorder(f,in,f[n].x);
    in.push_back(n);
    if(f[n].y!=0)
        inorder(f,in,f[n].y);
}
void postorder(vector<data>& f,vector<int>& post,int n)
{
    if(f[n].x!=0)
        postorder(f,post,f[n].x);
    if(f[n].y!=0)
        postorder(f,post,f[n].y);
    post.push_back(n);
}
int main()
{
    int n,i,j;

    scanf("%d",&n);

    vector<data> f(n+1,{0,0});
    for(i=1; i<=n; i++)
    {
        char x,y,z;
        scanf(" %c %c %c",&x,&y,&z);
        if(y!='.')
            f[x-64].x=y-64;
        if(z!='.')
            f[x-64].y=z-64;
    }
    vector<int> pre;
    preorder(f,pre,1);
    for(int i=0; i<pre.size(); i++)
        printf("%c",pre[i]+64);
    printf("\n");
    vector<int> in;
    inorder(f,in,1);
    for(int i=0; i<in.size(); i++)
        printf("%c",in[i]+64);
    printf("\n");
    vector<int> post;
    postorder(f,post,1);
    for(int i=0; i<post.size(); i++)
        printf("%c",post[i]+64);
    printf("\n");
    return 0;
}