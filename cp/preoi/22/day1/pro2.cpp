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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
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

int p(int a, int b){
	return a+rng()%(b-a+1);
}

const int INF = 1e9+7;

void solve(){
	LL n, m, k; cin >> n >> m >> k;
	vector<vi>tab(n+1, vi(m+1, 0)), right(n+1, vi(m+1, m+1));
	if (!k){
		LL ans = n*m*(n+1)*(m+1)/4;
		cout << ans << "\n";
		return;
	}
	rep(i, 0, k){
		int a, b; cin >> a >> b;
		tab[a][b] = 1;
	}
	rep(i, 1, n+1){
		repd(j, m-1, 0){
			if (tab[i][j+1] == 1){
				right[i][j] = j+1;
			} else {
				right[i][j] = right[i][j+1];
			}
		}
	}
	LL ans = 0LL;
	rep(l, 0, m){
		vi tab;
		rep(i, 1, n+1){
			tab.pb(right[i][l]-l-1);
		}
		//debug(tab);
		vi left(n), right(n);
		stack<pii>s;
		s.push({-INF, 0});
		rep(i, 0, n){
			while (s.top().st >= tab[i]) s.pop();
			left[i] = i-s.top().nd+1;
			s.push({tab[i], i+1});
		}
		s = {};
		s.push({-INF, n+1});
		repd(i, n-1, 0){
			while (s.top().st > tab[i]) s.pop();
			right[i] = s.top().nd-i-1;
			s.push({tab[i], i+1});
		}
		//debug(tab, left, right);
		LL res = 0LL;
		rep(i, 0, n){
			res += (LL)tab[i]*(right[i]*left[i]);
		}
		//debug(res);
		ans += res;
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
