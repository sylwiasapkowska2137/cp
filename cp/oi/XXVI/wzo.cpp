//Sylwia Sapkowska
#include <bits/stdc++.h>
#include "cyklib.hpp"
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

void solve(){
    int s = 45;
    vector<int>curr;
    curr.emplace_back(circular_shift(0));
    int ile = 0;
    bool ok = 0;
    for (int i = 1; i<=s; i++){
        int x = circular_shift(s);
        if (x < curr.back()) ok = 1;
        if (x >= curr[0] && ok){
            ile = i*s;
            break;
        }
        curr.emplace_back(x);
    }
    vector<int>idx;
    if (ile >= s+s) circular_shift(ile-2*s);
    for (int i = 1; i<=2*s; i++){
        int x = circular_shift(1);
        if (x == curr[0]){
            idx.emplace_back(i);
            if (idx.size() >= 2) break;
        }
    }
    if (idx.size() == 1) give_answer((idx[0]-2*s+ile+ile)/2);
    else give_answer(idx[1]-idx[0]);
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