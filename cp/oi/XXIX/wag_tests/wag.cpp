#include "waglib.h"
//Sylwia Sapkowska
#include <bits/stdc++.h>
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
int q = 0, cnt = 0;

bool cmp(int a, int b){
    if (a == b) return 0;
    q++;
    poloz_lewo(a);
    poloz_prawo(b);
    int x = wazenie();
    odloz(a); odloz(b);
    return (x == 1);
}

void mergesort(vector<int>&now){
    int s = (int)now.size();
    if (s <= 1) return;
    int mid = s/2;
    vector<int>L, R;
    for (int i = 0; i<s; i++) {
        if (i < mid) L.emplace_back(now[i]);
        else R.emplace_back(now[i]);
    }
    mergesort(L);
    mergesort(R);
    now.clear();
    int ptrL = 0, ptrR = 0;
    for (int i = 0; i<s; i++){
        if (ptrL == (int)L.size()) {
            now.emplace_back(R[ptrR++]);
        } else if (ptrR == (int)R.size()){
            now.emplace_back(L[ptrL++]);
        } else {
            if (cmp(L[ptrL], R[ptrR])){
                now.emplace_back(L[ptrL++]);
            } else {
                now.emplace_back(R[ptrR++]);
            }
        }
    }
}

void solve(){
    vector<int>a(7);
    q = 0;
    iota(a.begin(), a.end(), 1);
    // stable_sort(a.begin(), a.end(), cmp);
    mergesort(a);
    vector<int>b(7);
    for (int i = 0; i<7; i++) b[a[i]-1] = i+1;
    odpowiedz(b);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    srand(213769);
    int t = liczba_testow();
    while (t--) solve();

    return 0;
}