#include <bits/stdc++.h>
#define MAX 2000000
using namespace std;
void update(vector<int> &tree,int start,int end,int node,int index,int value){
  if(start==end){
    tree[node] += value;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid)
    update(tree, start, (start + end) / 2, node * 2, index, value);
  else
    update(tree, (start + end) / 2 + 1, end, node * 2 + 1, index, value);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(vector<int> &tree,int start,int end,int node,int index){
  // if(!(start <= index && index <= end))
  //   return 0;
  if(start == end)
    return start;
  if(index<=tree[node*2])
    return query(tree, start, (start + end) / 2, node * 2, index);
  else
    return query(tree, (start + end) / 2 + 1, end, node * 2 + 1, index - tree[node * 2]);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int tree_size = (int)(ceil(log2(MAX)));
  vector<int> tree(1 << (tree_size + 1), 0);

  for (int i = 1; i <= n; i++)
  {
    int a, b;
    cin >> a >> b;

    if(a==1){
      update(tree, 1, MAX, 1, b, 1);
    }else{
      int num = query(tree, 1, MAX, 1, b);
      cout << num << "\n";
      update(tree, 1, MAX, 1, num, -1);
    }
  }
  return 0;
}