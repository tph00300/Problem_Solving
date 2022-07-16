#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct point{
  ll x, y;
};
struct vect{
  point p1, p2;
  ll w;
}line[2501];
int ccw(point p1,point p2,point p3){
  ll ans = (p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y);
  if (ans > 0)
    return 1;
  else if (ans < 0)
    return -1;
  else
    return 0;  
}
int comp(point a,point b){
  if (a.x == b.x)
    return (a.y <= b.y);
  else
    return (a.x <= b.x);
}
int isCross(vect a,vect b){
  int ab = ccw(a.p1, a.p2, b.p1) * ccw(a.p1, a.p2, b.p2);
  int ba = ccw(b.p1, b.p2, a.p1) * ccw(b.p1, b.p2, a.p2);
  int isCross;
  if (ab == 0 && ba == 0)
  {
    if(!comp(a.p1,a.p2))
      swap(a.p1,a.p2);
    if(!comp(b.p1,b.p2))
      swap(b.p1, b.p2);
    return comp(b.p1, a.p2) && comp(a.p1, b.p2);
  }
  else{
    return (ab <= 0 && ba <= 0);
  }
}
bool cmp(vect a,vect b){
  int cross = isCross(a, b);
  int ans=0;
  if (cross)
    ans = a.w > b.w;
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;

  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> line[i].p1.x >> line[i].p1.y >> line[i].p2.x >> line[i].p2.y >> line[i].w;
    ans += line[i].w;
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = i + 1; j <= n; j++)
    {
      if(isCross(line[i],line[j]))
        ans += min(line[i].w,line[j].w);
    }
  }
  cout << ans;
  return 0;
}