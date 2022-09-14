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

bool ok;

int win(vi &x, vi&y, int X, int Y){
	int A = 0, B = 0;
	for (auto a: x){
		for (auto b: y){
			if (a == b) continue;
			if (a > b) A++;
			else B++;
		}
	}
	if (A == B) return 3;
	if (A > B) return X;
	return Y;
}

void backtrack(int pos, vi &curr, vi&a, vi&b){
	if (pos == 4){
		int cnt[4] = {0, 0, 0, 0};
		cnt[win(curr, a, 0, 1)]++;
		cnt[win(curr, b, 0, 2)]++;
		cnt[win(a, b, 1, 2)]++;
		int x = *max_element(cnt, cnt+3);
		if (x == 1 && cnt[3] == 0){
			ok = 1;
			//debug(curr);
		}
		return;
	}
	rep(i, 1, 11){
		curr.pb(i);
		backtrack(pos+1, curr, a, b);
		curr.pop_back();
	}
}

void solve(){
	vi a(4), b(4);
	rep(i, 0, 4) cin >> a[i];
	rep(i, 0, 4) cin >> b[i];
	ok = 0;
	vi curr = {};
	backtrack(0, curr, a, b);
	if (ok) cout << "yes\n";
	else cout << "no\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
