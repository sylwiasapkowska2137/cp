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

void solve(){
	int n; cin >> n;
	vector<LL>base;
	for (int i = 0; i<n; i++){
		int ile; LL c; cin >> ile >> c;
		vector<LL>pref(c+1, INF);
		pref[0] = 0LL;
		LL sum = 0LL, rest = 0LL, ans = 0LL;
		for (int j = 0; j<ile; j++) {
			LL x; cin >> x;
			rest = (rest+x)%c;
			sum += x;
			if (pref[rest] != INF) ans = max(ans, sum-pref[rest]);
			else pref[rest] = sum;
		}
		for (auto &v: base){
			ans = min(ans, ans^v);
		}
		if (ans) base.push_back(ans);
	}
	sort(base.begin(), base.end());
	reverse(base.begin(), base.end());
	//debug(base);
	int q; cin >> q;
	while (q--){
		LL x; cin >> x;
		for (auto i: base){
			x = min(x, x^i);
		}
		if (!x) cout << "TAK\n";
		else cout << "NIE\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
