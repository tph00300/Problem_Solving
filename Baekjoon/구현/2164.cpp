#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  queue<int> q;

  for (int i = 1; i <= n; i++)
    q.push(i);

  while(q.size()>1){
    q.pop();
    int temp = q.front();
    q.pop();
    q.push(temp);
  }
  cout << q.front();
  return 0;
}