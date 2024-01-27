#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  
  cin >> n;
  
  if(n==0){
    cout << "0";
    return 0;
  }
  int cutline = round(n * 0.15);

  vector<int> arr(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  
  sort(arr.begin() + 1, arr.end());

  double sum = 0.0;
  for (int i = cutline + 1; i <= n - cutline; i++)
    sum += arr[i];
  
  cout << round(sum / (n - cutline * 2));
  return 0;
}