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
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
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


const int S = 720, MAX = 3e5+1;
int cnt[MAX], ans = 0;
bool zero = 0;
vi a;

inline LL gilbertOrder(int x, int y, int pow, int rotate) {
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
	LL subSquareSize = LL(1) << (2*pow - 2);
	LL ans = seg * subSquareSize;
	LL add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct q{
	int l, r, i;
	LL ord;
	inline void calcOrder() {
		ord = gilbertOrder(l, r, 21, 0);
	}
};

inline bool operator<(const q &a, const q &b) {
	return a.ord < b.ord;
}

inline int count(int num){
	return (num/2 + num%2);
}

void push(int i){
	if (a[i] == 0 && zero) return;
	ans -= count(cnt[a[i]]);
	cnt[a[i]]++;
	ans += count(cnt[a[i]]);
}

void pop(int i){
	if (a[i] == 0 && zero) return;
	ans -= count(cnt[a[i]]);
	cnt[a[i]]--;
	ans += count(cnt[a[i]]);
}

void solve(){
	int n, m; cin >> n >> m;
	vi scaler, res(m);
	a.resize(n+2);
	map<int, int>mapa;
	rep(i, 1, n+1) {
		cin >> a[i];
		scaler.pb(a[i]);
		zero |= (a[i]==0);
	}
	sort(all(scaler));
	scaler.erase(unique(all(scaler)), scaler.end());
	rep(i, 0, sz(scaler)) mapa[scaler[i]] = i;
	rep(i, 1, n+1) a[i] = mapa[a[i]];
	vector<q>query(m);
	rep(i, 0, m){
		cin >> query[i].l >> query[i].r;
		query[i].r++;
		query[i].i = i;
		query[i].calcOrder();
	}
	sort(all(query));
	int L = 0, R = 0;
	for (auto x: query){
		while(R < x.r) push(R++);
		while(L > x.l) push(--L);
		while(R > x.r) pop(--R);
		while(L < x.l) pop(L++);
		res[x.i] = ans;
	}
	rep(i, 0, m) cout << res[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
