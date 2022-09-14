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

const int MAX = 2e6+7, S = 316;
int cnt[MAX];
int k;
LL curr;

struct Query{
	int l, r, i;
};

bool cmp(Query a, Query b){
	if (a.l/S == b.l/S) return a.r < b.r;
	return a.l/S < b.l/S;
}

void add(int num){
	curr += (LL)cnt[num^k];
	cnt[num]++;
}

void remove(int num){
	cnt[num]--;
	curr -= (LL)cnt[num^k];
}

void solve(){
	int n, q; cin >> n >> q >> k;
	cnt[0] = 1;
	vi a(n+1), pref(n+1, 0);
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n+1) pref[i] = pref[i-1]^a[i];
	vector<Query>Q(q);
	rep(i, 0, q){
		cin >> Q[i].l >> Q[i].r;
		Q[i].l--;//Q[i].r++;
		Q[i].i = i;
	}
	vll ans(q);
	sort(all(Q), cmp);
	int L = 0, R = 0;
	for (auto x: Q){
		while (L > x.l){
			L--;
			add(pref[L]);
		}
		while (L < x.l){
			remove(pref[L]);
			L++;
		}
		while (R > x.r){
			remove(pref[R]);
			R--;
		}
		while (R < x.r){
			R++;
			add(pref[R]);
		}
		ans[x.i] = curr;
	}
	rep(i, 0, q) cout << ans[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
