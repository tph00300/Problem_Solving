#include <bits/stdc++.h>
using namespace std;
struct tree_data{
  int x, y;
};
void tree_init(vector<tree_data> &tree,vector<int> &data,int start,int end,int node){
  if(start==end){
    if(data[start]%2){
      tree[node] = {0, 1};
    }else{
      tree[node] = {1, 0};
    }
    return;
  }
  tree_init(tree, data, start, (start + end) / 2, node * 2);
  tree_init(tree, data, (start + end) / 2 + 1, end, node * 2 + 1);
  tree[node] = {tree[node * 2].x + tree[node * 2 + 1].x, tree[node * 2].y + tree[node * 2 + 1].y};
}
void update(vector<tree_data> &tree,int start,int end,int node,int index,int value){
  if(start==end){
    if(value%2){
      tree[node] = {0, 1};
    }else{
      tree[node] = {1, 0};
    }
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid){
    update(tree, start, (start + end) / 2, node * 2, index, value);
  }else{
    update(tree, (start + end) / 2 + 1, end, node * 2 + 1, index, value);
  }
  tree[node] = {tree[node * 2].x + tree[node * 2 + 1].x, tree[node * 2].y + tree[node * 2 + 1].y};
}
int query(vector<tree_data> &tree,int start,int end,int node,int x,int y,bool num){
  if(y<start || end<x){
    return 0;
  }
  if(x<=start && end<=y){
    if(num){ //짝수
      return tree[node].x;
    }else{
      return tree[node].y;
    }
  }
  int num1 = query(tree, start, (start + end) / 2, node * 2, x, y, num);
  int num2 = query(tree, (start + end) / 2 + 1, end, node * 2 + 1, x, y, num);
  return num1 + num2;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int tree_size = (int)(ceil(log2(n)));
  vector<tree_data> tree(1 << (tree_size + 1), {0, 0});
  vector<int> arr(n + 1, 0);

  for (int i = 1; i <= n; i++){
    cin >> arr[i];
  }
  tree_init(tree, arr, 1, n, 1);

  int m;
  cin >> m;
  for (int i = 1; i <= m; i++){
    int a, b, c;

    cin >> a >> b >> c;

    if(a==1){
      update(tree, 1, n, 1, b, c);
    }else if(a==2){
      cout << query(tree, 1, n, 1, b, c, true) << "\n";
    }else{
      cout << query(tree, 1, n, 1, b, c, false) << "\n";
    }
  }
  return 0;
}