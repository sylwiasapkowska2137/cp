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

const int MAX = 1e6+7;
vi graf[MAX];

void solve(){
	int n; cin >> n;
	
	bool ok = 1;
	vector<pair<char, int>>tab;
	rep(i, 0, n){
		char type; cin >> type;
		int x; cin >> x;
		tab.emplace_back(type, x);
		if (type == 'W') ok = 0;
	}
	if (ok){
		int cnt1 = 1, cnt2 = 1;
		vi color(n+5, 0);
		color[2] = 1;
		int k = 2;
		for (auto [type, x]:tab){
			if (type == '?') {
				if (color[x]) cout << cnt2 << "\n";
				else cout << cnt1 << "\n";
				continue;
			} 
			k++;
			if (type == 'Z'){
				color[k] = color[x];
				if (color[k]) cnt1++;
				else cnt2++;
			}
		}
		return;
	}
	
	int k = 2;
	graf[1].pb(2);
	graf[2].pb(1);
	for (auto [type, x]:tab){
		if (type == '?') {
			cout << sz(graf[x]) << "\n";
			continue;
		} 
		k++;
		if (type == 'Z'){
			for (auto v: graf[x]){
				graf[v].pb(k);
				graf[k].pb(v);
			}
		}
		if (type == 'W'){
			graf[k].pb(x);
			graf[x].pb(k);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
