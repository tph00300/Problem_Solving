#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int testcase;
  int arr[15][15]={0};

  cin >> testcase;

  for (int i = 1; i <= 14; i++)
    arr[0][i] = i;
  for (int i = 1; i <= 14; i++)
    for (int j = 1; j <= 14; j++)
      arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
  for (int t = 1; t <= testcase; t++)
  {
    int k, n;
    cin >> k >> n;
    cout << arr[k][n] << "\n";
  }
  return 0;
}