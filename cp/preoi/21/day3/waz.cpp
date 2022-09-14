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
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
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
#define memo(x, val) memset(x, val, sizeof(x))
#define PI 3.14159265359

pair<int, string> solve(int a, int b, int c, int d, int &n, int &m, vi&x, vi&y, int &p){
	if (a == b){
		int ans = 0;
		string res;
		rep(i, c, d+1){
			ans += ((x[a]+y[i])%p);
			res += "P";
		}
		res.pop_back();
		return {ans, res};
	}
	int mid = (a+b)/2;
	vi dp1(d-c+1, 0), dp2(d-c+1, 0);
	rep(i, a, mid+1){
		//policzyc dp1
		rep(j, c, d+1){
			if (j-c>0) dp1[j-c] = max(dp1[j-c], dp1[j-c-1]);
			dp1[j-c] += ((x[i]+y[j])%p);
		}
	}
	repd(i, b, mid+1){
		//policzyc dp2
		repd(j, d, c){
			if (j-c<m-1) dp2[j-c] = max(dp2[j-c], dp2[j-c+1]);
			dp2[j-c] += ((x[i]+y[j])%p);
		}
	}
	int maxi = 0, pos = -1;
	rep(i, c, d+1){
		if (dp1[i-c]+dp2[i-c] >= maxi){
			maxi = dp1[i-c]+dp2[i-c];
			pos = i;
		}
	}
	pair<int, string> res1 = solve(a, mid, c, pos, n, m, x, y, p);
	pair<int, string> res2 = solve(mid+1, b, pos, d, n, m, x, y, p);
	return {maxi, res1.nd+"G"+res2.nd};
}

void solve(){
	int n, m, p; cin >> n >> m >> p;
	vi x(n), y(m);
	rep(i, 0, n) cin >> x[i];
	rep(i, 0, m) cin >> y[i];
	pair<int, string> ans = solve(0, n-1, 0, m-1, n, m, x, y, p);
	cout << ans.st << "\n";
	for (auto u:ans.nd){
		if (u == 'P') cout << 'G';
		else cout << 'P';
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
