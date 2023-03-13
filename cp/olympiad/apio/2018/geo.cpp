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
const int K = 30;

struct circle{
    int x, y, r, i; 
    circle(){}
    circle(int _x, int _y, int _r, int _i){x = _x, y = _y, r = _r, i = _i;}
    bool operator <(const circle&he)const {return r == he.r ? i < he.i : r > he.r; }
    bool intersect(circle he){return (x - he.x) * (x - he.x) + (y - he.y) * (y - he.y) <= (r + he.r) * (r + he.r); }
};

void solve(){
    int n; cin >> n;
    vector<circle>a;
    for (int i = 0; i<n; i++){
        int x, y, r; cin >> x >> y >> r;
        a.emplace_back(x, y, r, i);
    }
    stable_sort(a.begin(), a.end());
    vector<int>ans(n, -1), ord(n);
    for (int i = 0; i<n; i++) ord[a[i].i] = i;
    map<pair<int, int>, vector<int>>divide;
    for (int rep = K; rep >= 1; rep--){
        divide.clear();
        bool any = 0;
        for (int i = 0; i<n; i++){
            if (ans[i] == -1){
                divide[{a[ord[i]].x >> rep, a[ord[i]].y >> rep}].emplace_back(i);
                any = 1;
            }
        }
        if (!any) break;
        auto what = [&](int i){
            T curr = {a[ord[i]].x >> rep, a[ord[i]].y >> rep};
            // debug(curr);
            for (int x = -2; x <= 2; x++){
                for (int y = -2; y <= 2; y++){
                    T s = {curr.first + x, curr.second + y};
                    for (auto idx: divide[s]){
                        if (ans[idx] == -1 && a[ord[i]].intersect(a[ord[idx]])){
                            ans[idx] = i;
                        }
                    }
                }
            }
        };
        for (int i = 0; i<n; i++){
            if (ans[a[i].i] == -1 && a[i].r >= (1<<(rep-1))){
                what(a[i].i);
            }
        }
    }
    for (int i = 0; i<n; i++){
        cout << ans[i]+1 << " ";
    }
    cout << "\n";
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