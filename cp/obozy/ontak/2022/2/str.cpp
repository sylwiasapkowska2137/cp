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
void __print(uint64_t x){cerr << x;}

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
const int oo = 1e9, K = 27;

mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

int pp(int a, int b){
	return a+rng()%(b-a+1);
}

int ti(char c){
	return (int)(c-'a');
}

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

void solve(){
	string t, p; cin >> t >> p;
	int T = (int)t.size();
	t = "$"+t;
	int P = (int)p.size();
	if (P > T){
		cout << "0\n";
		return;
	}
	vector<int>a(T+1), inv(T+1);
	a[0] = inv[0] = 1;
	int I = power(Q, mod-2);
	for (int i = 1; i<=T; i++) {
		a[i] = mul(a[i-1], Q);
		inv[i] = mul(inv[i-1], I);
	}
	vector<vector<int>>H(T+1, vector<int>(K));
	int curr = 0;
	vector<int>ans(T+1);
	for (int j = 0; j<K; j++){
		int tmp = 0;
		for (int i = 0; i<P; i++) if (ti(p[i]) == j) add(tmp, a[i+1]);
		curr ^= tmp;
		for (int i = 1; i<=T; i++){
			H[i][j] = H[i-1][j];
			if (ti(t[i]) == j) add(H[i][j], a[i]);
			// debug(i, j, H[i][j]);
		}
		for (int i = P; i<=T; i++) ans[i] ^= mul((H[i][j]-H[i-P][j]+mod), inv[i-P]);
	}
	// sort(curr.begin(), curr.end());
	// for (int i = P; i<=T; i++) sort(ans[i].begin(), ans[i].end());
	int ret = 0;
	for (int i = P; i<=T; i++){
		if (curr == ans[i]){
			// debug(i);
			ret++;
		}
	}
	cout << ret << "\n";
}


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}