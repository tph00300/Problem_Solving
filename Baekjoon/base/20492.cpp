#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  cout << n / 100 * 78 << " " << n / 1000 * 956;
  return 0;
}