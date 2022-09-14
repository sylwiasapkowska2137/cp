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
	int n;cin >> n;
	vll a(n+2);
	int x = -1, S = -1;
	LL sum = 0LL;
	rep(i, 0, n+2) {
		cin >> a[i];
		sum+=a[i];
	}
	sort(all(a));
	rep(i, 0, n+2){
		if ((sum-a[i])&1) continue;
		LL check = (sum-a[i])/2;
		int ind = lb(all(a), check)-a.begin();
		if (ind == i) ind++;
		if (ind >= n+2) continue;
		if (a[ind] == check){
			x = i;
			S = ind;
			break;
		}
	}
	//debug(x);
	if (x == -1){
		cout << "-1\n";
		return;
	}
	rep(i, 0, n+2){
		if (i != x && i!=S) cout << a[i] << " ";
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
