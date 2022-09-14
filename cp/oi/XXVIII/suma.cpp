//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,tune=native")
#pragma GCC optimize("unroll-loops")

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

const int wheel[] = {10,2,4,2,4,6,2,6,4,2,4,6,6,2,6,4,2,6,4,6,8,4,2,4,2,4,8,6,4,6,2,4,6,2,6,6,4,2,4,6,2,6,4,2,4,2,10,2};
const int wheei[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-47};
#define step(s, i) (s += wheel[i], i += wheei[i])

deque<int>primes;
LL N;

void segmented_sieve(LL n) {
	const int SEG = 16384; // parameter tuned
	const LL sqn = (LL)sqrt(n);
	LL sum = 17;
	static vector<char> is_prime(sqn+1, 1);
	for (int i = 3; i*i <= sqn; i += 2)
		if (is_prime[i]) 
			for (int j = i*i; j <= sqn; j += 2*i)
				is_prime[j] = 0;
 
	// segmented sieve
	vpii p; // st: prime, nd: next to sieve
	LL s = 1+wheel[0], si = 1, k = 1+wheel[0], ki = 1;
	static unsigned char seg[SEG];
	for (LL low = 0; low <= n; low += SEG) {
		LL high = min(low + SEG - 1, n);
		
		memset(seg, -1, sizeof(seg));
		for (; s * s <= high; step(s, si)) 
			if (is_prime[s]) 
				p.pb({s, s*s-low});
		for (int i = 0; i < p.size(); ++i) {
			int j = p[i].nd, w = 2*p[i].st;
			for (; j < SEG; j += w) seg[j] = 0;
			p[i].nd = j - SEG;
		}
		for (; k <= high; step(k, ki)) if (seg[k - low]) {
			primes.pb(k);
			sum += k;
			while (!primes.empty() && sum > N){
				sum -= primes.front();
				primes.pop_front();
			}
			if (sum == N){
				cout << primes.front() << " " << primes.back() << "\n";
				exit(0);
			}
		}
	}
}

bool is_prime(LL n){
	for (LL d = 2; d*d<=n; d++){
		if (n%d == 0) return 0;
	}
	return 1;
}

void solve(){
	cin >> N;
	if (N == 1){
		cout << "NIE\n";
		return;
	}
	if (is_prime(N)){
		cout << N << " " << N << "\n";
		return;
	}
	if (N <= 20){
		vll p = {2, 3, 5, 7, 11, 13, 17};
		rep(i, 0, sz(p)){
			rep(j, i, sz(p)){
				int sum = 0;
				rep(k, i, j+1){
					sum += p[k];
				}
				if (sum == N){
					cout << p[i] << " " << p[j] << "\n";
					return;
				}
			}
		}
		cout << "NIE\n";
		return;
	}
	primes.pb(2);
	primes.pb(3);
	primes.pb(5);
	primes.pb(7);
	
	LL x = N/2;
	LL y = N-x;
	LL nearest = -1;
	while(1) {
		if (is_prime(x)){
			nearest = x;
			break;
		}
		if (is_prime(y)){
			nearest = y;
			break;
		}
		x--;y++;
	}
	if (is_prime(N-nearest) && nearest*2!=N){
		cout << nearest << " " << N-nearest << "\n";
		return;
	} 
	
	segmented_sieve(N/3LL+2137LL);
	//debug(primes);
	cout << "NIE\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();

	return 0;
}
