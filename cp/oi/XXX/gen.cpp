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

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int p(int a, int b){
	return a+rng()%(b-a+1);
}

void solve(){
	int n = p(3, 100);
	int k = p(1, n-1);
	// int k = p(500, n-1);
	cout << n << " " << k << "\n";
	for (int i = 2; i<=n; i++){
		cout << p(1, i-1) << " " << i << " " << p(1, 5) << "\n";
	}
	set<int>s;
	while (s.size() < k){
		s.insert(p(2, n));
	}
	vector<int>a;
	for (auto x: s) a.emplace_back(x);
	shuffle(a.begin(), a.end(), rng);
	for (auto x: a) cout << x << "\n";
}

int n;

bool check(int i, int bal){
	return min(i,n-i)>=bal&&bal>=0;
}

void solve2(){
	n = p(1e5, 5e5)*2;
	int h = n/2;
	int k = p(1, h);
	
	cout << n << " " << k << "\n";
	int bal = 0;
	string s;
	for (int i = 0; i<n; i++){
		bool open = check(i+1, bal+1);
		bool close = check(i+1, bal-1);
		if (open && close){
			if (p(0, 1)){
				s += '(';
				bal++;
			} else {
				s += ')';
				bal--;
			}
		} else if (open){
			s += '(';
			bal++;
		} else {
			s += ')';
			bal--;
		}
	}
	cout << s << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
