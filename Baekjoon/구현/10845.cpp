#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;

  cin >> n;

  queue<int> q;
  for(int i = 1; i <= n; i++)
  {
    string s;
    int temp;
    cin >> s;
    if(s=="push"){
      cin >> temp;
      q.push(temp);
    }else if(s=="pop"){
      if(q.empty())
        cout << "-1\n";
      else{
        cout << q.front() << "\n";
        q.pop();
      }
    }else if(s=="size")
      cout << q.size() << "\n";
    else if(s=="empty")
      cout << q.empty() << "\n";
    else if(s=="front"){
      temp = q.empty() ? -1 : q.front();
      cout << temp << "\n";
    }
    else if(s=="back"){
      temp = q.empty()?-1:q.back();
      cout << temp << "\n";
    }
  }
  return 0;
}