#include <bits/stdc++.h>
#define MAX 30001
typedef long long ll;
using namespace std;
struct rect{
  int x, y1, y2;
  bool se; // false==좌측 true==우측
};
bool cmp_rect(rect a,rect b){
  return a.x < b.x;
}
void update(vector<pair<int,int> > &tree,int start,int end,int node,int x,int y,int value){
  if(y<start || end<x)
    return;
  if(x<=start && end<=y){
    tree[node].second += value;
  }else{
    update(tree, start, (start + end) / 2, node * 2, x, y, value);
    update(tree, (start + end) / 2 + 1, end, node * 2 + 1, x, y, value);
  }
  if(tree[node].second){
    tree[node].first = (end - start + 1);
  }else{
    if(start==end)
      tree[node].first = 0;
    else
      tree[node].first = tree[node * 2].first + tree[node * 2 + 1].first;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int tree_size = (int)(ceil(log2(MAX)));
  vector<pair<int, int> > tree(1 << (tree_size + 1), {0, 0});
  vector<rect> arr(1);

  for (int i = 1; i <= n; i++)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    arr.push_back({x1, y1 + 1, y2, 0});
    arr.push_back({x2, y1 + 1, y2, 1});
  }

  sort(arr.begin() + 1, arr.end(), cmp_rect);


  ll ans = 0;
  for (int i = 1; i < arr.size(); i++)
  {
    // printf("%d %d %d %d\n", arr[i].x, arr[i].y1, arr[i].y2, arr[i].se ? -1 : 1);
    if(i > 1){
      ll temp = (ll)(arr[i].x) - (ll)(arr[i - 1].x);
      ans += temp * (ll)(tree[1].first);
    }
    update(tree, 1, MAX, 1, arr[i].y1, arr[i].y2, arr[i].se ? -1 : 1);
  }
  cout << ans;
  return 0;
}