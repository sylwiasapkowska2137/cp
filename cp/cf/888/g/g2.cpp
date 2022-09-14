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
const int oo = 1e18;

const int M = 2e5+7;
const int K = 30;

int tab[M*K][2], cnt[M*K];
int sz = 1;

	
void add(int x){
	int v = 0;
	for (int i = K; i>=0; i--){
		bool a = x&(1<<i);
		if (!tab[v][a])	tab[v][a] = sz++;
		v = tab[v][a];
		cnt[v]++;
	}
	
}

void remove(int x){
	int v = 0;
	for (int i = K; i>=0; i--){
		bool s = (x&(1<<i));
		v = tab[v][s];
		cnt[v]--;
	}
}

int minn(int x){
	int v = 0, ans = 0;
	for (int i = K; i>=0; i--){
		bool s = (x&(1<<i));
		if (cnt[tab[v][s]] > 0){
			v = tab[v][s];
			ans += (s?(1<<i):0);
		} else {
			v = tab[v][s^1];
			ans += (s?0:(1<<i));
		}
	}
	return ans;
}

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	vector<vector<int>>comp(n+1);
	set<pair<int, int>>s; //a[i], i
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		add(a[i]);
		comp[i].emplace_back(i);
		s.insert({a[i], i});
	}
	vector<int>rep, sz;
	rep.assign(n+1, 0);
	sz.assign(n+1, 1);
	iota(rep.begin(), rep.end(), 0);

	function<int(int)>Find = [&](int a){
		if (a == rep[a]) return a;
		return rep[a] = Find(rep[a]);
	};

	function<bool(int, int)>Union = [&](int a, int b){
		a = Find(a);
		b = Find(b);
		if (a == b) return 0;
		if (sz[a] < sz[b]) swap(a, b);
		rep[b] = a;
		return 1;
	};

	int edges = 0;
	int ans = 0;

	while (edges < n-1){
		vector<pair<int, int>>good;
		for (int i = 1; i<=n; i++) comp[i].clear();
		for (int i = 1; i<=n; i++) comp[Find(i)].emplace_back(i);
		for (int i = 1; i<=n; i++){
			if (comp[i].empty()) continue;
			for (auto x: comp[i]){
				remove(a[x]);
				s.erase({a[x], x});
			}
			int from = -1, to = -1, mini = oo;
			for (auto x: comp[i]){
				int y = minn(a[x]);
				//debug(x, a[x], y, a[x]^y);
				if ((y^a[x]) <= mini){
					to = s.lower_bound({y, -1})->second;
					from = x;
					mini = y^a[x];
				}
			}
			for (auto x: comp[i]){
				s.insert({a[x], x});
				add(a[x]);
			}
			good.emplace_back(from, to);
		}
		//debug(good);
		sort(good.begin(), good.end(), [&](auto x, auto y){return (a[x.first]^a[x.second]) < (a[y.first]^a[y.second]);});
		for (auto [x, y]: good) {
			if (Union(x, y)) {
				edges++;
				ans += (a[x]^a[y]);
			}
		}
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
