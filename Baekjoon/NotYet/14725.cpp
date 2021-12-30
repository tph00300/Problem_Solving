#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;
vector<map<string, vector<int> > > floor2[16];
void dfs(int f, int num)
{
  int i;
  for (i = 1; i < f; i++)
    printf("--");
  cout << floor[f][num].name << endl;
  for (i = 0; i<floor[f][num].child.size(); i++)
  {
    dfs(f + 1, floor[f][num].child[i]);
  }
}
int main()
{
  int n,i,j,k;

  scanf("%d", &n);

  for (i = 1; i <= n; i++)
  {
    int m;
    scanf("%d", &m);
    string temp;
    int father=-1;
    for (j = 1; j <= m; j++)
    {
      cin >> temp;
      bool flag = false;
      for (k = 0; k < floor[j].size(); k++)
      {
        if(floor[j][k].name==temp){
          if(father!=-1)
            floor[j - 1][father].child.push_back(k);
          father = k;
          flag = true;
          break;
        }
      }
      if(flag==false){
        node nodetmp;
        nodetmp.name = temp;
        floor[j].push_back(nodetmp);
        if(father!=-1)
          floor[j - 1][father].child.push_back(floor[j].size() - 1);
        father = floor[j].size() - 1;
      }
    }
  }
  for (i = 0; i < floor[1].size(); i++)
  {
    dfs(1, i);
  }
  return 0;
}