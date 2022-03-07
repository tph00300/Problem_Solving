#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  cout << n / 5 + (n % 5 > 0 ? 1 : 0);
  return 0;
}