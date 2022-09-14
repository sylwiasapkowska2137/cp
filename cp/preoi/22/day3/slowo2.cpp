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

const LL MOD = 1e9+7;
const int MAX = 130;
int C[MAX];

void solve(){
	string s; cin >> s;
	int n = sz(s);
	for (auto u:s) C[(int)u]++;
	s = "$"+s;
	vector<char>All;
	for (char c = '0'; c<='9'; c++) All.pb(c);
	for (char c = 'a'; c<='z'; c++) All.pb(c);
	for (char c = 'A'; c<='Z'; c++) All.pb(c);
	LL ans = 0LL;
	for (auto a:All){
		for (auto b:All){
			if (a==b) continue;
			if (C[(int)a]<=1 || C[(int)b]<=1) continue;
			vll lewo(n+1, 0);
			map<char, int>cnt;
			LL diff = 0;
			rep(i, 1, n+1){
				lewo[i] = lewo[i-1];
				if (s[i] == a || s[i] == b) continue;
				lewo[i] += (LL)(diff-(LL)cnt[s[i]]);
				if (lewo[i]>=MOD) lewo[i]%=MOD;
				cnt[s[i]]++;
				diff++;
			}
			vll prawo(n+1, 0);
			LL cnt1 = 0, cnt2 = 0;
			if (s.back() == a) cnt1++;
			else if (s.back() == b) cnt2++;
			repd(i, n-1, 0){
				prawo[i] = prawo[i+1];
				if (s[i] == a){
					prawo[i] += (LL)cnt2;
					cnt1++;
				} 
				if (s[i] == b) cnt2++;
				if (prawo[i]>=MOD) prawo[i]%=MOD;
			}
			LL tmp = 0;
			/*
			for (auto B:pos[(int)b]){
				for (auto A: pos[(int)a]){
					//debug(A,B);
					if (A > B) break;
					tmp += (LL)lewo[A]*(LL)prawo[B];
					if (tmp >= MOD) tmp %= MOD;
				}
			}
			*/
			LL R = 0;
			repd(i, n, 1){
				if (s[i] == b) {
					R += prawo[i];
					if (R>=MOD) R%=MOD;
				}
				if (s[i] == a){
					tmp += ((LL)lewo[i]*R);
					if (tmp>=MOD) tmp%=MOD;
				}
			}
			//debug(a, b, lewo, prawo, tmp);
			ans += tmp;
			if (ans >= MOD) ans %= MOD;
		}
	}
	ans += MOD;
	ans %= MOD;
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
