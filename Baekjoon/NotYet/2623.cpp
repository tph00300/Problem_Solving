#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> ind[1001],ans;
int n, m;
int v[1001];
int main()
{
  int i,j,k;

  scanf("%d %d", &n, &m);

  for (i = 1; i <= m; i++)
  {
    int temp,pre;
    scanf("%d", &temp);
    scanf("%d", &pre);
    for (j = 1; j < temp; j++)
    {
      int now;
      scanf("%d", &now);
      ind[pre].push_back(now);
      v[now]++;
      pre = now;
    }
  }
  queue<int> q;

  for (i = 1; i <= n; i++)
  {
    if(v[i]==0)
      q.push(i);
  }
  while (!q.empty())
  {
    int temp = q.front();
    q.pop();
    ans.push_back(temp);
    for (i = 0; i < ind[temp].size(); i++)
    {
      v[ind[temp][i]]--;
      if (v[ind[temp][i]] == 0)
        q.push(ind[temp][i]);
    }
  }
  if(ans.size()!=n){
    printf("%d", 0);
    return 0;
  }
  for (i = 0; i < n; i++)
  {
    printf("%d\n", ans[i]);
  }
  return 0;
}