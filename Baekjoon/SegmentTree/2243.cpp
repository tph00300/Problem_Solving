#include <bits/stdc++.h>
#define MAX 1000000
typedef long long ll;
using namespace std;
void tree_update(vector<ll> &tree,int start,int end,int node,int index,int value){
  if(!(start<=index && index<=end))
    return;
  tree[node] += value;
  if (start == end)
    return;
  tree_update(tree, start, (start + end) / 2, node * 2, index, value);
  tree_update(tree, (start + end) / 2+1, end, node * 2 + 1, index, value);
}
ll query(vector<ll> &tree,int start,int end,int node,int rank){
  if(start==end)
    return (ll)(start);

  if (tree[node * 2] >= rank)
    return query(tree, start, (start + end) / 2, node * 2, rank);
  
  return query(tree, (start + end) / 2 + 1, end, node * 2 + 1, rank - tree[node * 2]);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;

  int tree_size = (int)(ceil(log2(MAX)));
  vector<ll> tree(1<<(tree_size+1),0);
  
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int a, b, c;
    cin >> a >> b;

    if (a == 1)
    {
      ll ans = query(tree, 1, MAX, 1, b);
      cout << ans << "\n";
      tree_update(tree, 1, MAX, 1, ans, -1);
      continue;
    }
    cin >> c;
    tree_update(tree, 1, MAX, 1, b, c);
  }
  return 0;
}