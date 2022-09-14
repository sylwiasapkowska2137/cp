#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define debug(x) cerr << x << " "
#define pii pair<int,int>
#define st first
#define nd second

const int MAX = 1e5+7;
int freq[MAX], tab[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	LL a, b, nww;
	cin >> n >> m;
	for (int i = 0; i<n; i++){
		cin >> a >> b;
		nww = (a*b)/(LL)(__gcd(a, b));
		if (nww > (LL)m) continue;
		freq[(int)nww]++;
	}
	for (int i = 1; i<=m; i++){
		if (freq[i]){
			for (int j = i; j<=m; j+=i) tab[j]+=freq[i];
		}
	}
	int ans = 1;
	for (int i = 1; i<=m; i++) {
		ans = max(ans, tab[i]);
		//debug(tab[i]);
	}
	cout << ans << "\n";
	return 0;
}
