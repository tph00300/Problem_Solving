#include <bits/stdc++.h>
using namespace std;
int sum[1001];
bool check(int num)
{
  vector<int> div;
  while(num>0)
  {
    int temp = num % 10;
    div.push_back(temp);
    num /= 10;
  }
  if(div.size()<=2)
    return true;
  for (int i = 1; i < div.size() - 1; i++)
  {
    if(div[i-1]-div[i] != div[i]-div[i+1])
      return false;
  }
  return true;
}
int main()
{
  for (int i = 1; i <= 1000; i++)
  {
    sum[i] = sum[i - 1];
    bool temp = check(i);
    if (temp)
      sum[i]++;
  }
  int n;

  cin >> n;

  cout << sum[n];
  return 0;
}