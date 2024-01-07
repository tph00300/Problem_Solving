#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while(1){
    long long arr[4];
    cin >> arr[1] >> arr[2] >> arr[3];
    if(arr[1]+arr[2]+arr[3]==0)
      return 0;
    sort(arr + 1, arr + 4);
    if(arr[3]*arr[3]==arr[1]*arr[1]+arr[2]*arr[2])
      cout << "right\n";
    else
      cout << "wrong\n";
  }
  return 0;
}