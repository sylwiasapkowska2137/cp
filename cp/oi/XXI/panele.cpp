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
const int oo = 1e9+7;

void solve(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    int ans = 1;
    int s = sqrt(max(b, d))+20;
    for (int x = 1; x <= s+20; x++){
        if ((a + x - 1)/x <= b/x && (c + x - 1)/x <= d/x){
            ans = x;
        }
    }
    for (int rep = 0; rep < 2; rep++){
        for (int alpha = 1; alpha <= s+20; alpha++){
            int L1 = (a + alpha - 1)/alpha;
            int R1 = b/ alpha;
            int x = R1;
            if (!x) break;
            int L2 = (c + x - 1)/x;
            int R2 = d/x;
            if (L1 <= R1 && L2 <= R2){
                ans = max(ans, x);
            }        
        }
        swap(a, c);
        swap(b, d);
    }
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}