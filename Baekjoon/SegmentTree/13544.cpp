#include <bits/stdc++.h>
using namespace std;
void tree_init(vector<vector<int> >&tree,vector<int> &data,int start,int end,int node){
  if(start==end){
    tree[node].push_back(data[start]);
    return;
  }
  tree_init(tree, data, start, (start + end) / 2, node * 2);
  tree_init(tree, data, (start + end) / 2 + 1, end, node * 2 + 1);
  tree[node].resize(tree[node * 2].size() + tree[node * 2 + 1].size());
  merge(tree[node * 2].begin(), tree[node * 2].end(), tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(), tree[node].begin());
}
int query(vector<vector<int> > &tree,int start,int end,int node,int x,int y,int value){
  if(y<start || end<x)
    return 0;
  if(x<=start && end<=y)
    return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), value);
  int num1 = query(tree, start, (start + end) / 2, node * 2, x, y, value);
  int num2 = query(tree, (start + end) / 2 + 1, end, node * 2 + 1, x, y, value);
  return num1 + num2;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;

  cin >> n;

  int tree_size = (int)(ceil(log2(n)));
  vector<vector<int> > tree(1 << (tree_size + 1),vector<int>(0));
  vector<int> arr(n+1,0);

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];    
  }
  tree_init(tree, arr, 1, n, 1);

  for (int i = 1; i < tree.size(); i++){
    sort(tree[i].begin(), tree[i].end());
  }
  int ans = 0, m;

  cin >> m;

  for (int i = 1; i <= m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    ans = query(tree, 1, n, 1, a^ans, b^ans, c^ans);
    cout << ans << "\n";
  }
  return 0;
}