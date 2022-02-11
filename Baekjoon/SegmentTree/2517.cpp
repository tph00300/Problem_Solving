#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b){
  return a.first > b.first;
}
void update(vector<int> &tree,int start,int end,int node,int index){
  if(start==end)
  {
    tree[node] = 1;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid)
    update(tree, start, mid, node * 2, index);
  else
    update(tree, mid + 1, end, node * 2 + 1, index);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(vector<int> &tree,int start,int end,int node,int index){
  if(index>=end)
    return tree[node];
  if (end < index || index < start)
    return 0;

  int num1 = query(tree, start, (start + end) / 2, node * 2, index);
  int num2 = query(tree, (start + end) / 2 + 1, end, node * 2 + 1, index);
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
  vector<pair<int, int> > arr(n + 1);
  vector<pair<int, int> > down(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i].first;
    down[i] = {arr[i].first, i};
  }
  sort(down.begin() + 1, down.end(),compare);

  for (int i = 1; i <= n; i++)
    arr[down[i].second].second = i;
  for (int i = 1; i <= n; i++)
  {
    int ans=query(tree, 1, n, 1, arr[i].second);
    cout << ans+1 << "\n";
    update(tree, 1, n, 1, arr[i].second);
  }
  return 0;
}