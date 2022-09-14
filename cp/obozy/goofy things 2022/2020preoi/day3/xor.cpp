/*
ฅ^•ﻌ•^ฅ
*/

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

void solve(){
	int n; cin >> n;
	vector<LL>base, a(n);
	LL k = 0;
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		k^=a[i];
	}
	
	if (k == 0){
		cout << "0\n";
		return;
	}

	for (auto &x: a){
		x &= k;
		for (auto i: base){
			x = min(x, x^i);
		}
		if (x) base.push_back(x);
	}
	sort(base.begin(), base.end());
	reverse(base.begin(), base.end());
	//debug(base, k);
	LL ans = 0; int p = 0;
	for (int i = 0; i<(int)base.size(); i++){
		if ((int)__lg(base[i]) == (int)__lg(k)){
			p = i+1;
			ans = base[i];
			break;
		}
	}
	for (int i = p; i<(int)base.size(); i++){
		ans = min(ans, ans^base[i]);
	}
	cout << abs(ans-(ans^k)) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
