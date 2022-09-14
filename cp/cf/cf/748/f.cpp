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

const int MAX = 45;
const LL INF = 1e18+7;

void solve(){
	int n, A, B; cin >> n >> A >> B;
	string x; cin >> x;
	vll digits(n);
	rep(i, 0, n) digits[i] = x[i]-'0';
	LL dp[n+1][n+1][A][B];
	memo(dp);
	dp[0][0][0][0] = 1;
	
	//czerwony = 0
	//niebieski = 1
	
	rep(i, 0, n){
		rep(j, 0, i+1){
			rep(a, 0, A){
				rep(b, 0, B){
					if (dp[i][j][a][b]){
						//mozemy dać na czerwono
						dp[i+1][j+1][(a*10+digits[i])%A][b] = dp[i][j][a][b];
						//mozemy dać na niebiesko
						dp[i+1][j][a][(b*10+digits[i])%B] = (dp[i][j][a][b] | (1LL<<(i+1)));
					}
				}
			}
		}
	}
	
	LL ans = INF, mask = 0;
	rep(i, 1, n){
		if (dp[n][i][0][0]){
			if (ans > abs(n-2*i)){
				ans = abs(n-2*i);
				mask = dp[n][i][0][0];
			}
		}
	}
	if (ans == INF){
		cout << "-1\n";
	} else {
		rep(i, 1, n+1){
			if (mask&(1LL<<i)) cout << "B";
			else cout << "R";
		}
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
