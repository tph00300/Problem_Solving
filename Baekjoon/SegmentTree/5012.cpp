#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void update(vector<int> &tree,int start,int end,int node,int index,int value){
  if(start==end)
  {
    tree[node]+=value;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid)
    update(tree, start, mid, node * 2, index, value);
  else
    update(tree, mid + 1, end, node * 2 + 1, index, value);
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

  int n;
  cin >> n;

  int tree_size = (int)(ceil(log2(n)));
  vector<int> ltree(1 << (tree_size + 1), 0);
  vector<int> rtree(1 << (tree_size + 1), 0);
  vector<int> arr(n + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    update(rtree, 1, n, 1, arr[i], 1);
  }
  ll ans = 0;
  update(rtree, 1, n, 1, arr[1], -1);
  for (int i = 2; i < n; i++)
  {
    update(ltree, 1, n, 1, arr[i - 1], 1);
    update(rtree, 1, n, 1, arr[i], -1);

    int num1 = query(ltree,1,n,1,arr[i]+1,n);
    int num2 = query(rtree, 1, n, 1, 1, arr[i] - 1);
    ans += (ll)(num1)*(ll)(num2);
  }
  cout << ans;
  return 0;
}