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
	int a, b; cin >> a >> b;
	vector<int>A(n);
	for (int i = 0; i<n; i++) cin >> A[i];
	sort(A.begin(), A.end());

	auto check = [&](int mid){
		int X = 0, Y = 0;
		for (int i = 0; i<n; i++){
			if (A[i] < mid){
				int l = 1, r = 1e9;
				int ans = r;
				while (r>=l){
					int m = (l+r)/2;
					if (A[i] + m * a >= mid){
						ans = m;
						r = m-1;
					} else l = m+1;
				}
				X += ans;
			} 
			if (A[i] > mid){
				int l = 1, r = 1e9;
				int ans = 0;
				while (r>=l){
					int m = (l+r)/2;
					if (A[i] - m * b >= mid){
						ans = m;
						l = m+1;
					} else r = m-1;
				}
				Y += ans;
			}
		}
		// debug(X, Y);
		return (X<=Y);
	};

	// check(3);
	// return;
	int l = 1, r = 1e9+7;
	int ans = oo;
	while (r>=l){
		int mid = (l+r)/2;
		if (check(mid)){
			ans = mid;
			l = mid+1;
		} else {
			r = mid-1;
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
