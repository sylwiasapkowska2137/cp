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

void solve(){
	int q; cin >> q;
	vector<int>cnt(q+3, -1), parent(q+3);
	parent[1] = 1; 
	int which = 2;
	int curr = 1;
	map<int, int>idx;
	while (q--){
		string s; cin >> s;
		if (s == "ADD"){
			int x; cin >> x;
			parent[which] = curr;
			curr = which;
			cnt[curr] = x;
			which++;
		}
		if (s == "DELETE"){
			curr = parent[curr];
		}
		if (s == "SAVE"){
			int x; cin >> x;
			idx[x] = curr;
		}
		if (s == "LOAD"){
			int x; cin >> x;
			// debug(x, idx[x]);
			curr = idx[x];
		}
		// debug(curr);
		cout << cnt[curr] << " ";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
