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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
    int n, m; cin >> n >> m;
    vector a(n+2, vector<char>(m+2));
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    auto fix = [&](){
        for (int i = 1; i<=n; i++){
            int mn = oo, mx = -oo;
            for (int j = 1; j<=m; j++){
                if (a[i][j] == '#'){
                    mn = min(mn, j);
                    mx = max(mx, j);
                }
            }
            for (int j = mn; j <= mx; j++) a[i][j] = '#';
        }
        for (int j = 1; j<=m; j++){
            int mn = oo, mx = -oo;
            for (int i = 1; i<=n; i++){
                if (a[i][j] == '#'){
                    mn = min(mn, i);
                    mx = max(mx, i);
                }
            }
            for (int i = mn; i <= mx; i++) a[i][j] = '#';
        }
    };
    T pos = {-1, -1};
    fix();
    fix();
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){
            if (a[i][j] == '#' && pos.first == -1){
                pos = {i, j};
                break;
            }
        }
    }
    queue<T>q;
    q.push(pos);
    vector vis(n+2, vector<int>(m+2));
    vis[pos.first][pos.second] = 1;
    vector<int>X = {-1, 1, 0, 0};
    vector<int>Y = {0, 0, -1, 1};
    vector<T>A = {pos}, B;
    while (q.size()){
        T v = q.front();q.pop();
        for (int k = 0; k<4; k++){
            int x = v.first + X[k];
            int y = v.second + Y[k];
            if (x >= 1 && y >= 1 && x <= n && y <= m && !vis[x][y] && a[x][y] == '#'){
                vis[x][y] = 1;
                A.emplace_back(x, y);
                q.push(T{x, y});
            }
        }
    }
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){
            if (!vis[i][j] && a[i][j] == '#'){
                B.emplace_back(i, j);
            }
        }
    }
    auto connect = [&](int aa, int b, int c, int d){
        debug(aa, b, c, d);
        for (int i = b; i<=d; i++){
            a[aa][i] = '#';
        }  
        if (aa > c) swap(aa, c);
        for (int i = aa; i<=c; i++){
            a[i][d] = '#';
        }
    };
    if ((int)B.size()){
        debug(A, B);
        if (pos.second < B[0].second){
            //left upper and right lower
            int mxA = -oo, mnA = -oo;
            for (auto [x, y]: A){
                mxA = max(mxA, y);
                mnA = max(mnA, x);
            }
            int mnB = oo, mxB = oo;
            for (auto [x, y]: B){
                mnB = min(mnB, y);
                mxB = min(mxB, x);
            }
            connect(mnA, mxA, mxB, mnB);
        } else {
            int mxA = oo, mnA = -oo;
            for (auto [x, y]: A){
                mxA = min(mxA, y);
                mnA = max(mnA, x);
            }
            int mnB = oo, mxB = -oo;
            for (auto [x, y]: B){
                mnB = min(mnB, x);
                mxB = max(mxB, y);
            }
            connect(mnA, mxA, mnB, mxB);
        }
        fix();
        fix();
    }
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){
            cout << a[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}