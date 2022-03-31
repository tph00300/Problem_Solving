#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct line{
  int x, y;
};
bool cmp(line a,line b){
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
void update(vector<int> &tree,int start,int end,int node,int index){
  if(start==end){
    tree[node] += 1;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid)
    update(tree, start, mid, node * 2, index);
  else
    update(tree, mid + 1, end, node * 2 + 1, index);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(vector<int> &tree,int start,int end,int node,int x,int y){
  if(y<start || end<x)
    return 0;
  if(x<=start && end<=y)
    return tree[node];
  int num1 = query(tree, start, (start + end) / 2, node * 2, x, y);
  int num2 = query(tree, (start + end) / 2 + 1, end, node * 2 + 1, x, y);
  return num1 + num2;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int tree_size = (int)(ceil(log2(n)));
  vector<int> tree(1 << (tree_size + 1), 0);
  vector<line> arr(m + 1);

  for (int i = 1; i <= m; i++)
  {
    line temp;
    cin >> temp.x >> temp.y;
    arr[i] = temp;
  }
  sort(arr.begin() + 1, arr.end(), cmp);

  ll ans = 0;
  for (int i = 1; i <= m; i++)
  {
    line temp = arr[i];
    ans += (ll)(query(tree, 1, n, 1, temp.y + 1, n));
    update(tree, 1, n, 1, temp.y);
  }
  cout << ans;
  return 0;
}