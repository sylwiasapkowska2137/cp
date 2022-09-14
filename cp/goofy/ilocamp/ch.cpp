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

const int rotateDelta[] = {3, 0, 0, 1};
 
long long gilbertOrder(int x, int y, int pow, int rotate) {
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
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow), nrot = (rotate + rotateDelta[seg]) & 3;
	long long subSquareSize = (1ll) << (2*pow - 2), ans = seg * subSquareSize;
	long long add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct query{
	int L, R, i;
	LL ord;
	void order() {
        ord = gilbertOrder(L, R, 21, 0);
    }
};

bool cmp(query a, query b){
	return a.ord < b.ord;
}

vi a;
int cnt[6];

void pop(int x){
	cnt[a[x]]--;
}

void push(int x){
	cnt[a[x]]++;
}

int get(){
	rep(i, 1, 6) if (cnt[i]) return i;
	return 5;
}

void solve(){
	int n, q; cin >> n >> q;
	a.resize(n+1);
	rep(i, 1, n+1) cin >> a[i];
	vector<query>Q(q);
	rep(i, 0, q){
		cin >> Q[i].L >> Q[i].R;
		Q[i].i = i;
		Q[i].order();
	}
	sort(all(Q), cmp);
	vi ans(q);
	int L = 0, R = 0;
	for (auto x: Q){
		//debug(x.L);
		//debug(x.R);
		while(R < x.R) {
			R++;
			cnt[a[R]]++;
		}
		while(L > x.L) {
			cnt[a[L]]--;
			L--;
		}
		while(R > x.R) {
			cnt[a[R]]--;
			R--;
		}
		while(L < x.L) {
			L++;
			cnt[a[L]]++;
		}
		ans[x.i] = get();
		//debug(ans[x.i]);
		//cerr << "\n";
	}
	rep(i, 0, q) cout << ans[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
		int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
