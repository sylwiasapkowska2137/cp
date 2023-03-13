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

struct Tree{
    vector<int>tab;
    int size = 1, SHIFT;

    Tree(int n, int s){
        while (size < n) size*=2;
        tab.assign(2*size, 0);
        SHIFT = s;
    }

    void update(int x, int v){
        x += SHIFT;
        x += size;
        tab[x] += v;
        while (x){
            x/=2;
            tab[x] = tab[2*x] + tab[2*x+1];
        }
    }

    int query(int l, int r){
        l += SHIFT;
        r += SHIFT;
        int ans = 0;
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans += tab[l+1];
            if (r&1) ans += tab[r-1];
        }
        return ans;
    }
};

void solve(){
    auto zet = [](string s){
        int k = (int)s.size();
        vector<int>z(k);
        for (int i = 1, l = 0, r = 0; i<k; i++){
            if (i <= r){
                z[i] = min(r-i+1, z[i-l]);
            }
            while (z[i]+i < k && s[z[i]] == s[z[i]+i]) z[i]++;
            if (i + z[i] - 1 > r){
                l = i;
                r = i+z[i]-1;
            }
        }
        return z;
    };
    int n, m; cin >> n >> m;
    string a, b, s; cin >> a >> b >> s;
    string tt = s + "$" + a;
    vector<int>pref = zet(tt);
    reverse(pref.begin(), pref.end());
    while (pref.size() > n) pref.pop_back();
    reverse(pref.begin(), pref.end());
    debug(pref);
    tt = string(s.rbegin(), s.rend()) + "#" + string(b.rbegin(), b.rend());
    vector<int>suf = zet(tt);
    reverse(suf.begin(), suf.end());
    while (suf.size() > n) suf.pop_back();
    debug(suf);
    Tree t(2*(n+m)+3, m+2);
    int r = -1, ans = 0;
    for (int l = 0; l < n; l++){
        while (r+1 && n && r+1 <= l+m-2){
            r++;
            t.update(suf[r], suf[r]);
        }  

        t.update(suf[l], -suf[l]);
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