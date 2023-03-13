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
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

struct event{
	int l, r, i;
	void assign(T a, T b, int _i){
		l = b.first - a.second;
		r = b.second - a.first;
		i = _i;
	}
	bool operator <(const event&he) const{
		return l == he.l ? r < he.r : l < he.l;
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vector<T>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i].first >> a[i].second;
	vector<event>b(n-1);
	for (int i = 2; i<=n; i++){
		b[i-2].assign(a[i-1], a[i], i);
	}
	sort(b.begin(), b.end());
	vector<int>ans(n+1, -1);
	set<T>s; //r,idx
	vector<T>len(m);
	for (int i = 0; i<m; i++) {
		cin >> len[i].first;
		len[i].second = i+1;
	}
	sort(len.begin(), len.end());
	int ptr = 0;
	for (auto [curr, idx]: len){
		while (ptr < (int)b.size() && b[ptr].l <= curr){
			s.insert({b[ptr].r, b[ptr].i});
			ptr++;
		}
		auto it = s.lower_bound({curr, -1});
		if (it != s.end()){
			ans[it->second] = idx;
			s.erase(it);
		}
	}
	for (int i = 2; i<=n; i++){
		if (ans[i] == -1){
			cout << "Nie\n";
			return;
		}
	}
	cout << "Tak\n";
	for (int i = 2; i<=n; i++) cout << ans[i] << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
