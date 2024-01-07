#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(1){
    bool flag = true;
    string s;
    stack<char> st;
    getline(cin, s);
    if (s == ".")
      return 0;
    for (int i = 0; i < s.size(); i++){
      if(s[i]=='(' || s[i]=='['){
        st.push(s[i]);
      }else if(s[i]==')'){
        if(st.empty() || st.top()!='('){
          flag = false;
          break;
        }
        st.pop();
      }
      else if (s[i] == ']')
      {
        if(st.empty() || st.top()!='['){
          flag = false;
          break;
        }
        st.pop();
      }
    }
    if(st.size()>0)
      flag = false;
    if (flag)
      cout << "yes";
    else
      cout << "no";
    cout << "\n";
  }
  return 0;
}