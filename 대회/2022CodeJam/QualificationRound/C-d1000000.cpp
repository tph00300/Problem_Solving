#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int testcase;
  cin >> testcase;

  for (int t = 1; t <= testcase; t++)
  {
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);

    for (int i = 1; i <= n;i++)
      cin >> arr[i];
    sort(arr.begin() + 1, arr.end());

    int ans = 0;
    for (int i = 1; i <= n; i++)
      if(ans+1<=arr[i])
        ans++;
    cout << "Case #" << t << ": " << ans << "\n";
  }
  return 0;
}