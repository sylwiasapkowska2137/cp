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
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;


void solve(){
	int n, m; cin >> n >> m;
	vector<T>tab(n);
	T prev; cin >> prev.first >> prev.second;
	tab[0] = prev;
	vector<T>a, b;
	for (int i = 1; i<n; i++){
		T curr; cin >> curr.first >> curr.second;
		a.emplace_back(curr.first-prev.second, i-1);
		tab[i] = curr;
		prev = curr;
	}
	for (int i = 0; i<m; i++) {
		int x; cin >> x;
		b.emplace_back(x, i);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	// debug(a);
	// debug(b);
	// debug(tab);
	int ptr = 0;
	vector<int>ans(n);
	for (auto [len, idx]: a){
		while (ptr < m && b[ptr].first < len){
			ptr++;
		}
		if (ptr == m){
			cout << "Nie\n";
			return;
		}
		ans[idx] = b[ptr].second;
		if (b[ptr].first > tab[idx+1].second - tab[idx].first){
			cout << "Nie\n";
			return;
		}
		ptr++;
	}
	cout << "Tak\n";
	for (int i = 0; i<n-1; i++) cout << ans[i]+1 << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
