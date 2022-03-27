#include <bits/stdc++.h>
#define MAX 10001
using namespace std;
int n, inDegree[MAX],result[MAX],build[MAX];
vector<int> ind[MAX];
queue<int> q;
void topologicalSort(){
  for (int i = 1; i<=n; i++){
    if(inDegree[i]==0)
    {
      q.push(i);
      result[i] = build[i];
    }
  }
  for (int i = 1; i <= n; i++){
    int x = q.front();
    q.pop();
    for (int j = 0; j < ind[x].size(); j++){
      int y = ind[x][j];
      result[y] = max(result[y], result[x] + build[y]);
      if(--inDegree[y]==0)
        q.push(y);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    int t, m;
    cin >> t >> m;
    build[i] = t;
    inDegree[i] = m;
    for (int j = 1; j <= m; j++)
    {
      int temp;
      cin >> temp;
      ind[temp].push_back(i);
    }
  }
  topologicalSort();
  int ans = 0;
  for (int i = 1; i<=n; i++)
    ans = max(ans, result[i]);
  
  cout << ans;
  return 0;
}