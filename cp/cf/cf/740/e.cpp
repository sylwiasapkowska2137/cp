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
	int n;
	cin >> n;
	vi a(n), ans;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n){
		if ((a[i]&1)!=((i+1)&1)){
			cout << "-1\n";
			return;
		}
	}
	while (sz(a)>1){
		if (a[sz(a)-1] == sz(a) && a[sz(a)-2] == sz(a)-1) {
			a.pop_back();
			a.pop_back();
			continue;
		}
		int x, y;
		rep(i, 0, sz(a)){
			if (a[i]==sz(a)) x = i+1;
			if (a[i]==sz(a)-1) y = i+1;
		}
		ans.pb(x);
		reverse(a.begin(), a.begin()+x);
		
		rep(i, 0, sz(a)){
			if (a[i]==sz(a)) x = i+1;
			if (a[i]==sz(a)-1) y = i+1;
		}
		
		ans.pb(y-1);
		reverse(a.begin(), a.begin()+y-1);
		rep(i, 0, sz(a)){
			if (a[i]==sz(a)) x = i+1;
			if (a[i]==sz(a)-1) y = i+1;
		}
		
		ans.pb(y+1);
		reverse(a.begin(), a.begin()+y+1);
		
		ans.pb(3);
		reverse(a.begin(), a.begin()+3);
		
		ans.pb(sz(a));
		reverse(all(a));
		
		
		a.pop_back();
		a.pop_back();
	}
	cout << sz(ans) << "\n";
	if (sz(ans)){
		for (auto x: ans) cout << x << " ";
		cout << '\n';
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

//10
//5 3 5 3 5 3 1 3 3 3
