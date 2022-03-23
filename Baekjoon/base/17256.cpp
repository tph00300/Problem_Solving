#include<bits/stdc++.h>
using namespace std;
struct cake{
  int x, y, z;
};
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cake a, c;
  cin >> a.x >> a.y >> a.z;
  cin >> c.x >> c.y >> c.z;

  cout << c.x - a.z << " " << c.y / a.y << " " << c.z - a.x;
  return 0;
}