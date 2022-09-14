//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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

// #define int long long
const int K = 60;
const int oo = 1e9+7;

struct TreeSum{
	typedef pair<int, int> T;
	vector<T>tab;
	vector<int>lazy;
	int size = 1, nn;

	T f(T a, T b){ return a.first == b.first ? make_pair(a.first, a.second + b.second) : max(a, b);}

	TreeSum(int n){
		while (size < n) size *= 2;
		nn = n;
		clear();
	}

	void clear(){
		tab.assign(2*size, {0, 0});
		for (int i = 1; i<nn; i++) tab[i+size].second = 1;
		lazy.assign(2*size, 0);
		for (int i = size-1; i>=1; i--) tab[i] = f(tab[2*i], tab[2*i+1]);
	}

	void push(int x){
		tab[2*x].first += lazy[x];
		tab[2*x+1].first += lazy[x];
		lazy[2*x] += lazy[x];
		lazy[2*x+1] += lazy[x];
		lazy[x] = 0;
	}

	void update(int x, int lx, int rx, int l, int r, int v){
		if (lx != rx && lazy[x]) push(x);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x].first += v;
			lazy[x]+=v;
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, v);
		update(2*x+1, m+1, rx, l, r, v);
		tab[x] = f(tab[2*x], tab[2*x+1]);
	}

	T query(int x, int lx, int rx, int l, int r){
		if (lx != rx && lazy[x]) push(x);
		if (lx > r || rx < l) return {-oo, 0};
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return f(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
};


void happy_intervals(vector<pair<int, int>>&mx, vector<long long>&a){
	int n = (int)a.size()-1;
	vector<int>s;
	for (int i = 1; i<=n; i++){
		while (s.size() && a[s.back()] <= a[i]) s.pop_back();
		if (s.empty()) mx[i].first = 1;
		else mx[i].first = s.back()+1;
		s.push_back(i);
	}
	s.clear();
	for (int i = n; i>=1; i--){
		while (s.size() && a[s.back()] < a[i]) s.pop_back();
		if (s.empty()) mx[i].second = n;
		else mx[i].second = s.back()-1;
		s.push_back(i);
	}
}


void solve(){
	int n; cin >> n;
	vector<vector<int>>tab(K);
	vector<long long>a(n+1);
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		tab[__builtin_popcountll(a[i])].emplace_back(i);	
	}
	vector<pair<int, int>>mx(n+1), mn(n+1);
	happy_intervals(mx, a);
	for (auto &x: a) x = -x; 
	happy_intervals(mn, a);
	long long ans = 0;
	TreeSum t(n+1);
	vector<vector<pair<int, int>>>add(n+1), sub(n+1);
	for (int b = 0; b < K; b++){
		if (tab[b].empty()) continue;
		for (int i = 1; i<=n; i++) {
			add[i].clear();
			sub[i].clear();
		}
		for (auto i: tab[b]){
			add[mn[i].first].emplace_back(i, mn[i].second);
			add[mx[i].first].emplace_back(i, mx[i].second);
			sub[i].emplace_back(i, mn[i].second);
			sub[i].emplace_back(i, mx[i].second);
		}	
		for (int i = 1; i<=n; i++){
			while (add[i].size()) {
				t.update(1, 0, t.size-1, add[i].back().first, add[i].back().second, 1);
				add[i].pop_back();
			}
			if (t.tab[1].first == 2) ans += t.tab[1].second;
			while (sub[i].size()) {
				t.update(1, 0, t.size-1, sub[i].back().first, sub[i].back().second, -1);
				sub[i].pop_back();
			}
		}
		t.clear();
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}