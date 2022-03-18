#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct node{
  ll l, d;
};
void tree_init(vector<ll> &tree,vector<ll> &data,int start,int end,int node){
  if(start==end){
    tree[node] = data[start];
    return;
  }
  tree_init(tree, data, start, (start + end) / 2, node * 2);
  tree_init(tree, data, (start + end) / 2 + 1, end, node * 2 + 1);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void lazy_update(vector<ll> &tree,vector<node> &lazy,int start,int end,int node){
  if(lazy[node].d!=0){
    ll num = end - start + 1;
    tree[node] += (ll)(num * (2 * lazy[node].l + (num - 1) * lazy[node].d) / 2);
    if (start != end)
    {
      lazy[node * 2].l += lazy[node].l;
      lazy[node * 2].d += lazy[node].d;
      ll mid = (ll)(end - start + 2) / 2;
      lazy[node * 2 + 1].l += (mid * lazy[node].d) + lazy[node].l;
      lazy[node * 2 + 1].d += lazy[node].d;
    }
  }
  lazy[node] = {0, 0};
}
void update(vector<ll> &tree,vector<node> &lazy,int start,int end,int node,int x,int y){
  lazy_update(tree, lazy, start, end, node);
  if(y<start || end<x)
    return;
  if(x<=start && end<=y){
    lazy[node].d += 1;
    lazy[node].l += (ll)(start - x)+1;
    lazy_update(tree, lazy, start, end, node);
    return;
  }
  update(tree, lazy, start, (start + end) / 2, node * 2, x, y);
  update(tree, lazy, (start + end) / 2 + 1, end, node * 2 + 1, x, y);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll query(vector<ll> &tree,vector<node> &lazy,int start,int end,int node,int index){
  lazy_update(tree, lazy, start, end, node);
  if(start==end)
    return tree[node];
  int mid = (start + end) / 2;
  if(index<=mid)
    return query(tree, lazy, start, mid, node * 2, index);
  else
    return query(tree, lazy, mid + 1, end, node * 2 + 1, index);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int tree_size = (int)(ceil(log2(n)));
  vector<ll> tree(1 << (tree_size + 1), 0);
  vector<node> lazy(1 << (tree_size + 1), {0, 0});
  vector<ll> data(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> data[i];

  tree_init(tree, data, 1, n, 1);

  int m;
  cin >> m;

  for (int i = 1; i <= m; i++)
  {
    int a;
    cin >> a;
    if(a==1){
      int x, y;
      cin >> x >> y;
      update(tree, lazy, 1, n, 1, x, y);
    }else{
      int x;
      cin >> x;
      cout << query(tree, lazy, 1, n, 1, x) << "\n";
    }
  }
  return 0;
}