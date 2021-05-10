#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n,i,j,k;
    
    scanf("%d",&n);
    
    vector<int> arr(n+1,0);
    vector<int> v(8001,0);
    int sum=0;
    int maxa=-4000;
    int mina=4000;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
        v[arr[i]+4000]++;
        maxa=max(maxa,arr[i]);
        mina=min(mina,arr[i]);
    }
    sort(arr.begin()+1,arr.end());
    printf("%.0f\n",double(sum)/n);
    printf("%d\n",arr[(n+1)/2]);
    vector<int> used;
    int maxused=0;
    for(i=mina+4000; i<=maxa+4000; i++)
    {
        if(maxused<v[i])
        {
            maxused=v[i];
            used.resize(0);
            used.push_back(i);
        }
        else if(maxused==v[i])
        {
            used.push_back(i);
        }
    }
    if(used.size()>1)
    {
        printf("%d\n",used[1]-4000);
    }
    else
    {
        printf("%d\n",used[0]-4000);
    }
    printf("%d",maxa-mina);
    return 0;
}