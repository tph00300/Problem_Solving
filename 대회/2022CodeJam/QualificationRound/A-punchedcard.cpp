#include <bits/stdc++.h>
using namespace std;
void output(int n,int m){
  for (int i = 1; i <= n * 2 + 1; i++){
    for (int j = 1; j <= m * 2 + 1; j++){
      if(i<=2 && j<=2){
        cout << ".";
      }else if(i%2){
        if(j%2)
          cout << "+";
        else
          cout << "-";
      }
      else{
        if(j%2)
          cout << "|";
        else
          cout << ".";
      }
    }
    cout << "\n";
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, testcase;
  cin >> testcase;

  for (t = 1; t <= testcase; t++){
    int n, m;
    cin >> n >> m;

    cout << "Case #" << t << ":" << "\n";
    output(n, m);
  }
  return 0;
}