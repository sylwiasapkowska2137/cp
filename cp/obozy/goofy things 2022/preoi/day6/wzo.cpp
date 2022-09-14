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

const LL INF = 1e18;
const LL oo = 1e12;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

LL p(LL a, LL b){
	return a+rng()%(b-a+1);
}

LL solve(vector<int>&a, int n, int m){
	vector<LL>change(m+1, 0), tmp(n+1, 0);
	for (int i = 1; i<=m; i++) change[i] = p((oo/2), oo);
	map<LL, LL>cnt;
	for (int i = 1; i<=n; i++) tmp[i] = change[a[i]];
	cnt[0]++;
	LL sum = accumulate(change.begin(), change.end(), 0LL);
	LL curr = 0;
	LL ans = 0LL;
	//debug(tmp, sum);
	for (int i = 1; i<=n; i++){
		curr = ((curr+tmp[i])%sum+sum)%sum;
		ans += cnt[curr];
		cnt[curr]++;
	}
	return ans;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	LL ans = INF;
	for (int i = 0; i<2; i++){
		ans = min(ans, solve(a, n, m));
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
