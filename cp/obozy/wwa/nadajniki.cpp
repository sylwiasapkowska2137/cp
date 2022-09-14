#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int MAX = 5e5+7;
vector<int>graf[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b, mindist = MAX, v;
	cin >> n;
	vector<int>maxdist(n+1);
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	for (int i = 1; i<=n; i++){
		cin >> maxdist[i];
		if (maxdist[i]<mindist){
			mindist = maxdist[i];
			v = i;
		}
		if (!maxdist[i]){
			cout << i << " ";
			for (int j = 1; j<i; j++) cout << j << " ";
			for (int j = i+1; j<=n; j++) cout << j << " ";
			cout << "\n";
			return 0;
		}
	}
	debug(v);
	cerr << "\n";
	return 0;
}
