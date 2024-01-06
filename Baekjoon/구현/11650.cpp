#include <bits/stdc++.h>
using namespace std;
struct coordinate{
  int x, y;
};
bool coordinate_compare(coordinate a,coordinate b){
  return a.x < b.x || (a.x == b.x && a.y < b.y);
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<coordinate> arr(n + 1);

  for (int i = 1; i <= n; i++){
    cin >> arr[i].x >> arr[i].y;
  }
  sort(arr.begin() + 1, arr.end(), coordinate_compare);

  for (int i = 1; i <= n; i++){
    cout << arr[i].x << " " << arr[i].y << "\n";
  }
  return 0;
}