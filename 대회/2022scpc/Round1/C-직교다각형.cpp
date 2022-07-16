#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct point{
  int x, y;
};
bool cmp_x(point a,point b){
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool cmp_y(point a,point b){
  return a.y < b.y || (a.y == b.y && a.x < b.x);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int testcase, t;
  cin >> testcase;

  for (t = 1; t <= testcase; t++)
  {
    int n;
    cin >> n;
    vector<point> px(n + 1), py(n + 1);
    for (int i = 1; i <= n; i++)
    {
      cin >> px[i].x >> px[i].y;
      py[i] = px[i];
    }
    sort(px.begin() + 1, px.end(), cmp_x);
    sort(py.begin() + 1, py.end(), cmp_y);
    int errorx = 0, errory = 0;
    int tx=px[1].x,ix=1;
    for (int i = 2; i <= n; i++){
      if (tx == px[i].x)
        ix++;
      else
      {
        if (ix % 2 == 1){
          errorx = tx;
          break;
        }
        tx = px[i].x;
        ix = 1;
      }
    }
    if(ix%2==1)
      errorx = tx;
    int ty = py[1].y, iy = 1;
    for (int i = 2; i <= n; i++){
      if(ty==py[i].y){
        iy++;
      }else{
        if(iy%2==1){
          errory = ty;
          break;
        }
        ty = py[i].y;
        iy = 1;
      }
    }
    if(iy%2==1)
      errory = ty;
    if (errorx != 0 && errory != 0){
      for (int i = 1; i <= n; i++){
        if(px[i].x==errorx && px[i].y==errory){
          px.erase(px.begin() + i);
          break;
        }
      } 
      for (int i = 1; i <= n; i++){
        if(py[i].x==errorx && py[i].y==errory){
          py.erase(py.begin() + i);
          break;
        }
      }
      n--;
    }
    ll sum = 0;
    for (int i = 1; i <= n; i += 2){
      sum += ll(px[i + 1].y - px[i].y);
      sum += ll(py[i + 1].x - py[i].x);
    }
    cout << "Case #" << t << "\n";
    cout << sum << "\n";
  }
  return 0;
}