#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  map<string, int> mapA;
  map<int, string> mapB;

  for (int i = 1; i <= n; i++){
    string str;
    cin >> str;
    mapA.insert({str, i});
    mapB.insert({i, str});
  }

  for (int i = 1; i <= m; i++)
  {
    string str;
    cin >> str;
    int temp;
    if (str[0] >= '0' && str[0] <= '9'){
      temp = stoi(str);
      cout << mapB.find(temp)->second << "\n";
    }else{
      cout << mapA.find(str)->second << "\n";
    }
  }
  return 0;
}