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
vector<int>graf[MAX], val, sub, depth, big, pre, pos, numer, ile, top, pa;
int tt, cnt, n;

void init(int n){
	val.resize(n);
	sub.assign(n, 0);
	depth.assign(n, 0);
	big.assign(n, -1);
	pos.assign(n, 0);
	numer.assign(n, 0);
	pa.assign(n, 0);
	top.assign(n, 0);
	ile.assign(n, 0);
}

void dfs1(int v, int p){
	sub[v] = 1;
	pa[v] = p;
	for (auto x: graf[v]){
		if (x!=p){
			depth[x] = depth[v]+1;
			dfs1(x, v);
			sub[v] += sub[x];
			if (big[v] == -1 || sub[x] > sub[big[v]]){
				big[v] = x;
			}
		}
	}
}

void dfs2(int v, int p){
	pre.push_back(v);
	numer[v] = cnt;
	pos[v] = tt++;
	ile[cnt]++;
	if (ile[cnt] == 1) top[cnt] = v;
	if (big[v] != -1) dfs2(big[v], v);
	for (auto x: graf[v]){
		if (x == p || x == big[v]) continue;
		cnt++;
		dfs2(x, v);
	}	
}

struct sadd{
	vector<int>tab;
	int size = 1;

	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		for (int i = 1; i<(int)val.size(); i++) {
			tab[pos[i]+size] = val[i];
		}
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
} add;

struct sdiff{
	vector<int>tab;
	int size = 1;

	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		for (int i = 1; i<(int)pre.size(); i++) tab[i+size] = val[pre[i]]-val[pre[i-1]]; //tab[1] = val[pre[1]]-val[pre[0]] itd...
		for (int i = size-1; i>=1; i--)	tab[i] = __gcd(tab[2*i], tab[2*i+1]);
	}

	void update(int x, int v){
		x += size;
		tab[x] += v;
		//tab[x] = abs(tab[x]);
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
} diff;

int query(int a, int b){
	int ans = 0;
	while (numer[a] != numer[b]){
		if (depth[top[numer[a]]] < depth[top[numer[b]]]) swap(a, b);
		ans = __gcd(ans, add.query(pos[a]));
		if (pos[top[numer[a]]] < pos[a]) ans = __gcd(ans, diff.query(pos[top[numer[a]]]+1, pos[a]));
		a = pa[top[numer[a]]];
	}
	if (depth[a] > depth[b]) swap(a, b);
	ans = __gcd(ans, add.query(pos[a]));
	//debug(diff.tab);
	//debug(pos[a], pos[b]);
	if (pos[a] < pos[b]) ans = __gcd(ans, diff.query(pos[a]+1, pos[b]));
	return abs(ans);
}

void update(int a, int b, int d){
	while (numer[a] != numer[b]){
		if (depth[top[numer[a]]] < depth[top[numer[b]]]) swap(a, b);
		diff.update(pos[top[numer[a]]], d);
		if (pos[a]+1 < n) diff.update(pos[a]+1, -d);
		add.update(pos[top[numer[a]]], pos[a], d);
		a = pa[top[numer[a]]];
	}
	if (depth[a] > depth[b]) swap(a, b);
	//debug(pos[a], pos[b]);
	diff.update(pos[a], d);
	if (pos[b]+1 < n) diff.update(pos[b]+1, -d);
	add.update(pos[a], pos[b], d);
}

void solve(){
	cin >> n;
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	init(n+1);
	for (int i = 1; i<=n; i++) cin >> val[i];
	dfs1(1, 1);
	dfs2(1, 1);
	add.init(n+1);
	diff.init(n+1);
	
	//debug(diff.tab);
	//debug(pre);
	//debug(pos);
	//debug(numer);
	//debug(top);
	//debug(ile);

	int q; cin >> q;
	while (q--){
		char t; cin >> t;
		if (t == 'Q'){
			int a, b; cin >> a >> b;
			cout << query(a, b) << "\n";
		} else {
			int a, b, d; cin >> a >> b >> d;
			update(a, b, d);
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
