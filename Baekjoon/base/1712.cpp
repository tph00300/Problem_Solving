#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll a, b, c;

  cin >> a >> b >> c;

  if(b>=c)
  {
    cout << -1;
    return 0;
  }
  ll ans = a / (c - b);
  if(ans*(c-b)<=a)
    ans++;
  cout << ans;
  return 0;
}