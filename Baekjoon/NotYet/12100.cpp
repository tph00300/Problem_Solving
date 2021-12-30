#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int maxBlock;
void dfs(int num,vector<vector<int> > gs){
  int i, j, k;
  if (num > 5)
    return;

  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      maxBlock = max(maxBlock, gs[i][j]);
  // right
  vector<vector<int> > rightGs(n + 1, vector<int>(n + 1, 0));
  for (i = 1; i <= n; i++)
  {
    vector<int> temp;
    bool flag = false;
    for (j = n; j >= 1; j--)
    {
      if(gs[i][j]!=0){
        if(flag==true && temp.back()==gs[i][j]){
          temp[temp.size() - 1] += gs[i][j];
          flag = false;
        } else {
          temp.push_back(gs[i][j]);
          flag = true;
        }
      }
    }
    for (j = n, k = 0; j >= 1 && k < temp.size(); j--,k++)
      rightGs[i][j] = temp[k];
    for (j; j > 0; j--)
      rightGs[i][j] = 0;
  }
  dfs(num + 1, rightGs);
  // left
  vector<vector<int> > leftGs(n + 1, vector<int>(n + 1, 0));
  for (i = 1; i <= n; i++)
  {
    vector<int> temp;
    bool flag = false;
    for (j = 1; j <= n; j++)
    {
      if(gs[i][j]!=0){
        if(flag==true && temp.back()==gs[i][j]){
          temp[temp.size() - 1] += gs[i][j];
          flag = false;
        } else {
          temp.push_back(gs[i][j]);
          flag = true;
        }
      }
    }
    for (j = 1, k = 0; j <= n && k < temp.size(); j++,k++)
      leftGs[i][j] = temp[k];
    for (j; j <= n; j++)
      leftGs[i][j] = 0;
  }
  dfs(num + 1, leftGs);
  // up
  vector<vector<int> > upGs(n + 1, vector<int>(n + 1, 0));
  for (i = 1; i <= n; i++)
  {
    vector<int> temp;
    bool flag = false;
    for (j = 1; j <= n; j++)
    {
      if(gs[j][i]!=0){
        if(flag==true && temp.back()==gs[j][i]){
          temp[temp.size() - 1] += gs[j][i];
          flag = false;
        } else {
          temp.push_back(gs[j][i]);
          flag = true;
        }
      }
    }
    for (j = 1, k = 0; j <= n && k < temp.size(); j++,k++)
      upGs[j][i] = temp[k];
    for (j; j <= n; j++)
      upGs[j][i] = 0;
  }
  dfs(num + 1, upGs);
  // down
  vector<vector<int> > downGs(n + 1, vector<int>(n + 1, 0));
  for (i = 1; i <= n; i++)
  {
    vector<int> temp;
    bool flag = false;
    for (j = n; j >= 1; j--)
    {
      if(gs[j][i]!=0){
        if(flag==true && temp.back()==gs[j][i]){
          temp[temp.size() - 1] += gs[j][i];
          flag = false;
        } else {
          temp.push_back(gs[j][i]);
          flag = true;
        }
      }
    }
    for (j = n, k = 0; j >= 1 && k < temp.size(); j--,k++)
      downGs[j][i] = temp[k];
    for (j; j >= 1; j--)
      downGs[j][i] = 0;
  }
  dfs(num + 1, downGs);
}
int main()
{
  int i, j, k;

  scanf("%d", &n);

  vector<vector<int> > gs(n + 1, vector<int>(n + 1, 0));

  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      scanf("%d", &gs[i][j]);
      maxBlock = max(maxBlock, gs[i][j]);
    }
  }
  dfs(0, gs);
  printf("%d", maxBlock);
  return 0;
}