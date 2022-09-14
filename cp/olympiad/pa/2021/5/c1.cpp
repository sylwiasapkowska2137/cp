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

const int MAX = 1e5+7;
string before, after;
vi graf[MAX];

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

void dfs(int v, int pa = -1){
	for (auto x: graf[v]) if (x!=pa) dfs(x, v);
	if (before[v]!=after[v]){
		for (auto x: graf[v]){
			if (before[x] == after[v]) {
				before[v] = before[x];
				break;
			}
		}
	}
}

void solve(){
	int n; cin >> n;
	rep(i, 0, n+1) graf[i].clear();
	cin >> before >> after;
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		a--;b--;
		graf[b].pb(a);
		graf[a].pb(b);
	}
	dfs(0);
	if (before == after) cout << "TAK\n";
	else cout << "NIE\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
