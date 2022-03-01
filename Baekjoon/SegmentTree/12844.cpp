#include <bits/stdc++.h>
using namespace std;
void lazy_update(vector<int> &tree,vector<int> &lazy,int node,int start,int end){
  if(lazy[node]){
    if((end-start+1)%2)
      tree[node] ^= lazy[node];

    if(start!=end){
      lazy[node * 2] ^= lazy[node];
      lazy[node * 2 + 1] ^= lazy[node];
    }
    lazy[node] = 0;
  }
}
void tree_init(vector<int> &tree,vector<int> &data,int start,int end,int node){
  if(start==end){
    tree[node] = data[start];
    return;
  }
  tree_init(tree, data, start, (start + end) / 2, node * 2);
  tree_init(tree, data, (start + end) / 2 + 1, end, node * 2 + 1);
  tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}
void update(vector<int> &tree,vector<int> &lazy,int start,int end,int node,int x,int y,int value){
  lazy_update(tree, lazy, node, start, end);
  if (y < start || end < x)
    return;
  if(x<=start && end<=y){
    lazy[node] ^= value;
    lazy_update(tree, lazy, node, start, end);
    return;
  }
  update(tree, lazy, start, (start + end) / 2, node*2, x, y, value);
  update(tree, lazy, (start + end) / 2 + 1, end, node * 2 + 1, x, y, value);
  tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}
int query(vector<int> &tree,vector<int> &lazy,int start,int end,int node,int x,int y){
  lazy_update(tree, lazy, node, start, end);
  if (y < start || end < x)
    return 0;
  if(x<=start && end<=y)
    return tree[node];

  int num1 = query(tree, lazy, start, (start + end) / 2, node * 2, x, y);
  int num2 = query(tree, lazy, (start + end) / 2 + 1, end, node * 2 + 1, x, y);
  return num1 ^ num2;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int tree_size = (int)(ceil(log2(n)));
  vector<int> tree(1 << (tree_size + 1), 0);
  vector<int> lazy(1 << (tree_size + 1), 0);
  vector<int> arr(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  tree_init(tree, arr, 1, n, 1);

  int m;
  cin >> m;

  for (int i = 1; i <= m; i++)
  {
    int a;
    cin >> a;
    if(a==1)
    {
      int b, c, d;
      cin >> b >> c >> d;
      b++, c++;
      update(tree, lazy, 1, n, 1, b, c, d);
    }else{
      int b, c;
      cin >> b >> c;
      b++, c++;
      cout << query(tree, lazy, 1, n, 1, b, c) << "\n";
    }
  }
  return 0;
}