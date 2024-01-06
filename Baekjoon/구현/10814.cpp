#include <bits/stdc++.h>
using namespace std;
struct member{
  int age,i;
  string name;
};
bool memberCompare(member a,member b){
  return a.age < b.age || (a.age == b.age && a.i<b.i);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<member> arr(n + 1);

  for (int i = 1; i <= n; i++){
    cin >> arr[i].age >> arr[i].name;
    arr[i].i = i;
  }
  sort(arr.begin() + 1, arr.end(), memberCompare);

  for (int i = 1; i <= n; i++)
    cout << arr[i].age << " " << arr[i].name << "\n";
  return 0;
}