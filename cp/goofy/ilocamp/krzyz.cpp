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

int n, m, k; 
vpii dots;
char tab[35][35];
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};

void cnt(int idx){
	if (idx == sz(dots)){
		rep(i, 1, n+1){
			rep(j, 1, m+1){
				cout << tab[i][j];
			}
			cout << "\n";
		}
		exit(0);
	}
	rep(i, 0, k){
		char c = (char)('A'+i);
		bool ok = 1;
		rep(j, 0, 4){
			pii v = {dots[idx].st + x[j], dots[idx].nd + y[j]};
			if (v.st >= 1 && v.st <= n && v.nd >= 1 && v.nd <= m){
				if (tab[v.st][v.nd] == c) ok = 0;
			}
		}
		if (ok){
			tab[dots[idx].st][dots[idx].nd] = c;
			cnt(idx+1);
			tab[dots[idx].st][dots[idx].nd] = '.';
		}
	}
}

void solve(){
	cin >> n >> m >> k;
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			cin >> tab[i][j];
			if (tab[i][j] == '.') dots.pb({i, j});
		}
	}
	cnt(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
