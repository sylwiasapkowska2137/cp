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

const int mod = 1e9+7;

struct segtree{
	vector<LL>tab;
	int size = 1;

	segtree(int n, vector<LL>&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, 1LL);
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--){
			tab[i] = (tab[2*i]*tab[2*i+1])%mod;
		}
	}

	LL query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL ans = 1LL;
		while (r-l>1){
			if (!(l&1)) ans = (ans*tab[l+1])%mod;
			if (r&1) ans = (ans*tab[r-1])%mod;
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n, k; cin >> n >> k;
	vector<LL>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	vector<int>s(n+1, mod);
	int r = 0;
	LL sum = 0LL;
	for (int l = 1; l<=n; l++){
		while (r+1<=n && sum <= k){
			r++;
			sum += a[r];
		}
		if (sum > k){
			s[l] = r;
		}
		sum -= a[l];
	}
	//debug(s);
	vector<LL>suff(n+2, 0);
	for (int i = n; i>=1; i--){
		suff[i] = (a[i]*(1+suff[i+1]))%mod;
	}
	//debug(suff);
	segtree seg(n+1, a);
	LL ans = 0LL;
	for (int i = 1; i<=n; i++){
		if (s[i] == mod) continue;
		LL x = 1LL;
		if (i < s[i]) x = seg.query(i, s[i]-1);
		x = (x*suff[s[i]])%mod;
		ans = (ans+x)%mod;
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
