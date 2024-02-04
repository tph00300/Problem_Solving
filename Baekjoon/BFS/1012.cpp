#include <bits/stdc++.h>
using namespace std;
int cx[5] = {0, -1, 0, 1, 0}, cy[5] = {0, 0, 1, 0, -1};
void bfs(vector<vector<int> > &mapA, int x, int y,int n,int m)
{
  int f = 0, s = 0;
  vector<int> px, py;

  px.push_back(x);
  py.push_back(y);

  while(f<=s)
  {
    for (int i = 1; i <= 4; i++)
    {
      int tx = cx[i] + px[f], ty = cy[i] + py[f];
      if(tx>0 && ty>0 && tx<=n && ty<=m && mapA[tx][ty]==-1)
      {
        mapA[tx][ty] = 1;
        s++;
        px.push_back(tx);
        py.push_back(ty);
      }
    }
    f++;
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int testcase, t;

  cin >> testcase;

  for (t = 1; t <= testcase; t++)
  {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > mapA(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= k; i++){
      int x, y;
      cin >> x >> y;
      mapA[x + 1][y + 1] = -1;
    }
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++){
        if(mapA[i][j]==-1){
          mapA[i][j] = 1;
          result++;
          bfs(mapA, i, j, n, m);
        }
      }
    }
    cout << result << "\n";
  }
  return 0;
}