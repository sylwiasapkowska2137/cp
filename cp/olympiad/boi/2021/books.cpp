//Sylwia Sapkowska
#include <bits/stdc++.h>
#include "books.h"
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

void solve(int n, int k, long long A, int S) {
    int L = 1, R = n, ans = n;
    while (R >= L){
        int mid = (L+R)/2;
        if (skim(mid) >= A){
            ans = mid;
            R = mid-1;
        } else {
            L = mid+1;
        }
    }
    // cout << ans << " " << skim(ans) << "\n";
    vector<pair<long long, int>>curr;
    for (int i = 1; i<=min(k, ans); i++) curr.emplace_back(skim(i), i);
    for (int i = ans, ck = k; i>=1 && ck > 0; i--, ck--) curr.emplace_back(skim(i), i);
    sort(curr.begin(), curr.end());
    curr.erase(unique(curr.begin(), curr.end()), curr.end());
    debug(curr);
    int M = (int)curr.size();
    for (int mask = 1; mask<(1<<M); mask++){
        if (__builtin_popcountll(mask) != k) continue;
        long long sum = 0;
        for (int i = 0; i<M; i++){
            if (mask&(1<<i)){
                sum += curr[i].first;
            }
        }
        if (sum >= A && sum <= 2*A) {
            vector<int>ans;
            for (int i = 0; i<M; i++){
                if (mask&(1<<i)){
                    ans.emplace_back(curr[i].second);
                }
            }
            answer(ans);
            exit(0);
        }
    }
    impossible();
}
