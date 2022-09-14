#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int>pii;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef vector<bool> vb;

#define debug(x) cerr << x << " "
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)
#define pb push_back

const int MAX = 5e5+7;
vi graf[MAX], depth[2];
vb vis;
int k;

void dfs(int v, int k, int pa = -1){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (x!=pa){
			depth[k][x] = depth[k][v]+1;
			dfs(x, k, v);
		}
	}
}

vpii ans;
int N;

void check(){
	vpii curr;
	rep(i, 1, N+1){
		for (auto x: graf[i]){
			if (i < x) curr.pb({i, x});
		}
	}
	sort(all(curr));
	if (ans.empty()){
		ans = curr;
	} else {
		rep(i, 0, sz(ans)){
			if (ans[i] > curr[i]){
				curr = ans;
				return;
			}
		}
	}
}

void backtrack(vi tab, int n){
	if (n == N+1){
		//for (auto x: tab) debug(x);
		//cerr << "\n";
		rep(i, 1, N+2) graf[i].clear();
		rep(i, 1, sz(tab)){
			graf[i+1].pb(tab[i]);
			graf[tab[i]].pb(i+1);
		}
		depth[0].assign(N+1, 0);
		vis.assign(N+1, 0);
		dfs(1, 0);
		rep(i, 1, N+1) {
			if (!vis[i]){
				return;
			}
		}
		int maxi = *max_element(all(depth[0]));
		depth[1].assign(N+1, 0);
		rep(i, 1, N+1){
			if (depth[0][i] == maxi){
				dfs(i, 1);
				break;
			}
		}
		maxi = *max_element(all(depth[1]));
		if (maxi == k){
			check();
		}
		return;
	}
	rep(i, 1, n){
		tab.pb(i);
		backtrack(tab, n+1);
		tab.pop_back();
	}
}

void solve(){
	cin >> N >> k;
	backtrack({0}, 2);
	if (ans.empty()){
		cout << "-1\n";
	}
	for (auto x: ans){
		cout << x.st << " " << x.nd << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
