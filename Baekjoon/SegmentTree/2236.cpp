#include <bits/stdc++.h>
#define MAX 500001
using namespace std;
struct ranks{
  int a,b,c;
};
bool compare_ranks(ranks x,ranks y){
  return x.a < y.a;
}
void update(vector<int> &tree,int start,int end,int node,int index,int value){
  if(!(start <= index && index<=end))
    return;
  if(start==end){
    tree[node]=value;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid)
    update(tree, start, mid, node * 2, index, value);
  else
    update(tree, mid + 1, end, node * 2 + 1, index, value);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int query(vector<int> &tree,int start,int end,int node,int x,int y){
  if(y<start || end<x){
    return MAX;
  }
  if(x<=start && end<=y)
    return tree[node];
  int num1 = query(tree, start, (start + end) / 2, node * 2, x, y);
  int num2 = query(tree, (start + end) / 2 + 1, end, node * 2 + 1, x, y);
  return min(num1, num2);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<ranks> arr(n + 1);

  for (int i = 1; i <= n; i++)
  {
    int temp;
    cin >> temp;
    arr[temp].a = i;
  }
  for (int i = 1; i <= n; i++)
  {
    int temp;
    cin >> temp;
    arr[temp].b = i;
  }
  for (int i = 1; i <= n; i++)
  {
    int temp;
    cin >> temp;
    arr[temp].c = i;
  }
  sort(arr.begin() + 1, arr.end(), compare_ranks);

  int tree_size = (int)(ceil(log2(n)));
  vector<int> tree(1 << (tree_size + 1), MAX);

  int ans = 1;
  update(tree, 1, n, 1, arr[1].b, arr[1].c);
  for (int i = 2; i <= n; i++)
  {
    int num = query(tree, 1, n, 1, 1,arr[i].b-1);
    if(num>arr[i].c)
      ans++;
    update(tree, 1, n, 1, arr[i].b, arr[i].c);
  }
  cout << ans;
  return 0;
}