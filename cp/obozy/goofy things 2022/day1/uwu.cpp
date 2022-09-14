#include <bits/stdc++.h>
using namespace std;


typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int>pii;

#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for(int i = a; i>=b; i--)
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define pb push_back

const LL INF = 1e15;

LL check(vi&a, int zero){
	vi tab = a;
	rep(i, 0, zero) tab.pb(0);
	sort(all(tab));
	int L = 0, R = sz(tab)-1;
	LL mini = INF, maxi = -INF;
	while (1){
		LL curr = tab[L]+tab[R];
		L++;R--;
		mini = min(mini, curr);
		maxi = max(maxi, curr);
		if (L>=R) break;
	}
	return maxi-mini;
}

void fastscan(int &n){
	bool neg = 0;
	register int c;
	n = 0;
	c = getchar();
	if (c == '-'){
		neg = 1;
		c = getchar();
	}
	for (; (c>47 && c<58); c=getchar()) n = n*10+c-48;
	if (neg) n = -n;
}

void solve(){
	int n; fastscan(n);
	vi a(n);
	rep(i, 0, n) fastscan(a[i]);
	if (n&1) a.pb(0);
	LL ans = INF;
	for (int zero = 0; zero<n-n/4; zero+=2) ans = min(ans, check(a, zero));
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
