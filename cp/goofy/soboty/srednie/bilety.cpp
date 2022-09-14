#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pb push_back
#define st first
#define nd second
#define pii pair <int, int>
#define debug(x) cerr << x << " "

map<int, int> m;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, a, b;
	cin >> n >> a >> b;
	vector <LL> dp(n+1, 0);
	dp[1] = a;
	b--;
	m[a]+=b;
	//debug(dp[1]);
	for (int i = 2; i<=n; i++){
		cin >> a >> b;
		m[a]+=b;
		dp[i] = dp[i-1]+m.begin()->st;
		//debug(dp[i]);
		//debug(m.begin()->nd);
		if (m.begin()->nd == 1) m.erase(m.begin());
		else m.begin()->nd --;
	}
	cout << dp[n] << "\n";
	return 0;
}

