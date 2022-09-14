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

struct TreeMin{
	typedef pair<int, int> T;
	vector<T>tab;
	int size = 1;

	TreeMin(int n){
		while (size < n) size*=2;
		tab.assign(2*size, {-oo, -oo});
	}
	
	void update(int x, T v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = max(tab[2*x], tab[2*x+1]);
		}
	}

	T query(int l, int r){
		T ans = {-oo, -oo};
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	vector<int>a(n+1), s;
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		s.emplace_back(a[i]);
	}
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	for (int i = 1; i<=n; i++) a[i] = (int)(lower_bound(s.begin(), s.end(), a[i])-s.begin()+1);
	vector<vector<int>>cnt(n+1);
	vector<int>ptr(n+1);
	for (int i = 1; i<=n; i++) {
		cnt[a[i]].emplace_back(i);
	}
	TreeMin t(n+1);
	for (int i = 1; i<=n; i++){
		if (cnt[i].empty()) continue;
		cnt[i].emplace_back(oo);
		t.update(cnt[i][0], {cnt[i][1], cnt[i][0]});
	}
	int q; cin >> q;
	vector<vector<pair<int, int>>>que(n+1);
	for (int i = 0; i<q; i++){
		int l, r; cin >> l >> r;
		que[l].emplace_back(r, i);
	}
	vector<int>ans(q);
	for (int l = 1; l<=n; l++){
		for (auto [r, i]:que[l]){
			pair<int, int>c = t.query(l, r);
			// debug(l, r, c);
			if (c.first > r) ans[i] = a[c.second];
		}
		ptr[a[l]]++;
		if (ptr[a[l]]+1 < (int)cnt[a[l]].size()){
			int x = cnt[a[l]][ptr[a[l]]];
			if (x == oo) continue;
			t.update(x, {cnt[a[l]][ptr[a[l]]+1], x});
		}
	}
	for (int i = 0; i<q; i++) cout << (ans[i] ? s[ans[i]-1] : 0) << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}