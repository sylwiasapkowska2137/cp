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

int judge(char a, char b){
	if (a == b) return -1;
	if (a == 'G' && b == 'P') return 1;
	if (a == 'C' && b == 'G') return 1;
	if (a == 'P' && b == 'C') return 1;
	return 0;
}

void solve(){
	int n, m; cin >> n >> m;
	char tab[n+n][m];
	rep(i, 0, n+n){
		rep(j, 0, m) {
			cin >> tab[i][j];
		}
	}
	vpii rank(n+n);
	rep(i, 0, n+n) rank[i] = {0, i};
	rep(i, 0, m){
		rep(j, 0, n){
			int a = rank[2*j].nd;
			int b = rank[2*j+1].nd;
			int res = judge(tab[a][i], tab[b][i]);
			if (res != -1) rank[2*j+res].st--;
		}
		sort(all(rank));
	}
	rep(i, 0, n+n) cout << rank[i].nd+1 << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
