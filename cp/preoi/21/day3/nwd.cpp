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

int losuj(int a, int b){
	return a+rng()%(b-a+1);
}

const int MAX = 2e6+7;
LL pref[MAX], suma[MAX];
vi prime(MAX, 1);

void sito(){
	prime[0] = prime[1] = 0;
	rep(i, 2, MAX){
		if (prime[i] && (LL)i*(LL)i < MAX){
			for (int j = i*i; j<MAX; j+=i){
				prime[j] = 0;
			}
		}
	}
}

void solve(){
	int n, x, y; cin >> n >> x >> y;
	vi a(n);
	sito();
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) {
		pref[a[i]]++;
		suma[a[i]]+=a[i];
	}
	rep(i, 1, MAX) {
		pref[i] += pref[i-1];
		suma[i] += suma[i-1];
	}
	LL ans = 1e18;
	rep(d, 2, MAX){
		if (!prime[d]) continue;
		LL f = min(d-1, x/y);
		//debug(d, f);
		LL curr = 0;
		f = (LL)d-1-f;
		for (int g = 0; g+d<MAX; g+=d){
			//[g+1, g+d-1];
			// [g+1, g+f] opłaca sie usunac
			LL sum = pref[g+f]-pref[g];
			LL sum2 = pref[g+d-1]-pref[g+f]; //add
			sum2 = (LL)((LL)g+(LL)d)*sum2-(LL)(suma[g+d-1]-suma[g+f]);
			curr += sum*(LL)x+(sum2)*(LL)y;
			//debug(g, sum, ile, sum2, curr);
		}
		ans = min(ans, curr);
		//cerr << "\n";
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
