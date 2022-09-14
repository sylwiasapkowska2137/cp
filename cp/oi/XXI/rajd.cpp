#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<bool> vb;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;

#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << x << " "
#define sz(x) (int)(x).size()
#define pb push_back
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)

const int MAX = 5e5+7;
vi graf[MAX], gt[MAX];

struct segtree{
	int size = 1;
	vi tab;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0); 
	}
	
	void update(int l, int r, int val){
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) tab[l+1] = max(tab[l+1], val);
			if (r&1) tab[r-1] = max(tab[r-1], val);
			l/=2;r/=2;
		}
	}
	
	int query(int pos){
		pos += size;
		int ans = 0;
		while (pos > 0){
			ans = max(ans, tab[pos]);
			pos/=2;
		}
		return ans;
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vi in(n+1, 0);
	
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		in[b]++;
		gt[b].pb(a);
	}
	queue<int>q;
	rep(i, 1, n+1) if (!in[i]) q.push(i);
	vi topo;
	while (!q.empty()){
		int v = q.front(); q.pop();
		topo.pb(v);
		for (auto x: graf[v]){
			in[x]--;
			if (!in[x]) q.push(x);
		}
	}
	vi before(n+1, 0), after(n+1, 0), dp(n+1, 0), dp2(n+1, 0);
	reverse(all(topo));
	for (auto v: topo){
		for (auto x: graf[v]) dp[v] = max(dp[v], dp[x]+1);
	}
	reverse(all(topo));
	repd(i, n-2, 0) before[topo[i]] = max(before[topo[i+1]], dp[topo[i+1]]);
	rep(v, 1, n+1){
		for (auto x: graf[v]) before[v] = max(before[v], dp[x]); 
	}
	/*
	rep(i, 1, n+1) debug(before[i]);
	cerr << "\n";
	*/
	for (auto v: topo){
		for (auto x: gt[v]) dp2[v] = max(dp2[v], dp2[x]+1);
	}
	rep(i, 1, n) after[topo[i]] = max(after[topo[i-1]], dp2[topo[i-1]]);
	/*
	rep(i, 1, n+1) debug(after[i]);
	cerr << "\n";
	*/
	vi pos(n+1, 0);
	rep(i, 0, n) pos[topo[i]] = i;
	segtree seg;
	seg.init(n+1);
	rep(v, 1, n+1){
		for (auto x: graf[v]){
			int a = v, b = x;
			if (pos[a] > pos[b]) swap(a, b);
			//a na lewo
			seg.update(pos[a]+1, pos[b]-1, dp2[a]+dp[b]+1);
		}
	}
	vi without(n+1, 0), DP(n+1, 0);
	
	//cerr << "\n";
	rep(i, 1, n+1) without[i] = max(max(before[i], after[i]), seg.query(pos[i]));
	
	/*
	rep(i, 1, n+1) debug(without[i]);
	cerr << "\n";
	*/
	
	rep(i, 1, n+1) DP[i] = dp[i]+dp2[i];
	int diff = -1, v = 1;
	rep(i, 1, n+1){
		if (DP[i]-without[i] > diff){
			diff = DP[i]-without[i];
			v = i;
		}
	}
	cout << v << " " << without[v] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
