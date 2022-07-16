#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct segnode{
  int s, e;
  int num;
};
int dfs(vector<vector<int> > &ind, vector<segnode> &arr, int node)
{
  int size = arr.size();
  arr.push_back({size, size, node});
  for (int i = 0; i < ind[node].size(); i++)
  {
    int temp = dfs(ind,arr,ind[node][i]);
    arr[size].e = temp;
  }
  return arr[size].e;
}
void lazy_update(vector<ll> &tree,vector<ll> &lazy,int start,int end,int node){
  if(lazy[node]!=0)
  {
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
    lazy[node] += value;
    lazy_update(tree, lazy, start, end, node);
    return;
  }
  update(tree, lazy, start, (start + end) / 2, node * 2, x, y, value);
  update(tree, lazy, (start + end) / 2 + 1, end, node * 2 + 1, x, y, value);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll query(vector<ll> &tree,vector<ll> &lazy,int start,int end,int node,int index)
{
  lazy_update(tree,lazy,start,end,node);
  if(start==end)
    return tree[node];
  int mid = (start + end) / 2;
  if(index<=mid)
    return query(tree, lazy, start, mid, node * 2, index);
  return query(tree, lazy, mid + 1, end, node * 2 + 1, index);
}
int main()
{
  int n, m;

  cin >> n >> m;

  int tree_size = (int)(ceil(log2(n)));
  vector<ll> tree(1 << (tree_size + 1), 0);
  vector<ll> lazy(1 << (tree_size + 1), 0);
  vector<vector<int> > ind(n + 1, vector<int>(0));
  vector<segnode> arr(1);

  for (int i = 1; i <= n; i++){
    int x;
    cin >> x;
    if(i==1)
      continue;
    ind[x].push_back(i);
  }

  dfs(ind,arr,1);

  vector<int> u(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    u[arr[i].num] = i;
  }
  for (int i = 1; i <= m; i++)
  {
    int a;
    cin >> a;
    if (a == 1)
    {
      int b;
      ll c;
      cin >> b >> c;
      update(tree, lazy, 1, n, 1, arr[u[b]].s, arr[u[b]].e, c);
    }
    else
    {
      int b;
      cin >> b;
      cout << query(tree, lazy, 1, n, 1, u[b]) << "\n";
    }
  }
  return 0;
}