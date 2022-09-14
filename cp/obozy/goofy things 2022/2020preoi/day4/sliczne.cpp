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

void solve(){
	int n, k; cin >> n >> k;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	set<pair<int, int>>s;
	vector<int>L(n+1), R(n+1);
	const int oo = 1e9+7;
	for (int i = 1; i<=n; i++){
		auto it = s.lower_bound({a[i], oo});
		if (it == s.end()) L[i] = 1;
		else L[i] = it->second+1;
		s.insert({a[i], i});
	}
	s.clear();
	for (int i = n; i>=1; i--){
		auto it = s.lower_bound({a[i], oo});
		if (it == s.end()) R[i] = n;
		else R[i] = it->second-1;
		s.insert({a[i], i});
	}
	vector<int>ul(n+1), ur(n+1), last(n+1, -1);
	for (int i = 1; i<=n; i++){
		if (last[a[i]] == -1) ul[i] = 1;
		else ul[i] = last[a[i]]+1;
		last[a[i]] = i;
	}
	fill(last.begin(), last.end(), -1);
	for (int i = n; i>=1; i--){
		if (last[a[i]] == -1) ur[i] = n;
		else ur[i] = last[a[i]]-1;
		last[a[i]] = i;
	}
	debug(L, R);
	debug(ul, ur);
	function<LL (int, int)>dnc = [&](int l, int r){
		if (l > r) return 0;
		if (l == r) return (LL)(a[l]-1 <= k);
		int mid = (l+r)/2;
		LL ans = 0LL;
		
		return dnc(l, mid)+ans+dnc(mid+1, r);
	};
	cout << dnc(1, n) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
