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

const int MAX = 4e5+7, INF = 1e9+7;
vector<int>rep, graf[MAX], pre, sub;
bitset<MAX>vis;

void dfs(int v){
	pre.push_back(v);
	sub[v] = 1;
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]){
			dfs(x);
			sub[v] += sub[x];
		}
	}
}

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

void merge(int a, int b, int&licznik){
	int A = Find(a);
	int B = Find(b);
	if (A == B) return;
	graf[A].push_back(licznik);
	graf[B].push_back(licznik);
	graf[licznik].push_back(A);
	graf[licznik].push_back(B);
	rep[A] = licznik;
	rep[B] = licznik;
	licznik++;
}

struct segtree{
	vector<pair<int, int>>tab;
	int size = 1;

	pair<int, int> comb(pair<int, int>a, pair<int, int>b){
		if (a.first >= b.first) return a;
		return b;
	}

	segtree(int n, vector<int>&pre, vector<int>&val, int N){
		while (size < n) size*=2;
		tab.resize(2*size+1);
		for (int i = 0; i<(int)pre.size(); i++) {
			if (pre[i] <= N) tab[i+size].first = val[pre[i]];
			tab[i+size].second = i;
		}
		for (int i = size-1; i>=1; i--) tab[i] = comb(tab[2*i], tab[2*i+1]);
	}	

	pair<int, int>query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return {-INF, -INF};
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return comb(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}

	void update(int x){
		x += size;
		tab[x].first = 0;
		while (x > 0){
			x/=2;
			tab[x] = comb(tab[2*x], tab[2*x+1]);
		}
	}
};

void solve(){
	int n, m, q; cin >> n >> m >> q;
	vector<pair<int, int>>edges;
	vector<int>val(n+1);
	for (int i = 1; i<=n; i++) cin >> val[i];
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		edges.emplace_back(a, b);
	}
	vector<pair<int, int>>query;
	vector<bool>used(m, 0);
	rep.resize(2*n+1);
	iota(rep.begin(), rep.end(), 0);
	for (int i = 0; i<q; i++){
		int t, v; cin >> t >> v;
		if (t == 2) {
			v--;
			used[v] = 1;
		}
		query.emplace_back(t, v);
	}
	int licznik = n+1;
	for (int i = 0; i<m; i++){
		if (!used[i]) merge(edges[i].first, edges[i].second, licznik);
	}
	vector<int>id(q, -1);
	for (int i = q-1; i>=0; i--){
		if (query[i].first == 2) merge(edges[query[i].second].first, edges[query[i].second].second, licznik);
		else id[i] = Find(query[i].second);
	}
	//for (int i = 1; i<licznik; i++){
	//	debug(i, graf[i]);
	//}
	//debug(id);
	sub.assign(licznik+1, 0);
	for (int i = licznik-1; i>=1; i--){
		if (!vis[i]){
			dfs(i);
		}
	}
	//return;
	//debug(pre);
	//debug(sub);
	segtree seg(licznik, pre, val, n);
	vector<int>pos((int)pre.size(), 0);
	for (int i = 0; i<(int)pre.size(); i++)	pos[pre[i]] = i;
	for (int i = 0; i<q; i++){
		if (query[i].first == 1){
			//debug(pos[id[i]], pos[id[i]]+sub[id[i]]-1);
			pair<int, int>x = seg.query(1, 0, seg.size-1, pos[id[i]], pos[id[i]]+sub[id[i]]-1);
			cout << x.first << "\n";
			seg.update(x.second);
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
