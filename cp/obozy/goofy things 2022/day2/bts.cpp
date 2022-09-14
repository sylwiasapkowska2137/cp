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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p(int a, int b){
	return a+rng()%(b-a+1);
}

const int MAX = 5e5+7, M = 22, INF = 1e9+7;
vi graf[MAX], color;
vb vis;
int cnt[2];

void dfs(int v){
	vis[v] = 1;
	if ((v&1) != (color[v]&1)) cnt[v&1]++;
	for (auto x: graf[v]){
		if (!vis[x]){
			dfs(x);
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	color.resize(n+1);
	rep(i, 1, n+1) cin >> color[i];
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	vis.assign(n+1, 0);
	vi val;
	rep(i, 1, n+1){
		if (!vis[i]){
			cnt[0] = cnt[1] = 0;
			dfs(i);
			if (cnt[0] != cnt[1]){
				val.pb(cnt[0]-cnt[1]);
			}
		}
	}
	if (sz(val) > 23){
		cout << sz(val)/2 << "\n";
		return;
	}
	int N = sz(val);
	vll dp((1<<(N)+1), 0);
	rep(mask, 0, (1<<N)){
		int s = 0;
		rep(i, 0, N) if (mask&(1<<i)) s += val[i];
		rep(i, 0, N) {
			if (!(mask&(1<<i))) {
				if (s + val[i] == 0) dp[mask|(1<<i)] = max(dp[mask|(1<<i)], dp[mask]+1);
				else dp[mask|(1<<i)] = max(dp[mask|(1<<i)], dp[mask]);
			}
		}
	}
	cout << N-dp[(1<<N)-1] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
