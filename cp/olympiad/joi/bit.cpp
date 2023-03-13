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

void solve(){
    int n, m; cin >> n >> m;
    vector<T>a;
    for (int i = 0; i<n; i++){
        int s, c; cin >> s >> c;
        a.emplace_back(c, s);
    }
    sort(a.begin(), a.end());
    int L = 0, R = n-1;
    multiset<int>A, B;
    int ret = -oo;
    int sum = 0;
    auto add = [&](int v){
        if ((int)A.size() < m){
            A.insert(v);
            sum += v;
            return;
        }
        if (*A.begin() < v){
            A.insert(v);
            sum += v;
            sum -= *A.begin();
            B.insert(*A.begin());
            A.erase(A.begin());
        } else {
            B.insert(v);
        }
    };
    auto remove = [&](int v){
        auto it = A.find(v);
        if (it != A.end()) {
            A.erase(it);
            sum -= v;
            if (B.size()){
                A.insert(*B.rbegin());
                sum += *B.rbegin();
                B.erase((--(B.end())));
            }
        } else {
            B.erase(B.find(v));
        }
    };
    auto fit = [&](int l, int r){
        while (L > l){
            L--;
            add(a[L].second);
        }
        while (R < r){
            R++;
            add(a[R].second);
        }
        while (L < l){
            remove(a[L].second);
            L++;
        }
        while (R > r){
            remove(a[R].second);
            R--;
        }
    };
    for (int i = 0; i<n; i++) add(a[i].second);
    function<void(int, int, int, int)>rec = [&](int l, int r, int la, int lb){
        if (l > r) return;
        int mid = (l+r)/2;
        int opt = la;
        int ans = -oo;
        for (int i = la; i<=min(mid-m+1, lb); i++){
            fit(i, mid);
            if ((int)A.size() == m){
                int maybe = sum + 2 * (a[i].first - a[mid].first);
                if (ans < maybe){
                    opt = i;
                    ans = maybe;
                }
            }
            // i, mid??
        }
        debug(mid, ans);
        ret = max(ret, ans);
        rec(l, mid-1, la, opt);
        rec(mid+1, r, opt, lb);
    };
    rec(0, n-1, 0, n-1);
    cout << ret << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}