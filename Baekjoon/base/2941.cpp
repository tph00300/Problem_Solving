#include <bits/stdc++.h>
using namespace std;
int main()
{
  string word,croatia[8]={"c=","c-","dz=","d-","lj","nj","s=","z="};
  string temp;

  cin >> word;
  int ans = 0;
  for (int i = 0; i < word.size(); i++)
  {
    for (int j = 0; j < 8; j++)
    {
      int m = croatia[j].size();
      if(i-m+1<0)
        continue;
      temp = word.substr(i - m+1, m);
      if (temp == croatia[j])
      {
        ans -= (m - 1);
        break;
      }
    }
    ans++;
  }
  cout << ans;
  return 0;
}