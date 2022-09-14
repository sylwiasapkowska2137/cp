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
	int n; cin >> n;
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<int>ord;

	function<void(int, int)>dfs = [&](int v, int pa){
		ord.emplace_back(v);
		for (auto x: g[v]){
			if (x == pa) continue;
			dfs(x, v);
			ord.emplace_back(v);
		}
	};
	dfs(1, 1);
	debug(ord);

	auto query = [&](int l, int r){
		vector<int>curr;
		for (int i = l; i<=r; i++) curr.emplace_back(ord[i]);
		sort(curr.begin(), curr.end());
		curr.erase(unique(curr.begin(), curr.end()), curr.end());
		cout << "? " << curr.size() << " ";
		for (auto x: curr) cout << x << " ";
		cout << "\n";
		cout.flush();
		int x; cin >> x;
		return x;
	};

	auto answer = [&](int a, int b){
		cout << "! " << a << " " << b << "\n";
		cout.flush();
		exit(0);
	};
	
	int l = 0, r = (int)ord.size()-1;
	int what = query(l, r);
	while (r-l>1){
		int mid = (l+r)/2;
		if (query(l, mid) == what){
			r = mid;
		} else {
			l = mid;
		}
	}
	answer(ord[l], ord[l+1]);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}