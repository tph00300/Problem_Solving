#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int testcase, t;
  cin >> testcase;

  for (t = 1; t <= testcase; t++){
    int n;

    cin >> n;
    vector<int> arr(n + 1, 0);

    for (int i = 1; i <= n; i++)
      cin >> arr[i];

    int s = 1, e = n;
    int ans = 0, nowWeight = 0;
    
    while(s<=e){
      if(arr[s]<arr[e])
      {
        if(nowWeight<=arr[s]){
          ans++;
          nowWeight = arr[s];
        }
        s++;
      }
      else
      {
        if(nowWeight<=arr[e]){
          ans++;
          nowWeight = arr[e];
        }
        e--;
      }
    }
    cout << "Case #" << t << ": " << ans << "\n";
  }
  return 0;
}