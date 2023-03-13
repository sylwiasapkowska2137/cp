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

// #define int long long
typedef pair<int, int> T;

struct F{
    int x[3], i;
};

void solve(){
    int n; cin >> n;
    vector<vector<F>>a(3);
    for (int i = 0; i<n; i++){
        F now;
        for (int j = 0; j<3; j++) cin >> now.x[j];
        now.i = i;
        for (int j = 0; j<3; j++){
            a[j].emplace_back(now);
        }
    }
    for (int i = 0; i<3; i++) {
        sort(a[i].begin(), a[i].end(), [&](auto x, auto y){return x.x[i] == y.x[i] ? x.i < y.i : x.x[i] < y.x[i];});
    }
    vector<bool>used(n+1);
    while(1){
        for (int i = 0; i<3; i++){
            while (a[i].size() && used[a[i].back().i]) a[i].pop_back();
            if (a[i].empty()){
                cout << "-1\n";
                exit(0);
            }
        }
        bool any = 0;
        for (int i = 0; i<3; i++){
            for (int j = i+1; j<3; j++){
                if (a[i].back().i == a[j].back().i){
                    used[a[i].back().i] = 1;
                    a[i].pop_back();
                    a[j].pop_back();
                    any = 1;
                    break;
                }
            }
            if (any) break;
        }
        if (any) continue;
        //all i different
        for (int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
                if (i == j) continue;
                if (a[i].back().x[i] <= a[j].back().x[i]){
                    used[a[j].back().i] = 1;
                    a[j].pop_back();
                    any = 1;
                    break;
                }
            }
            if (any) break;
        }
        if (any) continue;
        int ans = 0;
        for (int i = 0; i<3; i++){
            ans += a[i].back().x[i];
        } 
        cout << ans << "\n";
        exit(0);
    }
    cout << "-1\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}