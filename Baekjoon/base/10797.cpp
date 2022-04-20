#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n,ans=0;
  cin >> n;

  for (int i = 1; i <= 5; i++)
  {
    int temp;
    cin >> temp;
    if(temp%10==n)
      ans++;
  }
  cout << ans;
  return 0;
}