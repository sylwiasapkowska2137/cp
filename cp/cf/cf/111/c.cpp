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
#define repd(i, a, b) for (int i=a; i>=b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define debug(x) cerr << x << " "

const int INF = 1e9+7;

vi a;

bool ok(int x, int y, int z){
	if ((a[x]<a[y] && a[y]>a[z]) || (a[x]>a[y] && a[y]<a[z])) return 1;
	return 0;
}

void solve(){
	/*
	int n; cin >> n;
	vi a(n), next(n);
	rep(i, 0, n) cin >> a[i];
	stack<int>s;
	s.push(-1);
	repd(i, n-1, 0){
		while (s.top() != -1 && a[s.top()] < a[i]) s.pop();
		next[i] = s.top();
		s.push(i);
	}
	rep(i, 0, n) debug(next[i]);
	cerr << "\n";
	*/
	//Idea rozwiązania: znaleźć ilość trójek jednomonotonicznych
	int n; cin >> n;
	a.resize(n);
	rep(i, 0, n) cin >> a[i];
	LL ans = 2*n-1;
	rep(i, 0, n){
		if (i+2<n){
			if (ok(i, i+1, i+2)) ans++; 
		}
	}
	rep(i, 0, n){
		if (i+3<n){
			if (ok(i, i+1, i+2) && ok(i, i+1, i+3) && ok(i, i+2, i+3) && ok(i+1, i+2, i+3)) ans++;
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
