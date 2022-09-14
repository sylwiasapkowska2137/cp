//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
const int oo = 1e18, K = 30;
const int Q = 2139, mod = 1e9+7;

int mul(int a, int b){
	return (a*b)%mod;
}

int power(int a, int b){
	if (!b) return 1LL;
	int k = power(a, b/2);
	k = mul(k, k);
	if (b&1) k = mul(k, a);
	return k;
}

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

int inve(int a){
	return power(a, mod-2);
}

const int M = 1e6+2137;
int H[M+1][3];
int a[M+1], inv[M+1];
vector<int>tab;

void solve(){
	int n, m; cin >> n >> m;
	tab.resize(n);
	int Hash = 0;
	for (int i = 0; i<n; i++) {
		cin >> tab[i];
		add(Hash, mul(tab[i]+1, a[i+1]));
	}
	if (m >= 5) {
		cout << "-1\n";
		return;
	}
	if (m == 1){
		if (*max_element(tab.begin(), tab.end()) != 0) cout << "-1\n";
		else cout << "0\n";
		return;
	}
	m-=2;
	for (int i = n; i<M; i++){
		int curr = mul((H[i][m]-H[i-n][m]+mod), inv[i-n]);
		if (curr == Hash){
			cout << i-n << "\n";
			return;
		}
	}
	cout << "-1\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	a[0] = inv[0] = 1;
	int I = power(Q, mod-2);
	for (int i = 1; i<=M; i++) {
		a[i] = mul(a[i-1], Q);
		inv[i] = mul(inv[i-1], I);
		// debug(a[i], inv[i]);
	}
	vector<int>prev, curr;
	for (int m: {2, 3, 4, 5}){
		prev = {0};
		curr.clear();
		while (1){
			for (int i = 0; i<m; i++){
				for (auto x: prev){
					curr.emplace_back((x+i)%m);
					if (curr.size() == M) break;
				}
				if (curr.size() == M) break;
			}
			swap(prev, curr);
			if (prev.size() >= M) break;
			curr.clear();
		}
		for (int i = 0; i<(int)prev.size(); i++){
			H[i+1][m-2] = H[i][m-2];
			add(H[i+1][m-2], mul(prev[i]+1, a[i+1]));
		}
	}
	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}
