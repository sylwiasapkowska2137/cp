#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

const int maxN = 100000;
const int maxT = 1000000;

int amount;
int limit;
int program[maxN + 10][3];
int lastTime = -1;
int dp[maxT + 1];
std::vector<int> T[maxT + 1];

bool check(int minLevel)
{
  int result = 0;
  dp[0] = 0;
  for (int i = 1; i <= lastTime; ++i)
  {
    dp[i] = dp[i - 1];
    for (int j = 0; j < T[i].size(); ++j)
    {
      if (program[T[i][j]][2] < minLevel) continue;
      int b = program[T[i][j]][0] - 1;
//       printf("-- %d, b = %d, dp[b] = %d\n", T[i][j], b, dp[b]);
      dp[i] = std::max(dp[i], dp[b] + 1);
    }
    result = std::max(result, dp[i]);
  }

  return result >= limit;
}

int main(int argc, char** argv)
{
  scanf(" %d %d", &amount, &limit);
  int maxA = -1;
  for (int i = 1; i <= amount; ++i)
  {
    scanf(" %d %d %d", &program[i][0], &program[i][1], &program[i][2]);
    T[program[i][1]].push_back(i);
    lastTime = std::max(lastTime, program[i][1]);
    maxA = std::max(maxA, program[i][2]);
  }

//   printf("%d\n", check(5));

  int last = -1;
  for (int i = 0; i <= maxA; ++i)
  {
    if (check(i)) last = i;
    else break;
  }
  printf("%d\n", last);

  return 0;
}