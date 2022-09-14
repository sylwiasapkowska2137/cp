//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

const int MAX = 2e5+7;
vector<int>tab[MAX], weights[MAX];
set<pair<int, int>>s;
vector<int>rep;

struct E{
	int a, b, c, i;
	bool added = false;
	E(){}
	E(int _a, int _b, int _c, int _i){
		a = _a, b = _b, c = _c, i = _i;
	}
};

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

struct segtree{
	vector<int>tab;
	int size = 1;
	
	void init(int n, vector<int>a){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		for (int i = 0; i<(int)a.size(); i++){
			tab[i+size] = a[i];
		}
		for (int i = size-1; i>=1; i--){
			tab[i] = max(tab[2*i], tab[2*i+1]);
		}
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}

	
};

void solve(){
	int n, m; cin >> n >> m;
	vector<E>edges;
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		edges.emplace_back(a, b, c, i);
	}
	rep.assign(n+1, 0);
	iota(rep.begin(), rep.end(), 0);
	for (int i = 1; i<=n; i++) tab[i].push_back(i);
	sort(edges.begin(), edges.end(), [](auto a, auto b){return a.c < b.c;});
	for (auto &[A, B, c, i, added]:edges){
		int a = Find(A), b = Find(B);
		if (a == b) continue;
		added = true;
		if ((int)tab[a].size() < (int)tab[b].size()) swap(a, b);
		weights[a].push_back(c);
		for (auto x: weights[b]) weights[a].push_back(x);
		rep[b] = a;
		for (auto x: tab[b]){
			rep[x] = a;
			tab[a].push_back(x);
		}
	}
	long long ans = 0;
	
	int x = 1;
	for (int i = 1; i<=n; i++){
		debug(tab[i], weights[i]);
		if ((int)tab[i].size() == n) x = i;
	}
	vector<int>pos(n+1, 0);
	for (int i = 0; i<(int)tab[x].size(); i++){
		pos[tab[x][i]] = i;
	}
	for (auto v: weights[x]) ans += (long long)v;
	debug(x);
	segtree seg;
	seg.init(n+1, weights[x]);
	sort(edges.begin(), edges.end(), [](auto a, auto b){return a.i < b.i;});
	for (auto [a, b, c, i, added]: edges){
		if (added) cout << ans << "\n";
		else {
			int l = pos[a];
			int r = pos[b];
			if (r < l) swap(l, r);
			debug(l, r);
			debug(seg.query(l, r-1));
			cout << ans-seg.query(l, r-1)+c << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
