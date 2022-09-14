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


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

LL p(LL a, LL b){
	return a+rng()%(b-a+1);
}

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<LL>c(n+1), ans(n+1, 0);
	const LL INF = (1LL<<60);
	for (int i = 1; i<=n; i++){
		c[i] = p(1, INF);
	}
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		ans[a] ^= c[b];
		ans[b] ^= c[a];
	}
	int res = 0;
	for (int i = 1; i<=n; i++){
		if (!ans[i]) res++;
	}
	while (k--){
		int v; cin >> v;
		vector<int>tab(v);
		LL xx = 0;
		for (int i = 0; i<v; i++){
			cin >> tab[i];
			xx ^= c[tab[i]];
		}
		for (auto x: tab){
			LL prev = ans[x];
			ans[x] ^= (xx^c[x]);
			if (!prev && ans[x]) res--;
			if (prev && !ans[x]) res++;
		}
		cout << res << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
