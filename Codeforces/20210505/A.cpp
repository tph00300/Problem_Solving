#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    int testcase,t;

    scanf("%d",&testcase);

    for(t=1; t<=testcase; t++)
    {
        int i,j,k,n;
        scanf("%d",&n);
        vector<int> v(27,0);
        char arr[51]={0};
        
        scanf("%s",arr);
        bool flag=false;
        for(i=0; i<n; i++)
        {
            if(v[arr[i]-'A']==0)
            {
                v[arr[i]-'A']=1;
                while(arr[i]==arr[i+1] && i<n-1)
                {
                    i++;
                }
            }
            else{
                flag=true;
                printf("NO\n");
                break;
            }
        }
        if(flag==false)
            printf("YES\n");
    }
    return 0;
}