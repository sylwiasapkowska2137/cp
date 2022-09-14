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
	int m, d, n; cin >> m >> d >> n;
	int l = m-d;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int x = (int)(lower_bound(a.begin(), a.end(), l)-a.begin());
	if (x >= (int)a.size()){
		cout << "0\n";
		return;
	}
	int end = d-(a[x]-m+d)/2;
	if (end <= 0){
		cout << "1\n";
		return;
	}
	int ans = 1, y = n;
	for (int i = n-1; i>=0; i--){
		if (i == x) continue;
		if (a[i] <= d){
			cout << "0\n";
			return;
		}
		l = a[i]-d;
		y = i;
		ans++;
		break;
	}
	int ptr = n-1;
	while (l < end){
		if (ptr < 0){
			cout << "0\n";
			return;
		}
		if (ptr == x || ptr == y){
			ptr--;
			continue;
		}
		l += a[ptr]-d+l;
		ptr--;
		ans++;
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
