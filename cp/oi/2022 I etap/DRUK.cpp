//Sylwia Sapkowska
//template from https://codeforces.com/profile/Geothermal
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

const LL MAX = 1002, MOD = 1e9+7, BASE = 2137;
int n, m;
vi ans;
char tab[MAX][MAX];
bool vis[MAX][MAX];
int V[MAX][MAX];
LL hash_poziomy[MAX][MAX], hash_pionowy[MAX][MAX];
LL inv[MAX];
set<int>divisors;

LL power(LL a, LL b){
	LL res = 1LL;
	while (b){
		if (b&1) res = (res*a)%MOD;
		a = (a*a)%MOD;
		b/=2;
	}
	return res;
}

LL inverse(LL num){
	return power(num, MOD-2);
}

void find_divisors(int k){
	for (int i = 1; i*i<=k; i++){
		if (k%i == 0){
			divisors.insert(i);
			divisors.insert(k/i);
		}
	}
}

void make_hash_pionowy(int lvl){
	LL pot = 1;
	rep(i, 1, n+1){
		hash_pionowy[i][lvl] = (hash_pionowy[i-1][lvl]+tab[i][lvl]*pot)%MOD;
		pot = (pot*BASE)%MOD;
	}
}

void make_hash_poziomy(int lvl){
	LL pot = 1;
	rep(j, 1, m+1){
		hash_poziomy[lvl][j] = (hash_poziomy[lvl][j-1]+tab[lvl][j]*pot)%MOD;
		pot = (pot*BASE)%MOD;
	}
}

LL count_hash_pionowy(int a, int b, int lvl){
	LL hash = (hash_pionowy[b][lvl]-hash_pionowy[a-1][lvl]+MOD)%MOD;
	hash = (hash*inv[a-1])%MOD;
	return hash;
}

LL count_hash_poziomy(int lvl, int a, int b){
	LL hash = (hash_poziomy[lvl][b]-hash_poziomy[lvl][a-1]+MOD)%MOD;
	hash = (hash*inv[a-1])%MOD;
	return hash;
}


bool check(LL H, int d){
	memo(V);
	rep(a, 1, n+1){
		rep(b, 1, m+1){
			if (V[a][b]) continue;
			if (b + d <= m+1){
				int sum = 0;
				rep(i, b, b+d) sum += V[a][i]; 
				if (count_hash_poziomy(a, b, b+d-1) == H && sum == 0){
					rep(i, b, b+d) V[a][i]++;
					continue;
				}
			}
			if (a + d <= n+1){
				if (count_hash_pionowy(a, a+d-1, b) == H){
					rep(i, a, a+d) V[i][b]++;
					continue;
				}
			}
			return 0;
		}
	}
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			//debug(V[i][j]);
			if (!V[i][j]) return 0;
		}
	}
	ans.pb(d);
	return 1;
}

void solve(){
	cin >> n >> m;
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			cin >> tab[i][j];
		}
	}
	rep(i, 1, n+1) make_hash_poziomy(i);
	rep(i, 1, m+1) make_hash_pionowy(i);
	
	LL pot = 1;
	rep(i, 0, max(n, m)+2){
		inv[i] = inverse(pot);
		pot = (pot*BASE)%MOD;
	}
	
	find_divisors(n);
	find_divisors(m);
	
	
	for (auto x: divisors){
		bool ok = 0;
		if (x <= n) ok = check(hash_pionowy[x][1], x);
		if (!ok && x<=m) check(hash_poziomy[1][x], x);
	}
	sort(all(ans));
	ans.erase(unique(all(ans)), ans.end());
	cout << sz(ans) << "\n";
	for (auto x: ans) cout << x << " ";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	
	return 0;
}
