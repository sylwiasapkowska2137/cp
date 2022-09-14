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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

struct Node{
	int lx, rx;
	LL val = 0, lazy = 0;
	Node *left, *right;
};

Node *T;

LL modify(LL a, LL b){
	return (b == LLONG_MAX) ? a : b;
}

Node *create(int l, int r){
	Node *nowy = new Node;
	nowy->val = nowy->lazy = 0;
	nowy->left = NULL;
	nowy->right = NULL;
	nowy->lx = l;
	nowy->rx = r;
	return nowy;
}

void push(Node *x){
	if (x->lx == x->rx) return;
	int m = (x->lx + x->rx)/2;
	if (x->left == NULL) x->left = create(x->lx, m);
	if (x->right == NULL) x->right = create(m+1, x->rx);
	x->left->val = modify(x->left->val, x->lazy);
	x->right->val = modify(x->right->val, x->lazy);
	x->left->lazy = modify(x->left->lazy, x->lazy);
	x->right->lazy = modify(x->right->lazy, x->lazy);
	x->lazy = LLONG_MAX;
}

LL query(Node *x, int l, int r){
	
	if (x->lx > r || x->rx < l) return LLONG_MIN;
	if (x->lx >= l && x->rx <= r) return x->val;
	push(x);
	return max(query(x->left, l, r), query(x->right, l, r));
}

void assign(Node* x, int l, int r, LL val){
	
	if (x->lx > r || x->rx < l) return;
	if (x->lx >= l && x->rx <= r) {
		x->val = modify(x->val, val);
		x->lazy = modify(x->lazy, val);
		return;
	}
	push(x);
	assign(x->left, l, r, val);
	assign(x->right, l, r, val);
	x->val = max(x->left->val, x->right->val);
}

void solve(){
	int D, n; cin >> D >> n;
	T = create(0, D);
	rep(i, 0, n){
		int l, r, d; cin >> l >> r >> d;
		LL x = query(T, l+1, r);
		assign(T, l+1, r, x+(LL)d);
	}
	cout << query(T, 0, D) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
