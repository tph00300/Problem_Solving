#include <bits/stdc++.h>
#define MAX 2147483647
using namespace std;
void tree_init(vector<int> &tree,vector<int> &data,int start,int end,int node){
  if(start==end){
    tree[node] = start;
    return;
  }
  tree_init(tree, data, start, (start + end) / 2, node * 2);
  tree_init(tree, data, (start + end) / 2 + 1, end, node * 2 + 1);
  if(data[tree[node*2]]<=data[tree[node*2+1]]){
    tree[node] = tree[node * 2];
  }else{
    tree[node] = tree[node * 2 + 1];
  }  
}
int query(vector<int> &tree,vector<int> &data,int start,int end,int node,int x,int y){
  if(y<start || end<x)
    return 0;
  if(x<=start && end<=y){
    return tree[node];
  }
  int num1 = query(tree, data, start, (start + end) / 2, node * 2, x, y);
  int num2 = query(tree, data, (start + end) / 2 + 1, end, node * 2 + 1, x, y);
  if(data[num1]<=data[num2])
    return num1;
  return num2;
}
void update(vector<int> &tree,vector<int> &data,int start,int end,int node, int index){
  if(start==end){
    tree[node] = index;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid){
    update(tree, data, start, mid, node * 2, index);
  }else{
    update(tree, data, mid + 1, end, node * 2 + 1, index);
  }
  if(data[tree[node*2]]<=data[tree[node*2+1]]){
    tree[node] = tree[node * 2];
  }else{
    tree[node] = tree[node * 2 + 1];
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;

  cin >> n;

  int tree_size = (int)(ceil(log2(n)));
  vector<int> tree(1 << (tree_size + 1), 0);
  vector<int> arr(n + 1, 0);
  arr[0] = MAX;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  tree_init(tree, arr, 1, n, 1);
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++){
    int a, b, c;
    cin >> a;
    if(a==2){
      cout << query(tree, arr, 1, n, 1, 1, n) << "\n";
    }else{
      cin >> b >> c;
      arr[b] = c;
      update(tree, arr, 1, n, 1, b);
    }
  }
  return 0;
}