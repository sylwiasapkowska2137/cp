#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

const int MAX = 3007;
vector <int> graf[MAX];
vector <bool> del;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, a, b;
	cin >> n >> m;
	del.assign(n+1, 0);
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	
	return 0;
}


