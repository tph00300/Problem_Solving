#include <bits/stdc++.h>
using namespace std;
int main()
{
  int alpha[9] = {-1, 2, 5, 8, 11, 14, 18, 21, 25};
  string str;

  cin >> str;

  int ans = 0,j;
  for (int i = 0; i < str.size(); i++)
  {
    int temp = str[i] - 'A';
    for (j = 0; j < 9; j++)
    {
      if(alpha[j]>=temp)
        break;
    }
    ans += (j + 2);
  }
  cout << ans;
  return 0;
}