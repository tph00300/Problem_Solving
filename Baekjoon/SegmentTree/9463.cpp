#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct edge{
  int x, y;
};
bool cmp_edge(edge a,edge b){
  return a.x < b.x;
}
void update(vector<int> &tree, int start, int end, int node, int index)
{
  if(start==end){
    tree[node] = 1;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid)
    update(tree, start, mid, node * 2, index);
  else
    update(tree, mid + 1, end, node * 2 + 1, index);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(vector<int> &tree,int start,int end,int node,int x, int y){
  if(y<start || end<x || x>y)
    return 0;
  if(x<=start && end<=y)
    return tree[node];
  return query(tree, start, (start + end) / 2, node * 2, x, y) + query(tree, (start + end) / 2 + 1, end, node * 2 + 1, x, y);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int testcase, t;
  cin >> testcase;

  for (int t = 1; t <= testcase; t++){
    int n;
    cin >> n;

    int tree_size = (int)(ceil(log2(n)));
    vector<int> tree(1 << (tree_size + 1), 0);
    vector<edge> arr(n + 1, {0, 0});

    for (int i = 1; i <= n; i++)
    {
      int a;
      cin >> a;
      arr[a].x = i;
    }
    for (int i = 1; i <= n; i++)
    {
      int a;
      cin >> a;
      arr[a].y = i;
    }
    sort(arr.begin() + 1, arr.end(), cmp_edge);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
      ans += (ll)(query(tree, 1, n, 1, arr[i].y + 1, n));
      update(tree, 1, n, 1, arr[i].y);
    }
    cout << ans << "\n";
  }
  return 0;
}