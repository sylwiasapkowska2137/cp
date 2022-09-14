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

bool check(LL m, vi&a){
	LL sum = 0LL, pref = 0LL;
	rep(i, 1, sz(a)){
		sum += (LL)a[i];
		pref += m;
		pref = max(pref, sum);
	}
	if (pref > sum) return 0;
	return 1;
}

void solve(){
	int n; cin >> n;
	vi a(n+1);
	rep(i, 1, n+1) cin >> a[i];
	LL maxi = 0;
	LL sum = 0LL;
	rep(i, 1, n+1){
		sum += (LL)a[i];
		maxi = max(maxi, (LL)ceil((LD)(sum)/(LD)(i)));
	}
	debug(maxi);
	LL L = 0, R = maxi, ans = 0;
	while (R>=L){
		LL m = (L+R)/2;
		if (check(m, a)){
			ans = m;
			L = m+1;
		} else R = m-1;
	}
	cout << maxi-ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
