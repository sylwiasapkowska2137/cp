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

void Inicjuj(int n, int m){
	vector<int>idx;
	vector<vector<int>>elem(n+1);
	vector<bool>vis(n*m+1, 0);
	int query = 0;
	int nr;

	function<void(int, int, int)>rek = [&](int l, int r, int ile){
		debug(nr, l, r, ile);
		if (!ile || l > r){
			return;
		}
		if (l == r){
			if (vis[l]) return;
			elem[nr].emplace_back(l);
			vis[l] = 1;
			return;
		}
		// if (ile == 1){
		// 	int ans = r;
		// 	while (r>=l){
		// 		vector<int>idx2 = idx;
		// 		int mid = (l+r)/2;
		// 		//debug(m);
		// 		for (int rr = 1; rr<=mid; rr++){
		// 			if (!vis[rr]){
		// 				idx2.emplace_back(rr);
		// 			}
		// 		}
		// 		//debug(idx2);
		// 		if (idx2.size() < n){
		// 			l = mid+1;
		// 			continue;
		// 		}
		// 		int d = Pytaj(idx2);
		// 		query++;
		// 		if (d){
		// 			ans = mid;
		// 			r = mid-1;
		// 		} else l = mid+1;
		// 	}
		// 	elem[nr].emplace_back(ans);
		// 	return;
		// }
	
		int mid = (l+r)/2;
		//debug(l, r, ile, mid);
		vector<int>idx2 = idx;
		for (int rr = 1; rr<=mid; rr++){
			if (!vis[rr]){
				idx2.emplace_back(rr);
			}
		}
		
		int d = (idx2.size() >= n?Pytaj(idx2):0);
		query++;
		rek(l, mid, d);
		rek(mid+1, r, ile-d);
	};

	for (nr = 1; nr<n; nr++){
		//debug(idx);
		rek(1, n*m, m);
		//debug(elem[nr]);
		idx.clear();
		for (int j = 1; j<=nr; j++){
			idx.emplace_back(elem[j][0]);
		}
		debug(elem[nr], query);
	}
	for (int i = 1; i<=n*m; i++){
		if (!vis[i]) {
			elem[n].emplace_back(i);
		}
	}
	for (int i = 0; i<m; i++){
		vector<int>ans;
		for (int j = 1; j<=n; j++){
			ans.emplace_back(elem[j][i]);
		}
		//debug(ans);
		Odpowiedz(ans);
	}
	
}
