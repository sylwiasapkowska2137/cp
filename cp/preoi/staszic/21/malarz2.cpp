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

struct Node{
	int lx, rx, val;
	bool lazy = 0;
	Node *left, *right;
};

Node *T;

void inv(Node *x){
	x->val = x->rx-x->lx+1-x->val;
}

Node *create(int l, int r){
	Node *nowy = new Node;
	nowy->val = r-l+1;
	nowy->lx = l;
	nowy->rx = r;
	nowy->lazy = 0;
	nowy->left = NULL;
	nowy->right = NULL;
	return nowy;
}

void push(Node *x){
	int m = (x->rx + x->lx)/2;
	x->lazy = 0;
	if (x->left == NULL) x->left = create(x->lx, m);
    if (x->right == NULL) x->right = create(m+1, x->rx);

    x->left->lazy = !x->left->lazy, x->right->lazy = !x->right->lazy;
    inv(x->left), inv(x->right);
}

void update(Node *x, int l, int r){
	if (x->lx > r || x->rx < l) return;
	if (x->lx >= l && x->rx <= r){
		inv(x);
		x->lazy = !x->lazy;
		return;
	}
	if (x->lazy) push(x);
	int m = (x->lx + x->rx)/2;
	if (x->left == NULL) x->left = create(x->lx, m);
	if (x->right == NULL) x->right = create(m+1, x->rx);
	update(x->left, l, r);
	update(x->right, l, r);
	x->val = x->left->val + x->right->val;
}

int query(Node *x, int l, int r){
	if (x->lx > r || x->rx < l) return 0;
	if (x->lx >= l && x->rx <= r) return x->val;
	if (x->lazy) push(x);
	int m = (x->lx + x->rx)/2;
	if (x->left == NULL) x->left = create(x->lx, m);
	if (x->right == NULL) x->right = create(m+1, x->rx);
	return query(x->left, l, r)+query(x->right, l, r);
}

void solve(){
	int n, m; cin >> n >> m;
	T = create(1, n);
	rep(i, 0, m){
		char type; int l, r; 
		cin >> type >> l >> r;
		if (type == '?') cout << query(T, l, r) << "\n";
		else update(T, l, r);
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
