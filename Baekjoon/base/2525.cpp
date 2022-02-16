#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a, b, c;

  cin >> a >> b >> c;

  b += c;

  if(b>=60)
  {
    a += (b/60);
    b %= 60;
  }
  if(a>=24){
    a %= 24;
  }
  cout << a << " " << b;
  return 0;
}