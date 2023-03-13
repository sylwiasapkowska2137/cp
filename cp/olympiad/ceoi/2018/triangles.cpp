//Sylwia Sapkowska
#include <bits/stdc++.h>
#include "trilib.h"
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

int cw(int a, int b, int c){
    if (a == b || b == c || a == c) return 0;
    return is_clockwise(a, b, c) ? 1 : -1;
}

void solve(){
    int n = get_n();
    //just use 1 and 2 to divide
    vector<vector<int>>parts(2), hull(2);
    parts[0].emplace_back(2);
    parts[1].emplace_back(2);
    for (int i = 3; i<=n; i++) parts[cw(1, 2, i) == 1 ? 1 : 0].emplace_back(i);
    for (int rep = 0; rep < 2; rep++){
        stable_sort(parts[rep].begin(), parts[rep].end(), [&](auto x, auto y){return cw(1, x, y) == 1;});
        for (auto x: parts[rep]){
            while ((int)hull[rep].size() >= 2 && cw(hull[rep].end()[-2], hull[rep].end()[-1], x) == -1) hull[rep].pop_back();
            hull[rep].emplace_back(x);
        }
        if (rep) reverse(hull[rep].begin(), hull[rep].end());
        hull[rep].insert(hull[rep].begin(), 1);
        // for (auto x: hull[rep]) cout << x << " ";
        // cout << "\n";
    }
    // now we have a heart and we want to merge it
    for (int rep = 0; rep < 2; rep++){
        hull[rep].pop_back();
        while (1){
            bool any = 0;
            if (hull[0].size() >= 2 && cw(hull[0].end()[-2], hull[0].end()[-1], hull[1].end()[-1]) == -1) {
                hull[0].pop_back();
                any = 1;
            }
            if (hull[1].size() >= 2 && cw(hull[0].end()[-1], hull[1].end()[-1], hull[1].end()[-2]) == -1) {
                hull[1].pop_back();
                any = 1;
            }
            if (!any) break;
        }
        for (int i = 0; i<2; i++) reverse(hull[i].begin(), hull[i].end());
        hull[0].swap(hull[1]);
    }
    // for (int rep = 0; rep < 2; rep++){
    //     for (auto x: hull[rep]) cout << x << " ";
    //     cout << "\n";
    // }
    int ans = (int)hull[0].size() + (int)hull[1].size();
    // cout << ans << "\n";
    give_answer(ans);
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