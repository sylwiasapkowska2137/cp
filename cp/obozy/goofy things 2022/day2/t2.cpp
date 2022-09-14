#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int>pii;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<pii> vpii;

#define debug(x) cerr << x << " "
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)
#define pb push_back

struct segmax{
	vll tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
	}
	
	void build(vi &a, int k){
		int n = sz(a);
		rep(i, 0, n) {
			if (a[i] <= k/2){
				tab[i+size] = a[i];
			}
		}
		repd(i, size-1, 0){
			tab[i] = max(tab[2*i], tab[2*i+1]);
		}
	}
	
	LL query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL ans = 0;
		while (r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
	
};

void solve(){
	int n, q, k; cin >> n >> q >> k;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
