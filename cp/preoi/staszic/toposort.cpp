#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define ULL unsigned LL
#define LD long double
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int INF = 1e9+7;

const int MAX = 1e6+7;
vector <int> graf[MAX];
vector <int> in, ans;
queue <int> k;

int main(){
	fastio;
	int n, m, a, b, ile = 0;
	cin >> n >> m;
	in.assign(n+1, 0);
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[a].pb(b);
		in[b]++;
	}
	for (int i = 1; i<=n; i++) if (in[i]==0) k.push(i);
	while (!k.empty()){
		auto x = k.front();
		ans.pb(x);
		k.pop();
		for (auto u: graf[x]){
			in[u]--;
			if (in[u]==0) k.push(u);
		}
	}
	for (auto x: ans) cout << x << " ";
	return 0;
}
