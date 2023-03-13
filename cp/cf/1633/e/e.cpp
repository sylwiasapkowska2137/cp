//Sylwia Sapkowska
#include <bits/stdc++.h>
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

#define int long long
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
	int n, m; cin >> n >> m;
	vector<tuple<int, int, int>>edges;
	vector<int>check = {0};
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		c *= 2;
		edges.emplace_back(a, b, c);
		check.emplace_back(c);
	}
	for (auto [a1, b1, c1]: edges){
		for (auto [a2, b2, c2]: edges){
			check.emplace_back((c1+c2)/2);
		}
	}
	sort(check.begin(), check.end());
	check.erase(unique(check.begin(), check.end()), check.end());
	struct UF{
		vector<int>rep, sz;
		int s;
		UF(int n){ s = n; clear();}
		void clear(){
			rep.assign(s, 0);
			iota(rep.begin(), rep.end(), 0);
			sz.assign(s, 1);
		}
		int f(int a) {return a == rep[a] ? a : rep[a] = f(rep[a]);}
		bool u(int a, int b){
			a = f(a); b = f(b);
			if (a == b) return 0;
			if (sz[a] < sz[b]) swap(a, b);
			sz[a] += sz[b];
			rep[b] = a;
			return 1;
		};
	} dsu(n+1);
	vector<pair<int, int>>ret;
	// debug(check);
	for (auto v: check){
		sort(edges.begin(), edges.end(), [&](auto x, auto y){
			int a = abs(get<2>(x) - v);
			int b = abs(get<2>(y) - v);
			return (a == b ? get<2>(x) > get<2>(y) : a < b);
		});
		dsu.clear();
		int ans = 0, ile = 0;
		for (auto [a, b, c]: edges){
			if (dsu.u(a, b)){
				ans += abs(c-v);
				if (c > v) ile++;
			}
		}
		ret.emplace_back(ans, ile);
	}
	int p, k, a, b, c; cin >> p >> k >> a >> b >> c;
	int what = 0, prev = 0;
	auto answer = [&](int w){
		auto idx = upper_bound(check.begin(), check.end(), 2*w)-check.begin()-1;
		int diff = 2*w - check[idx];
		int now = (ret[idx].first - diff * ret[idx].second + (n-1-ret[idx].second) * diff)/2;
		what ^= now; 
	};
	for (int i = 0; i<p; i++){
		int curr; cin >> curr;
		prev = curr;
		answer(curr);
	}
	k -= p;
	while (k--){
		int curr = (prev * a + b) % c;
		if (curr < 0) curr += c;
		prev = curr;
		answer(curr);
	}
	cout << what << "\n";
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