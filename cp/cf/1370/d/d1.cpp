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
	int n, k; cin >> n >> k;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	vector<int>b = a;
	sort(b.begin(), b.end());
	
	auto check = [&](int mid, int f){
		int ans = 0;
		for (int i = 0; i<n; i++){
			if (!f){
				ans++;
				f ^= 1;
			} else {
				if (a[i] <= mid){
					ans++;
					f ^= 1;
				}
			}
		}
		return ans >= k;
	};

	int l = 0, r = n-1, ans = 0;
	while (r >= l){
		int mid = (l+r)/2;
		if (check(b[mid], 0) || check(b[mid], 1)){
			ans = mid;
			r = mid-1;
		} else l = mid+1;
	}
	cout << b[ans] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}