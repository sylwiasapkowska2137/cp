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
const int oo = 1e18, K = 30;

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if ((a[0]-n)%2 == 0){
		cout << "B\n";
		return;
	} 
	if (n == 1){
		cout << "A\n";
		return;
	}
	int x = 0;
	for (int i = 0; i<n-2; i++){
		debug(i);
		x = (x+a[i])%2;
	}
	a[n-2]-=x;
	a[n-1]-=x;
	debug(x, a[n-2], a[n-1]);
	if (a[n-2]%2 == 1){
		cout << "A\n";
	} else if (a[n-2]%4 == 0){
		if (a[n-1] > a[n-2] && a[n-1]%2 == 0){
			cout << "A\n";
		} else {
			cout << "B\n";
		}
	} else if (a[n-2]%4 == 2){
		if (a[n-1] == a[n-2] || (a[n-1]-a[n-2])%2 == 0){
			cout << "A\n";
		} else {
			cout << "B\n";
		}
	} else {
		cout << "B\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
