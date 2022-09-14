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

const int MAX = 2003;
char tab[MAX][MAX];

void solve(){
	int n, m; cin >> n >> m;
	
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			cin >> tab[i][j];
		}
	}
	
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			int ans = 0;
			rep(len, 0, max(n, m)){
				if (i-len < 1 || j-len < 1 || i+len > n || j+len > m) break;
				set<char>s;
				s.insert(tab[i-len][j]);
				s.insert(tab[i+len][j]);
				s.insert(tab[i][j-len]);
				s.insert(tab[i][j+len]);
				if (sz(s) == 1) ans = len;
				else break;
			}
			cout << ans << " ";
		}
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
