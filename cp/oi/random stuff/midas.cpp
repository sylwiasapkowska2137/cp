#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

vector<pii>trie;
vector<int>depth, cnt, ans, r;

void dfs(int v, int lvl = 1){
	depth[v] = lvl;
	if (trie[v].st){
		if (cnt.size() <= lvl) cnt.resize(lvl+1, 0);
		cnt[lvl]++;
		ans[trie[v].st] = cnt[lvl];
		dfs(trie[v].st, lvl+1);
	}
	if (trie[v].nd){
		if (cnt.size() <= lvl) cnt.resize(lvl+1, 0);
		cnt[lvl]++;
		ans[trie[v].nd] = cnt[lvl];
		dfs(trie[v].nd, lvl+1);
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q, a, b;
	cin >> n;
	trie.resize(n+1);
	depth.assign(n+1, 0);
	ans.assign(n+1, 1);
	for (int i = 1; i<=n; i++)	cin >> trie[i].st >> trie[i].nd;
	int v = 1;
	ans[1] = 0;
	while (trie[v].st){
		ans[trie[v].st] = 0;
		r.pb(trie[v].nd);
		v = trie[v].st;
	}
	r.pb(trie[v].nd);
	reverse(r.begin(), r.end());
	//for (auto x: r) debug(x);
	for (auto x: r) {
		dfs(x);
		cnt.clear();
	}
	//cerr << "\n";
	//for (int i = 1; i<=n; i++) debug(depth[i]);
	//cerr << "\n";
	//for (int i = 1; i<=n; i++) debug(ans[i]);
	cin >> q;
	while (q--){
		cin >> a >> b;
		if (depth[a]>depth[b]) cout << "TAK\n";
		else if (depth[a]<depth[b]) cout << "NIE\n";
		else {
			if (ans[a]>=ans[b]) cout << "TAK\n";
			else cout << "NIE\n";
		}
	}
	return 0;
}
