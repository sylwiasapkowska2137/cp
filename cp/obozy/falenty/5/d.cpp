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

int count(int x){
	int ans = 0;
	while (x){
		ans += (x%10);
		x/=10;
	}
	return ans;
}

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	iota(a.begin(), a.end(), 0);
	vector<int>s(n+1);
	for (int i = 1; i<=n; i++){
		if (i%10 == 0){
			s[i] = count(i);
		} else {
			s[i] = s[i-1]+1;
		}
	}
	sort(a.begin()+1, a.end(), [&](auto x, auto y){return s[x] == s[y] ? x < y : s[x] < s[y];});
	int ans = 0;
	for (int i = 1; i<=n; i++) ans += (a[i] == i);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}