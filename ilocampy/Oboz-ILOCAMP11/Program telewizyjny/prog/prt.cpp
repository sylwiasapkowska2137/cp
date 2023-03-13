#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

const int maxAmount = 100000;

int amount;
int limit;
int program[maxAmount + 2][3];
int dp[maxAmount + 1];

bool cmp(const int& a, const int& b)
{
  return program[a][1] < program[b][1];
}

bool check(int minLevel)
{
  std::vector<int> V;
  for (int i = 1; i <= amount; ++i)
  {
    if (program[i][2] >= minLevel) V.push_back(i);
  }
  if (V.size() == 0) return false;
  std::sort(V.begin(), V.end(), cmp);

  dp[0] = 1;
  int result = 1;
  for (int i = 1; i < V.size(); ++i)
  {
    int u = V[i];
    int t = amount + 1;
    program[t][1] = program[u][0];
    int* p = std::lower_bound(&V[0], &V[i], t, cmp);
    if (p == &V[0]) dp[i] = 1;
    else
    {
      --p;
      int x = p - &V[0];
      dp[i] = std::max(dp[i - 1], dp[x] + 1);
      result = std::max(result, dp[i]);
    }
  }

  if (result >= limit) return true;
  return false;
}

int main(int argc, char** argv)
{
  scanf(" %d %d", &amount, &limit);
  for (int i = 1; i <= amount; ++i)
  {
    scanf(" %d %d %d", &program[i][0], &program[i][1], &program[i][2]);
  }

  if (!check(0))
  {
    puts("-1");
    return 0;
  }

  int begin = 1, end = 1000000;
  while (begin < end)
  {
    int mid = (begin + end + 1) / 2;
    if (check(mid)) begin = mid;
    else end = mid - 1;
  }

  printf("%d\n", begin);

  return 0;
}