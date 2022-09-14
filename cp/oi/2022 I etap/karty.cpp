//Układanie kart
//Sylwia Sapkowska
//template from https://codeforces.com/profile/Geothermal
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

LL tab[] = {0, 0, 1, 15, 168, 1700, 17220, 182406, 2055200,24767928, 319463100};

void solve(){
	LL n, MOD; cin >> n >> MOD;
	LL tmp = 0LL;
	if (n <= 5){
		cout << (tab[n]%MOD) << "\n";
		return;
	}
	/*
	rep(i, 0, n){
		LL curr = 1LL;
		rep(j, i+1, n+1) curr = (curr*(LL)j)%MOD;
		tmp+=curr;
		if (tmp >= curr) tmp%=MOD;
	}
	*/
	LL curr = 1LL;
	repd(i, n-1, 0){
		curr*=(LL)(i+1);
		if (curr >= MOD) curr%=MOD;
		tmp+=curr;
		if (tmp >= curr) tmp%=MOD;
	}
	LL silnia = 1LL;
	//debug(tmp);
	rep(i, 2, n+1) {
		if (i == 4) continue;
		silnia = (silnia*(LL)i)%MOD;
	}
	LL ANS = (n-1)*(((5LL*n*silnia)%MOD-tmp)%MOD);
	while (ANS < 0) ANS+=MOD;
	if (ANS >= MOD) ANS%=MOD;
	cout << ANS << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	//cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	
	return 0;
}
