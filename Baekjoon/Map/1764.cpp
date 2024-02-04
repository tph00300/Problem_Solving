#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  map<string, bool> mapA;


  for (int i = 1; i <= n; i++)
  {
    string str;
    cin >> str;
    mapA.insert({str, true});
  }
  vector<string> result;
  for (int i = 1; i <= m; i++)
  {
    string str;
    cin >> str;
    if (mapA.find(str)!=mapA.end())
      result.push_back(str);
  }
  cout << result.size() << "\n";
  sort(result.begin(), result.end());
  for (int i = 0; i < result.size(); i++)
    cout << result[i] << "\n";
  return 0;
}