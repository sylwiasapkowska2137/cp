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
const int sq = 1000;

struct T{
	int l, r, i;
	void read(int _i){cin >> l >> r; i = _i;}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n+1);
	vector<int>s = {0};
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		s.emplace_back(a[i]);
	}
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	for (int i = 1; i<=n; i++) a[i] = (int)(lower_bound(s.begin(), s.end(), a[i])-s.begin());
	vector<T>Q(q);
	for (int i = 0; i<q; i++) Q[i].read(i);
	sort(Q.begin(), Q.end(), [&](auto x, auto y){
		return (x.l/sq == y.l/sq) ? x.r < y.r : x.l/sq < y.l/sq;
	});
	int L = 0, R = 0;
	vector<int>ans(q);
	int curr_ans = 0;
	vector<int>cnt(n+1);
	auto add = [&](int x){
		if (!x) return;
		curr_ans -= (cnt[x]+1)/2;
		cnt[x]++;
		curr_ans += (cnt[x]+1)/2;
	};
	auto remove = [&](int x){
		if (!x) return;
		curr_ans -= (cnt[x]+1)/2;
		cnt[x]--;
		curr_ans += (cnt[x]+1)/2;
	};
	for (auto [l, r, idx]: Q){
		while (R < r){
			R++;
			add(a[R]);
		}
		while (R > r){
			remove(a[R]);
			R--;
		}
		while (L < l){
			remove(a[L]);
			L++;
		}
		while (L > l){
			L--;
			add(a[L]);
		}
		ans[idx] = curr_ans;
	}
	for (int i = 0; i<q; i++) cout << ans[i] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
