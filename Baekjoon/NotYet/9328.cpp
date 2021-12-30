#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
char map[102][102]={'`'};
int n, m;
int mx[5] = {0, -1, 0, 1, 0}, my[5] = {0, 0, 1, 0, -1};
bool keys[27];
void Initialize(){
  memset(map, 0, sizeof(map));

}
int main()
{
  int testcase, t;

  scanf("%d", &testcase);

  for (t = 1; t <= testcase; t++)
  {
    
    int i, j, k;

    scanf("%d %d", &n, &m);
    
    for (i = 1; i <= n; i++)
      scanf("%s", map[i][1]);
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
      {
        printf("%c", map[i][j]);
      }
      printf("\n");
    }
    char tempKeys[27];
    scanf("%s", tempKeys);
    int keyN = strlen(tempKeys);
    for (i = 0; i < keyN; i++)
    {
      if(tempKeys[0]=='0')
        continue;
      keys[tempKeys[i] - 'a' + 1] = true;
    }
  }
  return 0;
}