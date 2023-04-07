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
    int n, q; cin >> n >> q;
    vector<T>a(n+1);
    vector<int>ss = {-oo};
    for (int i = 1; i<=n; i++) {
        cin >> a[i].first >> a[i].second;
        ss.emplace_back(a[i].first);
        ss.emplace_back(a[i].second);
    }
    sort(ss.begin(), ss.end());
    ss.erase(unique(ss.begin(), ss.end()), ss.end());
    for (int i = 1; i<=n; i++){
        a[i].first = lower_bound(ss.begin(), ss.end(), a[i].first) - ss.begin();
        a[i].second = lower_bound(ss.begin(), ss.end(), a[i].first) - ss.begin();
    }
    vector<int>ord(n);
    iota(ord.begin(), ord.end(), 1);
    int M = 2*n+3;
    vector<vector<T>>event(M);
    //indeks przedzialu z najdalszym koncem do ktorego mozemy doskoczyc w jednym ruchu
    //gdy zaden -> loop
    for (int i = 1; i<=n; i++){
        event[a[i].first].emplace_back(i, 1);
        event[a[i].second].emplace_back(i, 0);
    }
    //dodaj lewe konce
    //check
    //usun prawe
    multiset<T>s;
    vector<vector<int>>up(n+1, vector<int>(K));
    for (int i = 1; i<M; i++){
        for (auto [id, work]: event[i]){
            if (work == 1){
                s.insert({a[id].second, id});
            }
        }
        for (auto [id, work]: event[i]){
            if (work == 0){
                assert(!s.empty());
                up[id][0] = s.rbegin()->second;
            }
        }
        for (auto [id, work]: event[i]){
            if (work == 0){
                s.erase(s.find({a[id].second, id}));
            }
        }
    }
    for (int i = 1; i<=n; i++){
        cerr << up[i][0] << " ";
    }
    cerr << "\n";
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