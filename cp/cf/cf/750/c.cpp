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

const int INF = 1e9+7;

bool palindrome(string s){
	int n = sz(s);
	int L = 0, R = n-1;
	while (L < R){
		if (s[L]!=s[R]) return 0;
		L++;R--;
	}
	return 1;
}

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	int ans = INF;
	for (char c = 'a'; c<='z'; c++){
		string t;
		rep(i, 0, n) if (s[i]!=c) t+=s[i];
		if (palindrome(t)){
			//debug(c);
			int tmp = 0;
			int L = 0, R = n-1;
			while (L < R){
				if (s[L] == s[R]){
					L++;
					R--;
					continue;
				}
				tmp++;
				if (s[L] == c) L++;
				else R--;
			}
			ans = min(ans, tmp);
		}
	}
	
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
