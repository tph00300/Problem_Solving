#define INF 2147483647
#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[101],maxa;
int main()
{
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++){
    for (int j = i + 1; j <= n; j++){
      for (int k = j + 1; k <= n; k++){
        int temp = arr[i] + arr[j] + arr[k];
        if(temp<=m && maxa<temp){
          maxa = temp;
        }
      }
    }
  }
  cout << maxa;
  return 0;
}