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

int len(LL n){
	int ans = 0;
	while (n > 0){
		ans ++;
		n/=10;
	}
	return ans;
}

map<LL, LL>vis;

void backtrack(LL curr, LL n, LL a, LL moves = 0){
	if (len(curr)>=7) return;
	if (vis.find(curr) != vis.end() && vis[curr] <= moves) return;
	vis[curr] = moves;
	backtrack(curr*a, n, a, moves+1);
	LL x = curr%10;
	if (curr>=10 && x!=0){
		LL sz = len(curr);
		LL nowy = x*(LL)pow(10LL, sz-1)+curr/10LL;
		backtrack(nowy, n, a, moves+1);
	}
}

void solve(){
	LL a, n; cin >> a >> n;
	backtrack(1, n, a);
	if (vis.find(n) == vis.end()) cout << "-1\n";
	else cout << vis[n] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
