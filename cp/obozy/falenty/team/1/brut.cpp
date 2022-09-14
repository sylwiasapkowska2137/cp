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

int change(int x, int A, int B){
	int ans = 0;
	int p = 1;
	while (x){
		if ((x%10) == A) ans += B*p;
		else ans += (x%10)*p;
		x/=10;
		p *= 10;
	}
	return ans;
}

void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	while (q--){
		int type; cin >> type;
		if (type == 1){
			int l, r, A, B; cin >> l >> r >> A >> B;
			for (int i = l; i<=r; i++){
				a[i] = change(a[i], A, B);
			}
		} else {
			int l, r; cin >> l >> r;
			int s = 0;
			for (int i = l; i<=r; i++){
				s += a[i];
			}
			cout << s << "\n";
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
