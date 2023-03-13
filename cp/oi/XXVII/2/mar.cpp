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

const int K = 19;
// #warning change K to 18

void solve(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<vector<int>>cnt(K);
    vector<vector<int>>end(n+1, vector<int>(K));
    vector<int>zero(K);
    for (int l = 1; l < K; l++){
        cnt[l].resize(1<<l);
        zero[l] = (1<<l);
        for (int i = l-1; i<n; i++){
            int mask = 0;
            for (int j = 0, idx = i-(l-1); j < l; j++, idx++){
                if (s[idx] == '1'){
                    mask += (1<<j);
                }
            }
            end[i][l] = mask;
            cnt[l][mask]++;
            if (cnt[l][mask] == 1) zero[l]--;
        }
        // debug(cnt[l]);
    }
    for (int i = 0; i<n; i++){
        debug(end[i]);
    }
    auto ans = [&](){
        for (int i = 1; i < K; i++){
            if (zero[i]){
                cout << i << "\n";
                return;
            }
        }
        assert(false);
    };
    ans();
    while (q--){
        int idx; cin >> idx;
        --idx;
        s[idx] = (s[idx] == '1' ? '0' : '1');
        // debug(s);
        for (int l = 1; l < K; l++){
            for (int r = idx, which = l-1; r < min(n, idx+K) && which >= 0; r++, which--){
                if (r+1 < l) continue;
                cnt[l][end[r][l]]--;
                if (cnt[l][end[r][l]] == 0) zero[l]++;
                if (s[idx] == '1') end[r][l] += (1<<which);
                else end[r][l] -= (1<<which);
                cnt[l][end[r][l]]++;
                if (cnt[l][end[r][l]] == 1) zero[l]--;
            }
        }
        // debug(zero);
        ans();
        // return;
    }
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