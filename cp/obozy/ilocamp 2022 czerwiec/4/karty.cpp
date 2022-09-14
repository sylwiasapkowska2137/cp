//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
 
vector<vector<int>>all;
vector<int>curr;
int K;
 
void rek(){
	if (curr.size() == K){
		do{
			all.emplace_back(curr);
		} while (next_permutation(curr.begin(), curr.end()));
		return;
	}
	int p = (curr.empty()?2:curr.back()+1);
	if (p > 14) return;
	for (int i = p; i<=14; i++){
		curr.emplace_back(i);
		rek();
		curr.pop_back();
	}
}

map<vector<int>, int>dp;

void solve(){
	int t; cin >> K >> t;
	map<char, int>ch;
	ch['T'] = 10;
	ch['J'] = 11;
	ch['Q'] = 12;
	ch['K'] = 13;
	ch['A'] = 14;
	rek();

	
	vector<int>y;
	vector<vector<int>>all2;
	for (int i = 0; i<13; i++){
		int who = i%K;
		all2.clear();
		for (auto x: all){
			bool ok2 = 1; 
			int p = -1;
			y.clear();
			for (int j = 2; j<=14; j++){
				y = x;
				y[who] = j;
				bool ok = 1;
				for (int k = 0; k<K; k++){
					if (k != who && y[k] == j){
						ok = 0;
						break;
					}
				}
				if (!ok) continue;
				if (dp.find(y) == dp.end()){
					sort(y.begin(), y.end());
					for (int k = 0; k<K; k++){
						if (y[k] == j){
							if (p == -1) p = k;
							else if (p != k) ok2 = 0;
							break;
						}
					}
				}
			}
			if (ok2) dp[x] = i;
			else all2.emplace_back(x);
		}
		all = all2;
	}
	while (t--){
		vector<int>a(K);
		for (int i = 0; i<K; i++) {
			char c; cin >> c;
			if (c <= '9') a[i] = (c-'0');
			else a[i] = ch[c];
		}
		cout << dp[a]+1 << "\n";
	}
}
 
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();
	
	return 0;
}