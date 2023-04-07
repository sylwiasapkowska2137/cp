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

int cross(T a, T b, T c){
    a.first -= c.first;
    b.first -= c.first;
    a.second -= c.second;
    b.second -= c.second;
    return a.first * b.second - a.second * b.first;
}

int dot(T a, T b, T c){
    a.first -= c.first;
    b.first -= c.first;
    a.second -= c.second;
    b.second -= c.second;
    return a.first * b.second + a.second * b.first;
}

void solve(){
    int n; cin >> n;
    int X1, Y1, X2, Y2; cin >> X1 >> Y1 >> X2 >> Y2;
    vector<T>p(n+1);
    if (cross({X1, Y1}, {X2, Y2}, {0, 0}) <= 0){
        swap(X1, X2);
        swap(Y1, Y2);
    }
    for (int i = 1; i<=n; i++) cin >> p[i].first >> p[i].second;
    vector<int>need(n+1), ans(n+1, oo);
    for (int i = 1; i<=n; i++) cin >> need[i];
    set<int>off;
    for (int i = 1; i<=n; i++) off.insert(i);
    queue<int>q;
    for (int i = 1; i<=n; i++){
        //zapalam lampe i;
        if (ans[i] != oo) continue;
        ans[i] = i;
        q.push(i);
        while (q.size()){
            int v = q.front(); q.pop();
            off.erase(v);
            // debug(v);
            for (auto j: off){
                //jesli j lezy na v
                int A = cross(p[j], {p[v].first + X1, p[v].second + Y1}, p[v]);
                int B = cross({p[v].first + X2, p[v].second + Y2}, p[j], p[v]);
                if ((A == 0 && B == 0 && dot({p[v].first + X2, p[v].second + Y2}, p[j], p[v]) >= 0) || (A <= 0 && B <= 0 && (A != 0 || B != 0))){
                    debug(v, j);
                    need[j]--;
                    if (need[j] <= 0 && ans[j] > i){
                        ans[j] = i;
                        q.push(j);
                    }
                }
            }
        }        
    }
    for (int i = 1; i<=n; i++) cout << ans[i] << " ";
    cout << "\n";
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