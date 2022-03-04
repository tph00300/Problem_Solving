#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct node{
  int num, s, e;
};
int dfs(vector<node> &list, vector<vector<int> > &graph, int now,int i)
{
  list[i] = {now, i, i};
  int sum = 1;
  for (int j = 0; j < graph[now].size(); j++)
  {
    sum += dfs(list, graph, graph[now][j], i + sum);
  }
  list[i].e = i + sum - 1;
  return sum;
}
void lazy_update(vector<ll> &tree,vector<ll> &lazy,int start,int end,int node){
  if(lazy[node]!=0){
    tree[node] += (end - start + 1) * lazy[node];
    if(start!=end){
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
}
void update(vector<ll> &tree,vector<ll> &lazy,int start,int end,int node,int x,int y,ll value){
  if(x>y ||y<start || end<x)
    return;
  lazy_update(tree, lazy, start, end, node);
  if(x<=start && end<=y){
    lazy[node] += value;
    lazy_update(tree, lazy, start, end, node);
    return;
  }
  update(tree, lazy, start, (start + end) / 2, node * 2, x, y, value);
  update(tree, lazy, (start + end) / 2 + 1, end, node * 2 + 1, x, y, value);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll query(vector<ll> &tree,vector<ll> &lazy,int start,int end,int node,int index){
  lazy_update(tree, lazy, start, end, node);
  if (start == end)
    return tree[node];
  int mid = (start + end) / 2;
  if(index<=mid)
    return query(tree, lazy, start, mid, node * 2, index);
  else
    return query(tree, lazy, mid + 1, end, node * 2 + 1, index);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int tree_size = (int)(ceil(log2(n)));
  vector<ll> tree(1 << (tree_size + 1), 0);
  vector<ll> lazy(1 << (tree_size + 1), 0);
  vector<ll> salary(n + 1, 0);
  vector<vector<int> > graph(n + 1, vector<int>(0)); // 그룹 연결
  vector<node> arr(n+1,{0,0,0}); // 월급 조정시 범위
  vector<int> u(n + 1, 0); // 각 사원 트리에서의 위치

  int pay;
  cin >> pay;
  salary[1] = pay;
  for (int i = 2; i <= n; i++)
  {
    int father;
    cin >> pay >> father;
    salary[i] = (ll)(pay);
    graph[father].push_back(i);
  }

  dfs(arr, graph, 1, 1);

  for (int i = 1; i <= n; i++)
    u[arr[i].num] = i;

  for (int i = 1; i <= m; i++)
  {
    char temp;
    cin >> temp;
    if(temp=='p'){
      int a, b;
      cin >> a >> b;
      update(tree, lazy, 1, n, 1, arr[u[a]].s+1, arr[u[a]].e, (ll)(b));
    }else{
      int a;
      cin >> a;
      ll num = query(tree, lazy, 1, n, 1, u[a]);
      cout << salary[a]+num << "\n";
    }
  }

  return 0;
}