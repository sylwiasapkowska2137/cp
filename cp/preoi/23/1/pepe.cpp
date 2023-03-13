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
const int oo2 = 1e9, K = 30;
const int sz = 3e5+7;
int bit[sz];

void update(int x, int v){
    while (x < sz){
        bit[x] += v;
        x += (x&-x);
    }
}

int query(int x){
    int ans = 0;
    while (x > 0){
        ans += bit[x];
        x -= (x&-x);
    }
    return ans;
}

int query(int l, int r){
    return query(r) - query(l-1);
}

struct F{
    int x, y1, y2, add;
    F(){}
    F(int _x, int _y1, int _y2, int _add): x(_x), y1(_y1), y2(_y2), add(_add) {}
};

vector<tuple<int, int, int>>X, Y;
vector<F>sweep;
vector<int>ss;

bool check(int mid){
    ss.clear();
    sweep.clear();
    memset(bit, 0, sizeof(bit));
    // auto get = [&](int x){
    //     return lower_bound(ss.begin(), ss.end(), x) - ss.begin() + 1;
    // };
    bool anyX = 0, anyY = 0;
    for (auto &[x1, x2, y]: X){
        if (x1 + mid <= x2 - mid){
            sweep.emplace_back(x1+mid, y, y, 1);
            sweep.emplace_back(x2-mid, y, y, -1);
            anyX = 1;
            ss.emplace_back(y);
        }
    }
    for (auto &[y1, y2, x]: Y){
        if (y1 + mid <= y2 - mid){
            sweep.emplace_back(x, y1+mid, y2-mid, 0);
            ss.emplace_back(y1+mid);
            ss.emplace_back(y2-mid);
            anyY = 1;
        }
    }
    if (anyX == 0 || anyY == 0) return false;
    sort(ss.begin(), ss.end());
    ss.erase(unique(ss.begin(), ss.end()), ss.end());
    stable_sort(sweep.begin(), sweep.end(), [](auto &x, auto &y){
        return x.x == y.x ? x.add > y.add : x.x < y.x;
    });
    for (auto &[x, y1, y2, add]: sweep){
        if (add == 0) {
            y1 = lower_bound(ss.begin(), ss.end(), y1) - ss.begin() + 1;
            y2 = lower_bound(ss.begin(), ss.end(), y2) - ss.begin() + 1;
            if (query(y1, y2) > 0) return true;
        } else {
            y1 = lower_bound(ss.begin(), ss.end(), y1) - ss.begin() + 1;
            update(y1, add);
        }
    }
    return false;
}

void solve(){
    int n, m; cin >> n >> m;
    for (int i = 0; i<n; i++){
        int x1, x2, y; cin >> x1 >> x2 >> y;
        X.emplace_back(x1, x2, y);
    }
    for (int i = 0; i<m; i++){
        int y1, y2, x; cin >> y1 >> y2 >> x;
        Y.emplace_back(y1, y2, x);
    }

    int ans = 0;
    for (int b = K; b >= 0; b--){
        ans += (1<<b);
        if (!check(ans)) ans -= (1<<b);
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