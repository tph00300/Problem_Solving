#include <bits/stdc++.h>
#define MAX_temperature 65536
typedef long long ll;
using namespace std;
void update(vector<int> &tree,int start,int end,int node,int index,int value){
  if(start==end){
    tree[node] += value;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid){
    update(tree, start, mid, node * 2, index, value);
  }else{
    update(tree, mid + 1, end, node * 2 + 1, index, value);
  }
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(vector<int> &tree,int start,int end,int node,int rank){
  if(start==end)
    return start;
  if(rank<=tree[node*2]){
    return query(tree, start, (start + end) / 2, node * 2, rank);
  }else{
    return query(tree, (start + end) / 2 + 1, end, node * 2 + 1, rank - tree[node * 2]);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;

  cin >> n >> m;

  int tree_size = (int)(ceil(log2(MAX_temperature)));
  vector<int> tree(1 << (tree_size + 1), 0);
  vector<int> arr(n + 1, 0);

  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    if(i>m)
      update(tree, 1, MAX_temperature, 1, arr[i - m], -1);
    cin >> arr[i];
    arr[i] += 1;
    update(tree, 1, MAX_temperature,1,arr[i],1);
    if (i >= m)
      ans += (ll)(query(tree, 1, MAX_temperature, 1, (m + 1) / 2) - 1);
  }
  cout << ans << "\n";
  return 0;
}