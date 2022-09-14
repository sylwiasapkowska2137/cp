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

struct segtree{
	vector<vector<int>>tab;
	int size = 1;

	segtree(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.resize(2*size);
		for (int i = 0; i<(int)a.size(); i++) tab[i+size].emplace_back(a[i]);
		for (int i = size-1; i>=1; i--) {
			tab[i].resize((int)tab[2*i].size()+(int)tab[2*i+1].size());
			merge(tab[2*i].begin(), tab[2*i].end(), tab[2*i+1].begin(), tab[2*i+1].end(), tab[i].begin());
		}
	}

	int query(int x, int lx, int rx, int l, int r, int v){
		if (lx > r || rx < l) return 0;
		if (lx >= l && rx <= r){
			if (tab[x].back() <= v) return (int)tab[x].size();
			if (tab[x][0] > v) return 0;
			int curr = (int)(upper_bound(tab[x].begin(), tab[x].end(), v)-tab[x].begin());
			if (curr < (int)tab[x].size()) return curr;
			return 0;
		}
		int m = (lx+rx)/2;
		return query(2*x, lx, m, l, r, v)+query(2*x+1, m+1, rx, l, r, v);
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<string>tab, rev;
	for (int i = 0; i<n; i++){
		string s; cin >> s;
		tab.emplace_back(s);
		reverse(s.begin(), s.end());
		rev.emplace_back(s);
	}
	sort(tab.begin(), tab.end());
	sort(rev.begin(), rev.end());
	vector<int>idx(n);
	for (int i = 0; i<n; i++){
		string s = tab[i];
		reverse(s.begin(), s.end());
		idx[i] = (int)(lower_bound(rev.begin(), rev.end(), s)-rev.begin());
	}
	// debug(idx);
	segtree seg(n+1, idx);
	while (q--){
		string pref, suf; cin >> pref >> suf;
		int l = (int)(lower_bound(tab.begin(), tab.end(), pref)-tab.begin());
		pref += (char)('z'+1);
		int r = (int)(lower_bound(tab.begin(), tab.end(), pref)-tab.begin())-1;
		reverse(suf.begin(), suf.end());
		int L = (int)(lower_bound(rev.begin(), rev.end(), suf)-rev.begin());
		suf += (char)('z'+1);
		int R = (int)(lower_bound(rev.begin(), rev.end(), suf)-rev.begin())-1;
		// debug(l, r, L, R);
		cout << seg.query(1, 0, seg.size-1, l, r, R)-seg.query(1, 0, seg.size-1, l, r, L-1) << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
