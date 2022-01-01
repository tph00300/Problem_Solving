#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;

  cin >> n;

  stack<pair<int, int> > st;
  long long ans = 0;
  for (int i = 1; i <= n; i++)
  {
    int temp;
    cin >> temp;
    while(!st.empty() && st.top().first<temp){
      ans += st.top().second;
      st.pop();
    }
    if(st.empty()){
      st.push({temp, 1});
    }
    else if(st.top().first==temp){
      pair<int, int> top=st.top();
      ans += top.second;
      st.pop();
      if(!st.empty()){
        ans++;
      }
      top.second++;
      st.push(top);
    }
    else{
      st.push({temp, 1});
      ans++;
    }
  }
  cout << ans;
  return 0;
}