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

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

const int MAX = 1e5+7;
set<int>seen[MAX];
int n, m;


struct testimony{
	int t, kto, ile;
	testimony(){}
	testimony(int t, int kto, int ile): t(t), kto(kto), ile(ile) {}
};

vector<testimony>tab;

bool cmp(testimony a, testimony b){
	return a.t < b.t;
}

bool warunek(int mid){
	vector<testimony>tmp;
	rep(i, 0, mid) tmp.pb(tab[i]);
	sort(all(tmp), cmp);
	
	cerr << "\n";
	for (auto x: tmp){
		debug(x.t);
		debug(x.kto);
		debug(x.ile);
		cerr << "\n";
	}
	
	rep(i, 1, m+1) seen[i].clear();
	for (auto x: tmp) seen[x.t].insert(x.ile+1);
	rep(i, 1, m+1) if (sz(seen[i])>1) return 0;
	
	
}

void solve(){
	cin >> n >> m;
	tab.resize(m+1);
	rep(i, 0, m) cin >> tab[i].t >> tab[i].kto >> tab[i].ile;
	int l = 1, r = m;
	rep(i, 1, m+1) warunek(i);
	cerr << "\n";
	return;
	int ans = 1;
	while (r - l > 1){
		int mid = (l+r)/2;
		if (warunek(mid)) {
			l = mid+1;
			ans = mid;
		}
		else r = mid-1;
	}
	cout << ans+1 << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
