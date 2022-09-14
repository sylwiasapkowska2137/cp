#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
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

const int MAX = 2e5+7;

void solve(){
	int n, m; cin >> n >> m;
	queue<int>s;
	vector<vi>tab(m), front(n+1);
	rep(i, 0, m){
		int k; cin >> k;
		rep(j, 0, k){
			int x; cin >> x;
			tab[i].pb(x);
		}
		int x = tab[i].back();
		front[x].pb(i);
		if (sz(front[x]) == 2) s.push(x);
	}
	
	while (!s.empty()){
		int v = s.front();s.pop();
		int a = front[v][0];
		int b = front[v][1];
		tab[a].pop_back();
		if (!tab[a].empty()){
			int x = tab[a].back();
			front[x].pb(a);
			if (sz(front[x]) == 2) s.push(x);
		}
		tab[b].pop_back();
		if (!tab[a].empty()){
			int x = tab[b].back();
			front[x].pb(b);
			if (sz(front[x]) == 2) s.push(x);
		}
		
	}
	bool ok = 1;
	rep(i, 0, m) ok&=tab[i].empty();
	if (ok) cout << "Yes\n";
	else cout << "No\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
