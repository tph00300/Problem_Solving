#include <bits/stdc++.h>
using namespace std;
void tree_init(vector<int> &tree,int start,int end,int node){
  if(start==end)
  {
    tree[node] = 1;
    return;
  }
  tree_init(tree, start, (start + end) / 2, node * 2);
  tree_init(tree, (start + end) / 2 + 1, end, node * 2 + 1);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void update(vector<int> &tree,int start,int end,int node,int index){
  if(start==end)
  {
    tree[node] = 0;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid){
    update(tree, start, mid, node * 2, index);
  }else{
    update(tree, mid + 1, end, node * 2 + 1, index);
  }
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(vector<int> &tree,int start,int end,int node,int ranks){
  if(start==end)
    return start;
  if(tree[node*2]>=ranks)
    return query(tree, start, (start + end) / 2, node * 2, ranks);
  else
    return query(tree, (start + end) / 2 + 1, end, node * 2 + 1, ranks-tree[node*2]);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int tree_size = (int)(ceil(log2(n)));
  vector<int> tree(1 << (tree_size + 1), 0);

  tree_init(tree, 1, n, 1);

  cout << "<";
  int index = 1;
  for (int i = 1; i <= n; i++)
  {
    int size = n - i + 1;
    index += m - 1;

    index %= size;
    if(index==0)
      index = size;

    int num = query(tree, 1, n, 1, index);
    if(i==1)
      cout << num;
    else
      cout << ", " << num;
    update(tree, 1, n, 1, num);
  }
  cout << ">";
  return 0;
}