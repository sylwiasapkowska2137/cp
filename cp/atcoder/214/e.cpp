#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)

const int MAX = 1e9;

void solve(){
	int n, a, b;
	cin >> n;
	set<int>s;
	map<int, vector<int>>mapa;
	rep(i, 0, n){
		cin >> a >> b;
		mapa[a].pb(b);
		s.insert(a);
	}
	s.insert(INT_MAX);
	priority_queue<int, vector<int>, greater<int>>pq;
	int k = *s.begin();
	while (k<=MAX){
		for (auto x: mapa[k]) pq.push(x);
		pq.pop();
		if (pq.empty()) k = (*s.lower_bound(k+1));
		else{
			if (pq.top()<=k) {
				cout << "NO\n";return;
			} 
			k++;
		}
	}
	if (!pq.empty()) cout << "NO\n";
	else cout << "YES\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}




