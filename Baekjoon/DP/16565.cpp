#define MOD 10007
#include <bits/stdc++.h>
using namespace std;
int nck[53][53];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n,i,j,k,ans=0;
  cin >> n;

  for (i = 0; i <= 52; i++)
  {
    nck[i][0] = 1;
    nck[i][i] = 1;
    for (j = 1; j < i; j++){
      nck[i][j] = nck[i - 1][j - 1] + nck[i - 1][j];
      nck[i][j] %= MOD;
    }
  }
  for (i = 4; i <= n; i+=4){
    int temp = (nck[13][i / 4] * nck[52 - i][n - i])%MOD;
    if((i/4)%2==1)
      ans += temp;
    else
      ans -= temp;
    ans %= MOD;
  }
  if(ans<0)
    ans += MOD;
  cout << ans;
  return 0;
}