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
const int mod = 1e9+7;

void add(int& a, int b) {
    if((a += b) >= mod) a -= mod;
}
int sub2(int a, int b){
    a -= b;
    if (a < 0) a+=mod;
    return a;
}

int mul(int a, int b) {
    a %= mod, b %= mod;
    return a * b % mod;
}

void solve(){
    int q; cin >> q;
    vector<tuple<char, int, int>>zap(q + 1);
    bool sub_1 = true;
    for(int i = 1; i <= q; i++) {
        char type; cin >> type;
        if(type == 'S') zap[i] = {'S', -1, -1};
        else {
            int x, y; cin >> x >> y;
            zap[i] = {type, x, y};
            sub_1 &= (x == 0 || y == 0);
        }
    }
    if(sub_1) {
        int lo_left = 0, lo_right = 0;
        int high_up = 0, high_down = 0;
        for(auto [a, x, y] : zap) {
            if(a == 'S') {
                __int128_t one = high_up - high_down;
                __int128_t two = lo_right - lo_left;
                cout << (int)(one * two % mod) << "\n";
            } else {
                if(a == 'A') {
                    if (x == 0){
                        if (y > 0) high_up += y;
                        else high_down += y;
                    } else {
                        if (x > 0) lo_right += x;
                        else lo_left += x;
                    }
                } else {
                    if (x == 0){
                        if (y > 0) high_up -= y;
                        else high_down -= y;
                    } else {
                        if (x > 0) lo_right -= x;
                        else lo_left -= x;
                    }
                }
            }
        }
        return;
    }
    debug(2137);
    multiset<T>s;
    for (auto [type, x, y]: zap){
        if (type == 'A'){
            s.insert({x, y});
        } else if (type == 'D'){
            auto it = s.find({x, y});
            assert(it != s.end());
            s.erase(it);
        } else if (type == 'S') {
            if (s.size() < 2){
                cout << "0\n";
            } else {
                auto fst = *s.begin();
                auto nd = *s.rbegin();
                __int128_t one = fst.first * nd.second;
                __int128_t two = fst.second * nd.first;
                one -= two;
                if(one < 0) one *= -1;
                cout << (int)(one % mod) << '\n';
            }
        }
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