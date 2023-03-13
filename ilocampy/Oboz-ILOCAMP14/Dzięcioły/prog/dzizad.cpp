#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define ff first
#define ss second

const int M = 3005;
int n, k;
vector <pair <int, int> > G[M];
bool visited[M];
int subtree[M];
pair <long long, long long> dp[M][M];
pair <long long, long long> tmp[M];
long long worstCase[M];

void count(int w) {   
    visited[w] = true;
    subtree[w]++;
    
    for (int i=0; i<G[w].size(); i++) {
        pair <int, int> s = G[w][i];
        if (!visited[s.ff]) {
            count(s.ff);
            worstCase[w] += s.ss;
            worstCase[w] += worstCase[s.ff];
            subtree[w] += subtree[s.ff];
            dp[w][1].ff += s.ss;
        }
    }
}

void DFS(int w) {   
    visited[w] = true;
    
    for (int i=0; i<G[w].size(); i++) {
        pair <int, int> s = G[w][i];
        if (!visited[s.ff]) {
            DFS(s.ff);
            
            for (int j=0; j<=subtree[w]; j++) {
                tmp[j].ff = dp[w][j].ff;
                tmp[j].ss = dp[w][j].ss;
            }
            
            for (int j=1; j<=subtree[s.ff]; j++) {
                // assuming there is a bird in vertex 'w'
                for (int used=subtree[w]-j; used>=1; used--) {
                    if (used > 1 && tmp[used].ff == 0)
                        continue;
                    
                    long long unUsedHollow = tmp[used].ff + dp[s.ff][j].ss;
                    long long usedHollow = tmp[used].ff + dp[s.ff][j].ff - s.ss;
                    
                    if (j == subtree[s.ff])
                        unUsedHollow = 0;
                    
                    dp[w][used+j].ff = max(dp[w][used+j].ff, max(unUsedHollow, usedHollow));
                }
                // there is no bird in vertex 'w'
                for (int used=subtree[w]-j-1; used>=0; used--) {
                    if (used > 0 && tmp[used].ss == 0)
                        continue;
                    
                    long long unUsedHollow = tmp[used].ss + dp[s.ff][j].ss;
                    long long usedHollow = tmp[used].ss + dp[s.ff][j].ff + s.ss;
                    
                    if (j == subtree[s.ff])
                        unUsedHollow = 0;
                    
                    dp[w][used+j].ss = max(dp[w][used+j].ss, max(unUsedHollow, usedHollow)); 
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    
    for (int i=0; i<n-1; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }
    
    count(1);
    
    for (int i=1; i<=n; i++)
        visited[i] = false;
    
    DFS(1);
    
    printf("%lld\n", worstCase[1] - max(dp[1][k].ff, dp[1][k].ss));
    
    return 0;
}