//Sylwia Sapkowska
#include <bits/stdc++.h>
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
#ifndef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve(){
    int n, m; cin >> n >> m;
    vector<int>pa(n+1), pb(m+1), a(n+1), b(m+1), s;
    for (int i = 1; i<=n; i++){
        cin >> a[i];
        s.emplace_back(a[i]);
    }
    for (int i = 1; i<=m; i++){
        cin >> b[i];
        s.emplace_back(b[i]);
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    for (int i = 1; i<=n; i++) a[i] = lower_bound(s.begin(), s.end(), a[i])-s.begin()+1;
    for (int i = 1; i<=m; i++) b[i] = lower_bound(s.begin(), s.end(), b[i])-s.begin()+1;
    vector<int>cnt(n+m+2, -1);
    for (int i = 1; i<=n; i++){
        pa[i] = cnt[a[i]];
        cnt[a[i]] = i;
    }
    cnt.assign(n+m+2, -1);
    for (int i = 1; i<=m; i++){
        pb[i] = cnt[b[i]];
        cnt[b[i]] = i;
    }
    // debug(pa);
    // debug(pb);
    vector<int>help(m+1);
    vector<vector<int>>dp(2, vector<int>(m+1));
    //trick: skoro dp[i][j] = dp[prevAi - 1][prevBj - 1] + 2, to jak idziemy pętlą najpierw po i, później po j, to prevAi jest ustalone. Skoro musi byc spełniony warunek, ze a[i] == b[j], to dla każdego ustalonego prevAi mamy pewien odpowiadający zbiór prevBi, dla a[i] != a[i'] są to różne zbiory. Z kolei, jeśli a[i] = a[i'], i < i', to prev(i') = i. zatem możemy utrzymywać pomocniczą tablicę, w której będziemy zapisywać wartości dp dla prevBj.
    for (int i = 1; i<=n; i++){
        int k = ((i&1) ? 1 : 0);
        dp[k].assign(m+1, 0);
        for (int j = 1; j<=m; j++){
            dp[k][j] = max(dp[k^1][j], dp[k][j-1]);
            if (a[i] == b[j] && pa[i] != -1 && pb[j] != -1) {
                dp[k][j] = max(dp[k][j], help[pb[j]]+2);  
            }
        }
        for (int j = 1; j<=m; j++){
            if (a[i] == b[j]){
                help[j] = dp[k^1][j-1];
            }
        }
    }
    cout << dp[(n&1) ? 1 : 0][m] << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}