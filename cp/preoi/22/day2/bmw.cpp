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

const int MAX = 1002;
vi in(MAX, 0), out(MAX, 0),Left(MAX, 0), numer, cnt(MAX, 0);
vb vis;
vi graf[MAX], G[MAX];
int nr;

void dfs(int v){
	vis[v] = 1;
	numer[v] = nr;
	for (auto x: G[v]){
		if (!vis[x]){
			dfs(x);
		}
	} 
}

vi ans;

void eulerian(int currnr){
	debug(currnr);
	vi edgecount(MAX, 0);
	rep(i, 1, MAX)edgecount[i] = sz(graf[i]);
	
	stack<int>s;
	int curr = 1;
	rep(i, 1, MAX){
		if (numer[i] == currnr){
			curr = i;
			break;
		}
	}
	s.push(curr);
	while (!s.empty()){
		if (edgecount[curr]){
			s.push(curr);
			int nextv = graf[curr].back();
			edgecount[curr]--;
			graf[curr].pop_back();
			curr = nextv;
		} else {
			ans.pb(curr);
			curr = s.top();
			s.pop();
		}
	}
}

void solve(){
	int n; cin >> n;
	set<pii>s;
	rep(i, 0, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		G[a].pb(b);
		G[b].pb(a);
		s.insert({a, b});
		in[b]++;
		out[a]++;
		cnt[a]++;cnt[b]++;
	}
	rep(i, 1, MAX) Left[i] = max(in[i], out[i]);
	int X = accumulate(all(Left), 0);
	
	debug(X);
	vis.assign(MAX, 0);
	numer.assign(MAX, 0);
	rep(i, 0, MAX){
		if (!vis[i] && cnt[i]){
			nr++;
			dfs(i);
		}
	}
	//debug(numer);
	queue<int>addout[MAX], addin[MAX];
	rep(i, 1, MAX){
		if (Left[i] == in[i]){
			rep(j, 0, in[i]-out[i]){
				addin[numer[i]].push(i);
			}
		} else {
			rep(j, 0, out[i]-in[i]){
				addout[numer[i]].push(i);
			}
		}
	}
	rep(i, 0, MAX){
		while (!addin[i].empty()){
			int v = addin[i].front();
			int x = addout[i].front();
			addin[i].pop();addout[i].pop();
			debug(i, v, x);
			graf[v].pb(x);
		}
	}	
	rep(i, 1, nr+1) {
		eulerian(i);
	}
	
	reverse(all(ans));
	cout << sz(ans) << "\n";
	for (auto x: ans) cout << x << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
