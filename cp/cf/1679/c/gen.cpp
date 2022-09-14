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

#define int long long
const int oo = 1e18, K = 30;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

int p(int a, int b){
	return a+rng()%(b-a+1);
}

void solve(){
	int n = p(1, 5);
	int q = p(1, 5);
	vector<pair<int, int>>tab;
	set<pair<int, int>>s;
	cout << n << " " << q << "\n";
	for (int i = 0; i<q; i++){
		int t = p(1, 3);
		while (t == 2 && tab.empty()){
			t = p(1, 3);
		}
		while (t == 1 && tab.size() == n*n){
			t = p(1, 3);
		}
		cout << t << " ";
		if (t == 1){
			int x, y;
			while (1){
				x = p(1, n);
				y = p(1, n);
				if (s.find({x, y}) == s.end()){
					s.insert({x, y});
					tab.emplace_back(x, y);
					shuffle(tab.begin(), tab.end(), rng);
					cout << x << " " << y << "\n";
					break;
				}
			}
		} else if (t == 2){
			int idx = p(0, (int)tab.size()-1);
			cout << tab[idx].first << " " << tab[idx].second << "\n";
			s.erase(tab[idx]);
			tab.erase(tab.begin()+idx);
		} else {
			int x1 = p(1, n);
			int x2 = p(1, n);
			int y1 = p(1, n);
			int y2 = p(1, n);
			if (y1 > y2) swap(y1, y2);
			if (x1 > x2) swap(x1, x2);
			cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; //cin >> t;
	while (t--) solve();
	
	return 0;
}
