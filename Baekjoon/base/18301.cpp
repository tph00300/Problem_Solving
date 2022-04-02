#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  cin >> a >> b >> c;

  cout << (a + 1) * (b + 1) / (c + 1) - 1;
  return 0;
}