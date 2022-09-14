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

void solve(){
	int a, b;
	string s;
	bool ok = 0;
	cin >> a >> b >> s;
	int n = a+b, f[2];
	f[0] = a;f[1] = b;
	rep(i, 0, n) if (s[i]!='?') f[s[i]-'0']--;
	int L = 0, R = n-1;
	while (L < R){
		if (s[L] != s[R]){
			if (s[L]!='?' && s[R]!='?')	{
				ok = 1;	break;
			}
			if (s[L]=='?'){
				s[L] = s[R];
				f[s[R]-'0']--;
			} else {
				s[R] = s[L];
				f[s[L]-'0']--;
			}
		}
		L++;R--;
	}
	if (ok || f[0]<0 || f[1]<0) {
		cout << "-1\n";
		return;
	}
	L = 0, R = n-1;
	while (L<R){
		if(s[L]=='?'){
			rep(i, 0, 2){
				if (f[i]>1){
					f[i]-=2;
					s[L] = (char)(i+'0');
					s[R] = (char)(i+'0');
					break;
				}
			}
		}
		L++;R--;
	}
	if (n&1 && s[(a+b)/2]=='?'){
		rep(i, 0, 2){
			if (f[i]){
				f[i]--;
				s[(a+b)/2] = (char)(i+'0');
			}
		}
	}
	if (f[0] || f[1]) {
		cout << "-1\n";
		return;
	}
	cout << s <<"\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
