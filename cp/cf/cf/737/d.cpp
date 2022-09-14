#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)

const int MAX = 3e5+7, INF = -1e9+7;
vector<pii>row[MAX];

struct segtree{
	vector<int>tab;
	vector<int>lazy;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		lazy.assign(2*size+1, INF);
		tab.assign(2*size+1, 0);
	}
	
	
	void push(int x, int lx, int rx){
		if (lx == rx) return;
		if (lazy[x] == INF) return;
		tab[2*x] = max(tab[2*x], lazy[x]);
		tab[2*x+1] = max(tab[2*x+1], lazy[x]);
		lazy[2*x] = max(lazy[2*x], lazy[x]);
		lazy[2*x+1] = max(lazy[2*x+1], lazy[x]);
		lazy[x] = INF;
	}
	
	void update(int x, int lx, int rx, int l, int r, int val){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x] = max(tab[x], val);
			lazy[x] = max(lazy[x], val);
			return;
		}
		push(x, lx, rx);
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, val);
		update(2*x+1, m+1, rx, l, r, val);
		tab[x] = max(tab[2*x], tab[2*x+1]);
	}
	
	int query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return INF;
		if (lx >= l && rx <= r)return tab[x];
		push(x, lx, rx);
		int m = (lx+rx)/2;
		return max(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
	
};

struct seg2{
	vector<int>tab;
	vector<int>lazy;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		lazy.assign(2*size+1, 0);
		tab.assign(2*size+1, 0);
	}
	
	void push(int x, int lx, int rx){
		if (lx == rx) return;
		tab[2*x] += lazy[x];
		tab[2*x+1] += lazy[x];
		lazy[2*x] += lazy[x];
		lazy[2*x+1] += lazy[x];
		lazy[x] = 0;
	}
	
	void update(int x, int lx, int rx, int l, int r, int val){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x] += val;
			lazy[x] += val;
			return;
		}
		push(x, lx, rx);
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, val);
		update(2*x+1, m+1, rx, l, r, val);
		tab[x] = max(tab[2*x], tab[2*x+1]);
	}
	
	int query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return 0;
		if (lx >= l && rx <= r)return tab[x];
		push(x, lx, rx);
		int m = (lx+rx)/2;
		return max(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, R, l, r;
	cin >> n >> m;
	vector<int>scaler;
	segtree seg;
	rep(i, 0, m){
		cin >> R >> l >> r;
		row[R].pb({l, r});
		scaler.pb(l);
		scaler.pb(r);
	}
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	seg.init(scaler.size()+1);
	map<int, int>mapa;
	rep(i, 0, scaler.size()) mapa[scaler[i]] = i;
	rep(i, 1, n+1){
		for (auto &x: row[i]) {
			x.st = mapa[x.st];
			x.nd = mapa[x.nd];
		}
	}
	vector<int>dp(n+1, 0);
	rep(i, 1, n+1){
		for (auto x: row[i]) dp[i] = max(dp[i], seg.query(1, 0, seg.size-1, x.st, x.nd));
		dp[i]++;
		for (auto x: row[i]) seg.update(1, 0, seg.size-1, x.st, x.nd, dp[i]);
	}
	
	
	int ans = 0, indeks;
	rep(i, 1, n+1) ans = max(ans, dp[i]);
	
	vector<bool>intervals(n+1, 1);
	rep(i, 1, n+1){
		if (dp[i] == ans){
			indeks = i;
			intervals[indeks] = 0;
			break;
		}
	}
	
	seg2 AND;
	AND.init(scaler.size()+1);
	for (auto x: row[indeks]) AND.update(1, 0, seg.size-1, x.st, x.nd, 1);
	
	int tmp = indeks;
	repd(i, tmp, 1){
		if (dp[i] == dp[indeks]-1){
			for (auto x: row[i]){
				if (AND.query(1, 0, seg.size-1, x.st, x.nd) > 0){
					intervals[i] = 0;
					for (auto y: row[indeks]) AND.update(1, 0, seg.size-1, y.st, y.nd, -1);
					indeks = i;
					for (auto y: row[indeks]) AND.update(1, 0, seg.size-1, y.st, y.nd, 1);
					break;
				}
			}
		}
	}
	cout << n-ans << "\n";
	rep(i, 1, n+1){
		if (intervals[i]) cout << i << " ";
	}
	return 0;
}
