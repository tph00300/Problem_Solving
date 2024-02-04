#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> u(n+1,0);

  for (int i = 1; i <= n; i++)
    u[i] = i;
  for (int i = 1; i <= m; i++){
    int x, y;
    cin >> x >> y;

    int fx = x;
    while(u[fx]!=fx)
      fx = u[fx];
    int fy = y;
    while(u[fy]!=fy)
      fy = u[fy];
    if(fx>fy)
      u[fx] = fy;
    else
      u[fy] = fx;
  }
  int result = 0;
  for (int i = 1; i <= n; i++){
    if(i==u[i])
      result++;
  }

  cout << result;
  return 0;
}