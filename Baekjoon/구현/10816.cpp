#include <bits/stdc++.h>
using namespace std;
int arr[20000001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int temp;
    cin >> temp;
    arr[temp+10000000]++;
  }
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++){
    int temp;
    cin >> temp;
    cout << arr[temp + 10000000] << " ";
  }
  return 0;
}