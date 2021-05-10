#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    int n;

    scanf("%d",&n);

    vector<int> arr(n+1,0);
    stack<int> st;
    for(int i=1; i<=n; i++)
        scanf("%d",&arr[i]);
    int i,j,k;
    j=1;
    vector<int> answer(0);
    for(i=1; i<=n; i++)
    {
        st.push(i);
        answer.push_back(1);
        while(!st.empty() && j<=n && arr[j]==st.top())
        {
            st.pop();
            answer.push_back(0);
            j++;
        }
    }
    if(!st.empty())
    {
        printf("NO");
        return 0;
    }
    for(i=0; i<answer.size(); i++)
    {
        if(answer[i]==1)
            printf("+\n");
        else   
            printf("-\n");
    }
    return 0;
}