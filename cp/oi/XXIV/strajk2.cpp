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

const int oo = 1e9+7;

struct segtree{
	vector<int>tab;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
	}

	void update(int l, int r, int v){
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) tab[l+1] += v;
			if (r&1) tab[r-1] += v;
			l/=2;r/=2;
		}
	}

	int query(int x){
		x += size;
		int ans = 0;
		while (x){
			ans += tab[x];
			x/=2;
		}
		return ans;
	}
};


void solve(){
	int n; cin >> n;
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<int>deg(n+1);
	for (int i = 1; i<=n; i++) deg[i] = (int)g[i].size();
	vector<int>par(n+1, -1);
	queue<int>q;
	vector<int>depth(n+1, oo);
	q.push(1);
	depth[1] = 0;
	vector<int>ord, pos(n+1);
	while (q.size()){
		int v = q.front(); q.pop();
		pos[v] = (int)ord.size();
		ord.emplace_back(v);
		for (auto x:g[v]){
			if (depth[x] == oo){
				depth[x] = depth[v]+1;
				par[x] = v;
				q.push(x);
			}
		}
	}
	// debug(ord);
	segtree seg(n+1);
	int Q; cin >> Q;
	int ans = 1;
	while (Q--){
		int v; cin >> v;
		int val = -1;
		if (v > 0) val = 1;
		v = abs(v);
		ans += (deg[v]-seg.query(pos[v])-1)*val;
		int f = -1;
		for (auto x: g[v]){
			if (depth[x] > depth[v]){
				f = x;
				break;
			}
		}
		if (f != -1) seg.update(pos[f], pos[f]+deg[v]-2+(int)(par[v]==-1), val);
		if (par[v] != -1) seg.update(pos[par[v]], pos[par[v]], val);
		cout << ans << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
