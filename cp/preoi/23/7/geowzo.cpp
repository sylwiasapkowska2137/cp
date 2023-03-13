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
const int mod = 1e9+7;
const int I = (mod+1)/2;

bool up(T x){return x.second > 0 || (x.second == 0 && x.first > 0);}
void add(int &a, int b){ if ((a += b) >= mod) a-=mod;}
void sub(int &a, int b){ if ((a -= b) < 0) a+=mod;}
int mul(int a, int b){ return (a*b)%mod;}
int sub2(int a, int b){ sub(a, b); return a;}

struct Tree{
    vector<int>tab;
    int size = 1;

    Tree(int n){
        while (size < n) size*=2;
        tab.assign(2*size, 0);
    }
    
    int query(int x){
        x += size;
        int ans = 0;
        while (x){
            add(ans, tab[x]);
            x/=2;
        }
        return ans;
    }

    void update(int l, int r, int v){
        if (v >= 0){
            for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
                if (!(l&1)) add(tab[l+1], v);
                if (r&1) add(tab[r-1], v);
            }   
        } else {
            v = -v;
            for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
                if (!(l&1)) sub(tab[l+1], v);
                if (r&1) sub(tab[r-1], v);
            }
        }
    }
};

void solve(){
    int n; cin >> n;
    vector<tuple<char, int, int>>que;
    vector<pair<T, int>>p;
    for (int i = 0; i<n; i++){
        char c; cin >> c;
        if (c == 'S') que.emplace_back(c, -1, -1);
        else {
            int x, y; cin >> x >> y;
            que.emplace_back(c, x, y);
            if (c == 'A') {
                p.emplace_back(T{x, y}, i);
            }
        }
    }
    vector<int>get(n);
    sort(p.begin(), p.end(), [&](auto a, auto b){
        auto x = a.first, y = b.first;
        return up(x) != up(y) ? up(x) : x.first * y.second - x.second * y.first < 0; 
    });
    int M = (int)p.size();
    for (int i = 0; i<M; i++) get[p[i].second] = i;
    debug(p);
    int area = 0;
    Tree X(2*M+3), Y(2*M+3);
    int k = -1;
    auto deb = [&](){
        for (int i = 1; i<=M+M; i++){
            cerr << "{" << X.query(i) << ", " << Y.query(i) << "}, ";
        }
        cerr << "\n";
    };
    for (auto [c, x, y]: que){
        k++;
        if (c == 'S'){
            cout << area << "\n";
            continue;
        }
        int coef = (c == 'A' ? 1 : -1);
        int idx = get[k]+1;
        
        auto change = [&](int pos, bool f){
            assert(pos > 0 && pos < M+M+1);
            T prev = {X.query(pos-1), Y.query(pos-1)};
            T curr = {X.query(pos), Y.query(pos)};
            int ilo = sub2(mul(prev.first, curr.second), mul(prev.second, curr.first));
            debug(prev, curr, ilo);
            if (!f) sub(area, ilo);
            else add(area, ilo);
        };
        debug(x, y, idx);
        change(idx, 1);
        change(idx+M, 1);
        T L = {X.query(idx), Y.query(idx)};
        T R = {X.query(idx+M-1), Y.query(idx+M-1)};
        int tmp = mul(y, sub2(L.second, R.second));
        add(tmp, mul(x, sub2(R.first, L.first)));
        debug(area, tmp);
        if (c == 'A') sub(area, tmp);
        else add(area, tmp);
        debug(area);
        X.update(idx, idx+M-1, mul(x, coef));
        Y.update(idx, idx+M-1, mul(y, coef));
        change(idx, 0);
        change(idx+M, 0);
        deb();
        cerr << "\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}