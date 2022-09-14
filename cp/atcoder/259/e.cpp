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
const int oo = 1e18, K = 30;
const int base = 1e9+9;

void solve(){
	int n; cin >> n;
	vector<vector<pair<int, int>>>num(n);
	map<int, vector<int>>tab;
	vector<int>scaler;
	for (int i = 0; i<n; i++){
		int m; cin >> m;
		for (int j = 0; j<m; j++){
			int p, e; cin >> p >> e;
			num[i].emplace_back(p, e);
			tab[p].emplace_back(e);
			scaler.emplace_back(p);
		}
	}
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	for (auto &x: tab) sort(x.second.begin(), x.second.end());
	vector<uint64_t>p((int)scaler.size()+3);
	p[0] = 1;
	for (int i = 1; i<(int)p.size(); i++){
		p[i] = p[i-1]*base;
	}
	uint64_t H = 0;
	for (auto x: tab){
		H += p[lower_bound(scaler.begin(), scaler.end(), x.first)-scaler.begin()+1]*(uint64_t)x.second.back();
	}
	vector<uint64_t>ans;
	for (int i = 0; i<n; i++){
		uint64_t curr = H;
		for (auto [prime, e]:num[i]){
			if (tab[prime].back() == e){
				curr -= p[lower_bound(scaler.begin(), scaler.end(), prime)-scaler.begin()+1]*(uint64_t)tab[prime].back();
				if (tab[prime].size() >= 2){
					curr += p[lower_bound(scaler.begin(), scaler.end(), prime)-scaler.begin()+1]*(uint64_t)tab[prime][tab[prime].size()-2];
				}
			} 
		}
		ans.emplace_back(curr);
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << (int)ans.size() << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
