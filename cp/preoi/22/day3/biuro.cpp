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

vpii Merge(vpii a, vpii &b){
	if (a.empty()) return b;
	if (b.empty()) return a;
	int ptra = 0, ptrb = 0;
	vpii ans;
	if (a[0].st < b[0].st){
		ans.pb(a[0]);
		ptra++;
	} else {
		ans.pb(b[0]);
		ptrb++;
	}
	rep(i, 1, sz(a)+sz(b)){
		if (ptra < sz(a) && ans.back().st == a[ptra].st) ans.back().nd += a[ptra++].nd;
		else if (ptrb < sz(b) && ans.back().st == b[ptrb].st) ans.back().nd += b[ptrb++].nd;
		else if (ptra < sz(a) && (ptrb == sz(b) || a[ptra].st < b[ptrb].st)){
			ans.pb(a[ptra]);
			ptra++;
		} else {
			ans.pb(b[ptrb]);
			ptrb++;
		}
	}
	return ans;
}

vpii dfs(int v, int pa, vll &s, vll &cap, vector<vi>&graf){
	
	vpii ans;
	debug(v);
	for (auto x:graf[v]){
		if (x != pa){
			vpii tmp = dfs(x, v, s, cap, graf);
			ans = Merge(ans, tmp);
			tmp.clear();
		}
	}
	
	if (sz(graf[v]) == 1 && v != 1){
		//debug(v, s[v], cap[v]);
		if ((s[v]%cap[v]) == 0){
			vpii ans2 = {{0, cap[v]}, {s[v]/cap[v], -cap[v]}};
			debug(ans2);
			return ans2;
		} else {
			vpii ans2 = {{0, cap[v]}, {s[v]/cap[v], -cap[v]+(s[v]%cap[v])}, {s[v]/cap[v]+1, -(s[v]%cap[v])}};
			debug(ans2);
			return ans2;
		}
	}
	//if (pa == -1) return ans;
	for (auto &x:ans) x.st++;
	//debug(ans);
	ans.insert(ans.begin(), {0, s[v]});
	if (sz(ans)>=2) ans[1].nd -= s[v];
	debug(v, ans);
	return ans;
	
	//debug(ans);
	LL All = 0LL;
	LL h = ans[0].nd;
	rep(i, 1, sz(ans)){
		All += h*(LL)(ans[i].st-ans[i-1].st);
		h += ans[i].nd;
	}
	ans.clear();
	//debug(v, All);
	
	if ((All%cap[v]) == 0){
		vpii ans2 = {{0, cap[v]}, {All/cap[v], -cap[v]}};
		debug(ans2);
		return ans2;
	} 
	vpii ans2 = {{0, cap[v]}, {All/cap[v], -cap[v]+(All%cap[v])}, {All/cap[v]+1, -(All%cap[v])}};
	debug(ans2);
	return ans2;
}


void solve(){
	int n; cin >> n;
	vector<vi>graf(n+1, vi());
	vll s(n+1), cap(n+1), pa(n+1);
	rep(i, 2, n+1) cin >> s[i];
	rep(i, 2, n+1) {
		cin >> pa[i];
		graf[i].pb(pa[i]);
		graf[pa[i]].pb(i);
	}
	rep(i, 2, n+1) cin >> cap[i];
	vpii ans = dfs(1, -1, s, cap, graf);
	cout << ans.back().st+1 << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
