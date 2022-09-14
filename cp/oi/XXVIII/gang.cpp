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
#define PI 3.14159265359

const int MAX = 1e5+7, SS = 400;
vi graf[MAX], curr[MAX], depth, nr, val, ans, cnt, pre, post;
int diff, CZAS;

struct Update{
	int i, a, b;
};

struct Query{
	int i, x;
};

vector<Query> query[SS];
vector<Update> update[SS];
vb done;

void __dfs(int v, int pa = 1){
	pre[v] = ++CZAS;
	for (auto x: graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			__dfs(x, v);
		}
	}
	post[v] = ++CZAS;
}

struct EDGE{
	int a, b, c, i; 
};
vector<EDGE>edge;
bool subtree(int v, int x){
	return (pre[v]<=pre[x] && post[v]>=post[x]);
}

void add(int c){
	cnt[c]++;
	if (cnt[c] == 1) diff++;
}

void remove(int c){
	cnt[c]--;
	if (cnt[c] == 0) diff--;
}

void dfs(int v, int pa, int i){
	add(val[v]);
	for (auto Q: curr[v]){
		/*
		debug(v);
		debug("answering query");
		debug(Q);
		cerr << "\n";
		*/
		int prev = diff;
		map<int, int>undo;
		for (auto [czas, idx, c]: update[i]){
			/*
			cerr << "zmiana w ";
			debug(nr[idx]);
			cerr << " dla ";
			debug(v);
			*/
			if (czas < Q && subtree(nr[idx], v)){
				//debug("Y");
				remove(val[nr[idx]]);
				if (undo.find(nr[idx]) == undo.end()) undo[nr[idx]] = val[nr[idx]];
				val[nr[idx]] = c;
				add(c);
			} 
			//cerr << "\n";
		}
		//rep(i, 1, sz(cnt)) debug(cnt[i]);
		//cerr << "\n";
		ans[Q] = diff;
		for (auto x: undo){
			remove(val[x.st]);
			val[x.st] = x.nd;
			add(x.nd);
		}
		diff = prev;
		//rep(i, 1, sz(cnt)) debug(cnt[i]);
		//cerr << "\n";
	}
	
	for (auto x: graf[v]){
		if (x != pa){
			dfs(x, v, i);
		}
	}
	remove(val[v]);
}

void solve(){
	int n, m, q; cin >> n >> m >> q;
	edge.resize(n-1);
	depth.assign(n+1, 0);
	nr.assign(n+1, 0);
	pre.assign(n+1, 0);
	post.assign(n+1, 0);
	val.assign(n+1, 0);
	rep(i, 0, n-1){
		int a, b, c; cin >> a >> b >> c;
		graf[a].pb(b);
		graf[b].pb(a);
		edge[i] = {a, b, c, i};
	}
	__dfs(1);
	
	for (auto [a, b, c, i]: edge){
		if (depth[a] > depth[b]){
			val[a] = c;
			nr[i] = a;
		} else {
			val[b] = c;
			nr[i] = b;
		}
	}
	/*
	rep(v, 1, n+1) debug(val[v]);
	cerr << "\n";
	rep(v, 0, n-1) debug(nr[v]);
	cerr << "\n";
	*/
	int S = sqrt(q);
	rep(i, 0, q){
		char type; cin >> type;
		if (type == 'Z'){
			int x; cin >> x;
			query[i/S].pb({i, x});
		} else {
			int idx, c; cin >> idx >> c;
			update[i/S].pb({i, idx-1, c});
		}
	}
	ans.assign(q, -1);
	int i = 0;
	while (1){
		if (query[i].empty() && update[i].empty()) break;
		cnt.assign(m+1, 0);
		done.assign(q+1, 0);
		diff = 0;
		rep(i, 1, n+1) curr[i].clear();
		//debug("queries");
		for (auto [czas, x]: query[i]){
			curr[x].pb(czas);
			//debug(czas);
		}
		//cerr << "\n";
		dfs(1, -1, i);
		//debug("updates");
		for (auto [czas, idx, c]: update[i]){
			val[nr[idx]] = c;
			//debug(czas);
		}
		/*
		cerr << "\n";
		
		rep(v, 1, n+1) debug(val[v]);
		cerr << "\n";
		rep(i, 0, q) debug(ans[i]-1);
		cerr << "\n\n";
		*/
		i++;
	}
	rep(i, 0, q) {
		if (ans[i] == -1) continue;
		cout << ans[i]-1 << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
