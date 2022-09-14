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

struct E{
	int a, b, c;
	E(){}
	E(int _a, int _b, int _c){
		a = _a, b = _b, c = _c;
	}
};

const int MAX = 3e5+7;
vector<int>rep, T[MAX], weights[MAX];

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

struct segmax{
	vector<int>tab;
	int size = 1;

	void init(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, -1);
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=0; i--) tab[i] = max(tab[2*i], tab[2*i+1]);
	}

	int query(int l, int r){
		int ans = 0;
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

struct Node{
	int min, max, min2, max2;
	Node(){}
	Node(int _min, int _max, int _min2, int _max2){
		min = _min, max = _max, min2 = _min2, max2 = _max2;
	}
};

struct segtree{
	int size = 1;
	const int INF = 1e9+7;
	vector<Node>tab;
	vector<int>lazy;
	Node empty = {INF, -1, INF, -1};

	void init(int n, vector<int>&pos){
		while (size < n) size*=2;
		tab.assign(2*size+1, empty);
		lazy.assign(2*size+1, 0);
		for (int i = 0; i<(int)pos.size(); i++) tab[i+size] = {pos[i], pos[i], INF, -1};
		for (int i = size-1; i>=1; i--) tab[i] = comb(tab[2*i], tab[2*i+1]);
	}

	Node comb(Node a, Node b){
		return {
			min(a.min, b.min),
			max(a.max, b.max),
			min(a.min2, b.min2),
			max(a.max2, b.max2)
		};
	}

	void push(int x, int lx, int rx){
		if (!lazy[x] || lx == rx) return;
		if (lazy[x] == 1){
			tab[2*x].min2 = tab[2*x].min;
			tab[2*x].max2 = tab[2*x].max;
			tab[2*x+1].min2 = tab[2*x+1].min;
			tab[2*x+1].max2 = tab[2*x+1].max;
		} else {
			tab[2*x].min2 = INF;
			tab[2*x].max2 = -1;
			tab[2*x+1].min2 = INF;
			tab[2*x+1].max2 = -1;
		}
		lazy[2*x] = lazy[2*x+1] = lazy[x];
		lazy[x] = 0;
	}

	void update(int x, int lx, int rx, int l, int r, int val){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			lazy[x] = val;
			if (val == 1){
				tab[x].min2 = tab[x].min;
				tab[x].max2 = tab[x].max;
			} 
			if (val == -1){
				tab[x].min2 = INF;
				tab[x].max2 = -1;
			}
			push(x, lx, rx);
			return;
		}
		
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, val);
		update(2*x+1, m+1, rx, l, r, val);
		tab[x] = comb(tab[2*x], tab[2*x+1]);
	}

	Node query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return empty;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return comb(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}

};

void solve(){
	int n, q; cin >> n >> q;
	vector<E>edges;
	for (int i = 1; i<n; i++){
		int a, b, c; cin >> a >> b >> c;
		edges.emplace_back(a, b, c);
	}
	rep.assign(n+1, 0);
	iota(rep.begin(), rep.end(), 0);
	for (int i = 1; i<=n; i++) T[i].push_back(i);
	sort(edges.begin(), edges.end(), [](auto a, auto b){return a.c < b.c;});
	for (auto [A, B, c]:edges){
		int a = Find(A);
		int b = Find(B);
		if (a == b) continue;
		if ((int)T[a].size() < (int)T[b].size()) swap(a, b);
		weights[a].push_back(c);
		for (auto x: weights[b]) weights[a].push_back(x);
		rep[b] = a;
		for (auto x: T[b]){
			rep[x] = a;
			T[a].push_back(x);
		}
	}
	int x = 1;
	for (int i = 1; i<=n; i++){
		if ((int)T[i].size() == n) x = i;
	}
	vector<int>pos(n+1, 0);
	for (int i = 0; i<(int)T[x].size(); i++){
		pos[T[x][i]] = i;
	}
	//debug(T[x], weights[x], pos);
	
	segtree seg;
	seg.init(n+2, pos);
	segmax maxi;
	maxi.init(n+2, weights[x]);
	
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int l, r; cin >> l >> r;
			seg.update(1, 0, seg.size-1, l, r, 1);
		} else if (t == 2){
			int l, r; cin >> l >> r;
			seg.update(1, 0, seg.size-1, l, r, -1);
		} else{
			int v; cin >> v;
			v = pos[v];
			auto [useless, useless2, l, r] = seg.query(1, 0, seg.size-1, 1, n);
			int ans = -1;
			//debug(v, l, r);
			if (l <= v-1) ans = max(ans, maxi.query(l, v-1));
			if (r-1 >= v) ans = max(ans, maxi.query(v, r-1));
			cout << ans << "\n";
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
