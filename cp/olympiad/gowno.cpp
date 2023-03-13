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
typedef long double ld;
const int oo = 1e18, oo2 = 1e9+7, K = 30;

struct segment{
    T a, b;
    void read(){
        cin >> a.first >> a.second >> b.first >> b.second;
        if (a.first > b.first) swap(a, b);
    }

    ld pos(int what){
        if (a.first == b.first) return oo;
        return (ld)(b.second * a.second - b.first * a.first + what * (a.second - b.second))/(a.first - b.first);
    }
};

int X;
vector<segment>a;
bool cmp(const T &x, const T &y) { return a[x.second].pos(X) < a[y.second].pos(X); }

bool intersect(int i, int j){
    
    if (i == j) return false;
    return false;
}

void solve(){
    int n; cin >> n;
    a.resize(n);
    for (int i = 0; i<n; i++) a[i].read();
    vector<T>events;
    for (int i = 0; i<n; i++){
        events.emplace_back(a[i].a.first, i);
        events.emplace_back(a[i].b.first, i);
    }
    sort(events.begin(), events.end());
    set<T, decltype(cmp)*>sweep(cmp);
    vector<bool>vis(n);
    auto nxt = [&](auto x){
        return x == sweep.end() ? sweep.begin() : ++x;
    };
    auto prv = [&](auto x){
        return x == sweep.begin() ? (--sweep.end()) : --x;
    };
    for (auto [t, i]: events){
        X = t;
        if (!vis[i]){
            auto it = sweep.lower_bound(T{t, i});
            auto it2 = nxt(it);
            if (intersect(i, it2->second)){
                //wow, znalazlam przeciecie
                break;
            }
            it2 = prv(it);
            if (intersect(i, it2->second)){
                //wow, znalazlam przeciecie
                break;
            }
        } else {
            auto it = sweep.lower_bound(T{t, i});
            auto it2 = prv(it);
            sweep.erase(it);
            auto it3 = nxt(it2);
            if (intersect(it2->second, it3->second)){
                //gowno
                break;
            }
        } 
        vis[i] = 1;
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