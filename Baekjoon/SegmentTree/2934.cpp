#include <bits/stdc++.h>
#define MAX 100001
typedef long long ll;
using namespace std;
void lazy_update(vector<int> &tree,vector<int> &lazy,int start,int end,int node){
  if(lazy[node]!=0){
    tree[node] += (end - start + 1) * lazy[node];
    if(start!=end)
    {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
  }
  lazy[node] = 0;
}
void update(vector<int> &tree,vector<int> &lazy,int start,int end,int node,int x,int y,int value){
  // printf("%d %d %d %d %d\n", start, end, node, x, y);
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
int query(vector<int> &tree,vector<int> &lazy,int start,int end,int node,int index){
  lazy_update(tree, lazy, start, end, node);
  if (start == end)
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

  int tree_size=(int)(ceil(log2(MAX)));
  vector<int> tree(1 << (tree_size + 1), 0);
  vector<int> lazy(1 << (tree_size + 1), 0);

  for (int i = 1; i <= n; i++)
  {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    int num = query(tree, lazy, 1, MAX, 1, x);
    ans += num;
    update(tree, lazy, 1, MAX, 1, x, x, -num);
    num = query(tree, lazy, 1, MAX, 1, y);
    ans += num;
    update(tree, lazy, 1, MAX, 1, y, y, -num);
    update(tree, lazy, 1, MAX, 1, x+1, y-1,1);
    cout << ans << "\n";
  }
  return 0;
}