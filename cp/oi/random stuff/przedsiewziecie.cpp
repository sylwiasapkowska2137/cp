#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 1e5+7;
vector<int>graf[MAX], gt[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, b, q, nr, czas;
	vector<int>t(n+1);
	for (int i = 1; i<=n; i++){
		cin >> t[i] >> m;
		for (int j = 0; j<m; j++){
			cin >> b;
			graf[i].pb(b);
			gt[b].pb(i);
		}
	}
	sss();
	
	cin >> q;
	while (q--){
		cin >> nr >> czas;
	}
	return 0;
}
