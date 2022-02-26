#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void update(vector<int> &tree,int start,int end,int node,int index){
  if(!(start<=index && index<=end))
    return;
  if(start==end){
    tree[node] = 1;
    return;
  }
  update(tree, start, (start + end) / 2, node * 2, index);
  update(tree, (start + end) / 2 + 1, end, node * 2 + 1, index);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(vector<int> &tree,int start,int end,int node,int x,int y){
  if(y<start || end<x)
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

  ll ans = 0;
  for (int i = 1; i <= n; i++){
    int temp;
    cin >> temp;

    ans += (ll)(query(tree, 1, n, 1, temp + 1, n));
    update(tree, 1, n, 1, temp);
  }
  cout << ans;
  return 0;
}