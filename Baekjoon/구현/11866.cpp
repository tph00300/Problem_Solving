#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int k, n;

  cin >> k >> n;

  vector<int> arr(k + 1, 0);
  for (int i = 1; i <= k; i++)
    arr[i] = i;
  cout << "<";
  int p = 0;
  for (int i = 1; i <= k; i++)
  {
    int temp = 0;
    while (temp<n){
      p++;
      if (p>k)
        p=1;
      if (arr[p] != 0)
        temp++;
    }
    arr[p] = 0;
    cout << p;
    if(i<k)
      cout << ", ";
    else
      cout << ">";
  }
  return 0;
}