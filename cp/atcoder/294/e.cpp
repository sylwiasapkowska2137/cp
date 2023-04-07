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

struct TreeMax{
    vector<T>tab;
    int size = 1;

    TreeMax(int n){
        while (size < n) size*=2;
        tab.assign(2*size, {-oo, -oo});
    }

    void update(int x, T v){
        x += size;
        tab[x] = v;
        while (x){
            x/=2;
            tab[x] = max(tab[2*x], tab[2*x+1]);
        }
    }

    T query(int l, int r){
        T ans = {-oo, -oo};
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans = max(ans, tab[l+1]);
            if (r&1) ans = max(ans, tab[r-1]);
        }
        return ans;
    }
};


void solve(){
    int LEN, n1, n2; cin >> LEN >> n1 >> n2;
    map<int, vector<T>>a, b;
    int L = 1;
    vector<int>s;
    for (int i = 0; i<n1; i++){
        int x, len; cin >> x >> len;
        a[x].emplace_back(L, L+len-1);
        s.emplace_back(L);
        s.emplace_back(L+len-1);   
        L += len;
    }
    L = 1;
    for (int i = 0; i<n2; i++){
        int x, len; cin >> x >> len;
        b[x].emplace_back(L, L+len-1);
        s.emplace_back(L);
        s.emplace_back(L+len-1);   
        L += len;
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    int M = (int)s.size();
    TreeMax t(M+2);
    auto get = [&](int x){
        return lower_bound(s.begin(), s.end(), x) - s.begin();
    };
    int ans = 0;
    for (auto [val, vec]: a){
        if (b.find(val) == b.end()) continue;
        debug(val);
        for (auto &[l, r]: vec){
            int ll = get(l);
            // int rr = get(r);
            debug(l, r);
            t.update(ll, {r, ll});
        }
        for (auto &[l, r]: b[val]){
            int rr = get(r);
            int ll = get(l);
            vector<T>back;
            while (1){
                T now = t.query(0, rr);
                if (now.first < l) break;
                back.emplace_back(now);
                //[l, r], [now.second, scaler[now.first]]
                debug(l, r, s[now.second], now.first);
                int pl = max(l, s[now.second]);
                int pr = min(r, now.first);
                assert(pl <= pr);
                ans += (pr-pl+1);
                t.update(now.second, {-oo, -oo});
            }
            debug(back);
            for (auto [r, l]: back){
                t.update(l, {r, l});
            }
        }
        while (1){
            T now = t.query(0, M);
            if (now.first == -oo) break;
            t.update(now.second, {-oo, -oo});
        }
    }
    cout << ans << "\n";
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