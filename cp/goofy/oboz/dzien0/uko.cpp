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

const int MAX = 1e5+7;
vpii graf[MAX];
vi cnt, grupa;
int fuj, ans;

void DFS(int v, int pa = -1){
	for (auto x: graf[v]){
		if (x.st != pa){
			if (x.nd > 0) grupa[x.nd]++;
			DFS(x.st, v);
		}
	}
}

bool condition(int num){
	return (grupa[num] == 0 || grupa[num] == cnt[num]);
}

void dfs(int v, int pa = -1){
	for (auto x: graf[v]){
		if (x.st != pa){
			int a = abs(x.nd);
			int jeden = condition(a);
			if (x.nd > 0) grupa[a]--;
			else grupa[a]++;
			int dwa = condition(a);
			
			if (jeden && !dwa) fuj++;
			if (!jeden && dwa) fuj--;
			
			if (!fuj) ans = min(ans, x.st);
			dfs(x.st, v);
			
			if (x.nd > 0) grupa[a]++;
			else grupa[a]--;
			if (jeden && !dwa) fuj--;
			if (!jeden && dwa) fuj++;
		}
	}
}

void solve(){
	int n, k; cin >> n >> k;
	cnt.assign(k+1, 0);
	ans = n;
	grupa.assign(k+1, 0);
	rep(i, 1, n){
		int a, b, g; cin >> a >> b >> g;
		graf[a].pb({b, g});
		graf[b].pb({a, -g}); //fake krawedz
		cnt[g]++;
	}
	DFS(1);
	rep(i, 1, k+1){
		if (!condition(i)) fuj++;
	}
	if (!fuj) ans = 1;
	else dfs(1);
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
