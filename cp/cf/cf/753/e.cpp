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
	int n, m; cin >> n >> m;
	string s; cin >> s;
	int x = sz(s);
	int L = 0, R = 0, U = 0, D = 0;
	int indeks = -1;
	rep(i, 0, x){
		if (s[i] == 'L') L++;
		if (s[i] == 'R') R++;
		if (s[i] == 'U') U++;
		if (s[i] == 'D') D++;
		if (L <= m && R <= m  && abs(L-R) <= m && U + D <= n) indeks = i;
	}
	//debug(indeks);
	if (indeks == -1){
		cout << "1 1\n";
	} else {
		L = 0, R = 0, U = 0, D = 0;
		int l = 0, u = 0;
		rep(i, 0, indeks+1){
			if (s[i] == 'L') L++;
			if (s[i] == 'R') R++;
			if (s[i] == 'U') U++;
			if (s[i] == 'D') D++;
		}
		cout << U+1 << " " << L+1 << "\n";
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
