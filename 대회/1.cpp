#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    vector<int> arr(3, 0);
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr.begin(), arr.end());
    if (arr[0] % 2)
    {
      if(arr[1]%2){
        cout << "B" << "\n";
      }
      else{
        if (arr[2] % 2)
        { // 1 2 3
          cout << "B" << "\n";
        }
        else
        {
          cout << "R" << "\n";
        }
      }
    }
    else
    {
      if(arr[1]%2){
        if(arr[2]%2){
          cout << "B" << "\n"; // 2 3 3
        }else{
          cout << "R" << "\n";
        }
      }else{
        cout << "R" << "\n"; // 2 2 2
      }
    }
  }
  return 0;
}