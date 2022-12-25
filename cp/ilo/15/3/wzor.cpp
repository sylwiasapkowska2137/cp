#include <bits/stdc++.h>
#include <sys/time.h>
 
using namespace std;
 
typedef long long int LL;
 
#define st first
#define nd second
#define PII pair <int, int>
 
const int N = 207;
const LL inf = 200LL * 1000 * 1000 * 1000 + 9LL;
 
int n;
string s;
LL cost[N];
LL dp[N][N][N];
 
int main(){
        ios_base::sync_with_stdio(false);
        cin >> n >> s;
        for(int i = 1; i <= n; ++i)
                cin >> cost[i];
 
        for(int l = 0; l < n; ++l)
                for(int i = 1; i + l <= n; ++i){
                        for(int j = 1; j <= l + 1; ++j){
                                dp[i][i + l][j] = inf;
                                for(int ii = i + l; i + j <= ii; --ii)
                                        dp[i][i + l][j] = min(dp[i][i + l][j], dp[i][ii - 1][j] + dp[ii][i + l][0]);
 
                                for(int ii = i; ii + j <= i + l; ++ii)
                                        dp[i][i + l][j] = min(dp[i][i + l][j], dp[i][ii][0] + dp[ii + 1][i + l][j]);
                               
                                if(j == 1)
                                        dp[i][i + l][1] = min(dp[i][i + l][1], min(dp[i + 1][i + l][0], dp[i][i + l - 1][0]));
                                else if(s[i - 1] == s[i + l - 1])
                                        dp[i][i + l][j] = min(dp[i][i + l][j], dp[i + 1][i + l - 1][j - 2]);
                        }
                       
                        dp[i][i + l][0] = inf;
                        for(int j = 1; j <= l + 1; ++j)
                                dp[i][i + l][0] = min(dp[i][i + l][0], dp[i][i + l][j] + cost[j]);
                }
 
        cout << dp[1][n][0];
        return 0;
}
 