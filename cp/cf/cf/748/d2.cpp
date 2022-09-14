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



void solve(){
	int n; cin >> n;
	vi a(n);
	map<int, int>mapa;
	rep(i, 0, n) cin >> a[i];
	sort(all(a));
	rep(i, 0, n) {
		mapa[a[i]]++;
		if (mapa[a[i]]>=n/2){
			cout << "-1\n";
			return;
		}
	}
	int ans = -1;
	rep(i, 0, n){
		map<int, int>mapa;
		rep(k, 0, n){
			int x = a[i]-a[k];
			if (x <= 0) continue;
			set<int>s;
			for (int j = 1; j*j<=x; j++){
				if (x%j  == 0){
					s.insert(j);
					s.insert(x/j);
				}
			}
			for (auto x: s) mapa[x]++;
		}
		int v = count(all(a), a[i]);
		for(auto to = mapa.rbegin(); to != mapa.rend(); to = next(to)){
			if ((to->nd+v)*2>=n){
				ans = max(ans, to->st);
				break;
			}
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
