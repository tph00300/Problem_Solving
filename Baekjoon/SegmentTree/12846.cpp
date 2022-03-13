#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;
void tree_init(vector<int> &tree, vector<int> &data, int start, int end, int node)
{
  if(start==end){
    tree[node] = start;
    return;
  }
  tree_init(tree, data, start, (start + end) / 2, node * 2);
  tree_init(tree, data, (start + end) / 2 + 1, end, node * 2 + 1);
  if(data[tree[node*2]]<=data[tree[node*2+1]])
    tree[node] = tree[node * 2];
  else
    tree[node] = tree[node * 2 + 1];
}
int query(vector<int> &tree,vector<int> &data,int start,int end,int node,int x,int y){
  if(y<start || end<x)
    return -1;
  if(x<=start && end<=y)
    return tree[node];
  int num1 = query(tree, data, start, (start + end) / 2, node * 2, x, y);
  int num2 = query(tree, data, (start + end) / 2 + 1, end, node * 2 + 1, x, y);
  if (num1 == -1)
    return num2;
  if (num2 == -1)
    return num1;
  if(data[num1]<=data[num2])
    return num1;
  return num2;
}
ll solution(vector<int> &tree,vector<int> &data,int x,int y){
  int mini = query(tree, data, 1, n, 1, x, y);
  ll ans = (y - x + 1) * (ll)(data[mini]);
  if (x <= mini - 1)
  {
    ll num1 = solution(tree, data, x, mini - 1);
    ans = max(ans, num1);
  }
  if(mini+1<=y){
    ll num2 = solution(tree, data, mini + 1, y);
    ans = max(ans, num2);
  }
  return ans;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  int tree_size = (int)(ceil(log2(n)));
  vector<int> tree(1 << (tree_size + 1), 0);
  vector<int> arr(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  tree_init(tree, arr, 1, n, 1);

  cout << solution(tree, arr, 1, n);
  return 0;
}