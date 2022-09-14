//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

// #define int long long
// const int oo = 1e18, K = 30;

struct fenwick{
	vector<int>s;
	void update(int pos, int dif) { // a[pos] += dif
		for (; pos < (int)s.size(); pos |= pos + 1) s[pos] += dif;
	}
	void clear(int &n){ s.assign(n+1, 0);}
	int query(int pos) { // sum of values in [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int query(int l, int &r){return query(r)-query(l-1);}
};
vector<pair<int, int>>tab;
vector<int>a, b;
fenwick fen;
int n, N, cnt;

long long check(int k){
	cnt++;
	tab.clear();
	fen.clear(n);
	for (int i = 0; i<N; i++){
		int l = a[i];
		int r = b[i + k >= N ? i+k-N : i+k];
		if (r < l) swap(l, r);
		tab.emplace_back(l, r);
	}
	stable_sort(tab.begin(), tab.end());
	long long tmp = 0;
	for (auto &[l, r]:tab){
		// debug(l, r, fen.query(l, r));
		tmp += fen.query(l+1, r);
		fen.update(r, 1);
	}
	// debug(k, tmp);
	return tmp;
}

void solve(){
	cin >> n;
	N = n;
	n = 2*n;
	for (int i = 0; i<n; i++){
		char c; cin >> c;
		if (c == 'B') a.emplace_back(i+1);
		else b.emplace_back(i+1);
	}
	// debug(a, b);
	// fen.init(n+1);
	long long f[N];
	memset(f, -1, sizeof(f));
	int l = 0, r = N-1;
	while (r - l >= 3){
		int m = (l+r)/2;
		if (f[m] == -1) f[m] = check(m);
		if (f[m+1] == -1) f[m+1] = check(m+1);
		if (f[m] < f[m+1]) l = m;
		else r = m+1;
	}
	long long ans = max(0LL, f[l]);
	for (int i = l+1; i<=r; i++) {
		if (f[l] == -1) f[l] = check(l);
		ans = max(ans, f[l]);
		if (f[i] == -1) f[i] = check(i);
		if (f[l] < f[i]) {
			l = i;
			ans = f[i];
		}
	}
	cout << ans << "\n";
	// debug(cnt);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
