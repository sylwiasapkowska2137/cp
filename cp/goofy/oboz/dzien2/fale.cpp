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
	int n, m, k; cin >> n >> m >> k;
	map<int, vi>mapa;
	vi a(n);
	rep(i, 0, n){
		cin >> a[i];
		mapa[a[i]].pb(i);
	}
	LL ans = 0LL;
	if (k>n/2) ans += (m-sz(mapa));
	for (auto x: mapa){
		bool ok = 0;
		if (sz(x.nd)>n/2){
			//przeszkadzanie
			map<int, int>freq;
			rep(i, 0, k) freq[a[i]]++;
			rep(i, k, n){
				if (sz(x.nd)-freq[x.st] > n/2 && sz(freq)<m) ok = 1; //istnieje jakis element by go wstawic w ten przedzial
				freq[a[i]]++;
				freq[a[i-k]]--;
				if (!freq[a[i-k]]) freq.erase(a[i-k]);
				if (sz(x.nd)-freq[x.st] > n/2 && sz(freq)<m) ok = 1;
			}
		}
		if (ok){
			ans++;
			continue;
		}
		if (sz(x.nd)+k<=n/2) continue;
		if (x.nd[0]>=k) ok = 1;
		rep(i, 1, sz(x.nd)) if ((x.nd[i]-x.nd[i-1])>=k) ok = 1;
		if ((n-x.nd.back()-1)>=k) ok = 1;
		if (ok) {
			//debug(x.st);
			ans++;
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}

/*
8 2137 5
1 1 3 2 1 1 1 2
*/
