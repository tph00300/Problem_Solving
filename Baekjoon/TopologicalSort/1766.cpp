#include <bits/stdc++.h>
#define MAX 32001
using namespace std;
int inDegree[MAX],result[MAX];
vector<int> ind[MAX];
priority_queue<int,vector<int>,greater<int> > pq;
int n;
void topologySort()
{
  for (int i = 1; i <= n; i++)
  {
    if(inDegree[i]==0)
      pq.push(i);
  }
  for (int i = 1; i <= n; i++)
  {
    int x = pq.top();
    pq.pop();
    result[i] = x;
    for (int j = 0; j < ind[x].size(); j++)
    {
      int y = ind[x][j];
      if (--inDegree[y]==0)
        pq.push(y);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m;
  cin >> n >> m;

  for (int i = 1; i <= m; i++)
  {
    int x, y;
    cin >> x >> y;
    ind[x].push_back(y);
    inDegree[y]++;
  }
  topologySort();

  for (int i = 1; i <= n; i++)
    cout << result[i] << " ";
  return 0;
}