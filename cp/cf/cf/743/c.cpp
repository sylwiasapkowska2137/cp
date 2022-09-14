#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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

void solve(){
	int n; cin >> n;
	vector<vi>graf(n+1);
	vi dist(n+1, -1), in(n+1, 0);
	rep(i, 1, n+1){
		int k; cin >> k;
		in[i] = k;
		while (k--){
			int a; cin >> a;
			graf[a].pb(i);
		}
	}
	queue<int>q;
	rep(i, 1, n+1){
		if (!in[i]){
			q.push(i);
			dist[i] = 1;
		}
	}
	int cnt = 0;
	while (!q.empty()){
		int v = q.front();q.pop();
		cnt++;
		for (auto x: graf[v]){
			int nd = dist[v];
			if(x<v) nd++;
			if(dist[x]<nd) dist[x] = nd;
			if(!--in[x]) q.push(x);
		}
	}
	int ans = 0;
	rep(i, 1, n+1) if(ans < dist[i]) ans = dist[i];
	if (cnt < n) cout << "-1\n";
	else cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
