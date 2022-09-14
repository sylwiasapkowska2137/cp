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

const int INF = 1e9+7;

void pop(deque<pii>&q, int i){
	while (!q.empty() && q.front().nd <= i) q.pop_front();
}

void push(deque<pii>&q, int x, int i){
	while (!q.empty() && q.back().st < x) q.pop_back();
	q.pb({x, i});
}

pii query(deque<pii>&q){
	return q.front();
}

void solve(){
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	int q; cin >> q;
	vi dp(n);
	
	while (q--){
		deque<pii>A, B;
		int curr[2] = {0, INF};
		int k; cin >> k;
		push(A, a[0], 0);
		rep(i, 1, n){
			pii x = query(A); //a[i], i
			dp[i] = dp[x.nd];
			if (x.st <= a[i]) dp[i]++;
			if (dp[i] == curr[0]) push(A, a[i], i);
			else if (dp[i] == curr[1] || curr[1] == INF){
				curr[1] = dp[i];
				push(B, a[i], i);
			}
			if (i>=k){
				pop(A, i-k);
				pop(B, i-k);
				if (A.empty()){
					A = B;
					B.clear();
					curr[0] = curr[1];
					curr[1] = INF;
				}
			}
			/*
			debug("A");
			debug(curr[0]);
			for (auto x: A) debug(x.st);
			cerr << "\n";
			debug("B");
			debug(curr[1]);
			for (auto x: B) debug(x.st);
			cerr << "\n\n";
			*/
		}
		//rep(i, 0, n) debug(dp[i]);
		//debug("ans");
		cout << dp[n-1] << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
