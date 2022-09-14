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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p(int a, int b){
	return a+rng()%(b-a+1);
}


LL p(LL a, LL b){
	return a+rng()%(b-a+1);
}

void solve(){
	int n = p(100, 200);
	int m = p(n-1, n*(n-1)/2);
	int k = p(1, n-1);
	set<pair<int, int>>s;
	cout << n << " " << m << " " << k << "\n";
	for (int i = 2;i<=n; i++){
		//cout << i << " " << p(1, i-1) << "\n";// << " " << p(999, 1000) << " " << p(0, 1) << "\n";
		int b = p(1, i-1);
		cout << i << " " << b << "\n";
		s.insert({b, i});
	} 
	for (int i = n-1; i<m; i++){
		int a = p(1, n);
		int b = p(1, n);
		while (1){
			while (a == b) b = p(1, n);
			if (a > b) swap(a, b);
			if (s.find({a, b}) == s.end()) break;
			a = p(1, n);
			b = p(1, n);
		}
		cout << a << " " << b << "\n";// << p(999, 1000) << " " << p(0, 1) << "\n";
		s.insert({a, b});
	}
	while (k--){
		LL x = p(0LL, (1LL<<n)-1);
		vector<int>tab;
		for (int i = 0; i<n; i++){
			if (x&(1LL<<i)){
				tab.push_back(i);
			}
		}
		random_shuffle(tab.begin(), tab.end());
		cout << (int)tab.size() << " ";
		for (auto x: tab) cout << x+1 << " ";
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
