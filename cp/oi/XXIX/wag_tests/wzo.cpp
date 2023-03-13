//Sylwia Sapkowska
#include <bits/stdc++.h>
#include "waglib.h"
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

void __print(int x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ", "; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? ", " : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifdef LOCAL
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef pair<int, int> T;
const int oo = 1e9+7;
int n = 7;
vector<vector<int>>g;
vector<T>check;

int cmp(int &a, int b, vector<int>&p){
    int L = 0, R = 0;
    for (int i = 0; i<n; i++){
        if (a&(1<<i)){
            L += p[i];
        } 
        if (b&(1<<i)){
            R += p[i];
        }
    }
    if (L > R) return 0;
    if (L == R) return 1;
    return 2;
}
int d;
map<int, vector<int>>ans;

void rec(vector<vector<int>>&p, int par){
    d++;
    int c = d;
    g.resize(d+2);
    check.resize(d+2);
    if (par){
        g[par].emplace_back(d);
    }
    if (p.empty()) return;
    if ((int)p.size() == 1){
        ans[d] = p[0];
        return;
    }
    T now = {0, 0};
    int mn = oo;
    for (int mask = 1; mask < (1<<n); mask++){
        for (int s = mask; s; s=(s-1)&mask){
            if (s == mask) continue;
            //probujemy operacje na s, mask/s
            array<int, 3>a = {0};
            for (auto &curr: p) a[cmp(s, mask^s, curr)]++;
            int currmn = max({a[0], a[1], a[2]});
            if (currmn < mn){
                mn = currmn;
                now = {s, mask^s};
            }
        }
    }
    assert(now.first != 0);
    vector podziel(3, vector<vector<int>>());
    for (auto &curr: p){
        podziel[cmp(now.first, now.second, curr)].emplace_back(curr);
    }
    check[c] = now;
    for (int i = 0; i<3; i++){
        rec(podziel[i], c);
    }
}

int cmp(int a, int b){
    for (int i = 0; i<n; i++){
        if (a&(1<<i)){
            poloz_lewo(i+1);
        } 
        if (b&(1<<i)){
            poloz_prawo(i+1);
        }
    }
    int x = wazenie();
    for (int i = 1; i<=n; i++) odloz(i);
    return x+1;
}

void solve(){
    vector<int>a(7);
    iota(a.begin(), a.end(), 1);
    int v = 1;
    while ((int)g[v].size()){
        // debug(v, g[v], check[v], cmp(check[v].first, check[v].second));
        v = g[v][cmp(check[v].first, check[v].second)];
    }
    // debug(ans[v]);
    odpowiedz(ans[v]);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>>all;
    vector<int>p(7);
    iota(p.begin(), p.end(), 1);
    do{
        all.emplace_back(p);
    } while (next_permutation(p.begin(), p.end()));
    rec(all, 0);
    int t = liczba_testow();
    while (t--) solve();

    return 0;
}