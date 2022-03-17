#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void tree_init(vector<ll> &tree,vector<ll> &data,int start,int end,int node){
  if(start==end){
    tree[node] = data[start];
    return;
  }
  tree_init(tree, data, start, (start + end) / 2, node * 2);
  tree_init(tree, data, (start + end) / 2 + 1, end, node * 2 + 1);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void update(vector<ll> &tree,int start,int end,int node,int index,ll value){
  if(start==end){
    tree[node]+=value;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid)
    update(tree, start, mid, node * 2, index, value);
  else
    update(tree, mid + 1, end, node * 2 + 1, index, value);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(vector<ll> &tree,int start,int end,int node,int value){
  if (start == end)
    return start;
  if(tree[node*2]>=value)
    return query(tree, start, (start + end) / 2, node * 2, value);
  else
    return query(tree, (start + end) / 2 + 1, end, node * 2 + 1, value - tree[node * 2]);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int tree_size=(int)(ceil(log2(n)));
  vector<ll> tree(1 << (tree_size + 1), 0);
  vector<ll> data(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> data[i];

  tree_init(tree, data, 1, n, 1);
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++)
  {
    int a;
    cin >> a;
    if(a==1){
      int b;
      ll c;
      cin >> b >> c;
      update(tree, 1, n, 1, b, c);
    }else{
      ll b;
      cin >> b;
      cout << query(tree, 1, n, 1, b) <<"\n";
    }
  }
    return 0;
}