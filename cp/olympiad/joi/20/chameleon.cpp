//Sylwia Sapkowska
#include <bits/stdc++.h>
#include "chameleon.h"
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


void Solve(int n){
	int N = 2*n;
	vector<vector<int>>G(N+1);
	vector<int>c(N+1);

	function<bool(vector<int>, int)>check = [&](vector<int>a, int x){
		if (a.empty()) return false;
		a.emplace_back(x);
		return (Query(a) != (int)a.size());
	};

	for (int i = 1; i<=N; i++){
		for (int j = 1; j<i; j++) c[j] = -1;
		for (int j = 1; j<i; j++){
			if (c[j] != -1) continue;
			queue<int>q;
			q.push(j);
			c[j] = 0;
			while (q.size()){
				int v = q.front();q.pop();
				for (auto x: G[v]){
					if (c[x] == -1){
						c[x] = c[v]^1;
						q.push(x);
					}
				}
			}
		}
		vector<vector<int>>d(2);
		for (int j = 1; j<i; j++) d[c[j]].emplace_back(j);
		for (int j = 0; j<2; j++){
			while (check(d[j], i)){
				int L = 0, R = (int)d[j].size()-1;
				int ans = R;
				while (R>=L){
					int m = (L+R)/2;
					vector<int>x;
					for (int k = 0; k<=m; k++) x.emplace_back(d[j][k]);
					if (check(x, i)){
						ans = m;
						R = m-1;
					} else L = m+1;
				}
				// debug(i, ans);
				G[i].emplace_back(d[j][ans]);
				G[d[j][ans]].emplace_back(i);
				d[j].erase(d[j].begin(), d[j].begin()+ans+1);
			}
		}
	}
	// for (int i = 1; i<=N; i++){
	// 	debug(G[i]);
	// }
	vector<pair<int, int>>ans;
	vector<int>who2(N+1, -1), who(N+1, -1);
	vector<bool>vis(N+1, 0);
	for (int i = 1; i<=N; i++){
		if ((int)G[i].size() == 1 && !vis[G[i][0]]){
			ans.emplace_back(i, G[i][0]);
			vis[i] = 1;
			vis[G[i][0]] = 1;
		} else if (G[i].size() == 3) {
			vector<int>curr;
			for (int j = 0; j<3; j++){
				curr.clear();
				for (int k = 0; k<3; k++){
					if (k == j) continue;
					curr.emplace_back(G[i][k]);
				}
				curr.emplace_back(i);
				if (Query(curr) == 1){
					who2[i] = G[i][j];
					who[G[i][j]] = i;
				}
			}
		}
	}
	for (int i = 1; i<=N; i++){
		if (vis[i]) continue;
		if ((int)G[i].size() == 3){
			for (int j = 0; j<3; j++){
				if (G[i][j] == who2[i] || G[i][j] == who[i]) continue;
				ans.emplace_back(i, G[i][j]);
				vis[i] = 1;
				vis[G[i][j]] = 1;
			}
		}
	}
	for (auto [a, b]:ans) Answer(a, b);
}