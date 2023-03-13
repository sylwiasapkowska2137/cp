//Sylwia Sapkowska
#include <bits/stdc++.h>
#include "combo.h"
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
#ifndef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

vector<char>ch = {'A', 'B', 'X', 'Y'};

string guess_sequence(int n){
    string s;
    if (press("AB")){
        if (press("A")) s += 'A';
        else s += 'B';
    } else {
        if (press("X")) s += 'X';
        else s += 'Y';
    }
    if (n == 1) return s;
    vector<int>curr;
    for (int j = 0; j<4; j++){
        if (ch[j] != s[0]){
            curr.emplace_back(ch[j]);
        }
    }
    for (int i = 1; i<n-1; i++){
        string t = s;
        t += curr[0];
        for (int j = 0; j<3; j++) {
            t += s;
            t += curr[1];
            t += curr[j];
        }
        int x = press(t);
        if (x == (int)s.size()) s += curr[2];
        else if (x == (int)s.size()+1) s += curr[0];
        else s += curr[1];
    }
    for (int j = 0; j<2; j++){
        s += curr[j];
        if (press(s) == n) return s;
        s.pop_back();
    }
    s += curr[2];
    return s;
}
