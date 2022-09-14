#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int>pii;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef long double LD;

#define debug(x) cerr << x << " "
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)
#define pb push_back

vi a;
int lvl;
const int MAX = 1e5+7, S = 320;
LL dp[MAX][S];
int n;
int s;

LL gen(int l, int r){
	int len = r-l+1;
	if (len <= s) return dp[l][len];
	int f = (l+r)/2;
	int c = (l+r+1)/2;
	return gen(l, f)+gen(c, r);
}

void LVL(int l, int r){
	if (l == r) return;
	lvl++;
	LVL(l, (l+r)/2);
}

void solve(){
	int q; cin >> n >> q;
	a.resize(n+1);
	s = sqrt(n);
	cout << fixed << setprecision(10);
	rep(i, 1, n+1) cin >> a[i];
	rep(L, 1, n+1) dp[L][1] = a[L];
	rep(len, 2, s+1){
		rep(L, 1, n+1){
			if (L+len > MAX) break;
			int R = L+len-1;
			int ll = (L+R)/2;
			int rr = (L+R+1)/2;
			dp[L][len] = dp[L][ll-L+1]+dp[rr][R-rr+1];
		}
	}
	while (q--){
		int L, R; cin >> L >> R;
		lvl = 0;
		LVL(L, R);
		LL ans = gen(L, R);
		cout << (LD)(ans)/(LD)(1LL<<lvl) << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
