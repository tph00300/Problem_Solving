#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long n, m;
  cin >> n >> m;

  cout << (n + m) * (n - m);
  return 0;
}