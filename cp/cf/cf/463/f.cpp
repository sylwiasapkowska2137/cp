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

const int MAX = 1e5+7;
const LL INF = 1e18;
int a[MAX], b[MAX], sz[MAX];
vi graf[MAX];
LL ans[MAX];

struct Line{
	LL a, b; 
	Line(LL a = 0LL, LL b = INF): a(a), b(b) {}
	LL operator()(LL x) {return a*x+b;}
};

struct Node{
	Line f;
	Node *left = NULL, *right = NULL;
	Node (Line x): f(x) {}
	Node (){}
};

Node *rt[MAX];

LL query(Node *v, int lx, int rx, LL x){
	int m = (lx+rx)/2;
	LL res = v->f(x);
	if (lx == rx) return res;
	if (x <= m){
		if (v->left) return min(res, query(v->left, lx, m, x));
		else return res;
	}
	if (v->right) return min(res, query(v->right, m+1, rx, x));
	return res;
}


void insert(Node *v, int lx, int rx, Line F){
	if (lx == rx){
		LL a = v->f(lx);
		LL b = F(lx);
		v->f = min(a, b);
		return;
	}
	int m = (lx+rx)/2;
	if (v->left == NULL) v->left = new Node();
	if (v->right == NULL) v->right = new Node();
	
	bool le = (F(lx) < v->f(lx));
	bool me = (F(m+1) < v->f(m+1));
	if (me) swap(v->f, F);
	if (le != me) insert(v->left, lx, m, F);
	else insert(v->right, m+1, rx, F);
}

vector<Line>al[MAX];

void dfs(int v, int pa = -1){
	sz[v] = 1;
	int ch = 0;
	for (auto x: graf[v]){
		if (x != pa){
			dfs(x, v);
			sz[v] += sz[x];
			if (sz[ch] < sz[x]) ch = x;
		} 
	}
	if (ch) rt[v] = rt[ch], swap(al[v], al[ch]);
	else rt[v] = new Node();
	
	for (auto x: graf[v]){
		if (x == ch || x == pa) continue;
		for (auto para: al[x]) insert(rt[v], -MAX, MAX, para);
		for (auto ln: al[x]) al[v].pb(ln);
	}
	if (ch) query(rt[v], -MAX, MAX, a[v]);
	else ans[v] = 0LL;
	
	al[v].pb(Line{b[v], ans[v]});
	insert(rt[v], -MAX, MAX, Line{b[v], ans[v]});
}

void solve(){
	int n; cin >> n;
	
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n+1) cin >> b[i];
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	
	dfs(1);
	rep(i, 1, n+1) cout << ans[i] << " ";
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
