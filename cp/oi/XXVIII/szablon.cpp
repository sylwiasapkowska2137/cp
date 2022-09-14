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

const int MAX = 2003, S = 27;
vector<pair<int, char>>graf[MAX];
string s;
vi depth, cnt;

struct node{
	int syn[S];
	node(){
		rep(i, 0, S) syn[i] = -1;
	}
};

struct p{
	int a, b, lca;
};

struct TRIE{
	vector<node>tab;
	vector<pair<int, char>> parent;
	vector<vector<p>>path;
	int curr = 0;
	
	TRIE(){
		node elem;
		tab.pb(elem);
		parent.pb({-1, 'A'});
	}
	
	void add(string &s){
		int v = 0;
		int n = sz(s);
		rep(i, 0, n){
			if (tab[v].syn[s[i]-'A'] == -1){
				tab[v].syn[s[i]-'A'] = sz(tab);
				node elem;
				parent.pb({v, s[i]});
				tab.pb(elem);
			}
			v = tab[v].syn[s[i]-'A'];
		}
	}
	
	string Find(int pos){
		string s;
		while (pos > 0){
			s += parent[pos].nd;
			pos = parent[pos].st;
		}
		return s;
	}
} trie;

void dfs(int v, int from, int lca, int pa = -1){
	trie.path[trie.curr].pb({v, from, lca});
	for (auto [x, c]: graf[v]){
		if (x != pa){
			int lca2 = lca;
			if (depth[x] < depth[lca]) lca2 = x;
			//debug(trie.curr);
			//debug(trie.tab[trie.curr].syn[c-'A']);
			//cerr << v << "--" << c << "--" << x << "\n";
			if (trie.tab[trie.curr].syn[c-'A'] == -1) continue;
			trie.curr = trie.tab[trie.curr].syn[c-'A'];
			dfs(x, from, lca2, v);
			trie.curr = trie.parent[trie.curr].st;
		}
	}
}

void depth_dfs(int v, int pa = -1){
	for (auto x: graf[v]){
		if (x.st!=pa){
			depth[x.st] = depth[v]+1;
			depth_dfs(x.st, v);
		}
	}
}

void __dfs(int v, int pa = -1){
	for (auto [x, c]: graf[v]){
		if (x == pa) continue;
		s.pb(c);
		trie.add(s);
		//reverse(all(s));
		//trie.add(s);
		//reverse(all(s));
		__dfs(x, v);
		s.pop_back();
	}
}

void dfs2(int v, int pa = -1){
	for (auto x: graf[v]){
		if (x.st!=pa){
			dfs2(x.st, v);
			cnt[v]+=cnt[x.st];
		}
	}
}

void solve(){
	int n; cin >> n;
	//int n = 5;
	depth.assign(n+1, 0);
	rep(i, 1, n){
		int a, b; char c; cin >> a >> b >> c;
		//int a = 1;
		//int b = i+1;
		//char c = 'A';
		//if (i&1) c = 'B';
		graf[a].pb({b, c});
		graf[b].pb({a, c});
	}
	//build trie
	rep(i, 1, n+1){
		if (sz(graf[i]) == 1){
			__dfs(i);
			break;
		}
	}
	depth_dfs(1);
	//rep(i, 1, n+1) debug(depth[i]);
	//cerr << "\n";
	/*
	rep(i, 0, sz(trie.tab)){
		node x = trie.tab[i];
		rep(j, 0, S){
			if (x.syn[j] != -1){
				debug(i);
				debug(x.syn[j]);
				debug(char(j+'A'));
				cerr << "\n";
			}
		}
	}
	*/
	//return;
	trie.path.resize(sz(trie.tab));
	rep(i, 1, n+1){
		trie.curr = 0;
		dfs(i, i, i);
	}
	//return;
	//cerr << "\n";
	set<string>ans;
	rep(i, 1, sz(trie.path)){
		//cerr << i << " " << trie.Find(i) << "\n";
		cnt.assign(n+1, 0);
		for (auto x: trie.path[i]){
			/*
			debug(x.a);
			debug(x.b);
			debug(x.lca);
			cerr << "\n";
			*/
			cnt[x.a]++;
			cnt[x.b]++;
			cnt[x.lca]-=2;
		}
		dfs2(1);
		//rep(i, 1, n+1) debug(cnt[i]);
		//cerr << "\n";
		bool ok = 1;
		rep(j, 2, n+1) ok &= (cnt[j]>0);
		if (ok){
			string s = trie.Find(i);
			ans.insert(s);
			reverse(all(s));
			ans.insert(s);
		}
	}
	cout << sz(ans) << "\n";
	for (auto x: ans) cout << x << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
