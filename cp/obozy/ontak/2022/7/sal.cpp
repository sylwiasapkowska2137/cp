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

bool check(vector<int>a, int mid, int k){
	int n = (int)a.size();
	int med = n/2;
	k -= (mid-a[med]);
	if (k < 0) return 0;
	a[med] = mid;
	for (int i = med+1; i<n; i++){
		if (a[i] >= mid) return 1;
		if (a[i] >= a[i-1]) continue;
		k -= (a[i-1]-a[i]);
		a[i] = a[i-1];
		if (k < 0) return 0;
	}
	// debug(a);
	return 1;
}

void solve(){
	int n, kk; cin >> n >> kk;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	if (a.back() == 1){
		int f = (n+1)/2;
		cout << kk/f+1 << "\n";
		return;
	}
	int f = (n+1)/2;
	int L = a[n/2];
	
	int R = kk+L+1;
	int ans = L;
	while (R>=L){
		int mid = (L+R)/2;
		int k = kk;
		bool ok = 1;
		k -= (mid-a[n/2]);
		if (k < 0) ok = 0;
		int prev = mid;
		if (ok){
			for (int i = n/2+1; i<n; i++){
				if (a[i] >= mid) break;
				if (a[i] >= prev) {
					prev = a[i];
					continue;
				}
				k -= (prev-a[i]);
				if (k < 0) {
					ok = 0;
					break;
				}
			}
		}
		if (ok) {
			ans = mid;
			L = mid+1;
		} else {
			R = mid-1;
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
