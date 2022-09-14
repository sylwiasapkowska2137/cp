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

const LL INF = 1e18;
const int MAX = 1e6+7;
vpii sub[MAX];

void solve(){
	int n, m, t; cin >> n >> m >> t;
	vector<submit>tab(m);
	rep(i, 0, m){
		cin >> tab[i].kto >> tab[i].t >> tab[i].p;
		if (tab[i].p == 0) {
			tab.pop_back();
			continue;
		}
		sub[tab[i].kto].pb({tab[i].t, tab[i].p});
	}
	sort(all(tab), [](submit a, submit b){return a.t < b.t;});
	for (auto [kto, t, p]:tab){
		debug(kto, t, p);
	}
	LL maxi = 0LL;
	vi curr(n+1, 0);
	set<pll>points;
	points.insert({0, 0});
	for (auto [kto, t, p]:tab){
		curr[kto]+=p;
		if (curr[kto]>maxi){
			maxi = curr[kto];
			points.insert({t, maxi});
		}
	}
	debug(points);
	vi ans(n+1, 0);
	rep(kto, 1, n+1){
		//if (kto != 2) continue;
		sort(all(sub[kto]));
		set<pll>currpoints;
		LL last = 0;
		currpoints.insert({0, 0});
		for (auto [czas, p]:sub[kto]){
			last += (LL)p;
			currpoints.insert({czas, last});
		}
		debug(kto, currpoints);
		//continue;
		for (auto [czas, p]:sub[kto]){
			LL L = czas;
			LL R = t;
			LL currans = -1;
			while (R>=L){
				LL m = (L+R)/2;
				auto it = points.ub({m, -1}); it--;
				auto it2 = currpoints.ub({m, -1}); it2--;
				//debug(m, it->nd, it2->nd);
				if (it->nd <= it2->nd){
					currans = m;
					L = m+1;
				} else R = m-1;
			}
			if (currans == -1) continue;
			debug(czas, currans);
			auto it = points.ub({currans, -1});
			it--;
			auto it2 = currpoints.lb({czas, -1});
			debug(it->nd, it2->nd);
			if (it->nd <= it2->nd) ans[kto] += (currans-czas+1);
		}
	}
	debug(ans);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
