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

const int INF = 1e9+7;

struct Node{
	int ile = 0;
	LL sum = 0LL;
	Node *left = NULL, *right = NULL; 
};

Node *T;


void update(Node *x, int lx, int rx, int pos, int add){
	if (lx == rx){
		x->ile+=add;
		x->sum += (lx*add);
		return;
	}
	int m = (lx+rx)/2;
	if (x->left == NULL) x->left = new Node;
	if (x->right == NULL) x->right = new Node;
	if (pos <= m) update(x->left, lx, m, pos, add);
	else update(x->right, m+1, rx, pos, add);
	x->sum = x->left->sum + x->right->sum;
	x->ile = x->left->ile + x->right->ile;
}

pll query(Node *x, int lx, int rx, int l, int r){
	if (lx > r || rx < l) return {0LL, 0LL};
	if (lx >= l && rx <= r) return {x->sum, x->ile};
	int m = (lx + rx)/2;
	if (x->left == NULL) x->left = new Node;
	if (x->right == NULL) x->right = new Node;
	pll a = query(x->left, lx, m, l, r);
	pll b = query(x->right, m+1, rx, l, r);
	return {a.st+b.st, a.nd+b.nd};
}

void solve(){
	int n, m; cin >> n >> m;
	//T = create(0, INF);
	T = new Node;
	vi curr(n+1, 0);
	while (m--){
		char type; cin >> type;
		if (type == 'U'){
			int nr, val; cin >> nr >> val;
			if (curr[nr]!=0) update(T, 0, INF, curr[nr], -1);
			update(T, 0, INF, val, 1);
			curr[nr] = val;
		} else {
			LL s, c; cin >> s >> c;
			if (query(T, 0, INF, 0, c-1).st+query(T, 0, INF, c, INF).nd*c>=s*c) cout << "TAK\n";
			else cout << "NIE\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
