#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)

void solve(){
	int n, m, a, b, q, t, cnt = 0;
	cin >> n >> m;
	vector<int>deg(n+1, 0), weaker(n+1, 0);
	rep(i, 0, m){
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
		if (a < b) swap(a, b);
		weaker[a]++;
	}
	rep(i, 1, n+1) if (deg[i] == weaker[i] && deg[i]>0) cnt++;
	cin >> q;
	while (q--){
		cin >> t;
		if (t == 1){
			cin >> a >> b;
			if (a < b) swap(a, b);
			deg[a]++;
			weaker[a]++;
			if (deg[b] == weaker[b]) cnt--;
			deg[b]++;
			if (deg[b] == weaker[b]) cnt++;
		} else if (t == 2){
			cin >> a >> b;
			if (a < b) swap(a, b);
			deg[a]--;
			weaker[a]--;
			if (deg[b] == weaker[b]) cnt--;
			deg[b]--;
			if (deg[b] == weaker[b]) cnt++;
		} else cout << cnt << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
