#include <bits/stdc++.h>
using namespace std;
 
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

const int INF = 1e6+7;

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vi wiersz(n+1, -1), kolumna(m+1, -1);
	vector<char> tab(k);
	rep(i, 0, k){
		int type, nr; char c;
		cin >> type >> nr >> c;
		if (type == 0){
			tab[i] = c;
			wiersz[nr] = i;
		} else {
			tab[i] = c;
			kolumna[nr] = i;
		}
	}
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			if (wiersz[i] == -1 && kolumna[j] == -1) cout << "a";
			else {
				if (wiersz[i]<kolumna[j]) cout << tab[kolumna[j]];
				else cout << tab[wiersz[i]];
			}
		}
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
