#include <bits/stdc++.h>
using namespace std;
void tree_init(vector<int> &tree,vector<int> &data,int start,int end,int node){
  if(start==end){
    tree[node] = data[start];
  }else{
    tree_init(tree, data, start, (start + end) / 2, node * 2);
    tree_init(tree, data, (start + end) / 2 + 1, end, node * 2 + 1);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }
}
int query(vector<int> &tree,vector<int> &data,int start,int end,int node,int x,int y){
  if(start>y || end<x){
    return -1;
  }
  if(x<=start && end<=y){
    return tree[node];
  }
  int num1 = query(tree, data, start, (start + end) / 2, node * 2, x, y);
  int num2 = query(tree, data, (start + end) / 2 + 1, end, node * 2 + 1, x, y);
  if(num1==-1)
    return num2;
  else if(num2==-1)
    return num1;
  return num1 + num2;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;

  cin >> n >> m;

  vector<int> data(n + 1, 0);
  int i, j, k;

  for (i = 1; i <= n; i++)
    cin >> data[i];

  int tree_size = (int)(ceil(log2(n)));
  vector<int> tree(1 << (tree_size + 1), 0);
  tree_init(tree, data, 1, n, 1);
  for (i = 1; i <= m; i++)
  {
    int tx, ty;
    cin >> tx >> ty;
    cout << query(tree, data, 1, n, 1, tx, ty) << "\n";
  }
  return 0;
}