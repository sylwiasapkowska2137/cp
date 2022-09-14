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


void solve(){
	int n, k; cin >> n >> k;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	if (n == k) {
		rep(i, 0, n) cout << a[i] << " ";
		cout << "\n";
		return;
	}
	int maxi = *max_element(all(a));
	vi pref(n+2, 0); 
	rep(i, 1, n+1){
		pref[i+1] = pref[i];
		if (a[i] == maxi) pref[i+1]++;
	}
	rep(i, k+1, n+1){
		if (pref[i]-pref[i-k] == k){
			rep(j, 0, k){
				cout << maxi << " ";
			}
			return;
		}
	}
	
	bool ok = 1;
	repd(i, n-1, n-k){
		if (a[i-1] > a[i]){
			ok = 0;
		}
	}
	if (ok){
		int x = 0;
		rep(i, 0, n-k-1){
			x = max(x, a[i]);
		}
		if (x <= a[n-k]){
			rep(i, n-k, n){
				cout << a[i] << " ";
			}
			return;
		}
	}
	ok = 1;
	rep(i, 1, k){
		if (a[i-1] < a[i]){
			ok = 0;
		}
	}
	if (ok){
		int x = 0;
		rep(i, k, n){
			x = max(x, a[i]);
		}
		if (x <= a[k-1]){
			rep(i, 0, k){
				cout << a[i] << " ";
			}
			return;
		}
	}
	cout << "-1\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
