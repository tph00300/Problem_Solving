#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long answer[10];
int main()
{
  long long n;
  long long m = 1;
  int i, j, k;

  scanf("%lld", &n);
  while (n >= m)
  {
    long long cycle = n / (m * 10);
    answer[0] += (cycle - 1 >= 0 ? (cycle - 1) * m : 0);
    for (i = 1; i <= 9; i++)
      answer[i] += cycle * m;
    long long num = (n%(m*10))/m;
    for (i = 0; i < num; i++)
    {
      if(i==0 && cycle==0)
        continue;
      answer[i] += m;
    }
    answer[num] += (n%m)+1;
    m *= 10;
  }
  for (i = 0; i <= 9; i++)
    printf("%lld ", answer[i]);
  return 0;
}