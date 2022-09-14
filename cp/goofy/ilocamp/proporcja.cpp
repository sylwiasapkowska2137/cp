#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
LL losuj(LL a, LL b){ return a+rng()%(b-a+1);}

void solve(){
	int n; cin >> n;
	LD f; cin >> f;
	string s; cin >> s;
	set<pair<LD, int>>S;
	s = "%"+s;
	int pref = 0, prev = 0, ans = -1;
	LD EPS = 1e9;
	rep(i, 1, n+1){
		prev = pref;
		pref += (s[i]-'0');
		LD num = f*(LD)i - pref + f;
		auto it = S.lb({num, -1});
		if (it != S.end() && abs(it->st-f)<EPS){
			EPS = abs(it->st-f);
			ans = it->nd;
		}
		if (it != S.begin()){
			it--;
			if (abs(it->st-f)<EPS){
				EPS = abs(it->st-f);
				ans = it->nd;
			}
		}
		LD num2 = f*(LD)i - prev;
		S.insert({num2, i});
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}