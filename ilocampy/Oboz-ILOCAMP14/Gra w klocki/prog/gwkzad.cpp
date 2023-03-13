#include <cstdio>
#include <iostream>

using namespace std;

int n, k;
long long X[1000000];
long long H[1000000];
int DP[3][1000000];

int main()
{
  scanf("%d %d", &n, &k);
  X[0] = -1e14;
  X[n + 1] = 1e14;
  for(int i = 1; i <= n; i++)
    scanf("%d %d", &X[i], &H[i]);
  for(int i = 1; i <= n; i++)
  {
    // 0 - upada w lewo
    if(X[i] - H[i] > X[i - 1])
      DP[0][i] = max(DP[0][i - 1], DP[1][i - 1]) + 1;
    if(X[i] - H[i] > X[i - 1] + H[i - 1])
      DP[0][i] = max(DP[0][i], DP[2][i - 1] + 1);

    // 1 - w ogole nie upada
    DP[1][i] = max(DP[0][i - 1], max(DP[1][i - 1], DP[2][i - 1]));

    // 2 - upada w prawo
    if(X[i] + H[i] < X[i + 1])
      DP[2][i] = max(DP[0][i - 1], max(DP[1][i - 1], DP[2][i - 1])) + 1;
  }
  int res = max(DP[0][n], max(DP[1][n], DP[2][n]));
  if(res == k)
    printf("NIE\n");
  else
    printf("TAK %d\n", res);
}
