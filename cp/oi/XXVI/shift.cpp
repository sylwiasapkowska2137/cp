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
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

/*
struct Interactor{
    vector<int>curr;
    int n;

    int p(int a, int b){
        return a+rng()%(b-a+1);
    }

    void begin(){
        // n = 5;
        // curr = {15, 17, 18, 0, 5};
        n = p(1, 10);
        set<int>s;
        while ((int)s.size() < n) s.insert(p(1, 20));
        for (auto x: s) curr.emplace_back(x);
        rotate(curr.begin(), curr.begin()+p(0, n-1), curr.end());
        // debug(curr);
    }

    int circular_shift(int x){
        x %= n;
        rotate(curr.begin(), curr.begin()+x, curr.end());
        return curr[0];
    }

    bool give_answer(int a){
        assert(a == n); 
        cerr << "OK!\n";
        exit(0);
    }
} I;
*/

int beg;
//1  ---> x > n
//-1 ---> x < n
int check(int x){
    // assert(x >= 2 && x % 2 == 0);
    int A = beg;
    int B = circular_shift(x/2);
    int C = circular_shift(x/2);
    if (A == C) {
        give_answer(x);
        exit(0);
    }
    int inv = 0;
    if (A > C) inv++;
    if (A > B) inv++;
    if (B > C) inv++;
    beg = C;
    return (inv&1) ? 1 : -1;
}

void solve(){
    // I.begin(); 
    int a = circular_shift(0);
    int b = circular_shift(1);
    if (a == b) {
        give_answer(1);
        exit(0);
    }
    beg = b;
    int p = 2;
    int L = 1, R = 2;
    for (int i = 1; i<K; i++){
        if (check(p) > 0){
            L = p/2, R = p;
            break;
        }
        p *= 2;
    }
    while (R - L > 1){
        int mid = (L+R)/2;
        if (check(mid) > 0) R = mid;
        else L = mid;
    }
    give_answer(L);
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