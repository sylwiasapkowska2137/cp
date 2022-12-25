#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

vector<pii>trie;
vector<int>cnt;

void dfs(int v, int val = 0){
	if (trie[v].st) dfs(trie[v].st, val*2);
	if (trie[v].nd) dfs(trie[v].nd, val*2+1);
	cnt[v] = val;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q, a, b;
	cin >> n;
	trie.resize(n+1);
	cnt.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		cin >> trie[i].st >> trie[i].nd;
	}
	dfs(1);
	//for (int i = 1; i<=n; i++) debug(cnt[i]);
	cin >> q;
	while(q--){
		cin >> a >> b;
		if (cnt[a]>=cnt[b]) cout << "TAK\n";
		else cout << "NIE\n";
	}
	return 0;
}