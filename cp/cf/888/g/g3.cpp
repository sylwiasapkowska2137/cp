//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;

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

#define int long long
const int oo = 1e18, M = 2e5+1, K = 30;

vector<int>rep, sz;
int tab[M*K][2], cnt[M*K], ends_here[M*K];
int trie_sz;

void add(int x, int pos){
	int v = 0;
	for (int i = K-1; i>=0; i--){
		bool s = (x&(1<<i));
		if (tab[v][s] == -1){
			tab[v][s] = ++trie_sz;
		}
		v = tab[v][s];
		cnt[v]++;
	}
	ends_here[v] = pos;
}

void remove(int x){
	int v = 0;
	for (int i = K-1; i>=0; i--){
		bool s = (x&(1<<i));
		v = tab[v][s];
		cnt[v]--;
	}
}

pair<int, int>minn(int x){
	int v = 0, ans = 0;
	for (int i = K-1; i>=0; i--){
		bool s = (x&(1<<i));
		if (tab[v][s] != -1 && cnt[tab[v][s]] > 0){
			v = tab[v][s];
			ans += (s?(1<<i):0);
		} else {
			v = tab[v][s^1];
			ans += (s?0:(1<<i));
		}
	}
	return {ans, ends_here[v]};
}

void init(int n){
	rep.assign(n+1, 0);
	iota(rep.begin(), rep.end(), 0);
	sz.assign(n+1, 1);
}

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

bool Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a == b) return 0;
	if (sz[a] < sz[b]) swap(a, b);
	rep[b] = a;
	sz[a] += sz[b];
	return 1;
}


void solve(){
	int n; cin >> n;
	memset(tab, -1, sizeof(tab));
	vector<int>a;
	for (int i = 1; i<=n; i++){
		int x; cin >> x;
		a.emplace_back(x);
	}
	init(n);
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	n = (int)a.size();
	int edges = 0;
	
	for (int i = 0; i<(int)a.size(); i++) add(a[i], i);
	int ans = 0;
	vector<vector<int>>comp(n+1);
	while (edges < n-1){
		vector<pair<int, int>>good;
		for (int i = 0; i<n; i++) comp[i].clear();
		for (int i = 0; i<n; i++){
			comp[Find(i)].emplace_back(i);
		}
		for (int i = 0; i<n; i++){
			if (comp[i].empty()) continue;
			//debug(comp[i]);
			for (auto x: comp[i]) remove(a[x]);
			int from = -1, to = -1, mini = oo;
			for (auto x: comp[i]){
				auto [y, id] = minn(a[x]);
				//debug(x, id, a[x], y);
				if ((a[x]^y) < mini){
					mini = a[x]^y;
					from = x, to = id;
				}
			}
			for (auto x: comp[i]){
				add(a[x], x);
			}
			if (to == -1) continue;
			good.emplace_back(from, to);
		}
		sort(good.begin(), good.end(), [&](auto x, auto y){return (a[x.first]^a[x.second]) < (a[y.first]^a[y.second]);});
		//debug(good);
		for (auto [x, y]:good){
			if (Union(x, y)){
				edges++;
				ans += (a[x]^a[y]);
			}
		}
		//return;
	}	
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; //cin >> t;
	while (t--) solve();
	
	return 0;
}
