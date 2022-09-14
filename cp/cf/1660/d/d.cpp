//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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

void solve(){
	int n; cin >> n;
	vector<int>a;
	int ans = 0, x = n, y = 0, l = 0, r;

	function<void()> check = [&](){
		//debug(a, l, r);
		if (a.empty()) return;
		int ile = 0, neg = 0;
		for (int i = 0; i<(int)a.size(); i++){
			if (abs(a[i]) == 2) ile++;
			if (a[i] < 0) neg++;
		}
		if (!(neg&1)){
			if (ile > ans){
				ans = ile;
				x = l, y = (n-r-1);
			}
			return;
		}
		//suffix
		int idx = -1;
		for (int i = (int)a.size()-1; i>=0; i--){
			if (a[i] < 0) {
				idx = i;
				break;
			}
		}
		int sub = 0;
		for (int i = idx; i<(int)a.size(); i++){
			if (abs(a[i]) == 2) sub++;
		}
		if (ile-sub > ans){
			ans = ile-sub;
			x = l, y = (n-1-r)+((int)a.size()-idx);
		}
		//prefix
		idx = -1;
		for (int i = 0; i<(int)a.size(); i++){
			if (a[i] < 0){
				idx = i;
				break;
			}
		}
		sub = 0;
		for (int i = 0; i<=idx; i++){
			if (abs(a[i]) == 2) sub++;
		}
		if (ile-sub > ans){
			ans = ile-sub;
			x = l+idx+1, y = n-r-1;
		}
	};

	for (int i = 0; i<n; i++) {
		int x; cin >> x; 
		if (x == 0){
			r = i-1;
			check();
			a.clear();
			l = i+1;
		} else a.emplace_back(x);
	}
	r = n-1;
	check();
	cout << x << " " << y << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}
