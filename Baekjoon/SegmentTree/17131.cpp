#include <bits/stdc++.h>
typedef long long ll;
#define MAX 4e5+1
#define MOD (ll)(1e9+7)
using namespace std;
struct star{
  int x, y;
};
bool cmp(star a, star b){
  return a.y > b.y || (a.y == b.y && a.x < b.x);
}
void update(vector<ll> &tree,int start,int end,int node,int index){
  if(start==end){
    tree[node]++;
    return;
  }
  int mid = (start + end) / 2;
  if(index<=mid)
    update(tree, start, mid, node * 2, index);
  else
    update(tree, mid + 1, end, node * 2 + 1, index);
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

  int tree_size = (int)(ceil(log2(MAX)));
  vector<ll> tree(1 << (tree_size + 1), 0);
  vector<star> stars(n + 1);
  for (int i = 1; i <= n; i++){
    cin >> stars[i].x >> stars[i].y;
    stars[i].x += 2e5+1;
    stars[i].y += 2e5+1;
  }
  sort(stars.begin()+1,stars.end(),cmp);

  queue<star> wait;
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    if(i!=1 && stars[i].y!=stars[i-1].y)// queue에 있는 내용 넣어주기
    {
      while(!wait.empty()){
        update(tree, 1, MAX, 1, wait.front().x);
        wait.pop();
      }
    }
    ll num1 = query(tree, 1, MAX, 1, 1, stars[i].x - 1);
    ll num2 = query(tree, 1, MAX, 1, stars[i].x + 1, MAX);
    ans += (num1 * num2) % MOD;
    ans %= MOD;
    wait.push(stars[i]);
  }
  cout << ans;
  return 0;
}