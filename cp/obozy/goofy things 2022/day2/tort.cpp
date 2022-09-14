#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int>pii;
typedef vector<int> vi;
typedef vector<LL> vll;

#define debug(x) cerr << x << " "
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)
#define pb push_back

int k;
const int INF = 1e9+7;

struct segmin{
	vi tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, INF); 
	}
	
	void build(vi &a){
		int n = sz(a);
		rep(i, 0, n) if (a[i]>k/2) tab[i+size] = a[i];
		repd(i, size-1, 0) tab[i] = min(tab[2*i], tab[2*i+1]);
	}
	
	int query(int l, int r){
		int ans = INF;
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

struct segmax{
	vi tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0); 
	}
	
	void build(vi &a){
		int n = sz(a);
		rep(i, 0, n) if (a[i] <= k/2) tab[i+size] = a[i];
		repd(i, size-1, 0) tab[i] = max(tab[2*i], tab[2*i+1]);
	}
	
	int query(int l, int r){
		int ans = 0;
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
	
};

void solve(){
	int n, q; cin >> n >> q >> k;
	vi a(n), pref(n+1, 0);
	rep(i, 0, n) {
		cin >> a[i];
		pref[i+1] = pref[i];
		if (a[i] <= k/2) pref[i+1]++;
	}
	segmin mini;
	mini.init(n+1);
	mini.build(a);
	segmax maxi;
	maxi.init(n+1);
	maxi.build(a);
	while (q--){
		int x, y; cin >> x >> y;
		/*
		if (x == y){ 
			x--;
			if (a[x] <= k) cout << "0\n";
			else cout << "1\n";
			continue;
		}
		*/
		int ans = (y-x+1)-(pref[y]-pref[x-1]);
		--x;--y;
		if (maxi.query(x, y)+mini.query(x, y) <= k) ans--;
		cout << ans << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
