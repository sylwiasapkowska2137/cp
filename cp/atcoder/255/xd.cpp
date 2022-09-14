//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
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

#define int long long
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353, I = 499122177;

struct mint{
	int x;
	mint():x(0){}
	mint(int _x): x(((_x%mod)+mod)%mod) {}
	mint &fix() {x = ((x%mod)+mod)%mod; return *this;}
	mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
	mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
	mint& operator*=(const mint& a){ (x*=(a.x%mod))%=mod; return *this;}
	mint& operator/=(const mint& a){ (x*=a.power(mod-2).x)%=mod; return *this;}
	mint operator+(const mint& a)const{ return mint(*this) += a;}
	mint operator-(const mint& a)const{ return mint(*this) -= a;}
	mint operator*(const mint& a)const{ return mint(*this) *= a;}
	mint operator/(const mint& a)const{ return mint(*this) /= a;}
	mint power(int t) const {
		if(!t) return 1;
		mint res = power(t/2);
		res *= res;
		return (t&1) ? res * x : res;
	}
	bool operator<(const mint& a)const{ return x < a.x;}
	bool operator==(const mint& a)const{ return x == a.x;}
	bool operator!=(const mint& a)const{ return x != a.x;}
};

istream& operator>>(istream &i,mint &a){ i >> a.x; return i;}
ostream& operator<<(ostream &o,const mint &a){o << a.x % mod; return o;}

struct Node{
	int L, R;
	mint mn = 0, mx = 0, lazy = -1;
	Node *left = NULL, *right = NULL;
};

Node *T;

Node *create(int l, int r){
	Node *nowy = new Node;
	nowy->L = l; nowy->R = r;
	return nowy;
}

mint sum(mint L, mint R){
	mint a = L*(L-1)/2;
	mint b = R*(R+1)/2;
	return b-a;
}

void push(Node *x){
	if (x->L == x->R) return;
	int m = (x->L + x->R)/2;
	if (x->left == NULL) x->left = create(x->L, m);
	if (x->right == NULL) x->right = create(m+1, x->R);
	if (x->lazy != -1) {
		x->left->mn = x->right->mn = x->lazy;
		x->left->mx = x->right->mx = x->lazy;
		x->left->lazy = x->right->lazy = x->lazy;
		x->lazy = -1;
	}
}

void update(Node *x, int l, int r, mint v){
	if (x->L > r || x->R < l) return;
	if (x->L >= l && x->R <= r){
		x->mn = x->mx = x->lazy = v;
		return;
	} 
	push(x);
	update(x->left, l, r, v);
	update(x->right, l, r, v);
	x->mn = min(x->left->mn, x->right->mn);
	x->mx = max(x->left->mx, x->right->mx);
}

mint query(Node *x, int l, int r){
	if (x->L > r || x->R < l) return 0;
	if (x->L >= l && x->R <= r && x->mn == x->mx) return x->mn * sum(x->L, x->R);
	push(x);
	return query(x->left, l, r) + query(x->right, l, r);
}

void solve(){
	int n, q; cin >> n >> q;
	T = create(0, oo);
	for (int i = 0; i<q; i++){
		int l, r; mint d; cin >> d >> l >> r;
		mint ans = sum(l, r) * d;
		ans -= query(T, l, r);
		cout << ans << "\n";
		update(T, l, r, d);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
