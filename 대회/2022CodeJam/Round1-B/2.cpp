#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct test{
  ll value, where;
};
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int testcase, t;
  cin >> testcase;

  for (int t = 1; t <= testcase; t++)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<test> > dp(n + 1, vector<test>(2,{0,0}));

    for (int i = 1; i <= n; i++)
    {
      vector<ll> temp(m + 1, 0);
      for (int j = 1; j <= m; j++)
        cin >> temp[j];
      sort(temp.begin() + 1, temp.end());
      ll sum = temp[m] - temp[1];
      dp[i][0].where = temp[1];
      dp[i][1].where = temp[m];
      dp[i][0].value = min(abs(dp[i - 1][0].where - dp[i][1].where) + dp[i - 1][0].value, abs(dp[i - 1][1].where - dp[i][1].where) + dp[i - 1][1].value) + sum;
      dp[i][1].value = min(abs(dp[i - 1][0].where - dp[i][0].where) + dp[i - 1][0].value, abs(dp[i - 1][1].where - dp[i][0].where) + dp[i - 1][1].value)+sum;
    }
    ll ans = min(dp[n][0].value, dp[n][1].value);
    cout << "Case #" << t << ": " << ans << "\n";
  }
  return 0;
}