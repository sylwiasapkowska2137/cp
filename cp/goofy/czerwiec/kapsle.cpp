#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int MAX = 1e6+7;
const LL MOD = 1e9+7;
LL silnia[MAX];
int x[] = {1,1,-1,-1,2,2,-2,-2};
int y[] = {2,-2, 2, -2, 1,-1, 1, -1};
vector<int>graf[MAX];
vector<bool>vis;
int cnt;

void dfs(int v){
	//debug(v);
	vis[v] = 1;
	cnt++;
	for (auto x: graf[v]){
		if (!vis[x]) dfs(x); 
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<pii>a(k);
	vis.assign(k+1, 0);
	set<pair<pii, int>>s;
	silnia[0] = silnia[1] = 1;
	for (int i = 2; i<=k; i++){
		silnia[i] = ((silnia[i-1]*i)%MOD+MOD)%MOD;
	}
	
	for (int i = 0; i<k; i++) {
		cin >> a[i].st >> a[i].nd;
		s.insert({a[i], i});
	}
	for (int i = 0; i<k; i++){
		for (int j = 0; j<8; j++){
			pii sasiad = {a[i].st+x[j], a[i].nd+y[j]};
			auto it = s.lower_bound({sasiad, 0});
			if (it!=s.end()){
				if (it->st.st == sasiad.st && it->st.nd == sasiad.nd){
					graf[i].pb(it->nd);
					//graf[it->nd].pb(i);
				}
			}
		}
	}
	LL ans = 1;
	for (int i = 0; i<k; i++){
		if (!vis[i]) {
			cnt = 0; 
			dfs(i);
			//debug(cnt);
			ans = ((ans*silnia[cnt])%MOD+MOD)%MOD;
			//cerr << "\n";
		}
		//debug(i);
		//for (auto x: graf[i]) debug(x);
		//cerr << "\n";
	}
	cout << ans << "\n";
	return 0;
}


