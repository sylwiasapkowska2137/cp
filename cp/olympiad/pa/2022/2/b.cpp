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
	int n, k; cin >> n >> k; 
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	bool bad = 1;
	for (int i = 2; i<=n; i++) bad &= (a[i] > a[i-1]);
	if (bad){
		cout << "NIE\n";
		return;
	}
	auto answer = [&](set<int>s){
		if (*s.rbegin() == n) s.erase(--(s.end()));
		if ((int)s.size() != k-1){
			for (int ck = 1; ck<=n; ck++){
				s.insert(ck);
				if ((int)s.size() == k-1) break;
			}
		}
		cout << "TAK\n";
		for (auto x: s) cout << x << " ";
		cout << "\n";
		exit(0);
	};
	if (k == 2){
		vector<int>pmax(n+1, oo), smin(n+2, -oo);
		for (int i = 1; i<=n; i++) pmax[i] = min(pmax[i-1], a[i]);
		for (int i = n; i>=1; i--) smin[i] = max(smin[i+1], a[i]);
		for (int i = 1; i<n; i++){
			if (pmax[i] > smin[i+1]){
				answer({i});
			}
		}
		cout << "NIE\n";
		return;
	}
	//od teraz k≥3
	vector<pair<int, int>>b;
	for (int i = 1; i<=n;i++) b.emplace_back(a[i], i);
	sort(b.begin(),b.end(),[](auto x, auto y){return (x.first==y.first) ? x.second < y.second : x.first > y.first;});
	debug(b);
	for (int i = 1; i<=n; i++){
		if (b[i].second > b[i-1].second){
			answer({b[i-1].second, b[i].second});
		}
	}
	cout << "NIE\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
