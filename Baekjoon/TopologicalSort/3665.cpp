#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int testcase, t;
  cin >> testcase;

  for (t = 1; t <= testcase; t++){
    int n, m;
    cin >> n;
    vector<int> arr(n + 1, 0);
    vector<int> inDegree(n + 1, 0);
    vector<vector<int> > ind(n + 1, vector<int>(n + 1, 0));
    vector<int> result;
    queue<int> q;
    for (int i = 1; i <= n; i++)
      cin >> arr[i];
    for (int i = n; i >= 1; i--){
      for (int j = i-1; j >= 1; j--){
        ind[arr[i]][arr[j]] = 1;
        inDegree[arr[j]]++;
      }
    }
    cin >> m;
    for (int i = 1; i <= m; i++){
      int x, y;
      cin >> x >> y;
      if(ind[x][y]==1){
        ind[x][y] = 0;
        ind[y][x] = 1;
        inDegree[y]--;
        inDegree[x]++;
      }else{
        ind[x][y] = 1;
        ind[y][x] = 0;
        inDegree[y]++;
        inDegree[x]--;
      }
    }
    bool question = 0, impossible = 0;
    for (int i = 1; i <= n; i++){
      if(inDegree[i]==0)
        q.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
      if(q.empty()){
        impossible = 1;
        break;
      }
      int x = q.front();
      q.pop();
      result.push_back(x);
      int count = 0;
      for (int j = 1; j <= n; j++)
      {
        if(!ind[x][j])
          continue;
        int y = j;
        if (--inDegree[y]==0){
          count++;
          q.push(y);
        }
      }
      if(count>1)
        question = 1;
    }
    if(impossible)
      cout << "IMPOSSIBLE";
    else if(question)
      cout << "?"; 
    else{
      for (int i = n; i >= 1; i--)
        cout << result[i - 1] << " ";
    }
    cout << "\n";
  }
  return 0;
}