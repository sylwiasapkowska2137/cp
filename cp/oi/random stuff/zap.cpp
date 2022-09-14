#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int MAX = 5e4+7;
int prime[MAX], mobius[MAX];

void sito(){
	for (int i = 0; i<MAX; i++) mobius[i] = 1;
	prime[0] = prime[1] = 1;
	for (int i = 2; i<MAX; i++){
		if (!prime[i] && (LL)i*i < MAX){
			for (int j = i; j<MAX; j+=i){
				if (j>i) prime[j] = 1;
				if (j%(i*i) == 0) mobius[j] = 0;
				mobius[j] = -mobius[j];
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	LL a, b, d;
	cin >> t;
	sito();
	while (t--){
		cin >> a >> b >> d;
		LL ans = 0LL;
		for (LL v = 1; v<=min(a/d, b/d); v++){
			ans += ((a/(v*d)) * (b/(v*d)) * mobius[v]);
		}
		cout << ans << "\n";
	}
	
	return 0;
} 
