#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;

  cin >> n;

  vector<int> arr(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  sort(arr.begin() + 1, arr.end());

  int sum = 0, result = 0;
  
  for (int i = 1; i <= n; i++)
  {
    sum += arr[i];
    result += sum;
  }

  cout << result;

  return 0;
}