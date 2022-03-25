#include <bits/stdc++.h>
#define MAX 1000
using namespace std;
int build[MAX],result[MAX];
int inDegree[MAX];
vector<int> ind[MAX];
queue<int> q;
int n;
void topologySort()
{
  for (int i = 1; i <= n; i++)
  {
    if(inDegree[i]==0){
      q.push(i);
      result[i] = build[i];
    }
  }
  for (int i = 1; i <= n; i++){
    int x = q.front();
    q.pop();
    for (int j = 0; j < ind[x].size(); j++)
    {
      int y = ind[x][j];
      result[y] = max(result[y], result[x] + build[y]);
      if (--inDegree[y] == 0){
        q.push(y);
      }
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
    int a;
    cin >> a;
    build[i] = a;
    while (1)
    {
      int b;
      cin >> b;
      if(b==-1)
        break;
      ind[b].push_back(i);
      inDegree[i]++;
    }
  }
  topologySort();
  for (int i = 1; i <= n; i++)
    cout << result[i] << "\n";
  return 0;
}