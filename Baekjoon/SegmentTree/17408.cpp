#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void tree_init(vector<vector<ll> > &tree,vector<ll> &data,int start,int end,int node){
  if(start==end){
    tree[node].push_back(data[start]);
    return;
  }
  tree_init(tree, data, start, (start + end) / 2, node * 2);
  tree_init(tree, data, (start + end) / 2 + 1, end, node * 2 + 1);
  vector<ll> temp(tree[node*2].size()+tree[node*2+1].size(),0);
  merge(tree[node * 2].begin(), tree[node * 2].end(), tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(), temp.begin());
  sort(temp.begin(), temp.end(), greater<>());
  tree[node].push_back(temp[0]);
  tree[node].push_back(temp[1]);
}
void update(vector<vector<ll> > &tree,int start,int end,int node,int index,ll value)
{
  if(start==end){
    tree[node][0] = value;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid)
    update(tree, start, mid, node * 2, index, value);
  else
    update(tree, mid + 1, end, node * 2 + 1, index, value);
  vector<ll> temp(tree[node*2].size()+tree[node*2+1].size(),0);
  merge(tree[node * 2].begin(), tree[node * 2].end(), tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(), temp.begin());
  sort(temp.begin(), temp.end(), greater<>());
  tree[node].resize(0);
  tree[node].push_back(temp[0]);
  tree[node].push_back(temp[1]);
}
vector<ll> query(vector<vector<ll> > &tree,int start,int end,int node,int x,int y){
  if(y<start || end<x)
    return {0,0};
  if(x<=start && end<=y)
    return tree[node];
  vector<ll> vec1 = query(tree, start, (start + end) / 2, node * 2, x, y);
  vector<ll> vec2 = query(tree, (start + end) / 2 + 1, end, node * 2 + 1, x, y);
  vector<ll> temp(vec1.size()+vec2.size(),0);
  merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), temp.begin());
  sort(temp.begin(), temp.end(), greater<>());
  vector<ll> ret(2, 0);
  ret[0] = temp[0];
  ret[1] = temp[1];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int tree_size = (int)(ceil(log2(n)));
  vector<vector<ll> > tree(1 << (tree_size + 1), vector<ll>(0));
  vector<ll> arr(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  tree_init(tree, arr, 1, n, 1);

  int m;
  cin >> m;

  for (int i = 1; i <= m; i++)
  {
    int a;
    cin >> a;
    if(a==1)
    {
      int b;
      ll c;
      cin >> b >> c;
      update(tree, 1, n, 1, b, c);
    }else{
      int b, c;
      cin >> b >> c;
      vector<ll> ans = query(tree, 1, n, 1, b, c);
      cout << ans[0] + ans[1] << "\n";
    }
  }
  return 0;
}