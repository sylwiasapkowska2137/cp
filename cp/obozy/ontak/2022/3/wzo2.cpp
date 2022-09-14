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
const int oo = 2e9+7, K = 30;

struct edge{
	int a, b, c;
	edge(int _a = 0, int _b = 0, int _c = 0){
		a = _a;
		b = _b;
		c = _c;
	}
};
vector<edge>e[2];
int n;

int f(int mid){
	vector<vector<int>>g(n+1);
	for (auto [a, b, c]:e[0]){
		if (c <= mid){
			g[a].emplace_back(b);
			g[b].emplace_back(a);
		}
	}
	int nr;
	vector<int>numer(n+1, -1);

	function<void(int)>dfs = [&](int v){
		numer[v] = nr;
		for (auto x: g[v]){
			if (numer[x] == -1){
				dfs(x);
			}
		}
	};

	for (int i = 1; i<=n; i++){
		if (numer[i] == -1){
			nr++;
			dfs(i);
		}
	}

	int L = 1, R = 1e9+7;
	int ans = oo;
	while (R>=L){
		int m = (L+R)/2;
		vector<vector<int>>G(n+1);
		for (auto [a, b, c]:e[1]){
			if (c <= m){
				G[a].emplace_back(b);
				G[b].emplace_back(a);
			}
		}
		vector<bool>vis(n+1);
		vector<int>curr;
		function<void(int)>dfs2 = [&](int v){
			curr.emplace_back(numer[v]);
			vis[v] = 1;
			for (auto x:G[v]){
				if (!vis[x]){
					dfs2(x);
				}
			}
		};
		bool ok = 0;
		for (int i = 1; i<=n; i++){
			if (!vis[i]){
				dfs2(i);
				sort(curr.begin(), curr.end());
				for (int j = 1; j<(int)curr.size(); j++) {
					if (curr[j] == curr[j-1]){
						ok = 1;
						break;
					}
				}
				curr.clear();
			}
		}
		if (ok){
			ans = m;
			R = m-1;
		} else L = m+1;
	}
	return mid+ans;
}

void solve(){
	int m;cin >> n >> m;
	for (int i = 0; i<m; i++){
		int a, b, w, c; cin >> a >> b >> w >> c;
		e[c].emplace_back(a, b, w);
	}
	
	int l = 1, r = oo;
    while (r-l>=3) {
		// debug(l, r);
        int m1 = l+(r-l)/3;
        int m2 = r-(r-l)/3;
        int f1 = f(m1);    
        int f2 = f(m2); 
		// debug(m1, f1);
		// debug(m2, f2);
        if (f1 > f2) l = m1;
        else r = m2;
    }
	// debug(l, r);
    int ans = min({f(l), f(l+1), f(l+2), f(l+3)});
	if (ans >= oo) cout << "-1\n";
	else cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
