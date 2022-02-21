#include <bits/stdc++.h>
using namespace std;
void tree_init(vector<int> &tree, int start,int end,int node){
  if(start==end){
    tree[node] = 1;
    return;
  }
  tree_init(tree, start, (start + end) / 2, node * 2);
  tree_init(tree, (start + end) / 2 + 1, end, node * 2 + 1);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void update(vector<int> &tree,vector<int> &data,int start,int end,int node,int index,int value){
  if (start == end)
  {
    tree[node] = 0;
    data[start] = index;
    return;
  }
  if(tree[node*2]>=value){
    update(tree, data, start, (start + end) / 2, node * 2, index, value);
  }else{
    update(tree, data, (start + end) / 2 + 1, end, node * 2 + 1, index, value - tree[node * 2]);
  }
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
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

  tree_init(tree, 1, n, 1);
  for (int i = 1; i <= n; i++)
  {
    int a;
    cin >> a;

    update(tree, arr, 1, n, 1, i, a + 1);
  }
  for (int i = 1; i <= n; i++)
    cout << arr[i] << "\n";
  return 0;
}