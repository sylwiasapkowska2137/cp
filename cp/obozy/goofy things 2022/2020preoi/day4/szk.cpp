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

const int MAX = 1e5+7;
vector<int>graf[MAX], val, big, depth, pa, sub, chain, num, cntsz, top, gcd;
int all, cnt = 1;

void init(int n){
	val.resize(n);
	big.assign(n, -1);
	pa.assign(n, -1);
	sub.assign(n, 0);
	depth.assign(n, 0);
	chain.assign(n, 0);
	top.assign(n, 0);
	num.assign(n, 0);
	cntsz.assign(n, 0);
	gcd.assign(n, 0);
}

struct add{
	vector<int>tab;
	int size = 1;

	void init(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = a[i];
	}

	void update(int l, int r, int v){
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) tab[l+1]+=v;
			if (r&1) tab[r-1]+=v;
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

struct diff{
	vector<int>tab;
	int size = 1;

	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		#warning todo: init tablicy roznic
		vector<int>tmp(n);
		for (int i = 1; i<(int)num.size(); i++){
			tmp[num[i]] = i;
		}
		debug(tmp);
		for (int i = 2; i<(int)tmp.size(); i++){
			if (chain[tmp[i]] == chain[tmp[i-1]]){
				tab[i+size-1] = abs(val[tmp[i]]-val[tmp[i-1]]);
			}
		}
		for (int i = size-1; i>=1; i--) tab[i] = __gcd(tab[2*i], tab[2*i+1]);
	}

	void update(int x, int v){
		x += size;
		tab[x] += v;
		while (x){
			x/=2;
			tab[x] = __gcd(tab[2*x], tab[2*x+1]);
		}
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) ans = __gcd(ans, tab[l+1]);
			if (r&1) ans = __gcd(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
} sdiff;

void dfs(int v, int p){
	pa[v] = p;
	sub[v] = 1;
	for (auto x: graf[v]){
		if (x!=p){
			depth[x] = depth[v]+1;
			dfs(x, v);
			sub[v] += sub[x];
			if (big[v] == -1 || sub[x] > sub[big[v]]){
				big[v] = x;
			}
		}
	}
}

void hld(int v, int p = -1){
	chain[v] = cnt;
	num[v] = ++all;
	if (!cntsz[cnt]) top[cnt] = v;
	cntsz[cnt]++;
	if (big[v] != -1) hld(big[v], v);
	for (auto x: graf[v]){
		if (x == big[v] || x == p) continue;
		cnt++;
		hld(x, v);
	}
}

void update(int a, int b){

}

int query(int a, int b){
	int res = 0;
	while (chain[a] != chain[b]){
		if (depth[top[chain[a]]] < depth[top[chain[b]]]) swap(a, b);
		int start = top[chain[a]];
		if (num[a] == num[start]+cntsz[chain[a]]-1) {
			res = __gcd(res, gcd[chain[a]]);
		} else res = __gcd(res, sdiff.query(num[a], num[b]));
		a = pa[start];
	}
	if (depth[b] > depth[a]) swap(a, b);
	res = __gcd(res, sdiff.query(num[a], num[b]));
	return res;
}

void solve(){
	int n; cin >> n;
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	init(n+1);
	for (int i = 1; i<=n; i++) cin >> val[i];
	dfs(1, 1);
	hld(1, 1);
	debug(chain);
	debug(top);
	debug(num);
	debug(val);
	sdiff.init(n+1);
	int q; cin >> q;
	debug(sdiff.tab);
	return;
	while (q--){
		char t; cin >> t;
		if (t == 'Q'){
			int a, b;
			cout << query(a, b) << "\n";
		} else {
			int a, b, d; cin >> a >> b >> d;
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
