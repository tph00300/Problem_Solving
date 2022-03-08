#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct question{
  int x, y, z, index;
};
struct up{
  int index;
  ll value;
};
bool cmp_question_x(question a,question b){
  return a.x < b.x;
}
bool cmp_question_index(question a, question b){
  return a.index < b.index;
}
void tree_init(vector<ll> &tree, vector<ll> &data, int start, int end, int node)
{
  if(start==end){
    tree[node] = data[start];
    return;
  }
  tree_init(tree, data, start, (start + end) / 2, node * 2);
  tree_init(tree, data, (start + end) / 2 + 1, end, node * 2 + 1);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void update(vector<ll> &tree,int start,int end, int node,int index,ll value){
  if(start==end){
    tree[node] = value;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid)
    update(tree, start, mid, node * 2, index, value);
  else
    update(tree, mid + 1, end, node * 2 + 1, index, value);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll query(vector<ll> &tree,int start,int end,int node,int x,int y){
  if(y<start || end<x)
    return 0;
  if(x<=start && end<=y)
    return tree[node];
  ll num1 = query(tree, start, (start + end) / 2, node * 2, x, y);
  ll num2 = query(tree, (start + end) / 2 + 1, end, node * 2 + 1, x, y);
  return num1 + num2;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int tree_size = (int)(ceil(log2(n)));
  vector<ll> tree(1 << (tree_size + 1), 0);
  vector<ll> arr(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  tree_init(tree, arr, 1, n, 1);

  int m;
  cin >> m;

  vector<question> q(0);
  vector<up> u(0);
  for (int i = 1; i <= m; i++)
  {
    int a;
    cin >> a;
    if(a==1){
      int x;
      ll y;
      cin >> x >> y;
      u.push_back({x, y});
    }else{
      question temp;
      cin >> temp.x >> temp.y >> temp.z;
      temp.index = q.size();
      q.push_back(temp);
    }
  }
  vector<ll> ans(q.size(), 0);
  sort(q.begin(), q.end(), cmp_question_x);

  int j = 0;
  for (int i = 0; i < q.size(); i++)
  {
    while(q[i].x>j){
      update(tree,1,n,1,u[j].index,u[j].value);
      j++;
    }
    ans[q[i].index] = query(tree, 1, n, 1, q[i].y, q[i].z);
  }
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << "\n";
  }
  return 0;
}