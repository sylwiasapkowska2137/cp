//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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

void solve(){
	int n, H, M; cin >> n >> H >> M;
	auto nxt = [&](){
		M++;
		if (M == 60) {
			M = 0;
			H++;
		}
		if (H == 24) H = 0;
	};
	int ch = 0, cm = 0;
	auto nxt2 = [&](){
		cm++;
		if (cm == 60) {
			cm = 0;
			ch++;
		}
		if (ch == 24) ch = 0;
	};

	set<pair<int, int>>s;
	for (int i = 0; i<n; i++){
		int h, m; cin >> h >> m;
		s.insert({h, m});
	}
	
	while (1){
		if (s.find({H, M}) != s.end()){
			cout << ch << " " << cm << "\n";
			return;
		}
		nxt();
		nxt2();
		// debug(H, M);
		// debug(ch, cm);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}