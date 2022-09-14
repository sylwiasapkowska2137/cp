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
	int n, m, t, st, l; cin >> n >> m >> t >> st >> l;
	vector<int>a(m);
	for (int i = 0; i<m; i++) cin >> a[i];
	sort(a.begin(), a.end());
	//debug(a);
	multiset<pair<int, int>>s;
	for (int i = 0; i<n; i++) s.insert({0, 0});
	deque<int>q; //czas w ktorym konczy sie blokada jakiegos pasa
	int ans = 0;
	for (int i = 0; i<m; i++){
		while (!q.empty() && q.front() <= a[i]){
			s.insert({q.front()%st, q.front()});
			q.pop_front();
		}
		if (s.empty()){
			cout << "NIE\n";
			return;
		}
		//debug(s);
		auto it = s.upper_bound({a[i]%st, -1});
		if (it == s.end()) it = prev(it);
		else if (it->first > a[i]%st){
			if (it == s.begin()) it = prev(s.end());
			else it--;
		}
		//debug(it->first, it->second, a[i]);
		s.erase(it);
		q.push_back(a[i]+l);
		ans += (a[i]-it->second)/st;
	}
	while (!q.empty() && q.front() <= t){
		s.insert({q.front()%st, q.front()});
		q.pop_front();
	}
	for (auto x: s) ans += (t-x.second)/st;
	//debug(s);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
