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

const int MAX = 1e5+2, MOD = 1e9+7;
LL dp[MAX][2][2];
int a[MAX];
pii in[MAX];

LL silnia(LL n){
	if (n <= 1) return 1;
	LL x = 1;
	rep(i, 2, n+1) {
		x*=(LL)i;
		if (x >= MOD) x%=MOD;
	}
	return x;
}

void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

void solve(){
	int n; fastscan(n);
	a[0] = -1;
	rep(i, 1, n+1) {
		fastscan(a[i]);
		if (in[a[i]].st == 0) in[a[i]].st = i;
		else {
			if (in[a[i]].nd != 0){
				cout << "0\n";
				return;
			}
			in[a[i]].nd = i;
		}
	}
	a[n+1] = MOD;
	a[n+2] = MOD+1;
	int ile = 0;
	rep(i, 1, n+1) if (in[i].st == 0) ile++;
	dp[1][0][1] = 1;
	rep(i, 2, n+1){
		//policzyc dp[i]
		if (dp[i-1][0][0] >= MOD) dp[i-1][0][0] %=MOD;
		if (dp[i-1][0][1] >= MOD) dp[i-1][0][1] %=MOD;
		if (dp[i-1][1][0] >= MOD) dp[i-1][1][0] %=MOD;
		if (dp[i-1][1][1] >= MOD) dp[i-1][1][1] %=MOD;
		
		if (a[i-1] == a[i+1]){
			dp[i][0][0] = dp[i][0][1] = 0;
			dp[i][1][0] = dp[i-1][0][1];
			if (a[i] == a[i-2]) dp[i][1][0] += dp[i-1][1][1];
			if (a[i-2]!=a[i]) dp[i][1][1] = dp[i-1][1][1] + dp[i-1][0][1];
			continue;
		}
		
		if (a[i-2] == a[i]){
			dp[i][0][1] = dp[i][1][1] = 0;
			if (a[i-1]!=a[i+1]) dp[i][0][0] = dp[i-1][1][0];
			dp[i][1][0] = dp[i-1][1][1];
			continue;
		}
		
		if (a[i] == a[i+2]){
			dp[i][0][0] = dp[i][1][0] = 0;
			dp[i][0][1] = dp[i-1][0][0] + dp[i-1][1][0];
			dp[i][1][1] = dp[i-1][0][1] + dp[i-1][1][1];
			continue;
		}
		dp[i][0][0] = dp[i-1][0][0];
		dp[i][0][1] = dp[i-1][0][0] + dp[i-1][1][0];
		
		dp[i][1][0] = dp[i-1][0][1];
		dp[i][1][1] = dp[i-1][0][1] + dp[i-1][1][1];
	}
	LL ans = dp[n][0][0] + dp[n][1][0];
	if (ans >= MOD) ans%=MOD;
	ans *= silnia(ile);
	if (ans >= MOD) ans%=MOD;
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
