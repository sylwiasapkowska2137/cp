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

#define int long long
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;
const int mx = 1e6+7;
// #warning change mx to 1e6+7

void solve(){
    int n; cin >> n;
    if (n == 1){
        cout << "1\n1 1\n";
        return;
    }
    vector<int>prime(mx+1), p;
    iota(prime.begin(), prime.end(), 0);
    for (int i = 2; i<mx; i++){
        if (prime[i] == i){
            p.emplace_back(i);
            for (int j = i*i; j < mx; j+=i){
                if (prime[j] == j) prime[j] = i;
            }
        }
    }
    // debug(p);
    auto d = [&](int x){
        if (x == 1) return 1LL;
        int ans = 1, prev = -1, cnt = 0;
        while (prime[x] != x){
            if (prime[x] == prev){
                cnt++;
            } else {
                ans *= (cnt+1);
                cnt = 1;
                prev = prime[x];
            }
            x/=prime[x];
        }
        if (prime[x] == prev)  ans *= (cnt+2);
        else ans *= 2*(cnt+1);
        // debug(ans);
        return ans;
    };
    int ans = 1;
    vector<pair<int, int>>pairs;
    vector<int>curr;
    for (int rep = 2; rep <= n; rep++){
        int A = rep;
        curr.clear();
        int x = A;
        while (prime[x] != x){
            if (curr.empty() || curr.back() != prime[x]) curr.emplace_back(prime[x]);
            x/=prime[x];
        }
        if (curr.empty() || curr.back() != x) curr.emplace_back(x);
        int B = 1, ptr = 0;
        for (auto v: p){
            if (ptr < (int)curr.size() && curr[ptr] == v) {
                ptr++;
                continue;
            }
            if (B * v <= n) B *= v;
            else break;
        }
        for (auto v: p){
            if (A * v <= n && B * v <= n){
                A *= v;
                B *= v;
            } else break;
        }
        while (A * 2 <= n && B * 2 <= n){
            A *= 2; B *= 2;
        }
        // debug(A, B);
        int cur = d(A) + d(B) - d(__gcd(A, B));
        if (cur > ans){
            pairs.clear();
            pairs.emplace_back(A, B);
            ans = cur;
        } else if (cur == ans){
            pairs.emplace_back(A, B);
        }
    }
    debug(ans, pairs);
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