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
const int K = 30;
#define empty gowno
vector<int>empty(K, -1);

struct trie{
    vector<vector<int>>tab;
    vector<int>cnt;

    trie(){
        tab.emplace_back(empty);
        cnt.resize(K);
    }

    int ti(char c){
        return (int)(c-'a');
    }

    void add(string &s){
        int v = 0;
        for (auto c: s){
            if (tab[v][ti(c)] == -1){
                tab[v][ti(c)] = (int)tab.size();
                if (v) cnt[ti(c)]++;
                tab.emplace_back(empty);
            }
            v = tab[v][ti(c)];
        }
    }
};

void solve(){
    int n; cin >> n;
    vector<string>a(n);
    for (int i = 0; i<n; i++) cin >> a[i];
    trie pref, suf;
    int ans = 0;
    vector<int>t(K);
    for (auto &x: a){
        if ((int)x.size() == 1) t[x[0]-'a'] = 1;
        pref.add(x);
        reverse(x.begin(), x.end());
        suf.add(x);
    }
    ans += ((int)pref.tab.size() - 1) * ((int)suf.tab.size() - 1);
    debug(ans);
    for (int i = 0; i<K; i++){
        ans -= pref.cnt[i] * suf.cnt[i];
        ans += t[i];
    }
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}