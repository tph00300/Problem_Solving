#include <bits/stdc++.h>
using namespace std;
pair<int,int> dp[400101];
int arr[5101];
int main()
{
  int n, w;

  cin >> w >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  sort(arr + 1, arr + n + 1);
  for (int i = 1; i < n; i++)
  {
    for (int j = i + 1; j <= n; j++){
      int temp = arr[i] + arr[j];
      dp[temp].first = i;
      dp[temp].second = j;
    }
  }
  for (int i = 1; i < n; i++){
    for (int j = i + 1; j <= n; j++){
      int temp = arr[i] + arr[j];
      if (!(w-temp >= 0 && w-temp <= 400000))
        continue;
      int x = dp[w - temp].first;
      int y = dp[w - temp].second;
      if(x==0 || y==0)
        continue;
      if (x != i && y != i && x != j && y != j)
      {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}