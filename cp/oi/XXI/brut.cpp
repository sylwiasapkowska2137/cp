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

const int INF = 1e9+7;

vi count(vi &c, vi &a, int x, int n, int k){
	vi next(n, INF), color(k+1, INF), d(k+1, INF), curr;
	vb vis(k+1, 0);
	repd(i, n-1, 0){
		next[i] = color[c[i]];
		color[c[i]] = i;
	}
	
	int ptr = 0;
	vis[c[0]] = 1;
	rep(i, 1, n){
		if (c[i] == a[ptr]){
			curr.pb(i);
			ptr++;
		}
		if (ptr >= x) break;
	}
	if (ptr < x){
		cout << "0\n\n";
		exit(0);
	}
	d[c[0]] = curr.back();
	bool ok = 1;
	rep(i, 1, n){
		if (!vis[c[i]]){
			vis[c[i]] = 1;
			if (i >= curr[0]){
				while (curr[0] <= i && curr[0]!=INF) curr[0] = next[curr[0]];
				rep(i, 1, sz(curr)){
					while (curr[i] <= curr[i-1] && curr[i]!=INF) curr[i] = next[curr[i]];
				}
			}
			if (curr.back() == INF) break;
			d[c[i]] = curr.back();
		}
	}
	return d;
}

void solve(){
	int n, k; cin >> n >> k;
	vi c(n);
	rep(i, 0, n) cin >> c[i];
	int x, y; cin >> x >> y;
	vi a(x), b(y);
	rep(i, 0, x) cin >> a[i];
	rep(i, 0, y) cin >> b[i];
	int last = a.back();
	
	vi d = count(c, a, x, n, k);
	reverse(all(c));
	vi e = count(c, b, y, n, k);
	rep(i, 1, k+1){
		if (e[i] == INF) continue;
		e[i] = n-1-e[i];
	}
	reverse(all(c));
	
	/*
	rep(i, 1, k+1) debug(d[i]);
	cerr << "\n";
	rep(i, 1, k+1) debug(e[i]);
	cerr << "\n";
	*/
	
	vpii sweep;
	rep(i, 1, k+1){
		if (d[i] == INF || e[i] == INF) continue;
		if (d[i]>e[i]) continue;
		sweep.pb({d[i], 0});
		sweep.pb({e[i], 2});
	}
	rep(i, 0, n) if (c[i] == last) sweep.pb({i, 1});
	sort(all(sweep));
	int sum = 0;
	set<int>ans;
	for (auto x: sweep){
		if (x.nd == 0) sum++;
		if (x.nd == 1) if (sum > 0) ans.insert(x.st);
		if (x.nd == 2) sum--;
	}
	cout << sz(ans) << "\n";
	for (auto x: ans) cout << x+1 << " ";
	cout << "\n";

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
