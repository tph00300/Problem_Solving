#include <iostream>
#include <algorithm>
#include <vector>
#define ml 100001
using namespace std;
int main()
{
    int n,m;

    scanf("%d %d",&n,&m);
    vector<int> arr(n+1,0);

    for(int i=1; i<=n; i++){
        scanf("%d",&arr[i]);
    }
    int sum=0,s=1,e=0,min_length=ml;
    for(int i=1; i<=n; i++)
    {
        e++;
        sum+=arr[i];
        while(sum-arr[s]>=m && s<e){
            min_length=min(e-s+1,min_length);
            sum-=arr[s];
            s++;
        }
        if(sum>=m && s<=e)
        {
            min_length=min(e-s+1,min_length);
        }
    }
    if(min_length==ml || m==0)
    {
        printf("0");
        return 0;
    }
    printf("%d",min_length);
    return 0;
}