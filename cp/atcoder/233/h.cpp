//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
#define PI 3.14159265359

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

const int MAX = 1e5, MAXY = 2e5;

struct segtree{
	int S = MAXY+1;
	vi tab;
	
	void init(){
		tab.assign(2*S+1, 0);
	}

	void update(int pos, int val){
		pos+=S;
		tab[pos]+=val;
		while (pos>0){
			pos/=2;
			tab[pos] += val;
		}
	}

	int query(int l, int r){
		int ans = 0;
		l = l+S-1;
		r = r+S+1;
		while (r-l>1){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
			l/=2;r/=2;
		}
		return ans;
	}
} seg;

#define LSB(x) (x&(-x))

struct fenwick{
	vi a;
	int n;
	
	void init(int x){
		n = x;
		a.assign(n, 0);
	}
	
	void update(int x, int val){
		for (int i = x+1; i<=n; i+=LSB(i)){
			a[i-1]+=val;
		}
	}
	
	int sum(int x){
		int ans = 0;
		for (int i = x; i>0; i-=LSB(i)){
			ans+=a[i-1];
		}
		return ans;
	}
	
	int query(int l, int r){
		return sum(r)-sum(l);
	}
	
} fen;

void solve(){
	int n; cin >> n;
	vpii p;
	rep(i, 0, n) {
		int x, y; cin >> x >> y;
		p.emplace_back(x-y+MAX, x+y);
	}
	sort(all(p));
	int q; cin >> q;
	vi a(q), b(q), k(q), L(q, 0), R(q, MAXY);
	rep(i, 0, q){
		int x, y; cin >> x >> y >> k[i];
		a[i] = x-y+MAX;
		b[i] = x+y;
	}
	while (1){
		bool ok = 1;
		vi cnt(q, 0);
		vector<tuple<int, int, int, int, int>>queries;
		rep(i, 0, q){
			if (L[i] < R[i]){
				int mid = (L[i]+R[i])/2;
				int L = max(0, a[i]-mid);
				int R = min(MAXY, a[i]+mid);
				int D = max(0, b[i]-mid);
				int U = min(MAXY, b[i]+mid);
				queries.emplace_back(L, i, -1, D, U);
				queries.emplace_back(R + 1, i, 1, D, U);
				ok = 0;
			}
		}
		if (ok) break;
		sort(all(queries));
		fen.init(MAXY+1);
		int j = 0;
		for (auto [v, i, c, d, u]: queries){
			while (j < n && p[j].st < v){
				fen.update(p[j].nd, 1);
				j++;
			}
			cnt[i] += c*fen.query(d, u+1);
		}
		
		rep(i, 0, q){
			if (L[i] < R[i]){
				int mid = (L[i]+R[i])/2;
				if (cnt[i] >= k[i]) R[i] = mid;
				else L[i] = mid+1; 
			}
		}
	}
	rep(i, 0, q) cout << L[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
