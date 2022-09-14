#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second

const int MAX = 1007;
bool vis[MAX][MAX];
int tab[MAX][MAX];
queue<pii>q;
int n, m, x[] = {-1, 1, 0, 0}, y[] = {0, 0, -1, 1};
vector<LL> res;
const LL POT = 57, MOD = 1e9+9;
LL ok, hasz;

void bfs(pii r){
	vis[r.st][r.nd] = 1;
	q.push(r);
	pii s, v;
	hasz = 0LL;
	while (!q.empty()){
		v = q.front();
		q.pop();
		for (int i = 0; i<4; i++){
			s = {v.st + x[i], v.nd + y[i]};
			if (s.st >= 0 && s.st < n && s.nd >= 0 && s.nd < m && tab[v.st][v.nd] == tab[s.st][s.nd]){
				if (!vis[s.st][s.nd]){
					q.push(s);
					vis[s.st][s.nd] = 1;
					s.st-=r.st;
					s.nd-=r.nd;
					hasz = ((hasz*POT)+(LL)s.st+MOD)%MOD;
					hasz = ((hasz*POT)+(LL)s.nd+MOD)%MOD;
				}
			}
		}
	}
	res.pb(hasz);
}

void solve(){
	cin >> n >> m;
	res.clear();
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++){
			cin >> tab[i][j];
			vis[i][j] = 0;
		}
	}
	for (int i = 0; i<n; i++){
		for (int j = 0; j<m; j++){
			if (!vis[i][j]) bfs({i, j});
		}
	}
	sort(res.begin(), res.end());
	ok = 1;
	for (int i = 1; i<(int)res.size(); i++)if (res[i]!=res[i-1])ok++;
	cout << ok << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
