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

int C2(int x){
    return x*(x-1)/2;
}

int dist(T &a, T &b){
    int x = (a.first - b.first);
    int y = (a.second - b.second);
    return x*x + y*y;
}

void solve(){
    int n; cin >> n;
    vector<T>points;
    for (int i = 0; i<n; i++){
        int x, y; cin >> x >> y;
        x *= 2; y *= 2;
        points.emplace_back(x, y);
    }
    map<pair<int, T>, int>cnt;
    int ans = 0;
    for (int i = 0; i<n; i++){
        for (int j = i+1; j<n; j++){
            T mid = {(points[i].first + points[j].first)/2, (points[i].second + points[j].second)/2};
            cnt[{dist(points[i], points[j]), mid}]++;
        }
    }
    for (auto [d, x]: cnt){
        ans += C2(x);
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