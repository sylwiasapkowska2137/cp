//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
	int n, q; cin >> n >> q;
	vector<int>a(n);
	set<int>s;
	multiset<int> d;
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	sort(a.begin(), a.end());
	for (int i = 1; i<n;i++) d.insert(a[i]-a[i-1]);
	if (d.empty()) cout << "0\n";
	else cout << *s.rbegin()-*s.begin()-(*d.rbegin()) << "\n";

	while (q--){
		int t, x; cin >> t >> x;
		if (t){
			s.insert(x);
			auto it = s.lower_bound(x);
			int l = -1, r = -1;
			if (it != s.begin()){
				auto it2 = it; it2--;
				d.insert(x-*it2);
				l = *it2;
			} 
			if (next(it) != s.end()){
				auto it2 = it; it2++;
				d.insert(*it2-x);
				r = *it2;
			}
			if (l != -1 && r != -1) d.erase(d.find(r-l));
		} else {
			auto it = s.lower_bound(x);
			int l = -1, r = -1;
			if (it != s.begin()){
				auto it2 = it; it2--;
				l = *it2;
				d.erase(d.find(x-*it2));
			} 
			if (next(it) != s.end()){
				auto it2 = it; it2++;
				r = *it2;
				d.erase(d.find(*it2-x));
			}
			s.erase(x);
			if (l != -1 && r != -1)	d.insert(r-l);
		}
		//debug(s, d);
		if (d.empty()) cout << "0\n";
		else cout << *s.rbegin()-*s.begin()-(*d.rbegin()) << "\n";
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