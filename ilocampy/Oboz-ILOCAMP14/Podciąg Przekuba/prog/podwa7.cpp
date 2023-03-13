#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#   define debug(args...) {}
#else
#   define debug(args...) fprintf(stderr, args)
#endif

int n;
const int N = 5009;
int dp[N][N], a[N], b[N], nxa[N], nxb[N], mrk[N], oca[N], ocb[N];
int na[N][N], nb[N][N], ch[N][N], fst[N];

inline int calc(int k) {
    return 1 + dp[nxa[k]][nxb[k]];
}

struct cmp {
    bool operator()(int x, int y) {
        int cx = calc(x), cy = calc(y);
        if(cx != cy) return cx > cy;
        return x < y;
    }
};


int main() {
    int i, j, k, n, m;
    scanf("%d", &k);
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for(i = 0; i < m; i++) scanf("%d", &b[i]);
    a[n] = 5001;
    b[m] = 5002;
    for(i = 0; i < n; i++) oca[a[i]]++;
    for(j = 0; j < m; j++) {
        oca[b[j]]++;
        if(fst[b[j]] == 0 && b[0] != b[j]) fst[b[j]] = j;
    }
    for(j = 1; j <= k; j++) {
        if(oca[j] == 0) {
            printf("1\n%d\n", j);
            return 0;
        }
        oca[j] = 0;
        ocb[j] = -1;
    }
    dp[n][m] = 1;
    //for(i = 0; i <= n; i++) dp[i][m] = 1;
    //for(i = 0; i <= m; i++) dp[n][i] = 1;
    for(i = 1; i <= k; i++) nxa[i] = n, nxb[i] = m;
    for(i = n - 1+1; i >= 0; i--) {
        priority_queue<int, vector<int>, cmp> pq;
        for(j = 1; j <= k; j++) nxb[j] = m, pq.push(j), mrk[j] = -1;
        for(j = m - 1+1; j >= 0; j--) {
            if(i == n && j == m) continue;
            if(i < n && j < m && fst[a[i]] > j) break;
            while(mrk[pq.top()] != -1) {
                int x = pq.top();
                pq.pop();
                nxb[x] = mrk[x];
                mrk[x] = -1;
                pq.push(x);
            }
            int x = pq.top();
            dp[i][j] = calc(x);
            na[i][j] = nxa[x];
            nb[i][j] = nxb[x];
            ch[i][j] = x;
            mrk[b[j]] = j;
        }
        nxa[a[i]] = i;
    }
    int mn = INT_MAX;
    int mi = -1, mj = -1;
    for(i = 0; i <= n; i++) {
        if(oca[a[i]] == 0) {
            for(j = 0; j <= m; j++) {
                if(ocb[b[j]] < i && a[i] == b[j] && mn > dp[i][j]) mn = dp[i][j], mi = i, mj = j;
                if(j == m && i < n && ocb[a[i]] < i && mn > dp[i][j]) mn = dp[i][j], mi = i, mj = j;
                if(i == n && j < m && oca[b[j]] == 0 && mn > dp[i][j]) mn = dp[i][j], mi = i, mj = j;
                ocb[b[j]] = i;
            }
        }
        oca[a[i]]++;
    }
    // SE FOR 0 PROVAVEL TEM QUE TRATAR SEPARADO
    printf("%d\n", mn);
    i = mi; j = mj;
    for(int g = 0; g < mn - 1; g++) {
        //printf("start at %d,%d\n", i, j);
        //assert(a[i] == b[j]);
        printf("%d ", min(a[i], b[j]));
        int x = i, y = j;
        if(g < mn - 2) i = na[x][y], j = nb[x][y];
    }
    printf("%d\n", ch[i][j]);
    return 0;
}
