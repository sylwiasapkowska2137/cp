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
const int oo = 1e18, K = 30;

struct max_queue{
	deque<pair<int, int>>q;

	void add(int v, int idx){
		while (!q.empty() && q.back().first <= v){
			q.pop_back();
		}	
		q.push_back({v, idx});
	}

	int max(){
		return (q.empty() ? 0: q.front().first);
	}

	void remove(int idx){
		while (!q.empty() && q.front().second <= idx){
			q.pop_front();
		}
	}
};


void solve(){
	int n, p, d; cin >> n >> p >> d;
	vector<int>a(n+1), pref(n+1), s(n+1);
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		pref[i] = pref[i-1]+a[i];
	}
	for (int i = d; i<=n; i++){
		s[i] = pref[i]-pref[i-d];
	}
	// debug(s);
	int R = d;
	max_queue q;
	q.add(s[d], d);
	int ans = d;
	for (int L = 1; L<=n-d+1; L++){
		R = max(R, L+d-1);
		q.add(s[R], R);
		while (R+1 <= n && pref[R+1]-pref[L-1]-max(q.max(), s[R+1]) <= p){
			R++;
			q.add(s[R], R);
		}
		if (pref[R]-pref[L-1]-q.max() <= p){
			// debug(L, R);
			ans = max(ans, R-L+1);
		}
		q.remove(L+d-1);
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
