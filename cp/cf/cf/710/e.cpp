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
	int n;cin >> n;
	vi q(n), perm(n);
	vb used(n+1, 0);
	rep(i, 0, n) cin >> q[i];
	perm[0] = q[0];
	used[q[0]] = 1;
	rep(i, 1, n){
		if (q[i]!=q[i-1]){
			perm[i] = q[i];
			used[q[i]] = 1;
		}
	}
	set<int>s;
	rep(i, 1, n+1) if (!used[i]) s.insert(i);
	rep(i, 0, n){
		if (!perm[i]){
			auto it = s.begin();
			perm[i] = (*it);
			s.erase(s.begin());
		}
		cout << perm[i] << " ";
	}
	cout << "\n";
	s.clear();
	perm.assign(n+1, 0);
	used.assign(n+1, 0);
	perm[0] = q[0];
	used[q[0]] = 1;
	rep(i, 1, n){
		if (q[i]!=q[i-1]){
			perm[i] = q[i];
			used[q[i]] = 1;
		}
	}
	rep(i, 1, n+1) if (!used[i]) s.insert(i);
	rep(i, 0, n){
		if (!perm[i]){
			auto it = s.lb(perm[i-1]);
			it--;
			perm[i] = (*it);
			s.erase(it);
		}
		cout << perm[i] << " ";
	}
	cout << "\n";
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
