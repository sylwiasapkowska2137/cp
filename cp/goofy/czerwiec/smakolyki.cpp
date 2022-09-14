#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second

const int MAX = 3e5+6;
int freq[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, r = 0;
	LL ans = 0LL;
	cin >> n >> m;
	vector<int>a(n);
	for (int i = 0; i<n; i++)cin >> a[i];
	for (int l = 0; l<n; l++){
		while (r<n && freq[a[r]] == 0){
			freq[a[r]]++;
			r++;
			ans += (LL)(r-l);
		}
		freq[a[l]]--;
	}
	cout << ans << "\n";
	return 0;
}
