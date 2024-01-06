#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;

  cin >> n;

  int end=1, result = 1;
  while(n>end){
    result++;
    end += (result - 1) * 6;
  }
  cout << result;
  return 0;
}