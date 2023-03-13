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
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
    int n; cin >> n;
    vector<T>points(n);
    for (auto &x: points) cin >> x.first >> x.second;
    sort(points.begin(), points.end()); //sort po x, potem po y
    int L = 0, R = 12, ans = oo;
    set<T>s;
    auto check = [&](int mid){
        s.clear(); 
        map<T, int>color;
        for (auto [x, y]: points) color[{y, x}] = -1;
        color[{points[0].second, points[0].first}] = 0;
        int j = 0;
        int d = ceil(sqrt(mid));
        for (int i = 0; i<n; i++){
            while (j < n && points[i].first - points[j].first >= d){
                s.erase({points[j].second, points[j].first});
                j++;
            }
            auto it1 = s.lower_bound({points[i].second-d, points[i].first});
            auto it2 = s.upper_bound({points[i].second+d, points[i].first});
            bool on = 0, off = 0;
            int cnt = 0;
            for (auto it = it1; it != it2; it++){
                int dx = points[i].first - it->second;
                int dy = points[i].second - it->first;
                if (dx*dx + dy*dy < mid){
                    // debug(*it);
                    if (color[*it] == 0) on = 1;
                    if (color[*it] == 1) off = 1;
                    // debug(on, off);
                    if (on && off) return false;
                    cnt++;
                    if (cnt >= 10) return false;
                }
            }
            if (off){
                color[{points[i].second, points[i].first}] = 0;
            } 
            if (on){
                color[{points[i].second, points[i].first}] = 1;
            }
            // debug(i, color);
            s.insert({points[i].second, points[i].first});
        }   
        // debug(mid, color);
        return true;
    };
    // check(5);
    // return;
    while (R >= L){
        int m = (L+R)/2;
        if (check(m)){
            ans = m;
            L = m+1;
        } else {
            R = m-1;
        }
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