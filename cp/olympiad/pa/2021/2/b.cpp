//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	vpii ans;
	s+="2";
	int cnt = 1;
	rep(i, 1, n+1){
		if (s[i]==s[i-1]) cnt++;
		else {
			if (s[i-1] == '0') ans.pb({cnt, -2});
			cnt = 1;
		}
	}
	
	if (s[0] == '0') {
		ans[0].st*=2;
		ans[0].nd = -1;
	} else {
		if (sz(ans) == 1 && s[n-1] == '0'){
			ans.back().st*=2;
			ans[sz(ans)-1].nd = -1;
		}
	}
	if (sz(ans) > 1 && s[n-1] == '0') {
		ans.back().st*=2;
		ans[sz(ans)-1].nd = -1;
	}
	sort(all(ans));
	
	int dzien = 0, saved = 0;
	while (!ans.empty()){
		pii v = ans.back();
		ans.pop_back();
		if (v.nd == -1) v.st/=2;
		/*
		debug(v.st);
		debug(-v.nd);
		debug(saved);
		cerr << "\n";
		*/
		if (v.nd == -1){ //brzeg
			int infected = dzien;
			if (v.st-infected <= 0) continue;
			saved += v.st-infected;
			dzien++;
		} else {
			int infected = 2*dzien;
			if (v.st-infected <= 0) continue;
			if (v.st-infected == 1){
				saved++;
				dzien++;
			} else {
				infected++;
				saved += (v.st-infected);
				dzien+=2;
			}
		}
	}
	int res = max(0, n-saved);
	cout << res << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
