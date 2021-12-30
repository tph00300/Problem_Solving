#define INF 1000000000
#define MAX 16
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <memory.h>
using namespace std;
int road[MAX][MAX],n;
int ans_bit;
int min_temp = INF;
int cost[MAX][1<<MAX];
int dfs(int city,int bit){
  if(bit==ans_bit)
    return road[city][0] ? road[city][0] : INF;
  if(cost[city][bit]!=-1)
    return cost[city][bit];
  cost[city][bit] = INF;  
  for (int i = 0; i < n; i++)
  {
    if(road[city][i]==0 || bit & (1<<i))
      continue;
    cost[city][bit] = min(cost[city][bit], dfs(i, bit | (1 << i)) + road[city][i]);
  }
  return cost[city][bit];
}
int main()
{
  scanf("%d", &n);

  int i, j, k;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &road[i][j]);
  ans_bit = (1 << n) - 1;
  memset(cost, -1, sizeof(cost));
  printf("%d", dfs(0, 1));
  return 0;
}