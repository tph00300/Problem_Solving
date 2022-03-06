#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct gold{
  ll x, y, value;
  int wy;
};
struct node{
  ll l, r, value, all;
};
bool cmp_x(gold a, gold b)
{
  return a.x < b.x || (a.x == b.x && a.y < b.y);
};
bool cmp_y(gold a,gold b){
  return a.y < b.y || (a.y == b.y && a.x < b.x);
};
void update(vector<node> &tree,int start,int end,int node,int index,ll value){
  if(start==end){
    tree[node].l += value;
    tree[node].r += value;
    tree[node].value += value;
    tree[node].all += value;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid)
    update(tree, start, mid, node * 2, index, value);
  else
    update(tree, mid + 1, end, node * 2 + 1, index, value);
  tree[node].l = max(tree[node * 2].l, tree[node * 2].all + tree[node * 2 + 1].l);
  tree[node].r = max(tree[node * 2 + 1].r, tree[node * 2 + 1].all + tree[node * 2].r);
  tree[node].all = tree[node * 2].all + tree[node * 2 + 1].all;
  tree[node].value = max(tree[node].l, max(tree[node].r, max(tree[node * 2].r + tree[node * 2 + 1].l,max(tree[node*2].value,tree[node*2+1].value))));
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<gold> arr(n + 1);
  vector<ll> ys(1);
  for (int i = 1; i <= n; i++)
  {
    ll a, b, c;
    cin >> a >> b >> c;

    arr[i] = {a, b, c, 0};
  }
  sort(arr.begin() + 1, arr.end(), cmp_y);
  ys.push_back(arr[1].y);
  arr[1].wy = 1;
  for (int i = 2; i <= n; i++)
  {
    if(arr[i].y!=arr[i-1].y)
      ys.push_back(arr[i].y);
    arr[i].wy = ys.size() - 1;
  }
  int m = ys.size()-1;
   
  int tree_size = (int)(ceil(log2(m)));

  sort(arr.begin() + 1, arr.end(), cmp_x);

  ll max_value = 0;
  for (int i = 1; i <= n; i++){
    if(i>1 && arr[i-1].x==arr[i].x)
      continue;
    vector<node> tree(1 << (tree_size + 1), {0, 0, 0, 0});
    for (int j = i; j<=n; j++){
      update(tree, 1, m, 1, arr[j].wy, arr[j].value);
      if(j<n && arr[j].x==arr[j+1].x)
        continue;
      max_value = max(max_value, tree[1].value);
    }
  }
  cout << max_value;
  return 0;
}