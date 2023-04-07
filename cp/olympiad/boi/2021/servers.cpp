//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
using namespace __gnu_pbds;

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
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef pair<int, int> T;
const int oo = 1e9+7, K = 20;
typedef tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

//czy sciezka od a do b uzywa krawedzi ≤t i jest rosnaca??
struct Q{
	int a, b, t, idx; 
	Q(){}
	Q(int _a, int _b, int _t, int _idx){
		a = _a, b = _b, t = _t, idx = _idx;
	}
};

struct DSU{
	vector<int>rep, sz;

	DSU(int n){
		rep.resize(n);
		iota(rep.begin(), rep.end(), 0);
		sz.assign(n, 1);
	}

	int f(int a){return a == rep[a] ? a : rep[a] = f(rep[a]);}

	bool sameset(int a, int b){
		return f(a) == f(b);
	}

	bool u(int a, int b){
		a = f(a); b = f(b);
		if (a == b) return false;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		rep[b] = a;
		return true;
	}
};

void solve(){
    int n, q; cin >> n >> q;
    int m = 1, idx = 1;
    vector<Q>Qque;
	vector<int>ans(q+1);
	vector<vector<T>>g(n+1), event(n+1);
	vector<T>edges = {{0, 0}};
    for (int i = 1; i<n+q; i++){
		char c; cin >> c;
		if (c == 'S'){
			int a, b; cin >> a >> b;
			g[a].emplace_back(b, m);
			g[b].emplace_back(a, m);
			edges.emplace_back(a, b);
			m++;
		} else if (c == 'Q'){
			int a, b; cin >> a >> b;
			Qque.emplace_back(b, a, m, idx++);
		} else {
			int a; cin >> a;
			event[a].emplace_back(m-1, idx++);
		}
	}
	DSU dsu(n+2);
	vector up(n+1, vector<int>(K));
	vector mn(n+1, vector<int>(K, oo));
	vector mx(n+1, vector<int>(K, -oo));
	vector<int>depth(n+1), cost(n+1);
	function<void(int, int, int)>dfs = [&](int v, int pa, int c){
		up[v][0] = pa;
		cost[v] = c;
		for (int i = 1; i<K; i++) {
			up[v][i] = up[up[v][i-1]][i-1];
			mn[v][i] = min(mn[v][i-1], mn[up[v][i-1]][i-1]);
			mx[v][i] = max(mx[v][i-1], mx[up[v][i-1]][i-1]);
		}
		for (auto [x, id]: g[v]){
			if (x == pa) continue;
			depth[x] = depth[v]+1;
			mn[x][0] = id - c;
			mx[x][0] = id - c;
			dfs(x, v, id);
		}
	};
	dfs(1, 1, -oo);
	auto lca = [&](int a, int b){
		if (depth[a] > depth[b]) swap(a, b);
		for (int i = K-1; i>=0; i--){
			if (depth[b] - (1<<i) >= depth[a]){
				b = up[b][i];
			}
		}
		if (a == b) return a;
		for (int i = K-1; i>=0; i--){
			if (up[a][i] != up[b][i]){
				a = up[a][i];
				b = up[b][i];
			}
		}
		return up[a][0];
	};
	int ptr = 0;
	auto is_increasing = [&](int a, int b, bool f){ 
		//f = 1->chcemy by byla rosnaca w gore
		//f = 0->malejaca w gore
		if (depth[b] - depth[a] <= 1) return true;
		//sciezka pionowa od a do b (b w poddrzewie a)
		// debug(a, b, depth[a], depth[b]);
		int jump = depth[b] - depth[a] - 1;
		if (!f){
			int currmn = oo, v = b;
			for (int i = K-1; i>=0; i--){
				if (jump&(1<<i)){
					debug(i, v, mn[v][i]);
					currmn = min(currmn, mn[v][i]);
					v = up[v][i];
				}
			}
			return currmn > 0;
		}
		int currmx = -oo, v = b;
		for (int i = K-1; i>=0; i--){
			if (jump&(1<<i)){
				debug(i, v, mx[v][i]);
				currmx = max(currmx, mx[v][i]);
				v = up[v][i];
			}
		}
		debug(currmx);
		return currmx < 0;
	};
	auto below_lca = [&](int a, int b){
		bool f = 0;
		if (depth[a] < depth[b]) {
			swap(a, b);
			f = 1;
		}
		for (int i = K-1; i>=0; i--){
			if (depth[a] - (1<<i) >= depth[b]){
				a = up[a][i];
			}
		}
		assert(a != b);
		for (int i = K-1; i>=0; i--){
			if (up[a][i] != up[b][i]){
				a = up[a][i];
				b = up[b][i];
			}
		}
		if (f) swap(a, b);
		return T{a, b};
	};
	for (auto &[a, b, t, id]: Qque){
		while (ptr + 1 < t){
			ptr++;
			dsu.u(edges[ptr].first, edges[ptr].second);
		}
		if (!dsu.sameset(a, b)) {
			ans[id] = -2;
			// cout << "no\n";
			continue;
		}
		int l = lca(a, b);
		debug(a, b, l);
		if (l == b){
			//sciezka ma byc rosnaca
			if (is_increasing(b, a, 1)) ans[id] = -1;
			else ans[id] = -2;
			continue;
		} 
		if (l == a){
			//sciezka ma byc malejaca
			if (is_increasing(a, b, 0)) ans[id] = -1;
			else ans[id] = -2;
			continue;
		}
		//rosnaca od a do l i malejaca od l do b
		T now = below_lca(a, b);
		debug(now, is_increasing(l, a, 1), is_increasing(l, b, 0));
		if (is_increasing(l, a, 1) && is_increasing(l, b, 0) && cost[now.first] < cost[now.second]) ans[id] = -1;
		else ans[id] = -2;
	}

	//-1 ->yes
	//-2 ->no

	vector<int>sub(n+1), used(n+1);
	function<int(int, int)>subsize = [&](int v, int pa){
		sub[v] = 1;
		for (auto [x, id]: g[v]){
			if (x == pa || used[x]) continue;
			sub[v] += subsize(x, v);
		}
		return sub[v];
	};
	function<int(int, int, int)>get_centroid = [&](int v, int pa, int ms){
		for (auto [x, id]: g[v]){
			if (x == pa || used[x]) continue;
			if (2*sub[x] > ms) return get_centroid(x, v, ms);
		}
		return v;
	};
	vector<int>tmp;
	vector<bool>increasing(n+1), decreasing(n+1);
	vector<int> cost2(n+1);
	function<void(int, int, int, bool, bool)>dfessa = [&](int v, int pa, int c, bool inc, bool dec){
		increasing[v] = inc;
		decreasing[v] = dec;
		cost2[v] = c;
		tmp.emplace_back(v);
		for (auto &[x, id]: g[v]){
			if (x == pa || used[x]) continue;
			dfessa(x, v, id, (inc && id > c), (dec && (id < c)));
		}	
	};
	ordered_set now;
	function<void(int)>centroid = [&](int v){
		v = get_centroid(v, v, subsize(v, v));
		sort(g[v].begin(), g[v].end(), [&](auto x, auto y){return x.second > y.second;});
		now.clear();
		for (auto &[y, tttt]: g[v]){
			if (used[y]) continue;
			dfessa(y, v, tttt, 1, 1);
			for (auto x: tmp){
				if (!decreasing[x]) continue;
				for (auto &[czas, id]: event[x]){
					if (x == v || cost2[y] > czas) continue;
					int it = now.order_of_key({czas, oo});
					debug(x, czas, id, it+1);
					ans[id] += it+1;
				}
			}
			debug(y, tmp);
			for (auto x: tmp){
				debug(x, cost2[x]);
				if (increasing[x]) now.insert({cost2[x], x}); //remember about centroid +1 !!
				debug(x, (bool)increasing[x], (bool)decreasing[x]);
			}
			tmp.clear();
		}
		debug(now);
		for (auto &[czas, id]: event[v]){
			int it = now.order_of_key({czas, oo});
			debug(v, czas, id, it+1);
			ans[id] += it+1;
		}
		used[v] = 1;
		for (auto &[x, id]: g[v]){
			if (!used[x]){
				centroid(x);
			}
		}
	};
	centroid(1);
	for (int i = 1; i<=q; i++){
		if (ans[i] == -1) cout << "yes\n";
		if (ans[i] == -2) cout << "no\n";
		if (ans[i] >= 0) cout << ans[i] << "\n";
	}
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}