//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;

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

typedef pair<int, int> T;
typedef tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int oo = 1e9+7;

void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n+1), m(n+2, oo), nxt(n+1, oo);;
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		a[i] = min(a[i], n+1);
	}
	for (int i = n; i>=1; i--){
		nxt[i] = m[a[i]];
		m[a[i]] = i;
	}
	ordered_set s;
	vector<vector<T>>que(n+1);
	for (int i = 0; i<q; i++){
		int l, r; cin >> l >> r;
		que[l].emplace_back(r, i);
	}
	m.assign(n+2, 0);
	vector<int>curr(n+2, oo);
	for (int i = 1; i<=n; i++){
		m[a[i]]++;
		if (m[a[i]] == a[i]) {
			s.insert({i, a[i]});
			curr[a[i]] = i;
		}
	}
	vector<int>ans(q);
	for (int l = 1; l<=n; l++){
		for (auto [r, idx]: que[l]) ans[idx] = s.order_of_key(T{r, oo});
		if (curr[a[l]] == oo) continue;
		s.erase({curr[a[l]], a[l]});
		curr[a[l]] = nxt[curr[a[l]]];
		s.insert({curr[a[l]], a[l]});
	}
	for (int i = 0; i<q; i++) cout << ans[i] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
