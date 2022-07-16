#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> sumTree, minTree, arr;
void sumTree_init(int start, int end, int node)
{
  if(start==end){
    sumTree[node] = arr[start];
    return;
  }
  sumTree_init(start, (start + end) / 2, node * 2);
  sumTree_init((start + end) / 2 + 1, end, node * 2 + 1);
  sumTree[node] = sumTree[node * 2] + sumTree[node * 2 + 1];
}
ll sumTree_query(int start,int end,int node,int x,int y){
  if(y<start || end<x)
    return 0;
  if(x<=start && end<=y)
    return sumTree[node];
  ll num1 = sumTree_query(start, (start + end) / 2, node * 2, x, y);
  ll num2 = sumTree_query((start + end) / 2 + 1, end, node * 2 + 1, x, y);
  return num1 + num2;
}
void minTree_init(int start,int end,int node){
  if(start==end){
    minTree[node] = start;
    return;
  }
  minTree_init(start, (start + end) / 2, node * 2);
  minTree_init((start + end) / 2 + 1, end, node * 2 + 1);
  if(arr[minTree[node*2]]<arr[minTree[node*2+1]])
    minTree[node] = minTree[node * 2];
  else
    minTree[node] = minTree[node * 2 + 1];
}
ll minTree_query(int start,int end,int node,int x,int y){
  if (y < start || end < x || x > y)
    return 0;
  if(x<=start && end<=y)
    return minTree[node];
  ll num1 = minTree_query(start, (start + end) / 2, node * 2, x, y);
  ll num2 = minTree_query((start + end) / 2 + 1, end, node * 2 + 1, x, y);
  if(num1==0)
    return num2;
  else if(num2==0)
    return num1;
  if (num2 == 0 || arr[num1] < arr[num2])
    return num1;
  return num2;
}
ll solve(int n,int start,int end){
  if(start>end)
    return 0;
  if (start == end)
    return arr[start]*arr[start];
  ll minIndex = minTree_query(1, n, 1, start, end);
  ll num1 = solve(n, start, minIndex - 1);
  ll num2 = solve(n, minIndex + 1, end);
  ll num3 = sumTree_query(1, n, 1, start, end) * arr[minIndex];

  return max(num1, max(num2, num3));
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int tree_size = (int)(ceil(log2(n)));

  sumTree.resize(1 << (tree_size + 1), 0);
  minTree.resize(1 << (tree_size + 1), 0);
  arr.resize(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  
  sumTree_init(1, n, 1);
  minTree_init(1, n, 1);

  cout << solve(n, 1, n);
  return 0;
}