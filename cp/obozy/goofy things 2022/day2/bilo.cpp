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

void solve(){
	int n, m; cin >> n >> m;
	vll a(n), b(m);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, m) cin >> b[i];
	LL tab[n][m];
	memset(tab, 0LL, sizeof(tab));
	rep(i, 0, n){
		rep(j, 0, m){
			tab[i][j] = a[i]*b[j];
		}
	}
	LL ans = 0LL;
	rep(a, 0, n){
		rep(b, 0, m){
			rep(c, a, n){
				rep(d, b, m){
					//debug(a);
					//debug(b);
					//debug(c);
					//debug(d);
					
					LL sum = 0LL;
					rep(k, a, c+1){
						rep(l, b, d+1){
							sum += tab[k][l];
						}
					}
					//debug(sum);
					if (sum > 0) ans++;
				}
			}
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
