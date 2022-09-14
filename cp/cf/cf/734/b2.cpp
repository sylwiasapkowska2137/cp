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
	int n, k;cin >> n >> k;
	vi ans(n+1, 0);
	unordered_map<int, vi> mapa;
	rep(i, 0, n){
		int x;cin >> x;
		if (mapa[x].size() < k) mapa[x].pb(i);
	}
	int N = 0;
	for (auto i:mapa) N+=sz(i.nd);
	N -= N%k;
	int K = 1;
	for (auto i:mapa){
		for (auto x: i.nd){
			if (!N) break;
			N--;
			ans[x] = K;
			K = (K==k)?1:K+1;
		}
		if (!N) break;
	}
	rep(i, 0, n) cout << ans[i] << " ";
	cout << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
