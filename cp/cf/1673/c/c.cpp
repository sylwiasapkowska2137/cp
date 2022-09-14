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
const int mod = 1e9+7;
const int N = 4e4+1;
int M = 498;

bool check(int x){
	vector<int>d;
	while (x){
		d.emplace_back(x%10);
		x/=10;
	}
	int L = 0, R = (int)d.size()-1;
	while (L <= R){
		if (d[L] != d[R]) return 0;
		L++, R--;
	}
	return 1;
}

void add(int &a, int b){
	a+=b;
	if (a >= mod) a -= mod;
}

int add2(int a, int b){
	int ret = a+b;
	if (ret >= mod) ret -= mod;
	return ret;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int>pal;
	for (int i = 1; i<=N; i++){
		if (check(i)){
			pal.emplace_back(i);
		}
	}
	//debug(pal);
	vector<int>dp(N+1, 0);
	dp[0] = 1;
	for (int i = 1; i<=M; i++){
		vector<int>new_dp(N+1, 0);
		for (int sum = 0; sum<=N; sum++){
			add(new_dp[sum],add2(dp[sum],(sum-pal[i-1]>=0?new_dp[sum-pal[i-1]]:0)));
		}
		swap(dp, new_dp);
	}

	int t = 1; cin >> t;
	while (t--) {
		int x; cin >> x;
		cout << dp[x] << "\n";
	}
	
	return 0;
}