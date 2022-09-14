/*
	Author: sysia
	10.01.2022 14:20:27
*/

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

const LL INF = 1e14;
const int MAX = 1e5+5;
vi graf[MAX], sub, a, b;
vll dp;

struct Line{
	LL a, b;
	
	LL operator()(LL x){
		return a*x+b;
	}
};

struct Node{
	Line val;
	Node *left=NULL, *right=NULL;
	
	Node(Line val): val(val) {}
};
 
void insert(int l, int r, Line val, Node *nd) {
	int m = (l+r)/2;
	bool left = nd->val(l) > val(l);
	bool mid = nd->val(m) > val(m);

	if (mid) swap(val, nd->val);

	if (r-l == 1) return;
	else if (left != mid) {
		if (nd->left) insert(l, m, val, nd->left);
		else nd->left = new Node(val);
	} else {
		if (nd->right) insert(m, r, val, nd->right);
		else nd->right = new Node(val);
	}
}

LL query(int l, int r, int x, Node *nd) {
	int m = (l+r)/2;
	if (r-l == 1) return nd->val(x);
	else if (x < m && nd->left) return min(nd->val(x), query(l, m, x, nd->left));
	else if (nd->right) return min(nd->val(x), query(m, r, x, nd->right));
	else return nd->val(x);
}
 
void del(Node* x) {
	if(x->left) del(x->left);
	if(x->right) del(x->right);
	delete x;
}
 
void merge(Node* d, Node* x) {
	if(x->val.b < INF) insert(-MAX, MAX, x->val, d);
	if(x->left) merge(d, x->left);
	if(x->right) merge(d, x->right);
}

void dfssz(int v, int pa = -1){
	for (auto x: graf[v]){
		if (x != pa) {
			dfssz(x, v);
			sub[v]+=sub[x];
		}
	}
	sub[v]++;
}

Node* dfs(int v, int pa = -1){
	int sz = 0, big = -1;
	for (auto x: graf[v]){
		if (x!=pa && sub[x] > sz){
			big = x;
			sz = sub[x];
		}
	}
	Node *root = new Node({0, INF});
	if (big != -1) root = dfs(big, v);
	for (auto x: graf[v]){
		if (x!=pa && x!=big){
			auto son = dfs(x, v);
			merge(root, son);
			del(son);
		}
	}
	if (big != -1) dp[v] = query(-MAX, MAX, a[v], root);
	insert(-MAX, MAX, {b[v], dp[v]}, root);
	sub[v]++;
	return root;
}

void solve(){
	int n; cin >> n;
	a.resize(n+1);
	b.resize(n+1);
	dp.assign(n+1, 0LL);
	sub.assign(n+1, 0);
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n+1) cin >> b[i];
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	dfssz(1);
	dfs(1);
	rep(i, 1, n+1) cout << dp[i] << " ";
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
