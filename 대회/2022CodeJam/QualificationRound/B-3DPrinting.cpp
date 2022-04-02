#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, testcase;
  cin >> testcase;

  for (t = 1; t <= testcase; t++){
    vector<int> colors(5, -1);
    for (int i = 1; i <= 3; i++)
    {
      for (int j = 1; j <= 4; j++)
      {
        int temp;
        cin >> temp;
        colors[j] = colors[j] == -1 ? temp : min(colors[j], temp);
      }
    }
    cout << "Case #" << t << ": ";
    int colorSum = 0;
    for (int i = 1; i<=4; i++)
      colorSum += colors[i];
    if(colorSum<1e6){
      cout << "IMPOSSIBLE\n";
      continue;
    }
    int diff = colorSum - 1e6;
    for (int i = 1; i <= 4; i++)
    {
      if (colors[i] >= diff)
      {
        colors[i] -= diff;
        diff = 0;
      }
      else
      {
        diff -= colors[i];
        colors[i] = 0;
      }
    }
    for (int i = 1; i <= 4; i++){
      cout << colors[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}