#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void update(vector<ll> &tree,int start,int end,int node,int index,ll value){
  if(start == end){
    tree[node] = value;
    return;
  }
  int mid = (start + end) / 2;
  if (index <= mid){
    update(tree, start, mid, node * 2, index, value);
  }else{
    update(tree, mid + 1, end, node * 2 + 1, index, value);
  }
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll query(vector<ll> &tree,int start,int end,int node,int x,int y){
  if(y<start || end<x)
    return 0;
  if(x<=start && end<=y)
    return tree[node];
  ll num1 = query(tree, start, (start + end) / 2, node * 2, x, y);
  ll num2 = query(tree, (start + end) / 2 + 1, end, node * 2 + 1, x, y);
  return num1 + num2;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;

  cin >> n >> m;

  int tree_size = (int)(ceil(log2(n)));
  vector<ll> tree(1 << (tree_size + 1), 0);

  for (int i = 1; i <= m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    if(a==0){
      if(b>c)
        swap(b, c);
      cout << query(tree, 1, n, 1, b, c) << "\n";
    }else{
      update(tree, 1, n, 1, b, (ll)(c));
    }
  }
  return 0;
}