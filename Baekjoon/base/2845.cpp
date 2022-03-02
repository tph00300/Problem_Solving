#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int num = n * m;

  vector<int> arr(5 + 1, 0);

  for (int i = 1; i <= 5; i++){
    cin >> arr[i];
  }
  for (int i = 1; i <= 5; i++)
    cout << arr[i]-num << " ";
  return 0;
}