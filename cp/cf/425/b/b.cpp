/*
	Author: sysia
	13.01.2022 17:33:16
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<LD> vld;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x) memset(x, 0, sizeof(x))
#define debug(x) cerr << x << " "
#define PI 3.14159265359

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

const int MAX = 107;
int tab[MAX][MAX];
int n, m, k;

int check(int x, bool ok){
	int bad = 0;
	if (ok){
		rep(i, 0, n){
			int good = 0;
			rep(j, 0, m){
				if (tab[x][j] == tab[i][j]){
					good++;
				}
			}
			bad += min(good, m-good);
		}
	} else {
		vi t(n, 0), c(m);
		rep(i, 0, n){
			if (x&(1<<i)){
				t[i] = 1;
			}
		}
		rep(i, 0, m){
			int good = 0;
			rep(j, 0, n){
				if (t[j] == !tab[j][i]) good++;
			}
			if (good >= n-good) c[i] = 1;
			else c[i] = 0;
		}
		rep(i, 0, n){
			rep(j, 0, m){
				if ((t[i]^c[j]) == !tab[i][j]) bad++; 
			}
		}
	}
	return bad;
}

void solve(){
	cin >> n >> m >> k;
	rep(i, 0, n){
		rep(j, 0, m){
			cin >> tab[i][j];
		}
	}
	int ans = 2137;
	if (n<=k){
		rep(mask, 0, (1<<n)){
			ans = min(ans, check(mask, 0));
		}
	} else {
		rep(i, 0, n){
			ans = min(ans, check(i, 1));
		}
	}
	if (ans > k) cout << "-1\n";
	else cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
