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
	int n;
	cin >> n;
	vector<int>a(n);
	int freq[3];
	memset(freq, 0, sizeof(freq));
	rep(i, 0, n) {
		cin >> a[i];
		freq[a[i]%3]++;
	}
	//rep(i, 0, 3) debug(freq[i]);
	//cerr << "\n";
	int ans = 0;
	rep(i, 0, 3){
		if (freq[i]<n/3){
			int prev = (i == 0)?2:i-1;
			freq[prev]-=(n/3-freq[i]);
			ans+=(n/3-freq[i]);
			freq[i]=n/3;
		}
	}
	//rep(i, 0, 3) debug(freq[i]);
	//cerr << "\n";
	rep(i, 0, 3){
		if (freq[i]<n/3){
			int prev = (i == 0)?2:i-1;
			freq[prev]-=(n/3-freq[i]);
			ans+=(n/3-freq[i]);
			freq[i]=n/3;
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
