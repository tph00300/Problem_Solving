#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
int dist[MAX],inDegree[MAX],n;
vector<int> ind[MAX];
queue<int> q;
void topologicalSort(){
  for (int i = 1; i <= n; i++)
  {
    if(inDegree[i]==0){
      q.push(i);
      dist[i] = 1;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    int x = q.front();
    q.pop();
    for (int j = 0; j < ind[x].size(); j++){
      int y = ind[x][j];
      dist[y] = max(dist[y], dist[x] + 1);
      if (--inDegree[y] == 0)
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
    int x, y;
    cin >> x >> y;
    ind[x].push_back(y);
    inDegree[y]++;
  }
  topologicalSort();
  for (int i = 1; i <= n; i++)
    cout << dist[i] << " ";
  return 0;
}