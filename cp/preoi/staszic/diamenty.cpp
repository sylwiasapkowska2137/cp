//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

bool check(long double m, int n, vector<long double>&v, vector<long double>&w, int&k){
	vector<long double>curr;
	for (int i = 0; i<n; i++){
		curr.push_back(v[i]-m*w[i]);
	}
	sort(curr.begin(), curr.end());
	reverse(curr.begin(), curr.end());
	long double S = 0;
	for (int i = 0; i<k; i++){
		S += curr[i];
	}
	return (S>=0);
}

void solve(){
	int n, k; cin >> n >> k;
	vector<long double>v(n), w(n);
	for (int i = 0; i<n; i++){
		cin >> v[i] >> w[i];
	}
	long double EPS = 1e-10;
	long double L = 0, R = 1e8;
	cerr << setprecision(10) << fixed;
	while (R-L>EPS){
		long double m = (L+R)/2.0;
		//debug(m);
		if (check(m, n, v, w, k)){
			L = m;
		} else R = m;
	}
	vector<pair<long double, int>>ans;
	for (int i = 0; i<n; i++){
		ans.push_back({v[i]-L*w[i], i+1});
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	for (int i = 0; i<k; i++){
		cout << ans[i].second << " ";
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
