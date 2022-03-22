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
int query(vector<int> &tree,int start,int end,int node,int value){
  if(start==end){
    tree[node] = 0;
    return start;
  }
  int num;
  if (tree[node * 2] >= value)
    num = query(tree, start, (start + end) / 2, node * 2, value);
  else
    num = query(tree, (start + end) / 2 + 1, end, node * 2 + 1, value-tree[node*2]);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
  return num;
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
  vector<int> order(n + 1, 0);

  tree_init(tree, 1, n, 1);
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  sort(arr.begin() + 1, arr.end());

  for (int i = 1; i <= n; i++)
    cin >> order[i];

  vector<int> ans(n + 1, 0);
  for (int i = n; i >= 1; i--)
  {
    int num = query(tree, 1, n, 1, order[i] + 1);
    ans[i] = arr[num];
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << "\n";
  return 0;
}