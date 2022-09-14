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

const int MAX = 1007;
vi graf[MAX], G[MAX], numer[MAX];
int in[MAX], out[MAX], cnt[MAX], edgecount[MAX];
bool vis[MAX];
int nr;


void dfs(int v){
	vis[v] = 1;
	numer[nr].pb(v);
	for (auto x: G[v]){
		if (!vis[x]){
			dfs(x);
		}
	}
}

vi eulerian(int currnr){
	stack<int>s;
	assert(!numer[currnr].empty());
	int curr = numer[currnr][0];
	for (auto v: numer[currnr]){
		if (in[v] < out[v]){
			curr = v;
			break;
		}
	}
	//debug(currnr, curr);
	vi ans;
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
	return ans;
}

void solve(){
	int n; cin >> n;
	rep(i, 0, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		G[a].pb(b);
		G[b].pb(a);
		cnt[a]++; cnt[b]++;
		in[b]++; out[a]++;
	}
	rep(i, 1, MAX){
		if (!cnt[i]) continue;
		if (!vis[i]){
			nr++;
			dfs(i);
		}
	}
	vi ans;
	rep(i, 1, MAX) edgecount[i] = sz(graf[i]);
	rep(i, 1, nr+1){
		stack<int>ain, aout;
		//debug(numer[i]);
		for (auto v: numer[i]){
			if (in[v] == out[v]) continue;
			else if (in[v] > out[v]) rep(j, 0, in[v]-out[v]) ain.push(v);
			else rep(j, 0, out[v]-in[v]) aout.push(v);
		}
		while (sz(ain)>1){
			int v = ain.top();
			int x = aout.top();
			ain.pop(); aout.pop();
			//debug(v, x);
			graf[v].pb(x);
			in[x]++;
			out[v]++;
			edgecount[v]++;
		}
		vi curr = eulerian(i);
		reverse(all(curr));
		ans.insert(ans.end(), all(curr));
	}
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
