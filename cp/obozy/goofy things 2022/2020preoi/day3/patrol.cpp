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

const int MAX = 1e5+7, K = 20;
int pos[MAX+2138][K+1];
const LL mod = 1e9+7, base = 2137, I = 440336924;
const LL base2 = 37277, I2 = 293880948, mod2 = 1e9+9;
vector<pair<int, char>>graf[MAX];
vector<pair<LL, LL>>Hash;
map<pair<LL, LL>, int>mapa;
LL H, H2;

struct HASH{
	LL base, mod, I;
	vector<LL>hh, pot, inv;

	void init(LL _base, LL _mod, LL _inv){
		base = _base, mod = _mod, I = _inv;
	}

	void create_powers(int x){
		pot.emplace_back(1);
		inv.emplace_back(1);
		LL p = 1LL, INV = 1LL;
		for (int i = 1; i<=x; i++){
			p = (p*base)%mod;
			pot.emplace_back(p);
			INV = (INV*I)%mod;
			inv.emplace_back(INV);
		}
	}

	void make_hash(string &s){
		int m = (int)s.size();
		hh.assign(m+1, 0);
		for (int i = 1; i<=m; i++) hh[i] = ((hh[i-1]+(LL)s[i]*pot[i])%mod+mod)%mod;
	}

	LL H(int a, int b){	
		LL x = (((hh[b]-hh[a-1]+mod)%mod * inv[a-1])%mod+mod)%mod;
		return x;
	}
} A, B;

LL power(LL a, LL b, LL mod){
	if (!b) return 1LL;
	LL k = power(a, b/2, mod);
	k = (k*k)%mod;
	if (b&1) k = (k*a)%mod;
	return k;
}
 
LL inver(LL a, LL mod){
    return power(a, mod-2, mod);
}

void dfs(int v = 0, int d = 0){
	Hash.push_back({H, H2});
	mapa[{H, H2}] = v;
	for (auto [x, c]: graf[v]){
		H = (H+(LL)c*A.pot[d+1])%mod;
		H2 = (H2+(LL)c*B.pot[d+1])%mod2;
		dfs(x, d+1);
		H = (H-(LL)c*A.pot[d+1]+mod)%mod;
		H2 = (H2-(LL)c*B.pot[d+1]+mod2)%mod2;
	
	}
}

void solve(){
	int n, m, q; cin >> n >> m >> q;
	A.init(base, mod, I);
	B.init(base2, mod2, I2);
	A.create_powers(max(n, m)+1);
	B.create_powers(max(n, m)+1);
	
	for (int i = 1; i<=n; i++){
		int x; char c; cin >> x >> c;
		graf[x].emplace_back(i, c);	
	}

	dfs();
	sort(Hash.begin(), Hash.end());
	string s; cin >> s;
	s = "$"+s;
	A.make_hash(s);
	B.make_hash(s);
	int inf = m+2137;
	for (int i = 0; i<MAX; i++){
		for (int j = 0; j<=K; j++){
			pos[i][j] = inf;
		}
	}

	for (int i = 1; i<=m; i++){
		int L = i, R = m, ans = -1;
		while (R>=L){
			int mid = (L+R)/2;
			pair<LL, LL> check = {A.H(i, mid), B.H(i, mid)};
			auto it = lower_bound(Hash.begin(), Hash.end(),check)-Hash.begin();
			if (it < (int)Hash.size() && Hash[it] == check){
				ans = mid;
				L = mid+1;
			} else R = mid-1;
		}
		if (ans == -1) pos[i][0] = i+1;
		else pos[i][0] = ans+2;
	}
	
	for (int j = 1; j<=K; j++){	
		for (int i = 1; i<=m; i++){
			if (pos[i][j-1] != inf) pos[i][j] = pos[pos[i][j-1]][j-1];
		}
	}
	/*
	for (int j = 0; j<=4; j++){
		cerr << j << " ";
		for (int i = 1; i<=m; i++){
			cerr << pos[i][j] << " ";
		}
		cerr << "\n";
	}
	*/
	while (q--){
		int a, b, ans = 0; cin >> a >> b;
		for (int i = K; i>=0; i--){
			if (pos[a][i] <= b+1){
				ans += (1<<i);
				a = pos[a][i];
			}
		}
		cout << ans << " ";
		if (a > b) cout << "0\n";
		else cout << mapa[{A.H(a, b), B.H(a, b)}] << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
