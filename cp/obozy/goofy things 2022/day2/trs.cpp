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
	//for (auto x: val) debug(x);
	
	int tmp = 2000000;
	int ans = INF;
	srand(2137);
	while (tmp--){
		random_shuffle(all(val));
		int curr = 0, ans2 = 0, sz = 0;
		rep(i, 0, sz(val)){
			curr += val[i];
			sz++;
			if (curr == 0){
				ans2 += sz-1;
				sz = 0;
			}
		}
		ans = min(ans, ans2);
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
