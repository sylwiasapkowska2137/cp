#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//Jakub Misiaszek
//szablon czesciowo skopiowany z profilu https://codeforces.com/profile/Geothermal
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
LL losuj(LL a, LL b){ return a+rng()%(b-a+1);}

void solve(){
	int n, m; cin >> n >> m;
	vector<vpii>G(n+1,vpii(0,{0,0}));
	rep(i,0,m){
		int a, b, v; cin >> a >> b >> v;
		G[a].pb({b,v});
		G[b].pb({a,v});
	}
	int s, e; cin >> s >> e;
	vll ans(2,-1);
	vector<vi> vis(n+1,vi(2,0));
	pqg<pair<LL,pii>>Q;
	//vis[s][0]=1;
	Q.push({0LL,{s,0}});
	while(!Q.empty()){
		LL koszt = Q.top().st;
		int w = Q.top().nd.st, len = Q.top().nd.nd;
		Q.pop();
		//cout << w << " " <<koszt << " " << len << "\n";
		if(vis[w][len]==1) continue;
		vis[w][len] = 1;
		if(w==e){
			ans[len]=koszt;
			//cout << "AAA\n";
		}
		else{
			for(auto x:G[w]){
				Q.push({koszt+x.nd,{x.st,(len+1)&1}});
			}
		}
	}
	
	cout << ans[0] << " " << ans[1] << "\n";
		
		
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
