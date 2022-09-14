#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>

const int MAX = 5007;
const LL INF = 1e18;
LL graf[MAX][MAX];
bool vis[MAX];
int n;
LL res;
struct edge{
	LL w = INF;
	int to = -1;
};
edge mini[MAX];

void prim(){
	mini[1].w = 0;
	for (int i = 1; i<=n; i++){
		int v = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && (v == -1 || mini[j].w < mini[v].w)) v = j;
		}
		vis[v] = 1;
		res = max(res, mini[v].w);
		for (int j = 1; j<=n; j++){
			if (graf[v][j] < mini[j].w) {
				mini[j].w = graf[v][j];
				mini[j].to = v;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	LL diff1, diff2;
	cin >> n;
	vector <pii> p(n+1);
	for (int i = 1; i<=n; i++) cin >> p[i].st >> p[i].nd;
	
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			diff1 = ((LL)p[i].st - (LL)p[j].st)*((LL)p[i].st - (LL)p[j].st);                                                
			diff2 = ((LL)p[i].nd - (LL)p[j].nd)*((LL)p[i].nd - (LL)p[j].nd);      
			graf[i][j] = (diff1+diff2);
		}
	}
	prim();
	res = ceil(double(sqrt(res)));
	res *= (LL)(n-1);
	cout << res << "\n";
	return 0;
}
