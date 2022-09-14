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
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x, val) memset(x, val, sizeof(x))
#define PI 3.14159265359

int p(int a, int b){
	return a+rng()%(b-a+1);
}

const int MAX = 5e5+7;
vi graf[MAX], big, tab, depth, parent;
int cnt, tmp;

void dfs__(int v, int prev, int pa = -1){
	if (big[v]){
		if (prev != v){
			tab.pb(depth[v]-depth[prev]-1);
			prev = v;
		}
	}
	if (sz(graf[v]) == 1){
		tab.pb(depth[v]-depth[prev]);
	}
	for (auto x: graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			dfs__(x, prev, v);
		}
	}
}

void DFS(int v, int pa = -1){
	for (auto x:graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			DFS(x, v);
		}
	}
}

void dfs(int v, int pa){
	parent[v] = pa;
	cnt += big[v];
	for (auto x: graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			tmp = max(tmp, depth[x]);
			dfs(x, v);
		}
	}
}

void dfs2(int v, int nie1, int nie2 = -1){
	tmp = max(tmp, depth[v]);
	for (auto x: graf[v]){
		if (x!=nie1 && x != nie2){
			depth[x] = depth[v]+1;
			dfs2(x, v);
		}
	}
}

void solve(){
	int n, k; cin >> n >> k;
	big.assign(n+1, 0);
	rep(i, 0, k) {
		int x; cin >> x;
		big[x] = 1;
	}
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	int L = 0;
	rep(i, 1, n+1) if (sz(graf[i]) == 1) L++;
	//debug(L);
	
	if (L == 2){
		rep(i, 1, n+1){
			if (sz(graf[i]) == 1){
				graf[0].pb(i);
				graf[i].pb(0);
				depth.assign(n+1, 0);
				big[0] = 1;
				dfs__(0, 0);
				sort(all(tab));
				reverse(all(tab));
				//debug(tab);
				int ans = 0;
				rep(i, 0, k) ans+=tab[i];
				cout << 2*(n-k)-ans << "\n";
				return;
			}
		}
	}
	
	
	if (k == 1){
		rep(i, 1, n+1){
			if (big[i]){
				depth.assign(n+1, 0);
				DFS(i);
			}
		}
		int ans = 0;
		rep(i, 1, n+1) ans = max(ans, depth[i]);
		cout << 2*(n-1)-ans << "\n";
		return;
	} 
	
	
	if (k == 2){
		rep(i, 1, n+1){
			vi tab;
			int v = 2, V = 2;
			int maxi = 0, maxi2 = 0;
			if (big[i]){
				for (auto x: graf[i]){
					cnt = 0;
					parent.assign(n+1, 0);
					depth.assign(n+1, 0);
					dfs(x, i);
					if (cnt){
						rep(j, i+1, n+1) if (big[j]) v = j;
						V = v;
						while (v != i){
							tab.pb(v);
							v = parent[v];
						}
						tab.pb(v);
						reverse(all(tab));
					} else {
						maxi = max(maxi, tmp+1);
					}
					tmp = 0;
				}
				
				for (auto x: graf[V]){
					if (x!=tab[sz(tab)-2]){
						dfs(x, V);
						maxi2 = max(maxi2, tmp+1);
						tmp = 0;
					}
				}
				//debug(i, V, tab, maxi, maxi2);
				depth[i] = depth[V] = 0;
				int ans = 0;
				tmp = 0;
				vi curr1(sz(tab)), curr2(sz(tab));
				rep(i, 1, sz(tab)-1){
					depth[tab[i]] = depth[tab[i-1]]+1;
					//depth[tab[i]] = 0;
					dfs2(tab[i], tab[i-1], tab[i+1]);
					curr1[i] = tmp;
					tmp = 0;
				}
				//debug(depth);
				repd(i, sz(tab)-2, 1){
					depth[tab[i]] = depth[tab[i+1]]+1;
					//depth[tab[i]] = 0;
					dfs2(tab[i], tab[i-1], tab[i+1]);
					curr2[i] = tmp;
					tmp = 0;
				}
				//debug(curr1);
				//debug(curr2);
				rep(i, 1, sz(tab)-1){
					ans = max(ans, max(maxi, curr1[i])+max(maxi2, curr2[i]));
				}
				cout << 2*(n-k)-ans << "\n";
				return;
			}
		}
		return;
	}
	int x = p(1, n);
	cout << 2*(n-k)-x << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
