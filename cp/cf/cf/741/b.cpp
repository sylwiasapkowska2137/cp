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

bool isprime(int x){
	rep(i, 2, sqrt(x)+1){
		if (x%i == 0) return 0;
	}
	return 1;
}

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	rep(i, 0, n){
		if (s[i] == '1' || s[i]=='9' || s[i]=='4' || s[i]=='6' || s[i]=='8'){
			cout << "1\n" << s[i] << "\n";
			return;
		}
	}
	rep(i, 0, n){
		rep(j, i+1, n){
			int x = 10*(s[i]-'0')+(s[j]-'0');
			if (!isprime(x)){
				cout << "2\n" << x << "\n";
				return;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
