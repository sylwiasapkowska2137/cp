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

struct submit{
	int kto, t, p;
};
int n, m, t;
vector<submit>tab;
const LL INF = 1e18;
const int MAX = 1e6+7;
vector<pair<int, LL>> v;
vll points;
vector<vpii>sub;

LL binsearch(int x) {
	LL score = 0;
	int nr = 0;
	sort(all(sub[x]));
	//debug(x, sub[x]);
	for (auto [tt, p]: sub[x]) {
		score += p;
		int up = (ub(all(v), make_pair(tt, INF))-v.begin());
		int left = up-1;
		if (left < 0) continue;
		if (v[left].nd == score) nr += ((LL)v[up].st - tt);
	}
	return nr;
}

void solve(){
	cin >> n >> m >> t;
	bool zeros = 1;
	vi scaler;
	rep(i, 0, m){
		int kto, tt, p; cin >> kto >> tt >> p;
		if (p == 0) continue;
		scaler.pb(kto);
		tab.pb(submit{kto, tt, p});
		zeros = 0;
	}
	//debug(zeros);
	if (zeros){
		cout << "1\n";
		return;
	}
	sort(all(scaler));
	scaler.erase(unique(all(scaler)), scaler.end());
	sub.assign(sz(scaler)+1, vpii());
	points.assign(sz(scaler)+1, 0);
	map<int, int>mapa;
	rep(i, 0, sz(scaler)) mapa[scaler[i]] = i;
	sort(all(tab), [](submit a, submit b){return a.t < b.t;});
	rep(i, 0, sz(tab)){
		tab[i].kto = mapa[tab[i].kto];
		sub[tab[i].kto].pb({tab[i].t, tab[i].p});
	}
	LL maxi = 0;
	for (auto [who, tt, p]: tab){
		points[who] += (LL)p;
		if (points[who] > maxi && !v.empty() && v.back().st == tt) v.pop_back();
		if (points[who] > maxi) {
			maxi = points[who];
			v.pb({tt, maxi});
		}
	}
	if (!v.empty()) v.pb({t+1, v.back().nd});
	//debug(v);
	int ans = 1;
	maxi = 0;
	//debug(scaler);
	for (auto x: scaler){
		LL X = binsearch(mapa[x]);
		//debug(x, X);
		if (X > maxi){
			maxi = X;
			ans = x;
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
