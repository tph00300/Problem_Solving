#include <bits/stdc++.h>
typedef long long ll;
#define MOD (ll)(1e9 + 7)
using namespace std;
struct up{
  ll mul, plus;
};
void lazy_update(vector<ll> &tree, vector<up> &lazy, int start, int end, int node){
  if(lazy[node].mul==1 && lazy[node].plus==0)
    return;
  ll mul = lazy[node].mul, plus = lazy[node].plus;
  tree[node] = (((mul * tree[node]) % MOD) + (((end - start + 1) * plus) % MOD)) % MOD;
  if(start!=end){
    lazy[node * 2].plus = (((lazy[node * 2].plus * lazy[node].mul) % MOD) + lazy[node].plus)%MOD;
    lazy[node * 2].mul = (lazy[node * 2].mul * lazy[node].mul) % MOD;
    lazy[node * 2 + 1].plus = (((lazy[node * 2 + 1].plus * lazy[node].mul) % MOD) + lazy[node].plus) % MOD;
    lazy[node * 2 + 1].mul = (lazy[node * 2 + 1].mul * lazy[node].mul) % MOD;
  }
  lazy[node] = {1, 0};
}
void tree_init(vector<ll> &tree,vector<ll> &data,int start,int end,int node)
{
  if(start==end)
  {
    tree[node] = data[start];
    return;
  }
  tree_init(tree, data, start, (start + end) / 2, node * 2);
  tree_init(tree, data, (start + end) / 2 + 1, end, node * 2 + 1);
  tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
}
void update(vector<ll> &tree,vector<up> &lazy,int start,int end,int node,int x,int y,up value){
  lazy_update(tree, lazy, start, end, node);
  if(y<start || end<x)
    return;
  if(x<=start && end<=y){
    lazy[node].plus = (((lazy[node].plus * value.mul) % MOD) + value.plus) % MOD;
    lazy[node].mul = (lazy[node].mul * value.mul) % MOD;
    lazy_update(tree, lazy, start, end, node);
    return;
  }
  update(tree, lazy, start, (start + end) / 2, node * 2, x, y, value);
  update(tree, lazy, (start + end) / 2 + 1, end, node * 2 + 1, x, y, value);
  tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
}
ll query(vector<ll> &tree,vector<up> &lazy,int start,int end,int node,int x,int y){
  lazy_update(tree, lazy, start, end, node);
  if(y<start || end<x)
    return 0;
  if(x<=start && end<=y)
    return tree[node];
  ll num1 = query(tree, lazy, start, (start + end) / 2, node * 2, x, y);
  ll num2 = query(tree, lazy, (start + end) / 2 + 1, end, node * 2 + 1, x, y);
  return (num1 + num2) % MOD;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int tree_size = (int)(ceil(log2(n)));
  vector<ll> tree(1 << (tree_size + 1), 0);
  vector<up> lazy(1 << (tree_size + 1), {1, 0});
  vector<ll> arr(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  tree_init(tree, arr, 1, n, 1);

  int m;
  cin >> m;
  for (int i = 1; i <= m; i++){
    int a;
    cin >> a;
    if(a==1){
      int x,y;
      ll temp;
      cin >> x >> y >> temp;
      update(tree, lazy, 1, n, 1, x, y, {1, temp});
    }else if(a==2){
      int x, y;
      ll temp;
      cin >> x >> y >> temp;
      update(tree, lazy, 1, n, 1, x, y, {temp, 0});
    }else if(a==3){
      int x, y;
      ll temp;
      cin >> x >> y >> temp;
      update(tree, lazy, 1, n, 1, x, y, {0, temp});
    }else if(a==4){
      int x, y;
      cin >> x >> y;
      cout << query(tree, lazy, 1, n, 1, x, y) << "\n";
    }
  }
  return 0;
}