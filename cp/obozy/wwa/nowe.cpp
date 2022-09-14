#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 1e5+7;
int graf[MAX];
vector<int> gt[MAX];
int dist[MAX], pre[MAX], post[MAX];
int czas; 
bool deleted[MAX];

void dfs(int v){
	pre[v] = czas++;
	for (auto x: gt[v]){
		dist[x] = dist[v]+1;
		dfs(x);
	}
	post[v] = czas++;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, a, b;
	cin >> n >> k;
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		graf[a] = b;
		gt[b].pb(a);
	}
	dfs(1);
	vector<pii>tab;
	for (int i = 1; i<=n; i++) {
		//debug(dist[i]);
		tab.pb({dist[i], i});
	}
	sort(tab.begin(), tab.end());
	reverse(tab.begin(), tab.end());
	//for (auto x: tab){
		//debug(x.st);
		//debug(x.nd);
		//cerr << "\n";
	//}
	int ans = 0;
	for (int i = 0; i<n; i++){
		int v = tab[i].nd;
		if (deleted[v]) continue;
		deleted[v] = 1;
		
		if (tab[i].st <= k) {
			cout << ans << "\n";
			return 0;
		}
		//debug(v);
		bool ok = 0;
		for (int j = 1; j<k; j++){
			if (deleted[graf[v]]){
				ok = 1;
				break;
			}
			v = graf[v];
			//debug("a");
			//debug(v);
			deleted[v] = 1;
		}
		if (!ok) ans++;
		//debug(ans);
		//cerr << "\n";
		//for (int i = 1; i<=n; i++) debug(deleted[i]);
		//cerr << "\n";
	}
	cout << ans << "\n";
	return 0;
}

