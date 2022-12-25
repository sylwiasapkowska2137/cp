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

#define int long long
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;
const int s = 2;
int n;

struct Block{
	vector<int>val, pref;

	void init(int p, int v){
		val.emplace_back(v);
		pref.emplace_back((pref.empty() ? v : pref.back()^v));
	}

	void update(int x, int v){
		x %= s;
		val[x] = v;
		pref[x] = (x ? pref[x-1]^v : v);
		for (int i = x+1; i<(int)pref.size(); i++){
			pref[i] = pref[i-1] ^ val[i];
		}
	}

	int count(int l, int r){
		l %= s;
		int x = 0;
		if (r == oo) r = (int)val.size()-1;
		for (int i = l; i<=r; i++) x ^= val[i];
		return x;
	}

	int all(){
		return pref.back();
	}

	int exists(int val, int idx){
		for (int i = idx%s; i<(int)pref.size(); i++){
			if (pref[i] == val){
				return (i-idx%s)+idx;
			}
		}
		return -1;
	}
};

vector<Block>tab;

int xor_count(int l, int r){
	int L = l/s;
	int R = r/s;
	if (L == R) return tab[L].count(l, r);
	int x = tab[L].count(l, oo) ^ tab[R].count(0, r);
	for (int i = L+1; i<R; i++) x ^= tab[L].all();
	return x;
}

int first_to_the_right(int val, int idx){
	int L = val/s;
	int x = tab[L].exists(val, idx);
	if (x != -1) return x;
	x = tab[L].count(idx+1, oo);
	for (int i = L+1; i<(int)tab.size(); i++){
		
	}
}


bool check(vector<int>&curr){
	int k = (int)curr.size();
	return 1;
	int base = (1<<k);
	vector<int>dist(base+1, oo);
	dist[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({0, 0});
	while (pq.size()){
		auto [d, mask] = pq.top();
		pq.pop();
		int v = 0;
		for (int i = 0; i<k; i++){
			if (mask&(1<<i)){
				v ^= curr[i];
			}
		}
		for (int i = 0; i<k; i++){
			int new_v = v^curr[i];
			int new_mask = mask^(1<<i);
			int e = first_to_the_right(new_v, dist[mask]);
			if (dist[new_mask] > e){
				dist[new_mask] = e;
				pq.push({e, new_mask});
			}
		}
	}
	for (int i = 0; i<base; i++){
		if (dist[i] == oo) continue;
		if (dist[i] == n) return 1;
		int a = xor_count(dist[i]+1, n);
		for (int j = 0; j<k; j++) if (a == curr[j]) return 1;
	}
	return 0;
}

void solve(){
	int q; cin >> n >> q;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	int ck = 1;
	while (ck * s <= n) ck++;
	tab.resize(ck);
	for (int i = 0; i<=n; i++) tab[i/s].init(i, a[i]);
	
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int x, v; cin >> x >> v;
			tab[x/s].update(x, v);
		} else {
			int k; cin >> k;
			vector<int>curr(k);
			for (int i = 0; i<k; i++) cin >> curr[i];
			if (check(curr)) cout << "TAK\n";
			else cout << "NIE\n";
		}
	}
	for (auto x: tab){
		debug(x.val);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
