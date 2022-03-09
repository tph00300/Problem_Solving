#include <bits/stdc++.h>
using namespace std;
void tree_init(vector<vector<int> > &color,vector<int> &tree,vector<int> &data,int start,int end,int node){
  if(start==end){
    tree[node] = data[start];
    return;
  }
  tree_init(color, tree, data, start, (start + end) / 2, node * 2);
  tree_init(color, tree, data, (start + end) / 2 + 1, end, node * 2 + 1);
  int num1 = upper_bound(color[tree[node * 2]].begin(), color[tree[node * 2]].end(), end) - lower_bound(color[tree[node * 2]].begin(), color[tree[node * 2]].end(), start) + 1;
  if (num1 > (end - start + 1) / 2)
  {
    tree[node] = tree[node * 2];
    return;
  }
  int num2 = upper_bound(color[tree[node * 2 + 1]].begin(), color[tree[node * 2 + 1]].end(), end) - lower_bound(color[tree[node * 2 + 1]].begin(), color[tree[node * 2 + 1]].end(), start) + 1;
  if (num2 > (end - start + 1) / 2)
  {
    tree[node] = tree[node * 2 + 1];
    return;
  }
  tree[node] = -1;
}
int query(vector<vector<int> > &color,vector<int> &tree,int start,int end,int node,int x,int y){
  if(y<start || end<x)
    return 0;
  if(x<=start && end<=y)
  {
    int cnt = upper_bound(color[tree[node]].begin(), color[tree[node]].end(), y) - lower_bound(color[tree[node]].begin(), color[tree[node]].end(), x);
    if (cnt > (y - x + 1) / 2)
      return tree[node];
    return 0;
  }
  int num1 = query(color, tree, start, (start + end) / 2, node * 2, x, y);
  if(num1>0)
    return num1;
  int num2 = query(color, tree, (start + end) / 2 + 1, end, node * 2 + 1, x, y);
  if(num2>0)
    return num2;
  return 0;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n,c;
  cin >> n >> c;

  int tree_size=(int)(ceil(log2(n)));
  vector<vector<int> > color(c+1,vector<int>(0));
  vector<int> tree(1 << (tree_size + 1), 0);
  vector<int> arr(n + 1, 0);

  for (int i = 1; i <= n; i++){
    cin >> arr[i];
    color[arr[i]].push_back(i);
  }
  tree_init(color, tree, arr, 1, n, 1);
  int m;
  cin >> m;

  for (int i = 1; i <= m; i++){
    int x, y;
    cin >> x >> y;
    int ans = query(color,tree,1,n,1,x,y);
    if(ans==0)
      cout << "no"<< "\n";
    else
      cout << "yes " << ans << "\n";
  }
  return 0;
}