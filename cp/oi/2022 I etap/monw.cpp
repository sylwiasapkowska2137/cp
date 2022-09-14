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

const int INF = 1e9+7, size = (1<<21);
int tab[2*size+1], lazy[2*size+1];

void init(vll scaler){
	rep(i, 0, 2*size+1) tab[i] = INF;
	rep(i, 0, sz(scaler)) tab[i+size+1] = scaler[i];
	repd(i, size-1, 1) tab[i] = min(tab[2*i], tab[2*i+1]);
}

void push(int x, int lx, int rx){
	if (lx == rx) return;
	lazy[2*x]+=lazy[x];
	lazy[2*x+1]+=lazy[x];
	tab[2*x]+=lazy[x];
	tab[2*x+1]+=lazy[x];
	lazy[x] = 0;
}

void update(int x, int lx, int rx, int l, int r, int val){
	if (lx > r || rx < l) return;
	if (lx >= l && rx <= r){
		tab[x]+=val;
		lazy[x]+=val;
		return;
	}
	push(x, lx, rx);
	int m = (lx+rx)/2;
	update(2*x, lx, m, l, r, val);
	update(2*x+1, m+1, rx, l, r, val);
	tab[x] = min(tab[2*x], tab[2*x+1]);
}

int query(int x, int lx, int rx, int l, int r){
	if (lx > r || rx < l) return INF;
	if (lx >= l && rx <= r) return tab[x];
	push(x, lx, rx);
	int m = (lx+rx)/2;
	return min(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
}

bool cmp(pii a, pii b){
	if (a.nd == b.nd) return a.st < b.st;
	return a.nd < b.nd;
}

void solve(){
	int n; cin >> n;
	vpii a(n);
	vll scaler;
	rep(i, 0, n) cin >> a[i].st >> a[i].nd;
	rep(i, 0, n) scaler.pb(a[i].nd);
	sort(all(scaler));
	scaler.erase(unique(all(scaler)), scaler.end());
	map<int, int>mapa;
	rep(i, 0, sz(scaler)) mapa[scaler[i]] = i+1;
	sort(all(a), cmp);
	init(scaler);
	int out = 0;
	pq<pii>q;
	rep(i, 0, n){
		if (a[i].st > a[i].nd) continue;
		int x = query(1, 0, size-1, mapa[a[i].nd], size-1);
		/*
		debug(a[i].st);
		debug(a[i].nd);
		debug(x);
		*/
		if (x >= a[i].st){
			update(1, 1, size-1, mapa[a[i].nd], size-1, -a[i].st);
			//ans[a[i].nd-a[i].st+1]++;
			out++;
			//debug("Y");
			q.push(a[i]);
		} else {
			if (!q.empty() && q.top().st >= a[i].st){
				update(1, 1, size-1, mapa[q.top().nd], size-1, q.top().st);
				q.pop();
				update(1, 1, size-1, mapa[a[i].nd], size-1, -a[i].st);
				q.push(a[i]);
				//debug("Y2");
			}
		}
		//cerr << "\n";
	}
	cout << out << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
