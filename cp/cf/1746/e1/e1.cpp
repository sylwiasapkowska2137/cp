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

bool check(int mid){
	vector<int>a(mid);
	iota(a.begin(), a.end(), 1);
	int prev = -1;
	while (1){
		cout << "? " << mid << " ";
		for (auto x: a) cout << x << " ";
		cout << "\n"; cout.flush();
		string s; cin >> s;
		int curr = 1;
		if (s == "YES") curr = 1;
		else curr = 0;
		if (curr == prev) return curr;
		prev = curr;
	}
	assert(false);
}

void solve(){
	int n; cin >> n;
	int l = 1, r = n;
	while (r > l){
		int mid = (l+r)/2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid+1;
		}
	}
	cout << "! " << l << "\n";
	cout.flush();
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}