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
int update(vector<int> &tree,int start,int end,int node,int value){
  if (start == end)
  {
    tree[node] = 0;
    return start;
  }
  int num;
  if (tree[node * 2 + 1] < value)
    num = update(tree, start, (start + end) / 2, node * 2, value - tree[node * 2 + 1]);
  else
    num = update(tree, (start + end) / 2 + 1, end, node * 2 + 1, value);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
  return num;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int tree_size = (int)(ceil(log2(n)));
  vector<int> tree(1 << (tree_size + 1), 0);
  vector<int> data(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> data[i];

  tree_init(tree, 1, n, 1);

  vector<int> ans(n + 1, 0);
  for (int i = n; i >= 1; i--){
    int num = update(tree, 1, n, 1, data[i]+1);
    ans[num] = i;
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << " ";
  return 0;
}