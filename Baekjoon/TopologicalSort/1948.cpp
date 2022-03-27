#include <bits/stdc++.h>
#define MAX 10001
using namespace std;
struct path{
  int x, value;
};
int n, m, inDegree[MAX],v[MAX];
int dist[MAX],pathNum;
vector<path> ind[MAX],backInd[MAX];
queue<int> q,p;
void topologocialSort(){
  for (int i = 1;i <=n; i++)
  {
    int x = q.front();
    q.pop();
    for (int j = 0; j < ind[x].size(); j++){
      int y = ind[x][j].x;
      int value = ind[x][j].value;
      dist[y] = max(dist[y], dist[x] + value);
      if (--inDegree[y] == 0)
        q.push(y);
    }
  }
}
void bfs(){
  while(!p.empty()){
    int x = p.front();
    p.pop();
    for (int i = 0; i < backInd[x].size(); i++){
      int y = backInd[x][i].x;
      int value = backInd[x][i].value;
      if (dist[x] - value == dist[y]){
        pathNum++;
        if(!v[y]){
          v[y] = 1;
          p.push(y);
        }
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= m; i++){
    int x, y, v;
    cin >> x >> y >> v;
    ind[x].push_back({y, v});
    backInd[y].push_back({x, v});
    inDegree[y]++;
  }
  int a, b;
  cin >> a >> b;
  q.push(a);
  topologocialSort();
  v[b] = 1;
  p.push(b);
  bfs();
  cout << dist[b] << "\n"
       << pathNum;
  return 0;
}