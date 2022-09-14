//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
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

const int MAX = 3e5+3;
vpii query[MAX];

//https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
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
	int n, k, q; 
	fastscan(n);
	fastscan(k);
	fastscan(q);
	vi a(n+1);
	vll pref(n+1, 0), dp(n+1, 0), ans(q, 0);
	rep(i, 1, n+1){
		fastscan(a[i]);
		pref[i] = pref[i-1]+(LL)a[i];
	}
	rep(i, 0, q){
		int l, r; 
		fastscan(l);
		fastscan(r);
		query[l].pb({r, i});
	}
	
	rep(i, 1, n+1){
		if (query[i].empty()) continue;
		dp.assign(n+1, 0LL);
		LL maxi = 0LL;
		rep(j, i+k-1, n+1){
			maxi = max(maxi, dp[j-k]);
			dp[j] = max(dp[j-1], maxi+pref[j]-pref[j-k]);
		}
		for (auto x: query[i]) ans[x.nd] = max(0LL, dp[x.st]);
	}
	rep(i, 0, q) printf("%lld\n", ans[i]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	//cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	
	return 0;
}
