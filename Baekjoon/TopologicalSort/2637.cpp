#include <bits/stdc++.h>
#define MAX 101
using namespace std;
struct path{
  int x, value;
};
int result[MAX], dist[MAX];
int n, inDegree[MAX];
vector<path> ind[MAX];
queue<int> q;
void topologicalsort(){
  q.push(n);
  dist[n] = 1;
  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    if (ind[x].size() == 0)
      result[x] = dist[x];
    for (int i = 0; i < ind[x].size(); i++)
    {
      int y = ind[x][i].x;
      int value = ind[x][i].value;
      dist[y] += value * dist[x];
      if (--inDegree[y]==0)
        q.push(y);
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
    int x, y, value;
    cin >> x >> y >> value;

    ind[x].push_back({y, value});
    inDegree[y]++;
  }
  topologicalsort();

  for (int i = 1; i < n; i++)
  {
    if(result[i]>0)
      cout << i << " " << result[i] << "\n";
  }
  return 0;
}