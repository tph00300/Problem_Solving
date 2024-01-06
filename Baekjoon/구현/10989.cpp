#include <bits/stdc++.h>
using namespace std;
int arr[10001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++){
    int temp;
    cin >> temp;
    arr[temp]++;
  }
  for (int i = 1; i <= 10000; i++)
    for (int j = 1; j <= arr[i]; j++)
      cout << i << "\n";
  return 0;
}