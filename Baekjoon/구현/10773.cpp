#include<bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  int sum = 0;

  stack<int> st;

  cin >> n;
  
  for (int i = 1; i <= n; i++)
  {
    int temp;
    cin >> temp;
    if(temp!=0){
      sum += temp;
      st.push(temp);
    }else{
      sum-=st.top();
      st.pop();
    }
  }
  cout << sum;
  return 0;
}