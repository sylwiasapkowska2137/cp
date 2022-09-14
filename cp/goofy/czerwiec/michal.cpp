#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define ok if(0)
#define pii pair<int, int>
#define pll pair<LL, LL>
#define pb push_back
#define st first
#define nd second

void solve(){
	LL n, t, ans = 0;
	cin >> n >> t;
	vector<pll>a(n);
	for (int i = 0; i<n; i++) cin >> a[i].nd >> a[i].st;
	sort(a.begin(), a.end()); //st - ton, nd - len
	ok{
		for (auto x: a){
			debug(x.st);
			debug(x.nd);
			cerr << "\n";
		}
	}
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	for (int i = 0; i<n; i++){
		for (int j = i; j<n; j++){
			
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int z;
	cin >> z;
	while (z--) solve();
	
	return 0;
}
