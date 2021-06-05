#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2147483647
using namespace std;
int main()
{
    int n;

    scanf("%d",&n);

    vector<pair<int,int> > arr(n+1,{INF,0});

    arr[1]={1,1};
    for(int i=1; i<=n; i++)
    {
        if(i*3<=n){
            if(arr[i*3].first>arr[i].first+1)
            {
                arr[i*3].first=arr[i].first+1;
                arr[i*3].second=i;
            }
        }
        if(i*2<=n){
            if(arr[i*2].first>arr[i].first+1)
            {
                arr[i*2].first=arr[i].first+1;
                arr[i*2].second=i;
            }
        }
        if(i+1<=n){
            if(arr[i+1].first>arr[i].first+1)
            {
                arr[i+1].first=arr[i].first+1;
                arr[i+1].second=i;
            }
        }
    }
    printf("%d\n",arr[n].first-1);
    int temp=n;
    while(temp!=1)
    {
        printf("%d ",temp);
        temp=arr[temp].second;
    }
    printf("1");
    return 0;
}