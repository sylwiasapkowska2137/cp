#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second

const int MAX = 2e5+7, M = 3e5+7, N = 7007;
struct e{int a, b, i;};
vector<e>graf[MAX];
int rep[MAX];
vector<bool>ans;

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a!=b) rep[b] = a;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, a, b, c;
	cin >> n >> m;
	ans.resize(m, 0);
	for (int i = 1; i<=n; i++) rep[i] = i;
	for (int i = 0; i<m; i++){
		cin >> a >> b >> c;
		if (a>b) swap(a, b);
		graf[c].pb({a, b, i});
	}
	for (int i = 1; i<MAX; i++){
		for (auto edge: graf[i]){
			if (Find(edge.a) != Find(edge.b)) {
				ans[edge.i] = 1;
			}
		}	
		for (auto edge: graf[i]) Union(edge.a, edge.b);
	}
	for (int i = 0; i<m; i++) {
		if (ans[i]) cout << "TAK\n";
		else cout << "NIE\n";
	}
	return 0;
}
