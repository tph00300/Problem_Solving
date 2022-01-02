#include <bits/stdc++.h>
using namespace std;
struct point{
  long long x, y;
}v[100100];
bool cmp_y(point a, point b){
  return a.y < b.y || (a.y == b.y && a.x < b.x);
}
long long ccw(point a,point b, point c){
  return (a.x * b.y + b.x * c.y + c.x * a.y) - (a.x * c.y + b.x * a.y + c.x * b.y);
}
bool cmp_ccw(point a, point b){ 
  long long temp = ccw(v[1], a, b);
  if(temp!=0)
    return temp > 0;
  return a.y < b.y || (a.y == b.y && a.x < b.x);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  stack<point> st;
  int n;

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> v[i].x >> v[i].y;
  
  sort(v + 1, v + n + 1, cmp_y);
  sort(v + 2, v + n + 1, cmp_ccw);
  st.push(v[1]);
  st.push(v[2]);

  for (int i = 3; i <= n; i++)
  {
    while (st.size() >= 2)
    {
      point f, s;
      s = st.top();
      st.pop();
      f = st.top();
      if (ccw(f, s, v[i]) > 0)
      {
         st.push(s);
         break;
       }
     }
    st.push(v[i]);
  }
  cout << st.size();
  return 0;
}
