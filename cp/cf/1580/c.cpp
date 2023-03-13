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

typedef pair<int, int> T;
typedef tuple<int, int, int> F;
const int s = 400;

void solve(){
    int n, m; cin >> n >> m;
    vector<T>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i].first >> a[i].second;
    vector<int>open(n+1, -1);
    vector<vector<F>>que(s+2);
    vector<int>pref(m+2);
    auto decompose = [&](int type, int l, int r){
        auto [x, y] = a[type];
        debug(type, l, r);
        for (int i = l; i+x<=r; i+=(x+y)){
            pref[i+x]++;
            pref[min(r+1, i+x+y)]--;
            debug(i+x, min(r+1, i+x+y));
        }
    };

    for (int i = 1; i<=m; i++){
        int op, k; cin >> op >> k;
        if (op == 1){
            open[k] = i;
        } else {
            //[open[k], i-1]
            if (a[k].first + a[k].second >= s){
                decompose(k, open[k], i-1);
            } else {
                que[a[k].first + a[k].second].emplace_back(k, open[k], i-1);
            }
            open[k] = -1;
        }
    }
    for (int i = 1; i<=n; i++) {
        if (open[i] != -1){
            if (a[i].first + a[i].second >= s){
                decompose(i, open[i], m);
            } else {
                que[a[i].first + a[i].second].emplace_back(i, open[i], m);
            }
        }
    }
    for (int i = 1; i<=m; i++) pref[i]+=pref[i-1];
    // debug(pref);
    // return;
    vector<int>ans(m+1);
    vector<vector<T>>event(m+2);
    vector<int>now;
    for (int A = 2; A < s; A++){
        debug(A);
        for (int i = 1; i<=m; i++) event[i].clear();
        for (auto [type, l, r]: que[A]){
            debug(type, l, r);
            event[l].emplace_back(type, 1);
            event[r+1].emplace_back(type, -l);
        }
        now.assign(A+2, 0);
        for (int i = 1; i<=m; i++){
            for (auto [type, which]: event[i]){
                if (which == 1){
                    for (int r = 0; r < A; r++){
                        if (((r-i)%A+A)%A >= a[type].first){
                            now[r]++;
                        }
                    }
                } else {
                    int l = -which;
                    for (int r = 0; r < A; r++){
                        if (((r-l)%A + A)%A >= a[type].first){
                            now[r]--;
                        }
                    }
                }
            }
            ans[i] += now[i%A]; 
        }
    }
    for (int i = 1; i<=m; i++){
        cout << ans[i] + pref[i] << "\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}