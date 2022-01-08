#include <bits/stdc++.h>
using namespace std;
bool check(string &str){
  vector<bool> v(27, 0);
  v[str[0] - 'a'] = true;
  for (int i = 1; i < str.size(); i++)
  {
    if(str[i-1]==str[i])
      continue;
    if(v[str[i]-'a'])
      return false;
    v[str[i] - 'a'] = true;
  }
  return true;
};
int main()
{
  int n,i,j,k;

  cin >> n;

  int ans = 0;
  for (i = 0; i < n; i++)
  {
    string temp;
    cin >> temp;
    if(check(temp))
      ans++;
  }
  cout << ans;
  return 0;
}