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

void solve(){
	int n; cin >> n;
	char c; string s; cin >> c >> s;
	int cnt = 0;
	rep(i, 0, n) if (s[i] == c) cnt++;
	if (cnt == n) {
		cout << "0\n";
		return;
	}
	int k = -1;
	rep(i, 2, n){
		if (n%i!=0){
			k = i;
			break;
		}
	}
	//spróbujmy jedną zmianą
	vb tab(n+1, 0);
	rep(i, 0, n){
		if (s[i]!=c){
			int x = i+1;
			for (int j = 1; j*j<=x; j++){
				if (x%j == 0){
					tab[j] = 1;
					tab[x/j] = 1;
				}
			}
		}
	}
	rep(i, 1, n+1) {
		if (!tab[i]){
			cout << "1\n" << i << "\n";
			return;
		}
	}
	
	cout << "2\n" << n << " " << k << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
