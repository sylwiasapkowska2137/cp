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

void coloring(int n, int m, int k, bool swap){
	char ans[n][m];
	debug(n);
	debug(m);
	debug(k);
	cerr << "\n";
	if (n&1){
		for (int i = 0; i<m; i+=2){
			if (i>0 && ans[n-1][i-1]=='r') {
				ans[n-1][i] = 's';
				ans[n-1][i+1] = 's';
			} else {
				ans[n-1][i] = 'r';
				ans[n-1][i+1] = 'r';
			}
		}
		k-=m/2;
	}
	if (m&1){
		for (int i = 0; i<n; i+=2){
			if (i>0 && ans[i-1][m-1]=='l') {
				ans[i][m-1] = 'w';
				ans[i+1][m-1] = 'w';
			} else {
				ans[i][m-1] = 'l';
				ans[i+1][m-1] = 'l';
			}
		}
		//k-=m/2;
	}
	
	for (int i = 0; i+1<n; i+=2){
		for(int j = 0; j+1<m; j+=2){
			if (k>0){
				char x = 'a';
				if (j>0 && ans[i][j-1]=='a') x = 'x';
				ans[i][j] = x;
				ans[i][j+1] = x;
				ans[i+1][j] = (x+1);
				ans[i+1][j+1] = (x+1);
				k-=2; 
			} else {
				char x = 'c';
				if (i>0 && ans[i-1][j]=='c') x = 'f';
				ans[i][j] = x;
				ans[i][j+1] = (x+1);
				ans[i+1][j] = x;
				ans[i+1][j+1] = (x+1);
			}
		}
	}
	if (swap){
		rep(i, 0, m){
			rep(j, 0, n){
				cout << ans[j][i];
			}
			cout << "\n";
		}
		return;
	}
	rep(i, 0, n){
		rep(j, 0, m){
			cout << ans[i][j];
		}
		cout << "\n";
	}
}


void solve(){
	int n, m, k; cin >> n >> m >> k;
	bool N = n&1, M = m&1, K = k&1, ok = 0;
	if (!N && !M) {
		ok = !K;
		if (ok){
			cout << "YES\n";
			coloring(n, m, k, 0);
			return;
		}
	} else if (N){
		k-=m/2;
		if (k>=0 && !(k&1)) {
			cout << "YES\n";
			coloring(n, m, k+m/2, 0);//n niep
			return;
		}
	} else { // m nieparzyste
		swap(n, m);
		swap(N, M);
		k = m*n/2-k;
		K = k&1;
		k-=m/2;
		if (k>=0 && !(k&1)) {
			cout << "YES\n";
			coloring(n, m, k+m/2, 1);
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
