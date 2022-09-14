//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;

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

#define int long long
const int oo = 1e18, K = 30;

int ans;

void backtrack(int &n, int &s, int num, int sum){
	if (num >= n){
		ans = min(ans, num-n);
		return;
	}
	for (int i = 0; i<=9; i++){
		if (sum + i <= s && num*10+i > 0){
			backtrack(n, s, num*10+i, sum+i);
		}
	}
}

int sum(int a){
	int ans = 0;
	while (a){
		ans += (a%10);
		a/=10;
	}
	return ans;
}

void solve(){
	int n, s; cin >> n >> s;
	int N = n;
	vector<int>d;
	while (N){
		d.emplace_back(N%10);
		N/=10;
	}
	reverse(d.begin(), d.end());
	//debug(d);
	if (sum(n) <= s){
		cout << "0\n";
		return;
	}
	int ans = oo;
	for (int i = 0; i<(int)d.size(); i++){
		vector<int>e = {0};
		int num = 0, sum = 0;
		for (auto x: d) e.emplace_back(x);
		e[i+1]++;
		for (int j = i+2; j<(int)e.size(); j++) e[j] = 0;
		int pos = i+1;
		while (pos > 0 && e[pos] >= 10){
			e[pos]-=10;
			pos--;
			e[pos]++;
		}
		for (auto x: e){
			num *= 10;
			num += x;
			sum += x;
		}
		//debug(e, sum);
		if (sum <= s){
			ans = min(ans, num-n);
		}
	}
	ans = min(ans, (int)pow(10, (int)d.size())-n);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}