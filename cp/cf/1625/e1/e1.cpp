/*
	Author: sysia
	14.01.2022 20:07:59
*/

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

const int MAX = 3e5+7;
vi graf[MAX];

LL pairs(LL x){
	return x*(x+1)/2;
}

#define lsb(x) x&(-x)

struct fenwick{
	vll tab;
	int size = 1;
	
	void init(int n){
		size = n+1;
		tab.assign(n+2, 0);
	}
	
	void update(int x, LL val){
		for (int i = x+1; i<=size; i += lsb(i)) tab[i-1]+=val;
	}
	
	LL query(int x){
		LL ans = 0LL;
		for (int i = x; i>0; i -= lsb(i)) ans += tab[i-1];
		return ans;
	}
	
	LL query(int l, int r) {
		return query(r)-query(l);
	}
	
};

void solve(){
	int n, q; cin >> n >> q;
	string s; cin >> s;
	int open = 0;
	vector<vi>level(n);
	vi bracket(n), deg(n, 0), parent(n, -1);
	stack<int>S;
	fenwick fen;
	fen.init(n);
	rep(R, 0, n){
		if (s[R] == '('){
			S.push(R);
			open++;
		} else if (!S.empty()) {
			int L = S.top(); S.pop();
			bracket[L] = R;
			bracket[R] = L;
			level[--open].pb(L);
			if (!S.empty()) parent[L] = S.top();
			deg[L] = ub(all(level[open+1]), R)-lb(all(level[open+1]), L);
			fen.update(L, pairs(deg[L]));
		}
	}
	rep(i, 0, n) debug(deg[i]);
	cerr << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
