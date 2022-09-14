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

int sgn(int x){
	if (x == 0) return 0;
	if (x < 0) return -1;
	return 1;
}

void solve(){
	int n; cin >> n;
	vi a(n+1, 0);
	rep(i, 1, n+1) {
		cin >> a[i];
		a[i] = sgn(a[i]);
	}
	int zero = -2, res = 0, koniec = 1;
	rep(i, 1, n+1){
		if (!a[i]){
			if (zero != -2) koniec = zero+1;
			zero = i;
		} else {
			if (a[i] == a[i-1]){
				zero = -2;
				koniec = i;
			} else {
				//
			}
		}
		res = max(res, i-koniec+1);
	}
	cout << res << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}