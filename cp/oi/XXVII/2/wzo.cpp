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
const int oo = 1e18, oo2 = 1e9+7, K = 42;
const int mod = 998244353;
vector<int>prime = {2, 3, 5, 7, 11, 13, 17, 19}; //23, 29, 31, 37, 41, 43
int n;
const int mx = 3000;
set<pair<int, int>>gen;

void backtrack(int val, int d, int ptr){
    if (ptr >= prime.size()) return;
    gen.insert({d, val});
    if (gen.size() > mx) gen.erase(gen.begin());
    for (int i = 0; i<K; i++){
        if (val <= n) {
            backtrack(val, d*(i+1), ptr+1);
        } else break;
        val *= prime[ptr];
    }
}

unordered_map<int, int>f;

int d(int x){
    if (f.find(x) != f.end()) return f[x];
    int xd = x;
    int ans = 1;
    for (int c = 2; c * c <= x; c++){
        if (x % c == 0){
            int cnt = 1;
            while (x%c == 0){
                x/=c;
                cnt++;
            }
            ans *= cnt;
        }
    }
    if (x > 1) ans *= 2;
    f[xd] = ans;
    return ans;
}

void solve(){
    cin >> n; //haha heura time
    backtrack(1, 1, 0);
    // debug((int)gen.size());
    vector<pair<int, int>>curr;
    for (auto x: gen) curr.emplace_back(x);
    int ans = 1, X = 1, Y = 1;
    for (int i = 0; i<(int)curr.size(); i++){
        for (int j = i+1; j<(int)curr.size(); j++){
            int tmp = curr[i].first + curr[j].first - d(__gcd(curr[i].second, curr[j].second));
            if (ans <= tmp){
                ans = tmp;
                X = curr[i].second, Y = curr[j].second;
            }
        }
    }
    cout << ans << "\n" << X << " " << Y << "\n";
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