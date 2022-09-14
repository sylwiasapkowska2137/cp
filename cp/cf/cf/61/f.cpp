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

const int MAX = 507;
int dp[MAX][MAX];
int n;
string s;

int count_dp(int L, int R){
	if (dp[L][R]) return dp[L][R];
	if (R < L) return 0;
	//jesli pojedyncza litera
	char c = s[L];
	bool ok = 1;
	rep(i, L+1, R+1) ok |= (s[i] == c);
	if (ok) {
		dp[L][R] = 1;
		return 1;
	}
	rep(k, L, R+1){
		dp[L][R] = min(dp[L][R], count_dp(L, k)+count_dp(k+1, R));
	}
	return dp[L][R];
}

void solve(){
	cin >> n >> s;
	cout << count_dp(0, n);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
