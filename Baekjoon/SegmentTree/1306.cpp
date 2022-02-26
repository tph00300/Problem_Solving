#include <bits/stdc++.h>
#define MAX 1000000
typedef long long ll;
using namespace std;
void update(vector<int> &tree,int start,int end,int node,int index,int value)
{
  if(start==end){
    tree[node]=value;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid)
    update(tree, start, (start + end) / 2, node * 2, index, value);
  else
    update(tree, (start + end) / 2 + 1, end, node * 2 + 1, index, value);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int tree_size = (int)(ceil(log2(n)));
  vector<int> tree(1 << (tree_size + 1), 0);
  vector<int> arr(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  for (int i = 1; i < 2*m-1; i++)
    update(tree, 1, n, 1, i, arr[i]);
  for (int i = m; i <= n - m + 1; i++){
    update(tree, 1, n, 1, i + m - 1, arr[i + m - 1]);
    cout << tree[1] << "\n";
    update(tree, 1, n, 1, i - m + 1, 0);
  }
  return 0;
}