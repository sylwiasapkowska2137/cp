#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int,int>
#define st first
#define nd second
#define pb push_back

const int MAX = 1e6+7;
int prime[MAX];

void sito(){
	prime[0] = prime[1] = 0;
	for (int i = 2; i<MAX; i++){
		if (!prime[i]){
			prime[i] = i;
			if ((LL)i*i < (LL)MAX){
				for (int j = (LL)(i*i); j<MAX; j+=i) prime[j] = i;
			}
		}
	}
}

LL rozloz(int x){
	LL ans = 0LL;
	while (prime[x]){
		ans+=(LL)prime[x];
		x/=prime[x];
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q, a, b;
	sito();
	cin >> n >> q;
	while (q--){
		cin >> a >> b;
		int d = __gcd(a, b);
		LL ans = rozloz(a) + rozloz(b) - (2*rozloz(d));
		cout << ans << "\n";
	}
	
	return 0;
}
