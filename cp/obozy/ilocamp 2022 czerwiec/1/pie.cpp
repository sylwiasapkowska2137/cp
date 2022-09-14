//Sylwia Sapkowska
#include <bits/stdc++.h>
#include "pielib.h"
using namespace std;
typedef long long LL;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int max(vector<int>idx, int n, int m){
	vector<bool>ok(n*m+1, 0);
	for (auto x: idx) ok[x] = 1;
	vector<int>a;
	for (int i = 1; i<=n*m; i++){
		if (!ok[i]){
			a.emplace_back(i);
		}
	}
	return m-Pytaj(a);
}

void Inicjuj(int n, int m){
	vector<vector<int>>elem(m+1);
	for (int i = 1; i<=n*m; i++){
		int L = 1, R = m, ans = 1;
		while (R>=L){
			int mid = (L+R)/2;
			elem[mid].emplace_back(i);
			if (max(elem[mid], n, m) == 2){
				L = mid+1;
			} else {
				ans = mid;
				R = mid-1;
			}
			elem[mid].pop_back();
		}
		//debug(ans);
		elem[ans].emplace_back(i);
	}

	for (int i = 1; i<=m; i++){
		Odpowiedz(elem[i]);
	}
}
