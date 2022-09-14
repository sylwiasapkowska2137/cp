//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

// #define int long long
const int oo = 2e9+7, K = 30;

struct min_queue{
	deque<pair<int, int>>q;

	void clear(){while (q.size()) q.pop_back();}

	int min(){return (q.size() ? q.front().first : 0);}

	void add(int v, int idx){
		while (q.size() && q.back().first >= v) q.pop_back();
		q.push_back({v, idx});
	}

	void remove(int idx){
		while (q.size() && q.front().second <= idx) q.pop_front();
	}
};

struct max_queue{
	deque<pair<int, int>>q;

	void clear(){while (q.size()) q.pop_back();}

	int max(){return (q.size() ? q.front().first : 0);}

	void add(int v, int idx){
		while (q.size() && q.back().first <= v)	q.pop_back();
		q.push_back({v, idx});
	}
	
	void remove(int idx){
		while (q.size() && q.front().second <= idx)	q.pop_front();
	}
};

void solve(){
	int n, t; cin >> t >> n;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	max_queue smax;
	min_queue smin;
	int R = 1;
	smin.add(a[1], 1);
	smax.add(a[1], 1);
	int ans = 1;
	for (int L = 1; L<=n; L++){
		if (R < L){
			smax.clear();
			smin.clear();
			R = L;
			smax.add(a[L], L);
			smin.add(a[L], L);
		}
		while (R+1 <= n && max(smax.max(), a[R+1])-min(smin.min(), a[R+1]) <= t){
			R++;
			smax.add(a[R], R);
			smin.add(a[R], R);
			ans = max(ans, R-L+1);
		}
		// debug(L, R);
		if (smax.max()-smin.min() <= t)	ans = max(ans, R-L+1);
		smax.remove(L);
		smin.remove(L);
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
