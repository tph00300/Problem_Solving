#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct node{
  int x, y;
  int num;
};
int dfs(vector<node> &arr,vector<vector<int> > &ind,int now){
  int w = arr.size();
  arr.push_back({w, w, now});
  for (int i = 0; i < ind[now].size(); i++)
  {
    arr[w].y=dfs(arr, ind, ind[now][i]);
  }
  return arr[w].y;
};
void lazy_update(vector<ll> &tree, vector<ll> &lazy, int start, int end, int node)
{
  if(lazy[node]>0){
    tree[node] += (end - start + 1) * lazy[node];
    if(start!=end){
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
  }
  lazy[node] = 0;
};
void update(vector<ll> &tree, vector<ll> &lazy, int start, int end, int node, int x, int y, int value)
{
  lazy_update(tree, lazy, start, end, node);
  if (y < start || end < x)
    return;
  if (x <= start && end <= y)
  {
    lazy[node] += (ll)(value);
    lazy_update(tree, lazy, start, end, node);
    return;
  }
  update(tree, lazy, start, (start + end) / 2, node * 2, x, y, value);
  update(tree, lazy, (start + end) / 2 + 1, end, node *2 +1, x, y, value);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
};
ll tree_query(vector<ll> &tree, vector<ll> &lazy, int start, int end, int node, int index)
{
  lazy_update(tree, lazy, start, end, node);
  if(start==end)
    return tree[node];
  int mid = (start + end) / 2;
  if(index<=mid)
    return tree_query(tree, lazy, start, mid, node * 2, index);
  else
    return tree_query(tree, lazy, mid + 1, end, node * 2 + 1, index);
};
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int tree_size = (int)(ceil(log2(n)));
  vector<ll> tree(1 << (tree_size + 1), 0);
  vector<ll> lazy(1 << (tree_size + 1), 0);
  vector<vector<int> > ind(n + 1, vector<int>(0));
  vector<node> arr(1);
  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    if(x==-1)
      continue;
    ind[x].push_back(i);
  }
  dfs(arr, ind, 1);
  vector<int> u(n + 1, 0); 
  for (int i = 1; i <= n; i++)
    u[arr[i].num] = i;

  for (int i = 1; i <= m; i++)
  {
   int query;
    cin >> query;
    if (query == 1)
    {
      int x, value;
      cin >> x >> value;
      update(tree, lazy, 1, n, 1, arr[u[x]].x, arr[u[x]].y, value);
    }else{
      int x;
      cin >> x;
      cout << tree_query(tree, lazy, 1, n, 1, u[x]) << "\n";
    }
  }
  return 0;
}