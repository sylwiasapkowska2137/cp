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
const int oo = 9e18, K = 30;

void solve(){
	int n; cin >> n;
	vector<int>p(n+1), x(n+1), y(n+1);
	for (int i = 1; i<=n; i++){
		cin >> x[i] >> y[i] >> p[i];
	}
	int ans = oo;
	__uint128_t l = 0, r = oo;
	while (r>=l){
		__uint128_t mid = (l+r)/2;
		bool ok = 0;
		for (int src = 1; src<=n; src++){
			vector<int>vis(n+1);
			queue<int>q;
			q.push(src);
			vis[src] = 1;
			while (q.size()){
				int v = q.front();q.pop();
				for (int u = 1; u<=n; u++){
					if (u == v) continue;
					if (mid * (__uint128_t)p[v] >= (__uint128_t)(abs(x[v]-x[u]) + abs(y[v] - y[u]))){
						if (!vis[u]){
							vis[u] = 1;
							q.push(u);
						}
						
					}
				}
			}
			int ile = 0;
			for (int i = 1; i<=n; i++) ile += vis[i];
			if (ile == n) ok = 1;
		}	
		if (ok){
			ans = mid;
			r = mid-1;
		} else l = mid+1;
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
