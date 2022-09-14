#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int>pii;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<pii> vpii;

#define debug(x) cerr << x << " "
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)
#define pb push_back

struct segtree{
	vll tab;
	int size = 1;
	
	void init(int n){
		size = 1;
		while (size < n) size*=2;
		tab.assign(2*size+1, 0LL);
	}
	
	void update(int pos, LL val){
		pos+=size;
		while (pos>0){
			tab[pos] += val;
			pos/=2;
		}
	}
	
	LL query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL ans = 0LL;
		while (r-l>1){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
			l/=2;r/=2;
		}
		return ans;
	}
};

const LL MOD = 1e9+7;

void solve(){
	int n, m; cin >> n >> m;
	vll a(n), b(m), pref(n+1);
	rep(i, 0, n) {
		cin >> a[i];
		pref[i+1] = pref[i]+a[i];
	}
	rep(i, 0, m) cin >> b[i];
	vll scaler = pref;
	segtree seg;
	sort(all(scaler));
	scaler.erase(unique(all(scaler)), scaler.end());
	map<LL, LL>mapa;
	rep(i, 0, sz(scaler)) mapa[scaler[i]] = i+1;
	LL pos = 0LL, neg = 0LL;
	LL sum = 0LL;
	seg.init(sz(scaler)+2);
	seg.update(mapa[0], 1);
	rep(i, 0, n){
		sum += a[i];
		pos += seg.query(0, mapa[sum]-1);
		neg += seg.query(mapa[sum]+1, seg.size-1);
		pos %= MOD;
		neg %= MOD;
		seg.update(mapa[sum], 1);
	}
	//debug(pos);
	//debug(neg);
	
	LL pos2 = 0, neg2 = 0;
	scaler.clear();
	mapa.clear();
	pref.assign(m+1, 0LL);
	rep(i, 0, m) pref[i+1] = pref[i]+b[i];
	scaler = pref;
	sort(all(scaler));
	scaler.erase(unique(all(scaler)), scaler.end());
	rep(i, 0, sz(scaler)) mapa[scaler[i]] = i+1;
	sum = 0LL;
	seg.init(sz(scaler)+2);
	seg.update(mapa[0], 1);
	rep(i, 0, m){
		sum += b[i];
		pos2 += seg.query(0, mapa[sum]-1);
		neg2 += seg.query(mapa[sum]+1, seg.size-1);
		pos2 %= MOD;
		neg2 %= MOD;
		seg.update(mapa[sum], 1);
	}
	//debug(pos2);
	//debug(neg2);
	//cerr << "\n";
	LL ans = (pos*pos2)%MOD;
	ans += ((neg*neg2)%MOD);
	ans %= MOD;
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
