#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;
long long arr[301001],myPow[301001];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  sort(arr + 1, arr + n + 1);
  myPow[0] = 1;
  for (int i = 1; i <= 300000; i++)
  {
    myPow[i] = myPow[i - 1] * 2;
    myPow[i] %= MOD;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans += (((myPow[i - 1] - myPow[n - i] + MOD) % MOD) * arr[i]);
    ans %= MOD;
  }
  cout << ans;
  return 0;
}