#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void tree_init(vector<int> &tree,int start,int end,int node,int ind,int val){
  if(start==end){
    tree[node] = val;
    return;
  }
  int mid = (start + end) / 2;
  if (ind<=mid)
    tree_init(tree, start, mid, node * 2, ind, val);
  else
    tree_init(tree, mid+1, end, node * 2 + 1, ind, val);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(vector<int> &tree,int start,int end,int node,int x, int y){
  if(start>y || end<x){
    return 0;
  }
  if(x<=start && end <=y){
    return tree[node];
  }
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
  vector< pair<int,int> > arr(n + 1);

  for (int i = 1; i <= n; i++)
  {
    int temp;
    cin >> temp;
    arr[i]={temp,i};
  }
  sort(arr.begin()+1, arr.end());
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans += (ll)(query(tree, 1, n, 1, arr[i].second + 1, n));
    tree_init(tree, 1, n, 1, arr[i].second, 1);
  }
  cout << ans << "\n";
  return 0;
}