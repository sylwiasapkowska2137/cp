#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second

const int MAX = 1e6+7;
int pref[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x, y, a, b;
	cin >> n >> x >> y;
	for (int i = 0; i<n; i++){
		cin >> a >> b;
		pref[a]++;
		pref[b+1]--;
	}
	for (int i = 1; i<1000000; i++){
		pref[i] += pref[i-1];
	}
	vector<int>ans;
	if (y>x){
		for (int i = x; i<=y; i++){
			if (!pref[i]) ans.pb(i);
		}
	} else {//y<x
		for (int i = x; i>=y; i--){
			if (!pref[i]) ans.pb(i);
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto x: ans) cout << x << " ";
	return 0;
}
