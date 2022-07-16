#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct ant{
  int position;
  int weight;
};
bool cmp(ant a,ant b){
  return a.weight < b.weight || (a.weight == b.weight && a.position < b.position);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int testcase;
  cin >> testcase;

  for (int t = 1; t <= testcase; t++)
  {
    int n;
    cin >> n;
    vector<ant> ants(n + 1),original(n+1);
    for (int i = 1; i <= n; i++)
      cin >> ants[i].position;
    for (int i = 1; i<=n; i++)
      cin >> ants[i].weight;
    for (int i = 1; i <= n; i++)
      original[i] = ants[i];
    sort(ants.begin() + 1, ants.end(), cmp);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
      sum += ll(abs(ants[i].position - original[i].position));
    cout << "Case #" << t << "\n";
    cout << sum << "\n";
  }
  return 0;
}