//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

const int MAX = 1e5+7, K = 20;
int up[MAX][K];
vi graf[MAX], in, out, order, values, depth;
int czas, n;

struct segtree{
	int size = 1;
	vll tab;
	
	void init(int N, bool Out){
		while (size < N) size*=2;
		tab.assign(2*size+1, 0);
		if (Out){
			rep(i, 1, n+1){
				tab[size+out[i]] = values[i];
			}
		} else {
			
			rep(i, 1, n+1){
				tab[size+in[i]] = values[i];
			}
			
		}
		repd(i, size-1, 1) tab[i] = tab[2*i]+tab[2*i+1];
	}
	
	void update(int p, LL val){
		p+=size;
		tab[p] = val;
		while (p>1){
			p/=2;
			tab[p] = tab[2*p]+tab[2*p+1];
		}
	}
	
	LL query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL ans = 0LL;
		while (r-l>1){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
			l/=2;r/=2;
		}
		return ans;
	}
	
} IN, OUT;


void dfs(int v, int pa = 1){
	in[v] = ++czas;
	up[v][0] = pa;
	rep(i, 1, K) up[v][i] = up[up[v][i-1]][i-1];
	order.pb(v);
	for (auto x: graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	}
	order.pb(v);
	out[v] = ++czas;
}

int lca(int a, int b){
	if (depth[a] > depth[b]) swap(a, b);
	repd(i, K-1, 0){
		if (depth[b]-(1<<i)>=depth[a]){
			b = up[b][i];
		}
	}
	if (a == b) return a;
	repd(i, K-1, 0){
		if (up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}

LL path(int x){
	return abs(IN.query(in[x]+1, IN.size-1)-OUT.query(in[x]+1, OUT.size-1));
}

void solve(){
	int q; cin >> n >> q;
	values.resize(n+1);
	depth.assign(n+1, 0);
	rep(i, 1, n+1) {
		cin >> values[i];
		values[i] = abs(values[i]);
	}
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	in.assign(n+1, 0);
	out.assign(n+1, 0);
	dfs(1);
	IN.init(sz(order), 0);
	OUT.init(sz(order), 1);
	while (q--){
		int type; cin >> type;
		if (type == 1){
			int v; LL c; cin >> v >> c;
			c = abs(c);
			values[v] = c;
			IN.update(in[v], c);
			OUT.update(out[v], c);
		} else {
			int a, b; cin >> a >> b;
			int L = lca(a, b);
			LL ans = (path(a)+path(b)-2*path(L)+values[L])*2-values[a]-values[b];
			cout << ans << "\n";
		}
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
