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
	vector<int>a(n+2);
	a[0] = oo; 
	a[n+1] = oo-1;
	for (int i = 1; i<=n; i++) cin >> a[i];

	auto calc = [&](int v){
		vector<int>tmp(n+2);
		iota(tmp.begin(), tmp.end(), 0);
		sort(tmp.begin(), tmp.end(), [&](auto x, auto y) {return a[x] < a[y];});
		vector<int>ord(n+2);
		for (int i = 0; i<(int)tmp.size(); i++) ord[tmp[i]] = i+1;
		// debug(ord);
		vector<int>L(n+2, 0), R(n+2, n);
		stack<int>s;
		s.push(0);
		for (int i = 1; i<=n; i++){
			while (!s.empty() && ord[s.top()]*v < ord[i]*v) s.pop();
			L[i] = i-s.top();
			s.push(i);
		}
		// debug(L);
		swap(ord[0], ord[n+1]);
		while (s.size()) s.pop();
		s.push(n+1);
		for (int i = n; i>=1; i--){
			while (!s.empty() && ord[s.top()]*v < ord[i]*v) s.pop();
			R[i] = s.top()-i;
			s.push(i);
		}
		// debug(R);
		int mx = 0;
		for (int i = 1; i<=n; i++){
			mx += a[i] * L[i] * R[i];
		}
		return mx;
	};
	
	int A = calc(1);
	a[0] = -a[0];
	a[n+1] = -a[n+1];
	int B = calc(-1);
	cout << A-B << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}