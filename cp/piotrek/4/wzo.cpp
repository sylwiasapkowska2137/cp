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

void solve(){
	int n; cin >> n;
	vector<int>a(n), b(n);
	for (int i = 0; i<n; i++){
		cin >> a[i] >> b[i];
	}
	while (1){
		bool any = 0;
		for (int i = 0; i<n; i++){
			if (a[i] > b[i]){
				int t = (a[i] - b[i] + 1)/2;
				// debug(a[i], b[i], t);
				if (a[i] - 2 * t < 0) t--;
				a[i] -= 2*t;
				a[(i+1)%n] += t;
				if (t) any = 1;
			}
		}
		if (!any) break;
	}
	bool ok = 1;
	for (int i = 0; i<n; i++){
		ok &= (a[i] == b[i]);
	}
	if (ok) cout << "TAK\n";
	else cout << "NIE\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}