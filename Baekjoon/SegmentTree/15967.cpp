#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void tree_init(vector<ll> &tree,vector<ll> &data,int start,int end,int node){
  if(start==end){
    tree[node] = data[start];
    return;
  }
  tree_init(tree, data, start, (start + end) / 2, node * 2);
  tree_init(tree, data, (start + end) / 2 + 1, end, node * 2 + 1);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void lazy_update(vector<ll> &tree,vector<ll> &lazy, int start,int end,int node){
  if(lazy[node]!=0){
    tree[node] += (end - start + 1) * lazy[node];
    if(start!=end){
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
  }
  lazy[node] = 0;
}
void update(vector<ll> &tree,vector<ll> &lazy,int start,int end,int node,int x,int y,ll value){
  lazy_update(tree, lazy, start, end, node);
  if(y<start || end<x)
    return;
  if(x<=start && end<=y){
    lazy[node]+=value;
    lazy_update(tree, lazy, start, end, node);
    return;
  }
  update(tree, lazy, start, (start + end) / 2, node * 2, x, y, value);
  update(tree, lazy, (start + end) / 2 + 1, end, node * 2 + 1, x, y, value);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll query(vector<ll> &tree,vector<ll> &lazy,int start,int end,int node,int x,int y){
  lazy_update(tree, lazy, start, end, node);
  if(y<start || end<x)
    return 0;
  if(x<=start && end<=y)
    return tree[node];
  ll num1 = query(tree, lazy, start, (start + end) / 2, node * 2, x, y);
  ll num2 = query(tree, lazy, (start + end) / 2 + 1, end, node * 2 + 1, x, y);
  return num1 + num2;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n,q1,q2;

  cin >> n >> q1 >> q2;
  int tree_size = (int)(ceil(log2(n)));
  vector<ll> tree(1 << (tree_size + 1), 0);
  vector<ll> lazy(1 << (tree_size + 1), 0);
  vector<ll> arr(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  tree_init(tree, arr, 1, n, 1);

  for (int i = 1; i <= q1 + q2; i++)
  {
    int q;
    cin >> q;
    if(q==1){
      int x, y;
      cin >> x >> y;
      cout << query(tree, lazy, 1, n, 1, x, y) << "\n";
    }
    else
    {
      int s, e;
      ll l;
      cin >> s >> e >> l;
      update(tree, lazy, 1, n, 1, s, e, l);
    }
  }
  return 0;
}