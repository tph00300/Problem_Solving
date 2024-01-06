#include <bits/stdc++.h>
#define MAX_DEFINE 1000001
using namespace std;
vector<int> sumArray(1000001,MAX_DEFINE);
int decompositionSum(int input){
  int sum = input;
  while(input>0){
    sum += input % 10;
    input /= 10;
  }
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i <= 1000000; i++){
    int temp = decompositionSum(i);
    sumArray[temp] = min(sumArray[temp], i);
  }
  int n;
  cin >> n;
  if(sumArray[n]== MAX_DEFINE)
    cout << 0;
  else
    cout << sumArray[n];
  return 0;
}