#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
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

const int MAX = 1e5+7;
bool freq[MAX];

void solve(){
	int n, m, x; cin >> n >> m;
	
	rep(i, 0, n) {
		cin >> x;
		rep(j, 1, sqrt(x)+2){
			if (x%j == 0){
				freq[j] = 1;
				freq[x/j] = 1;
			}
		}
		//freq[x]++;
	}
	bool ans[MAX];
	rep(i, 1, MAX) ans[i] = 1;
	rep(i, 2, MAX){
		if (freq[i]){
			for (int j = i; j<MAX; j+=i) ans[j] = 0;
		}
	}
	vi out;
	rep(i, 1, m+1){
		if (ans[i]) out.pb(i);
	}
	cout << out.size() << "\n";
	for (auto x: out) cout << x << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
