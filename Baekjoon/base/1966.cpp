#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct data{
    int cnt,x;
};
int main()
{
    int t,testcase;

    scanf("%d",&testcase);

    for(t=1; t<=testcase; t++)
    {
        int n,m,i,j,k;

        scanf("%d %d",&n,&m);

        vector<int> arr(n+1,0);
        queue<data> que;
        priority_queue<int> pq;
        for(i=1; i<=n; i++)
        {
            int a;
            scanf("%d",&a);
            que.push({a,i});
            pq.push(a);
        }
        j=0;
        while(!que.empty() && !pq.empty())
        {
            j++;
            while(que.front().cnt<pq.top())
            {
                data temp=que.front();
                que.pop();
                que.push(temp);
            }
            if(que.front().x==m+1)
            {
                printf("%d\n",j);
                break;
            }
            que.pop();
            pq.pop();
        }
    }
    return 0;
}