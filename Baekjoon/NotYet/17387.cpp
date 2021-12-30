#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct vec{
  long long x1, y1, x2, y2;
};
int ccw(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3)
{
  long long temp = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
  if(temp>0){
    return 1;
  }else if(temp<0){
    return -1;
  }
  return 0;
}
int crossCheck(vec x,vec y){
  pair<long long, long long> a = {x.x1, x.y1};
  pair<long long, long long> b = {x.x2, x.y2};
  pair<long long, long long> c = {y.x1, y.y1};
  pair<long long, long long> d = {y.x2, y.y2};
  int temp_a = ccw(a.first, a.second, b.first, b.second, c.first, c.second)*ccw(a.first, a.second, b.first, b.second, d.first, d.second);
  int temp_b = ccw(c.first,c.second,d.first,d.second,a.first,a.second)*ccw(c.first,c.second,d.first,d.second,b.first,b.second);
  if(temp_a==0 && temp_b==0){
    if(a>b)
      swap(a, b);
    if(c>d)
      swap(c, d);
    return c <= b && a <= d;
  }
  return temp_a <= 0 && temp_b <= 0;
}
int main()
{
  vec a, b;

  scanf("%lld %lld %lld %lld", &a.x1, &a.y1, &a.x2, &a.y2);
  scanf("%lld %lld %lld %lld", &b.x1, &b.y1, &b.x2, &b.y2);

  printf("%d", crossCheck(a, b));
  return 0;
}