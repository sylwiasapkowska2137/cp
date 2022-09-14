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

const int MAX = 317;
unordered_map<int, int>mapa[MAX];
int cnt[MAX];

void solve(){
	int n; cin >> n;
	vi a(n);
	int S = max(1, (int)sqrt(n));
	rep(i, 0, n) {
		cin >> a[i];
		mapa[i/S][a[i]]++;
	}
	debug(S);
	int q; cin >> q;
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int l, r, c; cin >> l >> r >> c;
			--l;--r;
			int L = l/S;
			int R = r/S;
			if (L == R){
				rep(i, l, r+1){
					mapa[i/S][a[i]+cnt[i/S]]--;
					a[i]+=c;
					mapa[i/S][a[i]+cnt[i/S]]++;
				}
				rep(i, 0, S+2) {
					debug(mapa[i]);
				}
				//debug(cnt);
				continue;
			}
			debug(L, R);
			rep(i, l, (L+1)*S){
				mapa[i/S][a[i]+cnt[i/S]]--;
				a[i]+=c;
				mapa[i/S][a[i]+cnt[i/S]]++;
			}
			rep(i, R*S, r+1){
				mapa[i/S][a[i]+cnt[i/S]]--;
				a[i]+=c;
				mapa[i/S][a[i]+cnt[i/S]]++;
			}
			rep(i, L+1, R) cnt[i]+=c;
			
			rep(i, 0, S+2) {
				debug(mapa[i]);
			}
			//debug(cnt);
		} else {
			int l, r, d; cin >> l >> r >> d;
			--l;--r;
			int L = l/S;
			int R = r/S;
			if (L == R){
				int ans = 0;
				rep(i, l, r+1){
					if (a[i]+cnt[L] == d) ans++;
				}
				cout << ans << "\n";
				continue;
			}
			debug(L, R);
			int ans = 0;
			rep(i, l, (L+1)*S){
				if (a[i]+cnt[i/S] == d) ans++;
			}
			rep(i, R*S, r+1){
				if (a[i]+cnt[i/S] == d) ans++;
			}
			rep(i, L+1, R) ans += mapa[i][d-cnt[i]];
			
			cout << ans << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
