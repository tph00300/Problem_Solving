#include <bits/stdc++.h>
using namespace std;
void tree_init(vector<int> &tree,int start,int end,int node){
  if(start==end){
    tree[node] = 1;
    return;
  }
  tree_init(tree, start, (start + end) / 2, node * 2);
  tree_init(tree, (start + end) / 2 + 1, end, node * 2 + 1);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void update(vector<int> &tree,int start,int end,int node,int index){
  if(start==end){
    tree[node] = 0;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid)
    update(tree, start, (start + end) / 2, node * 2, index);
  else
    update(tree, (start + end) / 2 + 1, end, node * 2 + 1, index);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(vector<int> &tree, int start, int end, int node, int x, int y){
  if(y<start || end<x || y<x)
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
  vector<int> tree(1 << (tree_size + 1), 0);
  vector<int> u(n + 1, 0);

  tree_init(tree, 1, n, 1);

  for (int i = 1; i <= n; i++)
  {
    int temp;
    cin >> temp;
    u[temp] = i;
  }
  int l = 1, r = n;
  bool flag = true;
  while(l<=r)
  {
    if(flag){
      cout << query(tree, 1, n, 1, 1, u[l] - 1) << "\n";
      update(tree, 1, n, 1, u[l]);
      l++;
      flag = false;
    }else{
      cout << query(tree, 1, n, 1, u[r] + 1, n) << "\n";
      update(tree, 1, n, 1, u[r]);
      r--;
      flag = true;
    }
  }
  return 0;
}