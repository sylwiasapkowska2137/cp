/*
	Author: sysia
	29.12.2021 13:44:06
*/

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
	vector<string>s(3);
	rep(i, 0, 3) cin >> s[i];
	int p[] = {0, 0, 0};
	string ans;
	bool b = 0;
	int m = 0;
	while (1){
		int cnt[2] = {0, 0};
		rep(i, 0, 3) cnt[s[i][p[i]]-'0']++;
		if (cnt[0] >= 2)ans += "0";
		else ans+="1";
		rep(i, 0, 3) if (s[i][p[i]] == ans[sz(ans)-1]) p[i]++;
		rep(i, 0, 3) {
			if (p[i] >= 2*n) {
				b = 1;
			}
		}
		m++;
		if (b) break;
	}
	m-=n;
	rep(i, 0, 3){
		if (p[i]!=2*n && p[i]>=m){
			cout << ans << s[i].substr(p[i]) << "\n";
			return;
		}
	}
	cout << ans << "\n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
