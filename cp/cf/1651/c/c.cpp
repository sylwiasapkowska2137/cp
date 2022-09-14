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
	int n; cin >> n;
	vector<int>a(n), b(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	for (int i = 0; i<n; i++) cin >> b[i];
	int ans = abs(a[0]-b[n-1])+abs(a[n-1]-b[0]);
	ans = min(ans, abs(a[0]-b[0])+abs(a[n-1]-b[n-1]));
	multiset<int>A, B;

	auto closestA = [&](int x){
		auto it = A.lower_bound(x);
		int curr = oo;
		if (it != A.end()){
			curr = min(curr, abs(*it-x));
		} 
		if (it != A.begin()){
			it--;
			curr = min(curr, abs(*it-x));
		}
		return curr;
	};

	auto closestB = [&](int x){
		auto it = B.lower_bound(x);
		int curr = oo;
		if (it != B.end()){
			curr = min(curr, abs(*it-x));
		} 
		if (it != B.begin()){
			it--;
			curr = min(curr, abs(*it-x));
		}
		return curr;
	};
	for (int i = 1; i<n; i++) B.insert(b[i]);
	for (int i = 0; i<n-1; i++) A.insert(a[i]);
	ans = min(ans, abs(b[0]-a[n-1]) + closestB(a[0]) + closestA(b[n-1]));
	A.erase(A.find(a[0]));
	A.insert(a[n-1]);
	B.erase(B.find(b[n-1]));
	B.insert(b[0]);
	ans = min(ans, abs(b[n-1]-a[0]) + closestB(a[n-1]) + closestA(b[0]));
	A.erase(A.find(a[n-1]));
	B.erase(B.find(b[0]));
	ans = min(ans, closestA(b[0])+closestA(b[n-1])+closestB(a[0])+closestB(a[n-1]));
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