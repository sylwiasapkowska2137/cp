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
const int S = 450;

struct Q{
    int l, r, i;
    void read(int _i){
        cin >> l >> r;
        i = _i;
    }
};

struct min_queue{
    deque<int>q;
    vector<int>cnt;

    min_queue(int n){
        cnt.assign(n+1, 0);
    }

    void add(int x){
        while ((int)q.size() && q.back() > x){
            q.pop_back();
        }
        q.push_back(x);
    }

    void remove(int x){
        cnt[x]++;
    }

    int mn(){
        while ((int)q.size() && cnt[q.front()]){
            cnt[q.front()]--;
            q.pop_front();
        }
        // assert(!q.empty());
        return q.front();
    }
}; 

void solve(){
    int n, q; cin >> n >> q;
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    vector<int>ans(q);
    vector<Q>que(q);
    for (int i = 0; i<q; i++) que[i].read(i);
    sort(que.begin(), que.end(), [&](auto x, auto y){
        if (x.l/S == y.l/S) return ((x.l/S)&1) ? x.r > y.r : x.r < y.r;
        return x.l/S < y.l/S;
    });
    set<int>active;
    min_queue mn(n+1);
    auto add = [&](int x){
        auto it = active.lower_bound(x);
        int big = -1, small = -1;
        if (it != active.end()) big = *it;
        if (it != active.begin()) small = *(--it);
        debug(x, big, small);
        if (big != -1) mn.add(big-x);
        if (small != -1) mn.add(x-small);
        if (big != -1 && small != -1) mn.remove(big-small);
        active.insert(x);
    };
    auto remove = [&](int x){
        active.erase(x);
        auto it = active.lower_bound(x);
        int big = -1, small = -1;
        if (it != active.end()) big = *it;
        if (it != active.begin()) small = *(--it);
        if (big != -1) mn.remove(big-x);
        if (small != -1) mn.remove(x-small);
        if (big != -1 && small != -1) mn.add(big-small);
    };
    int L = 1, R = 1;
    add(a[1]);
    for (auto [l, r, i]: que){
        debug(l, r);
        while (L > l){
            L--;
            add(a[L]);
        }
        while (R < r){
            R++;
            add(a[R]);
        }
        while (L < l){
            remove(a[L]);
            L++;
        }
        while (R > r){
            remove(a[R]);
            R--;
        }
        debug(mn.mn());
        debug(active);
        ans[i] = mn.mn();
    }
    for (int i = 0; i<q; i++) cout << ans[i] << "\n";
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