//Sylwia Sapkowska
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
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x, val) memset(x, val, sizeof(x))
#define PI 3.14159265359

int p(int a, int b){
	return a+rng()%(b-a+1);
}

const LL MAX1 = 507, MAX2 = 2e4+7, MOD = 1e9+7, BASE = 2137, INF = 1e9+7;
int n, m;
char tab[MAX1][MAX2];
LL Hash[MAX1][MAX2];
LL inv[MAX2];

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

void make_hash(int lvl){
	LL pot = 1;
	rep(j, 1, m+1){
		Hash[lvl][j] = (Hash[lvl][j-1]+tab[lvl][j]*pot)%MOD;
		pot = (pot*BASE)%MOD;
	}
}

LL count_hash(int lvl, int a, int b){
	LL hash = (Hash[lvl][b]-Hash[lvl][a-1]+MOD)%MOD;
	hash = (hash*inv[a-1])%MOD;
	return hash;
}

bool check(int l, int r){
	LL prev = count_hash(1, l, r), curr;
	rep(i, 2, n+1){
		curr = count_hash(i, l, r);
		//debug(prev, curr);
		if (prev == curr) return 1;
		prev = curr;
	}
	return 0;
}

void solve(){
	cin >> n >> m;
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			cin >> tab[i][j];
		}
	}
	LL pot = 1;
	rep(i, 0, max(n, m)+2){
		inv[i] = inverse(pot);
		pot = (pot*BASE)%MOD;
	}
	rep(i, 1, n+1) make_hash(i);
	
	vi col(m+1, 0);
	rep(i, 1, m+1){
		bool ok = 1;
		rep(j, 2, n+1){
			ok &= (tab[j][i]>=tab[j-1][i]);
		}
		//if (tab[1][i] == tab[n][i]) ok = 0;
		col[i] = ok;
	}
	//debug(col);
	int len = INF, ansl, ansr;
	rep(i, 1, m+1){
		if (!col[i]) continue;
		int L = i, R = m;
		//debug(L, R);
		int ans = -1;
		while (R>=L){
			int m = (L+R)/2;
			//debug(i, m);
			if (check(i, m)){
				ans = m;
				L = m+1;
			} else R = m-1;
		}
		if (ans == -1){
			len = 1;
			ansl = i;
			ansr = i;
			break;
		}
		if (ans == m) continue;
		//debug(i, ans);
		bool ok = 1;
		rep(j, 2, n+1){
			if (count_hash(j, i, ans) == count_hash(j-1, i, ans)){
				if (tab[j][ans+1] < tab[j-1][ans+1]){
					ok = 0;
				}
			}
		}
		//debug(ok);
		if (!ok) continue;
		if (len > ans+1-i+1){
			len = ans-i+2;
			ansl = i;
			ansr = ans+1;
		}
	}
	cout << len << "\n";
	debug(ansl, ansr);
	//cout << ansl << " " << ansr << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
