#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back
#define dbg if(1)
const int MAX = 1e5+8;

struct HLD{
	int n, nr;
	vector<int>graf[MAX], depth, subtree, heavy, parent, lancuch[MAX], numer, head, val, sz;
	vector<vector<int>>segtree;
	vector<tuple<int, int, int>>edges;
	
	void dfs(int v, int pa = 1){
		subtree[v] = 1;
		parent[v] = pa;
		int maxi = 0;
		for (auto x: graf[v]){
			if (x!=pa){
				depth[x] = depth[v]+1;
				dfs(x, v);
				subtree[v] += subtree[x];
				if (subtree[x] > maxi){
					maxi = subtree[x];
					heavy[v] = x;
				}
			}
		}
	}
	
	void init(){
		cin >> n;
		
		depth.assign(n+1, 0);
		val.assign(n+1, 0);
		heavy.assign(n+1, -1);
		subtree.assign(n+1, 0);
		head.assign(n+1, 0);
		parent.assign(n+1, 0);
		numer.assign(n+1, 0);
		int a, b, c;
		for (int i = 1; i<n; i++){
			cin >> a >> b >> c;
			edges.pb(make_tuple(a, b, c));
			graf[a].pb(b);
			graf[b].pb(a);
		}
		nr = 0;
		dfs(1);
		for (tuple<int, int, int> x: edges){
			if (depth[get<0>(x)]>depth[get<1>(x)]) val[get<0>(x)] = get<2>(x);
			else val[get<1>(x)] = get<2>(x);
		}
		decompose();
		seg_init();
	}
	
	void seg_init(){
		segtree.resize(nr, vector<int>());
		sz.resize(nr);
		for (int i = 0; i<nr; i++){
			for (auto x: lancuch[i]) debug(x);
			cerr << "\n";
			sz[i] = 1;
			while (sz[i]<lancuch[i].size()) sz[i]*=2;
			segtree[i].assign(2*sz[i]+1, 0);
			for (int j = 0; j<(int)lancuch[i].size(); j++){
				segtree[i][j+sz[i]] = lancuch[i][j];
			}
			for (int j = sz[i]-1; j>=0; j--){
				segtree[i][j] = segtree[i][2*j]+segtree[i][2*j+1];
			}
		}
	}
	
	void decompose(int v = 1, int h = 1){
		head[v] = h;
		lancuch[nr].pb(v);
		numer[v] = nr;
		if (heavy[v]!=-1) decompose(heavy[v], head[v]);
		else nr++;
		for (auto x: graf[v]){
			if (x!=parent[v] && x!=heavy[v]) decompose(x, x);
		}
	}
	
	int LCA(int a, int b){
		//debug(a);
		//debug(b);
		if (numer[a]==numer[b]){
			if(depth[a]<depth[b]) return a;
			return b;
		}
		int pa = parent[head[a]];
		int pb = parent[head[b]];
		if (a == pa || b == pb) return 1;
		if (depth[pa]>=depth[pb]) return LCA(pa, b);
		return LCA(a, pb);
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	HLD hld;
	hld.init();
	//for (auto x: hld.val) debug(x);
	
	return 0;
}
 

