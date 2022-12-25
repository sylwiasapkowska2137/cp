//Sylwia Sapkowska
#include <bits/stdc++.h>
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

#define int long long
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;


struct Tree{
	vector<vector<pair<int, int>>>g;
	vector<int>dist;
	int size = 1;

	int get(int x){return x+2*size;}

	Tree(int n){
		while (size < n) size*=2;
		dist.assign(5*size, oo);
		dist[1] = 0;
		g.resize(5*size);
		for (int i = 1; i<size; i++){
			g[i].emplace_back(2*i, 0);
			g[i].emplace_back(2*i+1, 0);
			debug(i, 2*i);
			debug(i, 2*i+1);
		}
		for (int i = 1; i<size; i++){
			g[get(2*i)].emplace_back(get(i), 0);
			g[get(2*i+1)].emplace_back(get(i), 0);
			debug(get(2*i), get(i));
			debug(get(2*i+1), get(i));
			if (2*i >= size){
				debug(2*i, get(i));
				debug(2*i+1, get(i));
				g[2*i].emplace_back(get(i), 0);
				g[2*i+1].emplace_back(get(i), 0);
			}
		}
	}

	void down(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			dec.emplace_back(x);
			return;
		}
		int m = (lx+rx)/2;
		down(2*x, lx, m, l, r);
		down(2*x+1, m+1, rx, l, r);
	}

	void up(int x, int lx, int rx, int l, int r){
		
	}

	void check(int a, int b){
		dec.clear();
		dec2.clear();
		down(1, 0, size-1, a, b);
	}
};

void solve(){
	int n, m; cin >> n >> m;
	Tree t(n+1);
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		t.check(a, b);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
