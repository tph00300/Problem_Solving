#include <bits/stdc++.h>
#define MAX 2147483647
using namespace std;
void tree_init(vector<int> &tree,vector<int> &data,int start,int end,int node){
  if(start==end){
    tree[node] = data[start];
  }else{
    tree_init(tree, data, start, (start + end) / 2, node * 2);
    tree_init(tree, data, (start + end) / 2 + 1, end, node * 2 + 1);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
  }
}
void update(vector<int> &tree,int start,int end,int node,int index,int value)
{
  if(start==end)
  {
    tree[node] = value;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid){
    update(tree, start, mid, node * 2, index, value);
  }else{
    update(tree, mid + 1, end, node * 2 + 1, index, value);
  }
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int query(vector<int> &tree,int start,int end,int node, int x, int y){
  if(y<start || end<x)
    return -1;
  if(x<=start && end<=y)
    return tree[node];
  int num1 = query(tree, start, (start + end) / 2, node * 2, x, y);
  int num2 = query(tree, (start + end) / 2 + 1, end, node * 2 + 1, x, y);
  if(num1==-1)
    return num2;
  else if(num2==-1)
    return num1;
  return min(num1,num2);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;

  cin >> n;

  int tree_size = (int)(ceil(log2(n)));
  vector<int> tree(1 << (tree_size + 1), MAX);
  vector<int> arr(n + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  tree_init(tree, arr, 1, n, 1);
  int m;
  cin >> m;

  for (int i = 1; i <= m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;

    if(a==1){
      update(tree, 1, n, 1, b, c);
    }else{
      cout << query(tree, 1, n, 1, b, c) << "\n";
    }
  }
  return 0;
}