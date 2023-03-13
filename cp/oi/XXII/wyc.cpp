//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
typedef pair<int, int> T;
const int oo = 1e18+210, K = 63;
const int mx = 121;

int mul(int a, int b){
    if (!b) return 0;
    if ((oo+b-1)/b < a) return oo;
    return min(oo, a*b);
}

void add(int &a, int b){
    if (a == oo || b == oo) a = oo;
    else a = min(a+b, oo);
    // a += b;
}

int n, N, k;

struct Mat{
    vector<vector<int>>a;

    void init(){
        a.assign(N+1, vector<int>(N+1, 0));
    }

    void matmul(const Mat &one){
        for (int i = 0; i<=N; i++){
            for (int j = 0; j<=N; j++){
                for (int ck = 0; ck<=N; ck++){
                    add(a[i][j], mul(one.a[i][ck], one.a[ck][j]));
                    if (a[i][j] == oo) break;
                }
            }
        }
    }

    void d(){
        // cerr << "    ";
        // for (int i = 0; i<=N; i++) cerr << i << " ";
        // cerr << "\n";
        // cerr << "-----------------------------\n";
        for (int i = 0; i<=N; i++){
            // cerr << i;
            // cerr << " | ";
            for (int j = 1; j<=N; j++){
                cerr << a[i][j] << " ";
            }
            cerr << "\n";
        }
    }
} M[K];

void solve(){
    int m; cin >> n >> m >> k;
    N = 3*n;
    M[0].init();
    for (int i = 0; i<n; i++){
        M[0].a[3*i][3*i+1] = 1;
        M[0].a[3*i+1][3*i+2] = 1;
        M[0].a[3*i+2][N] = 1;
    }
    M[0].a[N][N] = 1;
    for (int i = 0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        --a;--b;
        M[0].a[3*a+2][3*b+3-c]++;
    }
    int pot = -1;
    for (int rep = 0; rep < K; rep++){
        if (rep) {
            M[rep].init();
            M[rep].matmul(M[rep-1]);
        }
        int s = -n;
        for (int i = 0; i<n; i++){
            add(s, M[rep].a[3*i+2][N]);
            if (s == oo) break;
        }
        // if (rep == 4 || rep == 5){
        //     M[rep].d();
        // }
        // for (int i = 0; i<n; i++){
        //     for (int j = 0; j<mx; j++){
        //         add(s, mul(M[rep].a[3*i+2][j], M[0].a[j][N]));
        //         if (s == oo) break;
        //     }
        //     if (s == oo) break;
        // }
        // tmp.matmul(M[rep], M[0]);
        // for (int i = 0; i<n; i++) {
            // add(s, tmp.a[3*i+2][N]);
            // if (s == oo) break;
        // }
        debug((1LL<<rep), s);
        if (s >= k){
            pot = rep;
            break;
        }
    }
    if (pot == -1){
        cout << "-1\n";
        return;
    }
    vector<int>now(mx, 0), tmp(mx);
    for (int i = 0; i<n; i++) now[3*i+2] = 1;
    int mask = 0;
    bool any = 0;
    for (int rep = pot-1; rep >= 0; rep--){
        tmp.assign(mx, 0);
        debug(mask, rep, (1<<rep));
        // M[rep].d();
        for (int i = 0; i<=N; i++){ //we dont care about exact values, just about the sum
            for (int j = 0; j<=N; j++){
                add(tmp[i], mul(now[j], M[rep].a[j][i]));
                if (tmp[i] == oo) break;
            }
        }
        int s = tmp[N]-n;
        debug(s, mask+(1<<rep));
        if (s < k){
            now = tmp;
            mask += (1LL<<rep);
        } else {
            any = 1;
        }
        
    }
    if (!any) mask = (1LL<<pot)-1;
    cout << mask << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}