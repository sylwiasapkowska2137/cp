#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

const LL MOD = 1e9+7, P = 37, P2 = 2137, INV = 621621626, INV2 = 440336924;
const int MAX = 1e6+3;
LL pot[MAX], pot2[MAX];

 
void solve(){
	pot[0] = 1;
	pot2[0] = 1;
	rep(i, 1, MAX) {
		pot[i] = (pot[i-1]*P)%MOD;
		pot2[i] = (pot2[i-1]*P2)%MOD;
	}
	
	int n; cin >> n;
	vector<string>tab(n);
	vll hashe(n), hashe2(n);
	int sum = 0;
	rep(i, 0, n) {
		cin >> tab[i];
		hashe[i] = 0LL;
		hashe2[i] = 0LL;
		rep(j, 0, sz(tab[i])) {
			hashe[i] = (hashe[i]+(tab[i][j]-'a'+1)*pot[j])%MOD;
			hashe2[i] = (hashe2[i]+(tab[i][j]-'a'+1)*pot2[j])%MOD;
		}
		sum += sz(tab[i]);
	}

	string s; cin >> s;
	int t = sz(s);
	vi p(n);
	rep(i, 0, n)p[i] = i;
	map<pll, LL>mapa;
	
	do{
		int curr = 0;
		LL hash = 0LL;
		LL hash2 = 0LL;
		rep(i, 0, n){
			hash = (hash+pot[curr]*hashe[p[i]])%MOD;
			hash2 = (hash2+pot2[curr]*hashe2[p[i]])%MOD;
			curr += sz(tab[p[i]]);
		}
		mapa[{hash, hash2}]++;
	} while (next_permutation(all(p)));
   
	LL ans = 0LL;
	LL curr_hash = 0;
	LL curr_hash2 = 0;
	rep(i, 0, sum){
		curr_hash = (curr_hash+(s[i]-'a'+1)*pot[i])%MOD;
		curr_hash2 = (curr_hash2+(s[i]-'a'+1)*pot2[i])%MOD;
	}
	rep(j, sum, t) {
		//debug(curr_hash);
		//debug(find_hash(j-sum+1, j));
		//cerr << "\n";
		ans += mapa[{curr_hash, curr_hash2}];
		curr_hash = (curr_hash-(s[j-sum]-'a'+1)+MOD)%MOD;
		curr_hash = ((curr_hash * INV)%MOD+MOD)%MOD;
		curr_hash = (curr_hash+(s[j]-'a'+1)*pot[sum-1])%MOD;
		curr_hash2 = (curr_hash2-(s[j-sum]-'a'+1)+MOD)%MOD;
		curr_hash2 = ((curr_hash2 * INV2)%MOD+MOD)%MOD;
		curr_hash2 = (curr_hash2+(s[j]-'a'+1)*pot2[sum-1])%MOD;
	}
	ans += mapa[{curr_hash, curr_hash2}];
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}


