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
const int mod = 998244353, I = 499122177;

void solve(){
	int n, k; cin >> n >> k;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];

	vector<int>vis(n+1);
	int turn = 0;
	vector<int>ret(n+1);
	while (1){
		pair<int, int>mx = {-oo, -oo};
		for (int i = 1; i<=n; i++){
			if (!vis[i]) mx = max(mx, {a[i], i});
		}
		if (mx.first == -oo) break;
		int pos = mx.second;
		vis[pos] = 1;
		ret[pos] = turn;
		// debug(pos);
		int ck = k;
		for (int i = pos-1; i>=0 && ck > 0; i--){
			if (!vis[i]){
				vis[i] = 1;
				ret[i] = turn;
				ck--;
			}
		}
		ck = k;
		for (int i = pos+1; i<=n && ck > 0; i++){
			if (!vis[i]){
				vis[i] = 1;
				ret[i] = turn;
				ck--;
			}
		}
		turn ^= 1;
	}
	for (int i = 1; i<=n; i++) cout << ret[i] << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
