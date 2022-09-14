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
const int oo = 1e18;

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	sort(a.begin(), a.end());

	function<bool(int, int)> check = [&](int mid, int maxi){
		int ile = mid/2;
		vector<int>b(n);
		int curr = 0;
		for (int i = 0; i<n; i++) b[i] = maxi-a[i];
		for (int i = 0; i<n; i++){
			if (b[i]&1) curr++;
			b[i]/=2;
			if (b[i] <= ile){
				ile-=b[i];
			} else {
				b[i] -= ile;
				ile = 0;
				curr += 2*b[i];
			}
		}
		return (curr <= mid-mid/2);
	};

	int ans = oo;
	for (int k = 0; k<2; k++){
		int maxi = a.back()+k;
		//chcemy miec mniej wiecej rowną liczbe operacji typu 1 i 2
		int L = 0, R = oo, curr = oo;
		while (R>=L){
			int mid = (L+R)/2;
			if (check(mid, maxi)){
				curr = mid;
				R = mid-1;
			} else L = mid+1;
		}
		ans = min(ans, curr);
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}
