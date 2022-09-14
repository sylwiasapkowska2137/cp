//Sylwia Sapkowska
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
#define PI 3.14159265359

const int MAX = 1e5+7;

struct Item{
	int l, r, d;
};

void solve(){
	int n, k; cin >> n >> k;
	vi ans(n+1, 0);
	int s = sqrt(n);
	vector<Item> tab;
	rep(i, 0, k){
		int a, l, d; cin >> a >> l >> d;
		if (d >= s){
			for (int j = a; j<=min(n, a+(l-1)*d); j+=d){
				ans[j]++;
			}
		} else {
			tab.pb({a, a+(l-1)*d, d});
		}
	}
	int q = sz(tab);
	rep(D, 1, s){
		vi start(n+D+1, 0), End(n+D+1);
		rep(i, 0, q) {
			if (tab[i].d == D){
				start[tab[i].l]++;
				End[tab[i].r]++;
			}
		}
		rep(x, 1, n+1){
			start[x+D] += (start[x]-End[x]);
			ans[x]+=start[x];
		}
	}
	rep(i, 1, n+1) cout << ans[i] << " ";
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
