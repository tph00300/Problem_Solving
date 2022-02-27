#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int arr[6] = {1, 1, 2, 2, 2, 8};

  for (int i = 0; i < 6; i++)
  {
    int a;
    cin >> a;

    cout << arr[i] - a << " ";
  }
  return 0;
}