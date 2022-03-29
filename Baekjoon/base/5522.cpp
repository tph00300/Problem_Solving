#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int ans=0;

  for (int i = 1; i <= 5; i++)
  {
    int a;
    cin >> a;
    ans += a;
  }
  cout << ans;
  return 0;
}