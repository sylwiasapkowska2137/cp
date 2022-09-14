//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<LD> vld;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x) memset(x, 0, sizeof(x))
#define debug(x) cerr << x << " "
#define PI 3.14159265359

const LL POT = 2137, MOD = 1e9+7, MAX = 5e5+7;

//https://codeforces.com/blog/entry/61203
inline LL hilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	LL subSquareSize = (1LL) << (2*pow - 2);
	LL ans = seg * subSquareSize;
	LL add = hilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

map<int, int>cnt, mapa;
LL HASH = 0;
LL powers[MAX];
vi a, scaler;

void add(int x){
	int v = a[x];
	cnt[v]++;
	if (cnt[v] == 1) HASH = (HASH+powers[mapa[v]]+MOD)%MOD;
}

void remove(int x){
	int v = a[x];
	cnt[v]--;
	if (cnt[v] == 0) HASH = (HASH-powers[mapa[v]]+MOD)%MOD;
}

struct Query{
	int l, r, idx;
	LL hash = 0, ord;
	Query() {}
	Query(int l, int r, int idx, LL hash): l(l), r(r), idx(idx), hash(hash) {}
	
	inline void order(){
		ord = hilbertOrder(l, r, 21, 0);
	}
};

bool cmp(Query a, Query b){
	return a.ord < b.ord;
}

void fastscan(int &number){
	bool negative = false;
	register int c;
	number = 0;
	c = getchar();
	if (c=='-'){
		negative = true;
		c = getchar();
	}
	for (; (c>47 && c<58); c=getchar())
		number = number *10 + c - 48;
	if (negative) number *= -1;
}

void solve(){
	int n, q; 
	fastscan(n);
	fastscan(q);
	
	a.resize(n+1);
	rep(i, 1, n+1) {
		fastscan(a[i]);
		scaler.pb(a[i]);
	}
	sort(all(scaler));
	scaler.erase(unique(all(scaler)), scaler.end());
	rep(i, 0, sz(scaler)) mapa[scaler[i]] = i+1;
	
	powers[0] = 1LL;
	rep(i, 1, sz(scaler)+3)	powers[i] = (powers[i-1]*POT)%MOD;
	
	vector<Query>Q;
	rep(i, 0, 2*q){
		int l, r;
		fastscan(l);
		fastscan(r);
		Q.pb({l, r, i, 0LL});
		Q.back().order();
	}
	sort(all(Q), cmp);
	int L = 0, R = 0;
	vll ans(2*q);
	for (auto [lx, rx, idx, hash, ord]: Q){
		while (L < lx){
			remove(L);
			L++;
		}
		while (L > lx){
			L--;
			add(L);
		}
		while (R > rx){
			remove(R);
			R--;
		}
		while (R < rx){
			R++;
			add(R);
		}
		ans[idx] = HASH;
	}
	for (int i = 0; i<sz(ans); i+=2){
		if (ans[i] == ans[i+1]) cout << "TAK\n";
		else cout << "NIE\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
