#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<int> arr(n + 1, 0);
  vector<int> v(8001, 0);

  double sum = 0.0;
  int minNum=4000,maxNum=-4000;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    sum += arr[i];
    maxNum = max(maxNum, arr[i]);
    minNum = min(minNum, arr[i]);
    v[arr[i] + 4000]++;
  }
  sort(arr.begin() + 1, arr.end());
  int maxUsed = 0;
  vector<int> used;
  for (int i = 0; i <= 8000; i++){
    if(v[i]>0){
      if(maxUsed<v[i]){
        maxUsed = v[i];
        used.resize(0);
        used.push_back(i - 4000);
      }else if(maxUsed==v[i]){
        maxUsed = v[i];
        used.push_back(i - 4000);
      }
    }
  }

  cout << round(sum / (double)n)+0.0 << "\n";
  cout << arr[(n + 1) / 2] << "\n";
  if(used.size()>1)
    cout << used[1] << "\n";
  else
    cout << used[0] << "\n";
  cout << maxNum - minNum << "\n";
  return 0;
}