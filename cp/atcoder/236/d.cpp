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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
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

int p(int a, int b){
	return a+rng()%(b-a+1);
}

const int MAX = 20;
int tab[MAX][MAX];
int ans = 0;

void backtrack(vi a, int n){
	if (sz(a) == n){
		//for (auto x: a) debug(x);
		//cerr << "\n";
		int tmp = 0;
		for (int i = 0; i<n; i+=2){
			tmp ^= (tab[a[i]][a[i+1]]);
		}
		ans = max(ans, tmp);
		return;
	}
	vi cnt(n+1, 0);
	for (auto x: a) cnt[x]++;
	rep(i, 1, n+1) {
		if (!cnt[i]){
			a.pb(i);
			break;
		}
	}
	rep(i, 1, n+1){
		if (!cnt[i] && i != a.back()){
			a.pb(i);
			backtrack(a, n);
			a.pop_back();
		}
	}
}

void solve(){
	int n; cin >> n;
	n*=2;
	rep(i, 1, n+1){
		rep(j, i+1, n+1){
			cin >> tab[i][j];
		}
	}
	backtrack({}, n);
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
