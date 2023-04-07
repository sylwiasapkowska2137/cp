#include <vector>
#include <iostream>
#include <cassert>
#include <numeric>
// #pragma GCC optimize("O3", "unroll-loops")
using namespace std;

void __print(int x) {cerr << x;}
void __print(uint16_t x) {cerr << x;}
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
const int oo = 2e9+7;

void solve(){
    int n, s; cin >> n >> s;
    vector<int>a(n), jump(2*n), curr(n); //up(2*n), 
    int all = 0, mn = 0;
    for (int i = 0; i<n; i++) {
        cin >> a[i];
        all += a[i];
        mn = max(mn, a[i]);
    }
    debug(a);
    for (int rep = 0; rep<s; rep++){
        int d; cin >> d;
        if (mn > d) {
            cout << "NIE\n";
            continue;
        }
        if (d >= all){
            cout << "1\n";
            continue;
        }
        int r = 1, sum = a[0];
        for (int l = 0; l < n; l++){            
            while (sum + a[(r >= n ? r-n : r)] <= d){
                sum += a[(r >= n ? r-n : r)];
                assert(r != 2*(n-1));
                r++;
            }
            jump[l] = r;
            jump[l+n] = jump[l]+n;
            sum -= a[l];
        }
        int ptr = 0, ans = 0;
        while (ptr < n){
            ans++;
            ptr = jump[ptr];
        }        
        debug(d, jump, ans);
        iota(curr.begin(), curr.end(), 0);
        //check ans-1 for every start
        int8_t t = 0;
        for (int b = 0; b < 20; b++){
            bool ok = 0;            
            if ((ans-1)&(1<<b)){
                t++;
                for (int i = 0; i < n; i++) {
                    curr[i] = jump[curr[i]];
                    if (curr[i] >= i+n){
                        ok = 1;
                        break;
                    }
                }
                if (t == __builtin_popcount(ans-1)) {
                    if (ok){
                        ans--;
                        break;
                    }
                }
            }
            for (int i = 0; i<2*n; i++){
                if (jump[i] >= 2*n) {
                    jump[i] -= n;
                }
            }
            for (int i = 0; i<2*n; i++) jump[i] = jump[jump[i]];
        }
        cout << ans << "\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}