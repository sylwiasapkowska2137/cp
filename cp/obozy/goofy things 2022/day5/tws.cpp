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

//dzieki za wyklad, fajen tlumaczysz
//https://www.youtube.com/watch?v=jwLBFucsdG4

void solve(){
	int n, k; cin >> n >> k;
	vi a(n+1), b(n+1);
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n+1) cin >> b[i];
	bool ok = 1;
	rep(i, 1, n+1){
		ok &= (a[i] == b[i]);
	}
	if (ok){
		cout << "0\n";
		return;
	} 
	if (k > n){
		cout << "-1\n";
		return;
	}
	map<int, int>cnt;
	rep(i, 1, k+1){
		cnt[b[i]]++;
	}
	int idx = -1;
	if (sz(cnt) == 1) idx = 1;
	rep(i, k+1, n+1){
		cnt[b[i-k]]--;
		if (cnt[b[i-k]] == 0) {
			cnt.erase(b[i-k]);
		}
		cnt[b[i]]++;
		if (sz(cnt) == 1) {
			idx = i-k+1;
			break;
		}
	}
	if (idx == -1){
		cout << idx << "\n";
		return;
	}
	debug(idx);
	vpii ans;
	rep(i, 1, idx) ans.pb({i, b[i]});
	repd(i, n+1, idx){
		if (i+k-1 > n) continue;
		ans.pb({i, b[i+k-1]});
	}
	cout << sz(ans) << "\n";
	for (auto x: ans){
		cout << x.st << " " << x.nd << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
