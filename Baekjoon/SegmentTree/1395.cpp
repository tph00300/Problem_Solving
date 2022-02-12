#include <bits/stdc++.h>
using namespace std;
void lazy_update(vector<int> &tree,vector<bool> &lazy,int start,int end,int node){
  if(lazy[node]){
    tree[node] = (end - start + 1) - tree[node];
    if(start!=end){
      lazy[node * 2] = !lazy[node * 2];
      lazy[node * 2 + 1] = !lazy[node * 2 + 1];
    }
    lazy[node] = false;
  }
}
void update(vector<int> &tree,vector<bool> &lazy,int start,int end,int node,int x,int y){
  lazy_update(tree, lazy, start, end, node);
  if(y<start || end<x)
    return;
  if(x<=start && end<=y){
    lazy[node] = 1;
    lazy_update(tree, lazy, start, end, node);
    return;
  }
  update(tree, lazy, start, (start + end) / 2, node * 2, x, y);
  update(tree, lazy, (start + end) / 2 + 1, end, node * 2 + 1, x, y);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(vector<int> &tree,vector<bool> &lazy,int start,int end,int node,int x,int y){
  lazy_update(tree, lazy, start, end, node);
  if(y < start || end < x)
    return 0;
  if(x<=start && end<=y)
    return tree[node];
  int num1 = query(tree, lazy, start, (start + end) / 2, node * 2, x, y);
  int num2 = query(tree, lazy, (start + end) / 2+1, end, node * 2 + 1, x, y);
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
  vector<bool> lazy(1 << (tree_size + 1), 0);

  for (int i = 1; i <= m; i++)
  {
    int o, s, t;
    cin >> o >> s >> t;

    if(o==1){
      cout << query(tree, lazy, 1, n, 1, s, t) << "\n";
    }else{
      update(tree, lazy, 1, n, 1, s, t);
    }
  }
  return 0;
}