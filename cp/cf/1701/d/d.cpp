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
	vector<int>b(n+1);
	vector<pair<int, int>>ev;
	for (int i = 0; i<n; i++) {
		cin >> b[i];
		int L = (i+1)/(b[i]+1)+1;
		ev.emplace_back(L, i);
	}
	int j = 0;
	set<pair<int, int>>s;
	sort(ev.begin(), ev.end());
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++){
		while (j < n && ev[j].first == i){
			int id = ev[j++].second;
			s.insert({b[id] ? (id+1)/b[id] : n, id});
		}
		// debug(s);
		a[s.begin()->second] = i;
		s.erase(s.begin());
	}
	for (int i = 0; i<n; i++) cout << a[i] << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}