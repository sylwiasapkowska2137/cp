#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pb push_back

vector <int> pierwsze;

void sieve(int n){
	vector<bool> is_prime(n+1, 1);
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (LL)i*i <= n) {
        for (int j = i*i; j <= n; j += i)
            is_prime[j] = false;
		}
	}
	for (int i = 1; i<=n; i++) if (is_prime[i]) pierwsze.pb(i);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, maxx = 0;
	LL x, y;
	cin >> n >> x >> y;
	sieve(1000000);
	vector <int> a(n);
	for (int i = 0; i<n; i++){
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	LL res = LLONG_MAX, curr;
	if (maxx == 1){
		cout << min(n*y, x*n);
		return 0;
	}
	int i = 0;
	maxx++;
	while (pierwsze[i]<=maxx && i < (int)pierwsze.size()){
		curr = 0LL;
		for (int j = 0; j<n; j++){
			if (a[j]%pierwsze[i] == 0) continue;
			LL v = a[j]%pierwsze[i];
			curr += min(((LL)pierwsze[i]-v)*y, x);
		}
		res = min(res, curr);
		i++;
	}
	cout << res;
	return 0;
}
